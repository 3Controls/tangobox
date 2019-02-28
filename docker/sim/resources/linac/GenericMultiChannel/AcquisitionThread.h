//=============================================================================
//
// file :         AcquisitionThread.h
//
// description :  Thread that handle State and Value data collection.
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

#ifndef ACQUISITION_THREAD_H
#define ACQUISITION_THREAD_H

#include <tango.h>
#include <GenericMultiChannel.h>
#include <time.h>
#include <math.h>
#include <vector>
#include "SharedData.h"
#include "Chronometer.h"

namespace GenericMultiChannel_ns
{
    
    class GenericMultiChannel;

class AcquisitionThread : public omni_thread
{
	public :

		AcquisitionThread(GenericMultiChannel *device, omni_mutex &m);
		void quit() { 
                    omni_mutex_lock lockIt(mutex);
                    abort = true;
                }

	protected:

		void *run_undetached (void *arg);

	private :

		bool deviceProxyCreationOk;
		string deviceProxyFailedReason;
		bool dataCollectionOk;
		string dataCollectionFailedReason;
		Chronometer chrono;
		DevLong pollingPeriod;
		DevLong deviceTimeOut;
		GenericMultiChannel *multiChannel;
		omni_mutex 			&mutex;
		bool abort;
		int attributesNumber;
		void collectData();
		void computeData();
		void synchronizeDataWithMainThread();
		SharedData localDataCopy;
		DeviceProxy **deviceProxies;
		long *readReplyIds;

		// Basic calculation methods.
		double getMean();
		double getMean(double sum);
		double getSum();
		double getStandardDeviation(double the_mean);
		double getRMS();
		void getAllStatistics(double *sum, double *mean, double *rms, double *stddev);

		vector<string>attributeName;
		vector<string>deviceName;

};

}// namespace
#endif	// ACQUISITION_THREAD_H


