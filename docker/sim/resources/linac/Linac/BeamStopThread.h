//static const char *RcsId = "$Header:";
//=============================================================================
//
// file :         BeamStopThread.h
//
// description :  Include for the BeamStopThread class.
//                		
// project :      TANGO Device Server
//
// $Author: bourtemb $
//
// $Log: BeamStopThread.h,v $
// Revision 1.3  2007/06/14 11:23:38  bourtemb
// There is now an ICT clone device, the beamstop is now able to check
// if the ICT clone device has changed.
// When there is a problem with the beamstop, the Linac device will now
// be warned and will change its state to FAULT and indicate in its status
// a description of the problem encountered.
//
// Revision 1.2  2006/09/27 13:33:02  bourtemb
// add cvs log in the header file
//
//
// copyleft :     European Synchrotron Radiation Facility
//                BP 220, Grenoble 38043
//                FRANCE
//
//=============================================================================

#ifndef _BEAMSTOPTHREAD_H
#define _BEAMSTOPTHREAD_H

#include <tango.h>
#include <Linac.h>


namespace Linac_ns
{
class BeamStopThread : public omni_thread, public Tango::LogAdapter
{
	public :
		BeamStopThread (Linac *obj, omni_mutex &m,omni_mutex &m2 );

	private :
		Linac 		*linacds;
		omni_mutex 	&beamstop_mutex;
		omni_mutex	&statethread_mutex;
		Tango::DeviceProxy * PCTds;
		Tango::DeviceProxy * ICTds;
		Tango::DeviceProxy * gunds;
		Tango::DevDouble	SR_Current;
		Tango::DevDouble	SRCT_Limit;
		Tango::DevState GunState;
		string pct_name;
		string ict_name;
		string gun_name;
		
		void clean_exit();
		void *run_undetached(void *arg);
		void check_quit();
		void check_ct_device();
		void check_gun_state();
			
};



}	//	namespace Linac

#endif // _BEAMSTOPTHREAD_H
