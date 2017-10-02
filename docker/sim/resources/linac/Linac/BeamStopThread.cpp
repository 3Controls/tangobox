static const char *RcsId = "$Header: /segfs/tango/cvsroot/cppserver/machine/linac/linac/BeamStopThread.cpp,v 1.4 2007/06/14 11:23:38 bourtemb Exp $";
//+=============================================================================
//
// file :        BeamStopThread.cpp
//
// description : C++ source for the BeamStopThread. 
//
// project :     TANGO Device Server
//
// $Author: bourtemb $
//
// $Log: BeamStopThread.cpp,v $
// Revision 1.4  2007/06/14 11:23:38  bourtemb
// There is now an ICT clone device, the beamstop is now able to check
// if the ICT clone device has changed.
// When there is a problem with the beamstop, the Linac device will now
// be warned and will change its state to FAULT and indicate in its status
// a description of the problem encountered.
//
// Revision 1.3  2006/11/16 15:44:15  bourtemb
// Correct a bug which was leading to do a lot of new DeviceProxy() when the pct device is changed
//
// Revision 1.2  2006/09/27 13:33:02  bourtemb
// add cvs log in the header file
//
//
// copyleft :   European Synchrotron Radiation Facility
//              BP 220, Grenoble 38043
//              FRANCE
//
//-=============================================================================


#include <BeamStopThread.h>

