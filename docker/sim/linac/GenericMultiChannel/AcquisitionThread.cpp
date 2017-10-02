//=============================================================================
//
// file :         AcquisitionThread.h
//
// description :  Thread that handle Beamloss data collection.
//
// project :      TANGO Device Server
//
// $Author: tappret $
//
// $Revision: 1.2 $
//
//
// copyleft :     European Synchrotron Radiation Facility
//                BP 220, Grenoble 38043
//                FRANCE
//
//=============================================================================

#include <AcquisitionThread.h>

namespace GenericMultiChannel_ns
{

/**
 *   Constructor:
 *      method: AcquisitionThread::AcquisitionThread
 *
 *      description: Take monitor, and start the thread.
 *
 */
AcquisitionThread::AcquisitionThread(GenericMultiChannel *device, omni_mutex &m) : omni_thread(), mutex(m)
{
	multiChannel = device;
	abort = false;
	deviceProxyCreationOk = true;
	deviceProxyFailedReason = "";

	{ // Copy readAttributeName device property.
		omni_mutex_lock lockIt(mutex);
		pollingPeriod = multiChannel->dataAcquisitionPeriod;
		deviceTimeOut = multiChannel->deviceTimeOut;
		attributesNumber = multiChannel->attributesList.size();

		// Allocate buffer for AttributeProxy pointers.
		deviceProxies = new DeviceProxy*[attributesNumber];
		readReplyIds = new long[attributesNumber];

		// Create attribute proxies.
		for (int i=0; i < attributesNumber; i++)
		{
			try
			{
				string devName = "Uninitialised";
				string attrName = "Uninitialised";

				// Extract device name / attribute from full 4 fields attribute name.
				size_t pos = multiChannel->attributesList[i].find_last_of("/");
				if (pos != string::npos)
				{
					devName  = multiChannel->attributesList[i].substr(0, pos);
					attrName = multiChannel->attributesList[i].substr(pos +1, multiChannel->attributesList[i].length() - (multiChannel->attributesList[i].length() -pos));
				}

				attributeName.push_back(attrName);
				deviceName.push_back(devName);
				deviceProxies[i] = NULL;
				deviceProxies[i] = new DeviceProxy(devName);
			}
			catch(DevFailed &e)
			{
				deviceProxyCreationOk = false;
				deviceProxyFailedReason = deviceProxyFailedReason + " * " +multiChannel->attributesList[i] + " :\n" + string(e.errors[0].reason)+"\n" + string(e.errors[0].desc)+"\n";
			}
		}
	}

	if (deviceProxyCreationOk == false)
	{
		cerr << "Ooops, we got problems during DeviceProxy creation :\n" + deviceProxyFailedReason;
	}
	cout << "Built "<< attributesNumber << " DeviceProxy." << endl;
	cout << "Starting Acquisition Thread, polling period is :"<< pollingPeriod << " milliseconds." << endl;
	start_undetached();
}


/**
 *      method: AcquisitionThread::run_undetached
 *
 *      description:    method which actually execute the data and
 *   expected calculations.
 *
 */
void *AcquisitionThread::run_undetached(void *arg)
{
	string full_status;

	struct timespec rqtp;
	long deltaT, remainingT;

	while(abort == false)
	{
		// Get actual time. Second parameter is no more used.
		chrono.start();
		collectData();
		chrono.stop();
		localDataCopy.dataCollectionDuration = chrono.getDeltaMilliseconds();

		computeData();
		synchronizeDataWithMainThread();
		chrono.stop();	// Chrono could be stopped n times.

		// Get duration in milliseconds.
		deltaT = chrono.getDeltaMilliseconds();
		remainingT = pollingPeriod - deltaT;

		// Do not pause if thread acquisition is late.
		if (remainingT > 0)
		{
			rqtp.tv_sec = remainingT / 1000;     // Number of seconds.
			rqtp.tv_nsec = (remainingT % 1000) * 1000000; // Number of ms.
			int r = nanosleep(&rqtp, NULL);

			if (r == -1)
			{
				cerr << "Nanosleep error !" << endl;
			}
			//cout << "To match pollingPeriod (" << pollingPeriod << " ms) nanosleep of " << remainingT << " ms was done (read: " << deltaT <<  " ms)."<< endl;
		}
	}


	// Free allocated things.
	delete [] readReplyIds;

	for (int i=0; i < attributesNumber; i++)
	{
		if (deviceProxies[i] != NULL) delete deviceProxies[i];
	}

	delete []deviceProxies;

	cout << "Exiting Acquisition Thread." << endl;
	return (void *)0xDEADBEEF;
}



/**
 *		This method collects data. It doesn't use read_attributes_reply(..., time_out)
 *      because time out delays are cumulative: e.g : 200 ms time is given for every
 * 		device. Instead, we do a pause and collect all data without time out. All
 * 		reply which are not arrived, are discarded.
 *
 *      method: AcquisitionThread::collectData()
 *
 *      description:    method which execute the data collecting.
 *
 */
void AcquisitionThread::collectData()
{
	// Perform read only if all AttributeProxy are OK.
	if (deviceProxyCreationOk != true) return;

	dataCollectionOk = true;
	dataCollectionFailedReason = "";
	vector<string> attributeToRead;

	// Launch all requests.
	for (int i=0; i < attributesNumber; i++)
	{
		// Init all values to worst case.
		localDataCopy.subDevicesStates[i] = Tango::UNKNOWN;
		localDataCopy.collectedData[i] = NAN;

		attributeToRead.clear();
		attributeToRead.push_back("State");
		attributeToRead.push_back(attributeName[i]);

		try
		{
			// Seen with manu taurel, id is a signed long incremented from 0 to...
			// It will take lot of time reading each second an attribute to overflow the value.
			readReplyIds[i] = -1;
			readReplyIds[i] = deviceProxies[i]->read_attributes_asynch(attributeToRead);
		}
		catch(DevFailed &e)
		{
			dataCollectionOk = false;
			dataCollectionFailedReason = dataCollectionFailedReason + "read_attributes_asynch() failed for '" + deviceName[i] + "': " + string(e.errors[0].reason) + ", " + string(e.errors[0].desc) + ", " + string(e.errors[0].origin) + "\n";
		}
	}

	struct timespec delay;
	delay.tv_sec = 0;     // Number of seconds.
	delay.tv_nsec = deviceTimeOut * 1000000; // Number of ms.
	int r = nanosleep(&delay, NULL);

	// Now harvest the results.
	vector<DeviceAttribute> *da;

	for (int i=0; i < attributesNumber; i++)
	{
		double v;

		try
		{
			localDataCopy.collectedData[i] = NAN;	// Init to NAN to get NAN in case of exception.

			// Only extract data that asynch read didn't failed.
			if (readReplyIds[i] != -1)
			{
				da = NULL;
				da = deviceProxies[i]->read_attributes_reply(readReplyIds[i]);
				(*da)[0] >> localDataCopy.subDevicesStates[i];
				(*da)[1] >> v; // Cannot use da >> v because da is a pointer.
				localDataCopy.collectedData[i] = v;
				delete da;
			}
		}
		catch(AsynReplyNotArrived &e)
		{
			try
			{
				// Data are not arrived in time, just cancel request to avoid memory leak.
				deviceProxies[i]->cancel_asynch_request(readReplyIds[i]);
			}
			catch(AsynCall &e)
			{
				dataCollectionFailedReason = dataCollectionFailedReason + "EXCEPT AsynCall : cancel_asynch_request() failed for '" + deviceName[i] + "': " + string(e.errors[0].reason) + ", " + string(e.errors[0].desc) + ", " + string(e.errors[0].origin) + "\n";
			}

			delete da;
			dataCollectionOk = false;
			dataCollectionFailedReason = dataCollectionFailedReason + "read_attributes_reply() failed for '" + deviceName[i] + "': " + string(e.errors[0].reason) + ", " + string(e.errors[0].desc) + ", " + string(e.errors[0].origin) + " (tango request cancelled).\n";
		}
		catch(DevFailed &e)
		{
			delete da;
			dataCollectionOk = false;
			dataCollectionFailedReason = dataCollectionFailedReason + "EXCEPT DevFailed :read_attributes_reply() failed for '" + deviceName[i] + "': " + string(e.errors[0].reason) + ", " + string(e.errors[0].desc) + ", " + string(e.errors[0].origin) + "\n";
		}
	}
}



/**
 *      method: AcquisitionThread::computeData()
 *
 *      description:    This method performs computations on data (if any).
 *
 *  Note : ORDER IS IMPORTANT HERE.
 */
void AcquisitionThread::computeData()
{
	localDataCopy.sum  = NAN;
	localDataCopy.mean = NAN;
	localDataCopy.rms  = NAN;
    localDataCopy.stdDeviation = NAN;

	// Now compute state / status.
	if (deviceProxyCreationOk == false)
	{
		localDataCopy.calculatedState  = Tango::FAULT;
		localDataCopy.calculatedStatus = deviceProxyFailedReason;
	}
	else
	{
		// Now compute global state based on Worst case.
		// Algorithm is given by JMC, see JIRA  http://jira.esrf.fr:8080/jira/browse/LOSUP-32
		bool fault = false;
		bool alarm = false;
		bool unknown = false;
		bool off = false;
		bool disable = false;

		for (unsigned int i=0; i < MAX_DEVICE_NUMBER; i++)
		{
			switch(localDataCopy.subDevicesStates[i])
			{
				case Tango::FAULT: fault = true; break;
				case Tango::ALARM: alarm = true; break;
				case Tango::UNKNOWN: unknown = true; break;
				case Tango::OFF: off = true; break;
				case Tango::DISABLE: disable = true; break;
			}
		}

		Tango::DevState finalState;
		if (fault == true) finalState = Tango::FAULT;
		else if (alarm == true) finalState = Tango::ALARM;
		else if (unknown == true) finalState = Tango::UNKNOWN;
		else if (off == true) finalState = Tango::OFF;
		else if (disable == true) finalState = Tango::DISABLE;
		else finalState = Tango::ON;

		localDataCopy.calculatedState  = finalState;

		if (finalState == Tango::ON)
		{
			localDataCopy.calculatedStatus = "Everything is working fine.";
		}
		else
		{
			localDataCopy.calculatedStatus = "At least on of the sub device is in ''";
			localDataCopy.calculatedStatus = localDataCopy.calculatedStatus + DevStateName[finalState];
			localDataCopy.calculatedStatus = localDataCopy.calculatedStatus + "'' state. Check subDevicesStates attribute.";

			// Append collection problem diagnostic in case of failure.
			if (dataCollectionOk != true)
			{
				localDataCopy.calculatedStatus = localDataCopy.calculatedStatus + "\nData collection errors :" + dataCollectionFailedReason;
			}
		}

		getAllStatistics(&localDataCopy.sum, &localDataCopy.mean, &localDataCopy.rms, &localDataCopy.stdDeviation);
	}
	//cout << "localDataCopy.calculatedState = " << DevStateName[localDataCopy.calculatedState] << endl;
}

/**
 *      method: AcquisitionThread::synchronizeDataWithMainThread()
 *
 *      description:    This method performs copy of data from Acquisition
 *      thread to main tango thread. This part of code needs to be mutex
 *      protected.
 *
 */
void AcquisitionThread::synchronizeDataWithMainThread()
{
	omni_mutex_lock lockIt(mutex);
	multiChannel->localDataCopy.sum = localDataCopy.sum;
	multiChannel->localDataCopy.mean = localDataCopy.mean;
	multiChannel->localDataCopy.rms = localDataCopy.rms;
	multiChannel->localDataCopy.dataCollectionDuration = localDataCopy.dataCollectionDuration;
	multiChannel->localDataCopy.stdDeviation = localDataCopy.stdDeviation;
	memcpy(multiChannel->localDataCopy.collectedData, localDataCopy.collectedData, sizeof(double) * attributesNumber);
	memcpy(multiChannel->localDataCopy.subDevicesStates, localDataCopy.subDevicesStates, sizeof(DevState) * attributesNumber);
	multiChannel->localDataCopy.calculatedState  = localDataCopy.calculatedState;
	multiChannel->localDataCopy.calculatedStatus = localDataCopy.calculatedStatus;
}


/**
 * Compute Mean on the AttributesNumber first elements of collectedData.
 */
double AcquisitionThread::getMean()
{
	double sum = getSum();
	return sum / (double) attributesNumber;
}

/**
 * Compute Mean on the AttributesNumber first elements of collectedData
 * on which sum has already been calculated, and is provided as method param.
 */
double AcquisitionThread::getMean(double sum)
{
	double nbr = 0;

	for (int i=0; i < attributesNumber; i++)
	{
		if (Tango_isnan(localDataCopy.collectedData[i]) == false)
		{
			nbr += 1;
		}
	}

	if (nbr != 0)
	{
		return sum / nbr;
	}
	return 0;
}

/**
 * Compute SUM on the AttributesNumber first elements of collectedData.
 * NaN are just ignored.
 */
double AcquisitionThread::getSum()
{
	double sum = 0.0;

	for (int i=0; i < attributesNumber; i++)
	{
		double val = localDataCopy.collectedData[i];

		if (Tango_isnan(val) == false)
		{
			sum += val;
		}
	}
	return sum;
}

/**
 * Compute RMS on the AttributesNumber first elements of collectedData.
 *
 * RMS = Quadratic mean:
 *      _______________________
 *     /  1
 * \  /  --- * Sigma X^2
 *  \/    N
 */
double AcquisitionThread::getRMS()
{
	double rms = 0;
	double nbr = 0;

	for (int i=0; i < attributesNumber; i++)
	{
		if (Tango_isnan(localDataCopy.collectedData[i]) == false)
		{
			rms += (localDataCopy.collectedData[i] * localDataCopy.collectedData[i]);
			nbr += 1;
		}
	}

	if (nbr > 0)
	{
		rms = rms / nbr;
		rms = sqrt(rms);
	}
	else
	{
		rms = NAN;
	}
	return rms;
}

/**
 * Compute standard deviation on the AttributesNumber first elements of
 * collectedData.
 *
 *  stdDev =
 *       ________________________
 *      /  1
 *  \  /  --- * Sigma(Xi - A)^2
 *   \/   N-1
 *
 */
double AcquisitionThread::getStandardDeviation(double the_mean)
{
	double  sd = 0;
	double  sigma = 0;
	double nbr = 0;

	for (int i=0; i < attributesNumber; i++)
	{
		double  Xi = localDataCopy.collectedData[i];
		if (Tango_isnan(Xi) == false)
		{
			sigma += (Xi - the_mean) * (Xi - the_mean);
			nbr += 1;
		}
	}

	if(nbr > 1)
	{
		sd = sqrt((1.0 / (double)(nbr - 1)) * sigma);
	}
	else
	{
		// Sample number < 2 so N-1 will result in div by zero.
		// Standard deviation of one sample is obviously zero.
		sd = 0.0;
	}

	return sd;
}

/**
 * Returns the sum, mean, rms and std deviation on the AttributesNumber first
 * elements of collectedData.
 */
void AcquisitionThread::getAllStatistics(double *sum, double *mean, double *rms, double *stddev)
{
	// Init results to NAN.
	*sum	= NAN;
	*mean   = NAN;
	*rms    = NAN;
	*stddev = NAN;

	*sum = getSum();

	if (Tango_isnan(*sum)) return;

	*mean   = getMean(*sum);
	*rms    = getRMS();
	*stddev = getStandardDeviation(*mean);
}

} // namespace
