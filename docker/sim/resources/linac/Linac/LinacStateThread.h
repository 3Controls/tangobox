//static const char *RcsId = "$Header: /segfs/tango/cvsroot/cppserver/machine/linac/linac/LinacStateThread.h,v 1.7 2009/08/14 07:15:17 vedder Exp $";
//=============================================================================
//
// file :         LinacSeqThread.h
//
// description :  Include for the LinacStateThread class.
//                		
// project :      TANGO Device Server
//
// $Author: vedder $
//
// $Log: LinacStateThread.h,v $
// Revision 1.7  2009/08/14 07:15:17  vedder
// Added : 3 devices proxy to handle new TDKLambda power supplies.
// 	-gun_focus_b1b4_tdk
// 	-gun_steerer_tdk
// 	-prebuncher_steerer_tdk
//
// Added : 3 state for global state computation:
// 	-gun_focus_b1b4_tdk_state
// 	-gun_steerer_tdk_state
// 	-prebuncher_steerer_tdk_state
//
// Bug fix : focus_beam1 was over-written with focus_beam 2 !
//
// Revision 1.6  2006/10/25 13:30:10  bourtemb
// Add get_device_state_no_alarm() method to get the state of a device.
// If the device is in ALARM state, the variable n_alarm will not be incremented.
// Thus the alarm state of this device is not taken into account for the
// calculation of the linac global state.
// The Bruker alarms are not not taken into account for the calculation of
// the linac global state.
//
// Revision 1.5  2006/10/20 08:38:37  bourtemb
// the sequencer state is now retrieved in the thread which get all the states
//
// Revision 1.4  2006/09/27 13:32:05  bourtemb
// add cvs log in the header file
//
//
// copyleft :     European Synchrotron Radiation Facility
//                BP 220, Grenoble 38043
//                FRANCE
//
//=============================================================================

#ifndef _LINACSTATETHREAD_H
#define _LINACSTATETHREAD_H

#include <tango.h>
#include <Linac.h>


namespace Linac_ns
{
	class LinacStateThread : public omni_thread, public Tango::LogAdapter
		{
		public :
			LinacStateThread (Linac *obj, omni_mutex &m);

		private :
			
			Linac 						*linacds;
			omni_mutex 					&mutex;
			
			Tango::DeviceProxy 		*gun_aux;
			string gun_aux_name;
			Tango::DevState gun_aux_state;
			Tango::DeviceProxy 		*gun;
			string gun_name;
			Tango::DevState gun_state;
			Tango::DeviceProxy 		*gun_HV;
			string gun_HV_name;
			Tango::DevState gun_HV_state;
			Tango::DeviceProxy 		*rf_run;
			string rf_run_name;
			Tango::DevState rf_run_state;
			Tango::DeviceProxy 		*cooling;
			string cooling_name;
			Tango::DevState cooling_state;
			Tango::DeviceProxy 		*mod1_aux;
			string mod1_aux_name;
			Tango::DevState mod1_aux_state;
			Tango::DeviceProxy 		*mod2_aux;
			string mod2_aux_name;
			Tango::DevState mod2_aux_state;
			Tango::DeviceProxy 		*mod1_HV;
			string mod1_HV_name;
			Tango::DevState mod1_HV_state;
			Tango::DeviceProxy 		*mod2_HV;
			string mod2_HV_name;
			Tango::DevState mod2_HV_state;
			Tango::DeviceProxy 		*mod1;
			string mod1_name;
			Tango::DevState mod1_state;
			Tango::DeviceProxy 		*mod2;
			string mod2_name;
			Tango::DevState mod2_state;
			Tango::DeviceProxy		*focus_klystron1;
			string focus_klystron1_name;
			Tango::DevState focus_klystron1_state;
			Tango::DeviceProxy		*focus_klystron2;
			string focus_klystron2_name;
			Tango::DevState focus_klystron2_state;
			Tango::DeviceProxy		*focus_beam1;
			string focus_beam1_name;
			Tango::DevState focus_beam1_state;
			Tango::DeviceProxy		*focus_beam2;
			string focus_beam2_name;
			Tango::DevState focus_beam2_state;
			Tango::DeviceProxy		*focus_steer;
			string focus_steer_name;
			Tango::DevState steerers_state;
			Tango::DeviceProxy 		*daresburyds;
			string daresbury_name;
			Tango::DeviceProxy		*sequencer;
			string sequencer_name;
			Tango::DevState sequencer_state;

			// New Linac Gun addition:
			Tango::DeviceProxy		*gun_focus_b1b4_tdk;
			string gun_focus_b1b4_tdk_name;
			Tango::DevState gun_focus_b1b4_tdk_state;

			Tango::DeviceProxy		*gun_steerer_tdk;
			string gun_steerer_tdk_name;
			Tango::DevState gun_steerer_tdk_state;

			Tango::DeviceProxy		*prebuncher_steerer_tdk;
			string prebuncher_steerer_tdk_name;
			Tango::DevState prebuncher_steerer_tdk_state;
			
// 			MyCallBack cb_gun_aux,cb_gun_hv,cb_gun;
// 			MyCallBack cb_rf;
// 			MyCallBack cb_cooling;
// 			MyCallBack cb_mod1_aux,cb_mod2_aux;
// 			MyCallBack cb_mod1_hv,cb_mod2_hv;
// 			MyCallBack cb_mod1,cb_mod2;
// 			MyCallBack cb_focus_klystron,cb_focus_beam1,cb_focus_beam2,cb_steerers;	
			
			double n_alarm;
			double n_fault;
			double n_unknown;
			string alarm_devices;
			string unknown_devices;
			string fault_devices;
			vector <Tango::DevDouble> pss_interlocks_list;
			vector <Tango::DevLong>	pss_interlocks;
			vector<unsigned char> pss_itlk_states;
			
			void clean_exit();
			void *run_undetached(void *arg);
			void check_quit();
			void update_variables_for_state(Tango::DevState);
			void get_all_state();
			void refresh_state();
			Tango::DevState get_device_state(Tango::DeviceProxy * ,const char*, string );
			Tango::DevState get_device_state_no_alarm(Tango::DeviceProxy * ,const char*, string );
};



}	//	namespace Linac

#endif // _LINACSTATETHREAD_H
