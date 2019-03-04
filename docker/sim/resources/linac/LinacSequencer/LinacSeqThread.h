//static const char *RcsId = "$Header:";
//=============================================================================
//
// file :         LinacSeqThread.h
//
// description :  Include for the LinacSeqThread class.
//                		
// project :      TANGO Device Server
//
// $Author: vedder $
//
// $Revision: 1.23 $
//
// $Log: LinacSeqThread.h,v $
// Revision 1.23  2010/06/17 11:31:03  vedder
// This version does not handle elin/focus/spare device anymore. The spare was a source of passing FAULT in the synoptic. This version also correct the end sequence message who was erroneously commented out.
//
// Revision 1.8  2009/08/14 07:21:10  vedder
// Regenerate with pogo to inherite from device_impl4.
//
// Modified:  default: case in dev_status() to prevent compiler warning.
// Added :  an empty default: case in macro_LOWHEATING() to prevent compiler warning
// 	it's been done in several place in the method.
// Corrected : many signed/unsigned comparison to prevent compiler warning.
// Corrected : a badly formed printf sequence in macro_LOAD_SETTINGS().
//
// Added : 19 new device properties for all device name for all linac devices:
//
// 	-gun_aux_name
// 	-gun_name
// 	-gun_HV_name
// 	-rf_run_name
// 	-cooling_name
// 	-mod1_aux_name
// 	-mod2_aux_name
// 	-mod1_HV_name
// 	-mod2_HV_name
// 	-mod1_name
// 	-mod2_name
// 	-focus_klystron1_name
// 	-focus_klystron2_name
// 	-focus_beam1_name
// 	-focus_beam2_name
// 	-focus_steer_name
// 	-gun_focus_b1b4_tdk
// 	-gun_steerer_tdk
// 	-prebuncher_steerer_tdk
// 	-gun_gunaux_tdk
//
// We could have use Class properties but i choose Device properties to allow me
// to run different instances (tests) of LinacSequencer with differents properties.
//
// Modified:  LinacFileReader.y to handle new devices:
// 		-elin/focus/b3coil
// 		-elin/focus/b4coil
// 		-elin/focus/gh2
// 		-elin/focus/gv2
// 		-elin/focus/gh3
// 		-elin/focus/gv3
// 		-elin/focus/gh4
// 		-elin/focus/gv4
// 		-elin/gun/heating-tdk
// 		-elin/gun/grid-tdk
// 		-elin/gun/pulse-tdk
//
// Modified : Rename the method set_focus to set_dev_double_array because it was not only
// used for the focus elements. It's now also used for the Current/Voltage of
// new power supplies and we benefit from the error handling done before.
//
// Modified : Rename the method read_set_focus to read_set_points because it was not
// only used for focusing power supply. Rename the attr_name parameter (which
// was not used) to "const char *command" in order to specify the command to
// use to get the set_points. It will allow us to get gun heating, grid and pulse
// voltage with the same method sending "GetVoltageSetPoints".
//
// Modified : Factorised SAVE / FORCE_SAVE redondant code by adding the WarnInPlaceOfExcept
// parameters. This leads to a a reduction of 544 lines of code.
//
// Modified : Adapt macro LOAD_SETTING in order to handle new linac gun.
// Modified : Adapt macro SAVE_SETTING in order to handle new linac gun.
// Modified : Adapt macro FORCE_SAVE_SETTING in order to handle new linac gun.
// Modified : Adapt ON macro to new linac gun. Remove In352Mhz off from this macro.
// Modified : Adapt OFF macro to new linac gun. Remove In352Mhz off from this macro.
// Modified : Adapt STDBY macro to new linac gun. Remove In352Mhz off from this macro.
// Modified : Adapt LOWHEATING macro to new linac gun. Remove In352Mhz off from this macro.
//
// Revision 1.7  2007/06/04 15:20:42  bourtemb
// Add the possibility to set the timeout globally (one timeout for all the devices)
// Add Timeout property and remove focus_klystron1_timeout and
// focus_klystron2_timeout properties.
// Some states (ALARM, UNKNOWN) were not correctly handled in the previous versions.
//
// Revision 1.6  2006/10/24 12:39:01  bourtemb
// Add focus_klystron1_timeout and focus_klystron2_timeout device properties
//
// Revision 1.5  2006/09/19 13:01:45  bourtemb
// elin/focus/klystron has been split into elin/focus/klystron1 and elin/focus/klystron2.
// This version forces the 3 last channels of elin/focus/klystron1 to 0.
// This version is a temporary version used while elin/focus/klystron1 is the control
// of the Bruker Power supply of the modulator 1 and elin/focus/klystron2 is the
// control of the new Danfysik system9000 for the modulator 2 klystron focussing.
//
// Revision 1.4  2006/09/18 07:19:11  bourtemb
// remove unused set_focus_on() function
//
// Revision 1.3  2005/11/24 09:47:56  bourtemb
// improve SIMU version
//
// Revision 1.2  2005/08/30 07:29:12  bourtemb
// Change definition of read_string_set_point function.
// add defaultVal variable.
//
// Revision 1.1.1.1  2005/08/18 14:26:53  bourtemb
// Imported using TkCVS
//
// Revision 1.8  2005/05/25 14:35:40  bourtemb
// The sequences don't stop in case of errors and report the number of errors occured
// at the end of each sequence.
//
// Revision 1.7  2005/05/18 11:10:56  bourtemb
// add ForceSave command and CT_Current attribute
//
// Revision 1.6  2005/04/19 12:45:21  bourtemb
// add cvs log in comments
//
//
// copyleft :     European Synchrotron Radiation Facility
//                BP 220, Grenoble 38043
//                FRANCE
//
//=============================================================================