namespace Linac_ns
{

BeamStopThread::BeamStopThread (Linac *obj, omni_mutex &m, omni_mutex &m2) : 
			omni_thread(),beamstop_mutex(m),statethread_mutex(m2),Tango::LogAdapter((Tango::DeviceImpl *)obj)
{
	DEBUG_STREAM << ">>>> BeamStopThread::BeamStopThread(): entering ....!" << endl;
	linacds = obj;
	DEBUG_STREAM << ">>>> retrieve CT devices names" << endl;
	{
		omni_mutex_lock l(beamstop_mutex);
		pct_name = linacds->pCT_device;
		ict_name = linacds->iCT_device;
	}
	{
		omni_mutex_lock l(statethread_mutex);
		gun_name = linacds->gun_name;
	}
	DEBUG_STREAM << ">>>> BeamStopThread: initialize Device Proxy Objects" << endl;
	try
	{
		PCTds = new Tango::DeviceProxy(pct_name.c_str());
		PCTds->set_source(Tango::DEV);
	}
	catch (Tango::DevFailed &e)
	{
		PCTds = NULL;
		ERROR_STREAM << ">>>> BeamStopThread: An exception occured!" << endl;
		Tango::Except::print_exception(e);
		string tmp_status;
		tmp_status = "******* Initialization failed with errors!\n";
			
		for (unsigned int i = 0; i<e.errors.length(); i++)
		{
			tmp_status = tmp_status + "**** ERROR **** " + e.errors[i].desc.in() + "\n";
		}
		tmp_status = tmp_status + "Ensure the PCT device is well defined in the database\n";
		tmp_status = tmp_status + " and execute the INIT function of the Linac server or restart it\n";
		ERROR_STREAM << tmp_status << endl;
		// Warn the Linac server that a problem occured
		{
			omni_mutex_lock l(beamstop_mutex);
			linacds->BeamStopProblem = true;
			linacds->BeamStopStatus = "BeamStop problem: Check that the PCT device \"";
			linacds->BeamStopStatus += pct_name;
			linacds->BeamStopStatus += "\" is well defined in the database(or that there is no problem with the database)\n";
		}
	}
	try
	{
		ICTds = new Tango::DeviceProxy(ict_name.c_str());
		ICTds->set_source(Tango::DEV);
	}
	catch (Tango::DevFailed &e)
	{
		ICTds = NULL;
		ERROR_STREAM << ">>>> BeamStopThread: An exception occured!" << endl;
		Tango::Except::print_exception(e);
		string tmp_status;
		tmp_status = "******* Initialization failed with errors!\n";
			
		for (unsigned int i = 0; i<e.errors.length(); i++)
		{
			tmp_status = tmp_status + "**** ERROR **** " + e.errors[i].desc.in() + "\n";
		}
		tmp_status = tmp_status + "Ensure the ICT device is well defined in the database\n";
		tmp_status = tmp_status + " and execute the INIT function of the Linac server or restart it\n";
		ERROR_STREAM << tmp_status << endl;
		// Warn the Linac server that a problem occured
		{
			omni_mutex_lock l(beamstop_mutex);
			linacds->BeamStopProblem = true;
			linacds->BeamStopStatus = "BeamStop problem: Check that the PCT device \"";
			linacds->BeamStopStatus += ict_name;
			linacds->BeamStopStatus += "\" is well defined in the database(or that there is no problem with the database)\n";
		}
	}
	
	try
	{
		gunds = new Tango::DeviceProxy(gun_name.c_str());
	}
	catch(Tango::DevFailed &e)
	{
		ERROR_STREAM << ">>>> BeamStopThread: An exception occured!" << endl;
		Tango::Except::print_exception(e);
		string tmp_status;
		tmp_status = "******* BeamStopThread initialization failed with errors!\n";
			
		for (unsigned int i = 0; i<e.errors.length(); i++)
		{
			tmp_status = tmp_status + "**** ERROR **** " + e.errors[i].desc.in() + "\n";
		}
		tmp_status = tmp_status + "Ensure the gun device is well defined in the database\n";
		tmp_status = tmp_status + " and execute the INIT function of the Linac server or restart it\n";
		ERROR_STREAM << tmp_status << endl;
		// Warn the Linac server that a problem occured
		{
			omni_mutex_lock l(beamstop_mutex);
			linacds->BeamStopProblem = true;
			linacds->BeamStopStatus = "BeamStop problem: Check that the Gun device \"";
			linacds->BeamStopStatus += gun_name;
			linacds->BeamStopStatus += "\" is well defined in the database (or that there is no problem with the database) and restart the Linac/linac server\n";
		}
		DEBUG_STREAM << ">>>> BeamStop Thread DEATH ..." << endl;
		gunds = NULL;
		clean_exit();
	}
	
	SR_Current = 0.0;
	SRCT_Limit = 1.0;
	GunState = Tango::UNKNOWN;
	start_undetached();
}

// method : BeamStopThread::clean_exit()
// This method is called when the thread must be killed
// It will free all the necessary resources
// and commit suicide
void BeamStopThread::clean_exit()
{
	DEBUG_STREAM << ">>>> The BeamStop thread must be killed! Exiting ..." << endl;
	// Free resources
	if(PCTds != NULL)
		delete PCTds;
	if(ICTds != NULL)
		delete ICTds;
	delete gunds;
	DEBUG_STREAM << ">>>> BeamStop Thread DEATH ..." << endl;
	exit();
}


//
// BeamStopThread::run_undetached 
//
void *BeamStopThread::run_undetached (void *arg)
{
	DEBUG_STREAM << ">>>> BeamStopThread starting up!" << endl;
		
	while(true)
	{
		check_quit();
		check_ct_device();
		check_gun_state();
		
		if((GunState == Tango::ON) || (GunState == Tango::UNKNOWN) || (GunState == Tango::ALARM))
		{			
			bool pctselected;
			{
				omni_mutex_lock l(beamstop_mutex);
				pctselected = linacds->pctselectedshared;
			}
			if(pctselected)
			{
				if(PCTds == NULL)
				{
					// Warn the Linac about the problem
					{
						omni_mutex_lock l(beamstop_mutex);
						linacds->BeamStopProblem = true;
						linacds->BeamStopStatus = "BeamStop Problem: Cannot import the PCT device\n";
						linacds->BeamStopStatus = "sr/d-ct/1/CurrentDeviceName property is well defined ?\n";
					}
				}
				else
				{
					try
					{
						Tango::DeviceAttribute current_val = PCTds->read_attribute("Current");
						current_val >> SR_Current;
						{
							omni_mutex_lock l(beamstop_mutex);
							linacds->BeamStopProblem = false;
						}
					}
					catch(Tango::DevFailed &e)
					{
						Tango::Except::print_exception(e);
						// Warn the Linac about the problem
						{
							omni_mutex_lock l(beamstop_mutex);
							linacds->BeamStopProblem = true;
							linacds->BeamStopStatus = "BeamStop Problem: Cannot read the current on the PCT device ";
							linacds->BeamStopStatus += pct_name;
							linacds->BeamStopStatus += "\n";
						}
						usleep(250000); // sleep 250 ms;
						continue;
					}
					//cout << "SR Current (" << PCTds->name() << ") = " << SR_Current << endl;
				}
			}
			else
			{
				if(ICTds == NULL)
				{
					// Warn the Linac about the problem
					{
						omni_mutex_lock l(beamstop_mutex);
						linacds->BeamStopProblem = true;
						linacds->BeamStopStatus = "BeamStop Problem: Cannot import the ICT device\n";
						linacds->BeamStopStatus = "sr/d-ct/2/CurrentDeviceName property is well defined ?\n";
					}
				}
				else
				{
					try
					{
						Tango::DeviceAttribute current_val = ICTds->read_attribute("Current");
						current_val >> SR_Current;
						{
							omni_mutex_lock l(beamstop_mutex);
							linacds->BeamStopProblem = false;
						}
					}
					catch(Tango::DevFailed &e)
					{
						Tango::Except::print_exception(e);
						// Warn the Linac about the problem
						{
							omni_mutex_lock l(beamstop_mutex);
							linacds->BeamStopProblem = true;
							linacds->BeamStopStatus = "BeamStop Problem: Cannot read the current on the ICT device ";
							linacds->BeamStopStatus += ict_name;
							linacds->BeamStopStatus += "\n";
						}
						usleep(250000); // sleep 250 ms;
						continue;
					}
					//cout << "SR Current (" << ICTds->name() << ") = " << SR_Current << endl;
				}
			}
			{
				omni_mutex_lock l(beamstop_mutex);
				SRCT_Limit = *(linacds->attr_SRCT_Limit_read);			
			}
			if(SR_Current >= SRCT_Limit)
			{
				try
				{
					gunds->command_inout("Off");
					cout << ">>>> BeamStop Thread: STOP the gun !" << endl;
					cout << "SR_Current = " << SR_Current << endl;
					cout << "SRCT_Limit = " << SRCT_Limit << endl;
				}
				catch(Tango::DevFailed &e)
				{
					cerr << "ERROR STOPPING THE GUN" << endl;
					Tango::Except::print_exception(e);
				}
			}
		}
		else
		{
			omni_mutex_lock l(beamstop_mutex);
			linacds->BeamStopProblem = false;
		}
		usleep(250000); // sleep 250 ms;
	}
}

void BeamStopThread::check_quit()
{
	{
		omni_mutex_lock * l = new omni_mutex_lock(beamstop_mutex);
		if(linacds->killbeamstopthread == true)
		{
			delete l;
			clean_exit();
		}
		delete l;
	}
}

void BeamStopThread::check_ct_device()
{
	bool pct_changed = false;
	bool ict_changed = false;
	{
		omni_mutex_lock l(beamstop_mutex);
		pct_changed = linacds->pct_has_changed;
		ict_changed = linacds->ict_has_changed;
	}
	if(pct_changed)
	{
		string old_pct_name = pct_name;
		{
			omni_mutex_lock l(beamstop_mutex);
			pct_name = linacds->pCT_device;
		}
		try
		{
			if(PCTds != NULL)
				delete PCTds;
			PCTds = new Tango::DeviceProxy(pct_name);
			PCTds->set_source(Tango::DEV);
			{
				omni_mutex_lock l(beamstop_mutex);
				linacds->pct_has_changed = false;
			}
			return;
		}
		catch(Tango::DevFailed &e)
		{
			Tango::Except::print_exception(e);
			try
			{
				// try to restore the old PCT_device
				PCTds = new Tango::DeviceProxy(old_pct_name.c_str());
				PCTds->set_source(Tango::DEV);
				{
					omni_mutex_lock l(beamstop_mutex);
					linacds->pct_has_changed = false;
				}
				return;
			}
			catch(Tango::DevFailed &e)
			{
				Tango::Except::print_exception(e);
				PCTds = NULL;
			}
		}
	}
	if(ict_changed)
	{
		string old_ict_name = ict_name;
		{
			omni_mutex_lock l(beamstop_mutex);
			ict_name = linacds->iCT_device;
		}
		try
		{
			if(ICTds != NULL)
				delete ICTds;
			ICTds = new Tango::DeviceProxy(ict_name);
			ICTds->set_source(Tango::DEV);
			{
				omni_mutex_lock l(beamstop_mutex);
				linacds->ict_has_changed = false;
			}
			return;
		}
		catch(Tango::DevFailed &e)
		{
			Tango::Except::print_exception(e);
			try
			{
				// try to restore the old ICT_device
				ICTds = new Tango::DeviceProxy(old_ict_name.c_str());
				ICTds->set_source(Tango::DEV);
				{
					omni_mutex_lock l(beamstop_mutex);
					linacds->ict_has_changed = false;
				}
				return;
			}
			catch(Tango::DevFailed &e)
			{
				Tango::Except::print_exception(e);
				ICTds = NULL;
			}
		}
	}
}

void BeamStopThread::check_gun_state()
{
	try
	{
		GunState = gunds->state();
	}
	catch(Tango::DevFailed &e)
	{
		Tango::Except::print_exception(e);
		GunState = Tango::UNKNOWN;
		// todo : Warn the linac that a problem occured
	}
}

} // namespace