#ifndef _LINACSEQTHREAD_H
#define _LINACSEQTHREAD_H

#include <tango.h>
#include <LinacSequencer.h>

#ifdef WIN32
#define strcasecmp(s1,s2) stricmp((s1), (s2))
#define usleep(t) Sleep((t)/1000)
#define sleep(t) Sleep((t)*1000)
#endif


namespace LinacSequencer_ns
{
	class LinacSeqThread : public omni_thread, public Tango::LogAdapter
		{
		public :
			LinacSeqThread (LinacSequencer *obj, omni_mutex &m);

		private :
			
			LinacSequencer 			*seq_obj;
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
			Tango::DeviceProxy		*focus_klystron2;
			string focus_klystron2_name;
			Tango::DeviceProxy		*focus_beam1;
			string focus_beam1_name;
			Tango::DeviceProxy		*focus_beam2;
			string focus_beam2_name;
			Tango::DeviceProxy		*focus_steer;
			string focus_steer_name;

			//
			// New Linac Gun devices proxies.
			//
			//Tango::DeviceProxy		*gun_gunaux_tdk;
			//string gun_gunaux_tdk_name;

			Tango::DeviceProxy		*gun_focus_b1b4_tdk;
			string gun_focus_b1b4_tdk_name;

			Tango::DeviceProxy		*gun_steerer_tdk;
			string gun_steerer_tdk_name;			

			Tango::DeviceProxy		*prebuncher_steerer_tdk;
			string prebuncher_steerer_tdk_name;			
			// End of new Gun device proxies.


			Tango::DevLong			timeout;
			
			FILE * configfile;
#ifndef SIMU			
			Values defaultVal;
#endif
			
			void clean_exit();
			void *run_undetached(void *arg);
			void write_history (string msg);
			/* macros */
			void macro_ON();
			void macro_OFF();
			void macro_STANDBY();
			void macro_LOWHEATING();
			void macro_LOAD_SETTINGS();
			void macro_SAVE_SETTINGS(string filename, bool warnInPlaceOfExcept = false);
			
			Tango::DevState get_state(Tango::DeviceProxy * device,const char* device_name);
			
			void check_abort();
			bool set_double_array_attribute_values(Tango::DeviceProxy *dev, const char *attr, vector <Tango::DevDouble> &values);
			bool set_double_value(Tango::DeviceProxy *,const char *,Tango::DevDouble,bool);
			bool set_string_value(Tango::DeviceProxy *,const char *,string,bool);
			bool set_bool_value(Tango::DeviceProxy *,const char *,bool,bool);
			bool set_dev_double_array(Tango::DeviceProxy *,const char *,vector<Tango::DevDouble>,bool);
			bool read_set_points(Tango::DeviceProxy *,const char *,Tango::DevVarDoubleArray *,bool);
			bool read_double_set_point(Tango::DeviceProxy *,const char *,Tango::DevDouble *,bool);
			bool read_string_set_point(Tango::DeviceProxy *,const char *,Tango::DevString *,bool);
			bool read_bool_set_point(Tango::DeviceProxy *,const char *,bool *,bool);
			bool send_cmd(Tango::DeviceProxy *,const char *,bool);
			void exceptionWritingFile(const char *);
			void WarnErrorReadingSetPoint(string);
			void set_timeout(Tango::DeviceProxy *,string,Tango::DevLong);
};



}	//	namespace Linac

#endif // _LINACSEQTHREAD_H
