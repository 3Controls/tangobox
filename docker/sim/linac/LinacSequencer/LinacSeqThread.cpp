static const char *RcsId = "$Header: /segfs/tango/cvsroot/cppserver/machine/linac/LinacSequencer/LinacSeqThread.cpp,v 1.23 2010/06/17 11:31:03 vedder Exp $";
//+=============================================================================
//
// file :        LinacSeqThread.cpp
//
// description : C++ source for the LinacSeqThread.
//
// project :     TANGO Device Server
//
// $Author: vedder $
//
// $Revision: 1.23 $
//
// $Log: LinacSeqThread.cpp,v $
// Revision 1.23  2010/06/17 11:31:03  vedder
// This version does not handle elin/focus/spare device anymore. The spare was a source of passing FAULT in the synoptic. This version also correct the end sequence message who was erroneously commented out.
//
// Revision 1.22  2009/08/14 07:21:10  vedder
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
// Revision 1.21  2007/08/21 09:29:23  bourtemb
// Changes in macro_LOWHEATING and macro_OFF
// Set the economy attribute of the modulator 2 before the modulator 1
//
// Revision 1.20  2007/06/04 15:20:42  bourtemb
// Add the possibility to set the timeout globally (one timeout for all the devices)
// Add Timeout property and remove focus_klystron1_timeout and
// focus_klystron2_timeout properties.
// Some states (ALARM, UNKNOWN) were not correctly handled in the previous versions.
//
// Revision 1.19  2007/04/05 11:47:27  bourtemb
// No longer execute TimingOn command in macro_ON().
// TimingOn was sending DevOn command on shorttiming devices.
// DevOn on these shorttiming devices is returning directly DS_OK.
// So, there is no need to execute this command.
//
// Revision 1.18  2007/01/18 09:08:17  bourtemb
// Correct a bug in macro_SAVE_SETTINGS() and macro_FORCE_SAVE() functions.
// This bug was linked to the installation of the new Danfysik 9000 power
// supplies for the klystron 1 focussing.
//
// Revision 1.17  2007/01/17 09:09:00  bourtemb
// Remove some code which was useful when the klystron 1 focusing current was
// given by a Bruker Power Supply.
//
// Revision 1.16  2006/10/24 12:39:01  bourtemb
// Add focus_klystron1_timeout and focus_klystron2_timeout device properties
//
// Revision 1.15  2006/10/20 08:43:10  bourtemb
// change some debug print
//
// Revision 1.14  2006/09/27 14:21:03  bourtemb
// The new klystron focussing device names are used when saving a file.
// Correct a little bug introduced in the previous version.
//
// Revision 1.13  2006/09/19 13:01:45  bourtemb
// elin/focus/klystron has been split into elin/focus/klystron1 and elin/focus/klystron2.
// This version forces the 3 last channels of elin/focus/klystron1 to 0.
// This version is a temporary version used while elin/focus/klystron1 is the control
// of the Bruker Power supply of the modulator 1 and elin/focus/klystron2 is the
// control of the new Danfysik system9000 for the modulator 2 klystron focussing.
//
// Revision 1.12  2006/09/18 07:19:11  bourtemb
// remove unused set_focus_on() function
//
// Revision 1.11  2006/08/24 14:23:18  bourtemb
// The command to open|close the economy relay is sent to the 2 modulators auxiliaries.
// (for the memorized attribute)
//
// Revision 1.10  2006/08/04 12:51:13  bourtemb
// configuation => configuration
//
// Revision 1.9  2006/08/01 11:33:24  bourtemb
// remove all reference to buncher attenuation
//
// Revision 1.8  2006/04/10 13:10:09  bourtemb
// clean clean_exit() function
//
// Revision 1.7  2005/11/24 09:53:51  bourtemb
// Reset the focussing and steering devices at end of Low Heating macro
//
// Revision 1.6  2005/11/24 09:47:56  bourtemb
// improve SIMU version
//
// Revision 1.5  2005/08/31 15:06:49  bourtemb
// Best default values management in load and save macros.
//
// Revision 1.4  2005/08/30 07:41:27  bourtemb
// Change read_set_focus function to make it use GetCurrentSetPoints command.
//
// Revision 1.3  2005/08/30 07:27:52  bourtemb
// Use LinacHVPS, LinacModulator and LinacModAux SoftOn and SoftOff commands
// in the sequences.
// Use a default variable to initialize set points.
// Use CORBA::string_xxx functions.
//
// Revision 1.2  2005/08/24 11:44:39  bourtemb
// set seq_obj->isFileLoaded to true at the end of macro_LOAD_SETTINGS,
// macro_SAVE_SETTINGS and macro_FORCE_SAVE.
// Add a mutex when getting the Linac devices names.
//
// Revision 1.1.1.1  2005/08/18 14:26:53  bourtemb
// Imported using TkCVS
//
// Revision 1.21  2005/08/04 08:26:46  bourtemb
// The modulators HV settings during sequence ON are no longer dependent on
// the last file loaded.
//
// Revision 1.20  2005/08/03 15:33:03  bourtemb
// Remove the set of Gun Heating voltage in Standby and Low Heating sequences.
// Change some displays in Save sequences.
//
// Revision 1.19  2005/06/09 14:32:05  bourtemb
// Switch off the beam at the begining of the Standby macro.
// Change the order of the actions.
//
// Revision 1.18  2005/06/08 06:55:44  bourtemb
// set_transparency_reconnection(true) after each new DeviceProxy
//
// Revision 1.17  2005/06/02 08:49:01  bourtemb
// load_file command allows errors now.
// If an error occured during the LOAD_SETTINGS macro,
// the file attribute become in ALARM quality factor.
//
// Revision 1.16  2005/06/01 09:49:53  bourtemb
// Changes in refresh_state() function.
// The state is UNKNOWN per default.
// If the gun or 1 modulator is in DISABLE state,
// the linac is considered to be in OFF state.
//
// Revision 1.15  2005/05/25 15:05:04  bourtemb
// Change some device names :
// elin/gun/run -> elin/beam/run
// elin/mod/aux-1(2) -> elin/mod1(2)/aux
// elin/mod/run-1(2) -> elin/mod1(2)/run
// elin/mod/hv-1(2)  -> elin/mod1(2)/hv
//
// Revision 1.14  2005/05/25 14:35:23  bourtemb
// Delete also the BrukerMch servers DeviceProxys on exit.
// The sequences don't stop in case of errors and report the number of errors occured
// at the end of each sequence.
// Change the error messages look.
//
// Revision 1.13  2005/05/18 11:10:56  bourtemb
// add ForceSave command and CT_Current attribute
//
// Revision 1.12  2005/05/09 08:23:39  bourtemb
// add many check_abort() in the sequences
//
// Revision 1.11  2005/04/27 14:19:12  bourtemb
// linac_obj->error = false; when a sequence begin
// Changes in refresh_state(). Correct a little bug.
//
// Revision 1.10  2005/04/20 12:23:30  bourtemb
// LinacSeqThread.cpp
//
// Revision 1.9  2005/04/19 14:12:43  bourtemb
// change permissions for the saved files, make the file readable for everybody
//
// Revision 1.8  2005/04/19 12:47:16  bourtemb
// add RcsId
//
// Revision 1.7  2005/04/19 12:46:00  bourtemb
// add cvs log in comments
//
//
//
// copyleft :   European Synchrotron Radiation Facility
//              BP 220, Grenoble 38043
//              FRANCE
//
//-=============================================================================


#include <LinacSeqThread.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#ifndef SIMU
extern Values * getValFromFile(const char *,Values);
#endif


namespace LinacSequencer_ns
{

LinacSeqThread::LinacSeqThread (LinacSequencer *obj, omni_mutex &m) :
			omni_thread(),mutex(m),Tango::LogAdapter((Tango::DeviceImpl *)obj)
{
	DEBUG_STREAM << ">>>> LinacSeqThread::LinacSeqThread(): entering ....!" << endl;
	seq_obj = obj;
	start_undetached();
}

// method : LinacSeqThread::clean_exit()
// This method is called when the thread must be killed
// It will free all the necessary resources
// and commit suicide
void LinacSeqThread::clean_exit()
{
	DEBUG_STREAM << ">>>> The thread must be killed! Exiting ..." << endl;
	// Free resources
	delete gun_aux;
	delete gun;
	delete gun_HV;
	delete rf_run;
	delete cooling;
	delete mod1_aux;
	delete mod2_aux;
	delete mod1_HV;
	delete mod2_HV;
	delete mod1;
	delete mod2;
	delete focus_klystron1;
	delete focus_klystron2;
	delete focus_beam1;
	delete focus_beam2;
	delete focus_steer;
	//delete gun_gunaux_tdk;
	delete gun_focus_b1b4_tdk;
	delete gun_steerer_tdk;
	delete prebuncher_steerer_tdk;

	DEBUG_STREAM << ">>>> Thread DEATH ..." << endl;
	exit();
}


//
// LinacSeqThread::run_undetached
//
void *LinacSeqThread::run_undetached (void *arg)
{
	DEBUG_STREAM << ">>>> LinacSeqThread starting up!" << endl;

#ifndef SIMU
	defaultVal.focus_klyst1[0]=0; 	/* values of the object ELIN/FOCUS/KLYSTRON1 */
	defaultVal.focus_klyst1[1]=0;
	defaultVal.focus_klyst1[2]=0;
	defaultVal.focus_klyst1[3]=0;
	defaultVal.focus_klyst1[4]=0;
	defaultVal.focus_klyst1[5]=0;
	defaultVal.focus_klyst2[0]=0; 	/* values of the object ELIN/FOCUS/KLYSTRON2 */
	defaultVal.focus_klyst2[1]=0;
	defaultVal.focus_klyst2[2]=0;
	defaultVal.focus_beam1[0]=0;	/* values of the object ELIN/FOCUS/BEAM1 */
	defaultVal.focus_beam1[1]=0;
	defaultVal.focus_beam1[2]=0;
	defaultVal.focus_beam1[3]=0;
	defaultVal.focus_beam1[4]=0;
	defaultVal.focus_beam1[5]=0;
	defaultVal.focus_beam1[6]=0;	/* Additional ZUPs  */
	defaultVal.focus_beam1[7]=0;
	defaultVal.focus_beam2[0]=0;	/* values of the object ELIN/FOCUS/BEAM2 */
	defaultVal.focus_beam2[1]=0;
	defaultVal.steer_beam[0]=0; 	/* Values of the object ELIN/STEER/1 */
	defaultVal.steer_beam[1]=0;
	defaultVal.steer_beam[2]=0;
	defaultVal.steer_beam[3]=0;
	defaultVal.steer_beam[4]=0;
	defaultVal.steer_beam[5]=0;
	defaultVal.steer_beam[6]=0;
	defaultVal.steer_beam[7]=0;
	defaultVal.steer_beam[8]=0;
	defaultVal.steer_beam[9]=0;
	defaultVal.steer_beam[10]=0;
	defaultVal.steer_beam[11]=0;
	defaultVal.steer_beam[12]=0;
	defaultVal.steer_beam[13]=0;
	defaultVal.steer_beam[14]=0;
	defaultVal.steer_beam[15]=0;
	defaultVal.steer_beam[16]=0; /* Additional ZUPs  */
	defaultVal.steer_beam[17]=0;
	defaultVal.steer_beam[18]=0;
	defaultVal.steer_beam[19]=0;
	defaultVal.steer_beam[20]=0;
	defaultVal.steer_beam[21]=0;

	defaultVal.mod_hv_v[0]=0; 		/* Value of the object ELIN/MOD/HV-1 an 2 */
	defaultVal.mod_hv_v[1]=0;
	defaultVal.vpfn[0]=0; 			/* Value of the objects ELIN/O-MOD/DEQ-1 and ELIN/O-MOD/DEQ-2 */
	defaultVal.vpfn[1]=0;
	defaultVal.bunch_phase=0; 		/* Value of the object ELIN/O-RF/BUN-PH */
	defaultVal.pbunch_phase=0; 	/* Value of the object ELIN/O-RF/PBUN-PH */
	defaultVal.pbunch_atten=0;		/* Value of the object ELIN/O-RF/PBUN-AT */
	defaultVal.section_phase=0; 	/* Value of the object ELIN/O-RF/SEC-PH */
	defaultVal.gun_heating_v=0; 	/* Value of the object ELIN/O-GUN/HEAT-V */
	defaultVal.gun_grid_v=0; 		/* Value of the object ELIN/O-GUN/GRID-V */
	defaultVal.gun_pulse_v=0; 		/* Value of object ELIN/O-GUN/PUSLE-V */
	defaultVal.gun_pulse_l=0; 		/* Value of the object ELIN/O-GUN/PULSE-L */
	defaultVal.gun_hv_v=0; 			/* Value of the object ELIN/O-GUN/HV */
	defaultVal.frequency=2998.160154; 	/* Frequency value of the object ELIN/O-RF/FREQ */
	defaultVal.short_pulse=true; 		/* Flag to indicate if the command DevOpen or DevClose should be performed on the object ELIN/R-GUN/SHORT */
	defaultVal.r352=false; 				/* Flag to indicate if the command DevOpen or DevClose should be performed on the object ELIN/R-GUN/352M */
	defaultVal.timer_rf=0; 			/* Value of the object ELIN/T-RF/1 */
	defaultVal.timer_mod[0]=0; 		/* Value of the objects ELIN/T-MOD/1 and ELIN/T-MOD/2 */
	defaultVal.timer_mod[1]=0;
	defaultVal.timer_mod_s[0]=0; 	/* Value of the objects ELIN/T-MOD/S1 and ELIN/T-MOD/S2 */
	defaultVal.timer_mod_s[1]=0;
#endif

	DEBUG_STREAM << ">>>> retrieve sequences devices names" << endl;
	{
		omni_mutex_lock l(mutex);
		gun_aux_name 		= seq_obj->gun_aux_name;
		gun_name 		= seq_obj->gun_name;
		gun_HV_name 		= seq_obj->gun_HV_name;
		rf_run_name 		= seq_obj->rf_run_name;
		cooling_name 		= seq_obj->cooling_name;
		mod1_aux_name 		= seq_obj->mod1_aux_name;
		mod2_aux_name 		= seq_obj->mod2_aux_name;
		mod1_HV_name 		= seq_obj->mod1_HV_name;
		mod2_HV_name 		= seq_obj->mod2_HV_name;
		mod1_name 		= seq_obj->mod1_name;
		mod2_name 		= seq_obj->mod2_name;
		focus_klystron1_name	= seq_obj->focus_klystron1_name;
		focus_klystron2_name	= seq_obj->focus_klystron2_name;
		focus_beam1_name	= seq_obj->focus_beam1_name;
		focus_beam2_name	= seq_obj->focus_beam2_name;
		focus_steer_name	= seq_obj->focus_steer_name;
		timeout 		= seq_obj->timeout;

		//gun_gunaux_tdk_name 		= 	seq_obj->gun_gunaux_tdk_name;
		gun_focus_b1b4_tdk_name		= 	seq_obj->gun_focus_b1b4_tdk_name;
		gun_steerer_tdk_name		=   seq_obj->gun_steerer_tdk_name;
		prebuncher_steerer_tdk_name = seq_obj->prebuncher_steerer_tdk_name;
	}

	DEBUG_STREAM << ">>>> initialize Device Proxy Objects" << endl;
	gun_aux 	= NULL;
	gun 		= NULL;
	gun_HV 		= NULL;
	rf_run 		= NULL;
	cooling 	= NULL;
	mod1_aux 	= NULL;
	mod2_aux 	= NULL;
	mod1_HV 	= NULL;
	mod2_HV		= NULL;
	mod1 		= NULL;
	mod2 		= NULL;
	focus_klystron1	= NULL;
	focus_klystron2	= NULL;
	focus_beam1	= NULL;
	focus_beam2	= NULL;
	focus_steer	= NULL;

	//gun_gunaux_tdk = NULL;
	gun_focus_b1b4_tdk	= NULL;
	gun_steerer_tdk	 = NULL;
	prebuncher_steerer_tdk	 = NULL;

	try
	{
		gun_aux 	= new Tango::DeviceProxy(gun_aux_name.c_str());
		gun 		= new Tango::DeviceProxy(gun_name.c_str());
		gun_HV 		= new Tango::DeviceProxy(gun_HV_name.c_str());
		rf_run 		= new Tango::DeviceProxy(rf_run_name.c_str());
		cooling 	= new Tango::DeviceProxy(cooling_name.c_str());
		mod1_aux 	= new Tango::DeviceProxy(mod1_aux_name.c_str());
		mod2_aux 	= new Tango::DeviceProxy(mod2_aux_name.c_str());
		mod1_HV 	= new Tango::DeviceProxy(mod1_HV_name.c_str());
		mod2_HV		= new Tango::DeviceProxy(mod2_HV_name.c_str());
		mod1 		= new Tango::DeviceProxy(mod1_name.c_str());
		mod2 		= new Tango::DeviceProxy(mod2_name.c_str());
		focus_klystron1	= new Tango::DeviceProxy(focus_klystron1_name.c_str());
		focus_klystron2	= new Tango::DeviceProxy(focus_klystron2_name.c_str());
		focus_beam1	= new Tango::DeviceProxy(focus_beam1_name.c_str());
		focus_beam2	= new Tango::DeviceProxy(focus_beam2_name.c_str());
		focus_steer	= new Tango::DeviceProxy(focus_steer_name.c_str());

		//gun_gunaux_tdk = new Tango::DeviceProxy(gun_gunaux_tdk_name.c_str());
		gun_focus_b1b4_tdk	= new Tango::DeviceProxy(gun_focus_b1b4_tdk_name.c_str());
		gun_steerer_tdk	 = new Tango::DeviceProxy(gun_steerer_tdk_name.c_str());
		prebuncher_steerer_tdk = new Tango::DeviceProxy(prebuncher_steerer_tdk_name.c_str());

		gun_aux->set_transparency_reconnection(true);
		gun->set_transparency_reconnection(true);
		gun_HV->set_transparency_reconnection(true);
		rf_run->set_transparency_reconnection(true);
		cooling->set_transparency_reconnection(true);
		mod1_aux->set_transparency_reconnection(true);
		mod2_aux->set_transparency_reconnection(true);
		mod1_HV->set_transparency_reconnection(true);
		mod2_HV->set_transparency_reconnection(true);
		mod1->set_transparency_reconnection(true);
		mod2->set_transparency_reconnection(true);
		focus_klystron1->set_transparency_reconnection(true);
		focus_klystron2->set_transparency_reconnection(true);
		focus_beam1->set_transparency_reconnection(true);
		focus_beam2->set_transparency_reconnection(true);
		focus_steer->set_transparency_reconnection(true);

		//gun_gunaux_tdk->set_transparency_reconnection(true);
		gun_focus_b1b4_tdk->set_transparency_reconnection(true);
		gun_steerer_tdk->set_transparency_reconnection(true);
		prebuncher_steerer_tdk->set_transparency_reconnection(true);
	}
	catch (Tango::DevFailed &e)
	{
		ERROR_STREAM << ">>>> An exception occured!" << endl;
		Tango::Except::print_exception(e);
		string tmp_status;
		tmp_status = "******* Initialization failed with errors!\n";

		for (unsigned short i = 0; i<e.errors.length(); i++)
		{
			tmp_status = tmp_status + "**** ERROR **** " + e.errors[i].desc.in() + "\n";
		}
		tmp_status = tmp_status + "Ensure the needed devices are well defined in the database\n";
		tmp_status = tmp_status + " and execute the INIT function of the LinacSequencer server\n";
		omni_mutex_lock l(mutex);
		seq_obj->sequence_history.push_back (tmp_status);
		seq_obj->error = true;
	}
	// set the timeout for each device
	set_timeout(gun_aux , gun_aux_name , timeout);
	set_timeout(gun , gun_name , timeout);
	set_timeout(gun_HV , gun_HV_name , timeout);
	set_timeout(rf_run , rf_run_name , timeout);
	set_timeout(cooling , cooling_name , timeout);
	set_timeout(mod1_aux , mod1_aux_name , timeout);
	set_timeout(mod2_aux , mod2_aux_name , timeout);
	set_timeout(mod1_HV , mod1_HV_name , timeout);
	set_timeout(mod2_HV , mod2_HV_name , timeout);
	set_timeout(mod1 , mod1_name , timeout);
	set_timeout(mod2 , mod2_name ,  timeout);
	set_timeout(focus_klystron1 , focus_klystron1_name , timeout);
	set_timeout(focus_klystron2 , focus_klystron2_name , timeout);
	set_timeout(focus_beam1 , focus_beam1_name , timeout);
	set_timeout(focus_beam2 , focus_beam2_name , timeout);
	set_timeout(focus_steer , focus_steer_name , timeout);

	//set_timeout(gun_gunaux_tdk ,  gun_gunaux_tdk_name , timeout);
	set_timeout(gun_focus_b1b4_tdk ,  gun_focus_b1b4_tdk_name , timeout);
	set_timeout(gun_steerer_tdk ,  gun_steerer_tdk_name , timeout);
	set_timeout(prebuncher_steerer_tdk ,  prebuncher_steerer_tdk_name , timeout);

	while(true)
	{
		DEBUG_STREAM << ">>>> Begining of While loop" <<endl;
		try
		{
			omni_mutex_lock *l = new omni_mutex_lock (mutex);

			if ( seq_obj->killthread == true)
			{
				/* The thread must commit suicide */
				delete l;
				clean_exit();
			}

			if ( seq_obj->start == true )
			{
				// clean history buffer
				seq_obj->sequence_history.clear();
				DEBUG_STREAM << ">>>> seq_obj->start == " << seq_obj->start << endl;
				seq_obj->start = false;
				seq_obj->run   = true;
				seq_obj->error = false;

				DEBUG_STREAM << ">>>> seq_obj->run == " << seq_obj->run << endl;
				switch(seq_obj->cmd)
				{
					case MACRO_ON:
							delete l;
							INFO_STREAM << ">>>> seq_obj->cmd == MACRO_ON" << endl;
							// Start ON sequence
							macro_ON();
							break;
					case MACRO_OFF:
							delete l;
							INFO_STREAM << ">>>> seq_obj->cmd == MACRO_OFF" << endl;
							// Start OFF sequence
							macro_OFF();
							break;
					case MACRO_STANDBY:
							delete l;
							INFO_STREAM << ">>>> seq_obj->cmd == MACRO_STANDBY" << endl;
							// Start STANDBY sequence
							macro_STANDBY();
							break;
					case MACRO_LOWHEATING:
							delete l;
							INFO_STREAM << ">>>> seq_obj->cmd == MACRO_LOWHEATING" << endl;
							// Start LOW HEATING sequence
							macro_LOWHEATING();
							break;
					case MACRO_LOAD_SETTINGS:
							delete l;
							INFO_STREAM << ">>>> seq_obj->cmd == MACRO_LOAD_SETTINGS" << endl;
							// Start LOAD_SETTINGS sequence
							macro_LOAD_SETTINGS();
							break;
					case MACRO_SAVE_SETTINGS:
							{
								string savefile = seq_obj->filename;
								delete l;
								INFO_STREAM << ">>>> seq_obj->cmd == MACRO_SAVE_SETTINGS" << endl;
								// Start SAVE_SETTINGS sequence (with exception on read set points failure)
								macro_SAVE_SETTINGS(savefile, false);
							}
							break;
					case MACRO_FORCE_SAVE:
							{
								string savefile = seq_obj->filename;
								delete l;
								INFO_STREAM << ">>>> seq_obj->cmd == MACRO_FORCE_SAVE" << endl;
								// Start SAVE_SETTINGS (no exception on read set points failure) sequence
								macro_SAVE_SETTINGS(savefile, true);
							}
							break;
					default: /* no macro command is passed */
							INFO_STREAM << ">>>> no macro command is passed" << endl;
							delete l;
				}
				DEBUG_STREAM << ">>>> End seq_obj->start == true" << endl;
			} // end if ( seq_obj->start == true )
			else
			{
				DEBUG_STREAM << ">>>> seq_obj->start = false" << endl;
				delete l;
			}
		}
		// Catch all exceptions to avoid leaving the endless loop.
		catch (Tango::DevFailed &e)
		{
			ERROR_STREAM << ">>>> An exception occured!" << endl;
			Tango::Except::print_exception(e);

			// Add the exception description to the end of the sequence history.
			string tmp_status;
			tmp_status = "\n*******  Sequence failed with errors!\n";
			for (unsigned short i = 0; i<e.errors.length(); i++)
			{
				tmp_status = tmp_status + "**** ERROR **** " + e.errors[i].desc.in() + "\n";
			}

			omni_mutex_lock l(mutex);
			seq_obj->sequence_history.push_back (tmp_status);

			// set flags
			seq_obj->error = true;
			seq_obj->run   = false;
		}
		{
			omni_mutex_lock l(mutex);
			seq_obj->run = false;
			seq_obj->quit = false; /* the sequence is ended, no need to abort now */
		}
		usleep(25000); // wait 25 ms
	} // end while(true)

	return NULL;
}

//
// LinacSeqThread::write_history
//
void LinacSeqThread::write_history (string msg)
{
	DEBUG_STREAM << ">>>> LinacSeqThread write history" << endl;
	{
		omni_mutex_lock l(mutex);
		seq_obj->sequence_history.push_back (msg);
	}
	DEBUG_STREAM << ">>>> End of  LinacSeqThread write history" << endl;
}

  /////////////////////////////////////////////////////////////////////////////
 //                          MACRO ON                                       //
/////////////////////////////////////////////////////////////////////////////
void LinacSeqThread::macro_ON()
{
	// TODO : add some check_abort()
	DEBUG_STREAM << ">>>> LinacThread ON sequence!" << endl;
	write_history("Begin macro On");
	int nberrors = 0;

	// Why not ON on ModAux ??
	write_history("Open the economy relay");
	if(set_bool_value(mod1_aux,"Economy",false,false) == false)
		nberrors++;
	if(set_bool_value(mod2_aux,"Economy",false,false) == false)
		nberrors++;
	check_abort();

/*****************************************************
 * Set values of focussing and turn ON power supply
 *****************************************************/
	write_history("Set the Klystron 1 focussing currents");
	if(send_cmd(focus_klystron1,"SetCurrent",false) == false)
		nberrors++;
	check_abort();
	write_history("Set the Klystron 2 focussing currents");
	if(send_cmd(focus_klystron2,"SetCurrent",false) == false)
		nberrors++;
	check_abort();
	write_history("Set the Beam1 focussing currents");
	if(send_cmd(focus_beam1,"SetCurrent",false) == false)
		nberrors++;
	check_abort();
	write_history("Set the Beam2 focussing currents");
	if(send_cmd(focus_beam2,"SetCurrent",false) == false)
		nberrors++;
	check_abort();
	write_history("Set the Steering currents");
	if(send_cmd(focus_steer,"SetCurrent",false) == false)
		nberrors++;
	check_abort();

/********************************************************
 *	Turn on focusing / steering TDKLambda power supply.
 *  The current set point is not restored since the
 * 	TDKLambda power supply memorises it.
 ********************************************************/
	write_history("Switch ON the Beam1 focussing (TDKLambda MultiChannel Coils B1-B4)");
	if(send_cmd(gun_focus_b1b4_tdk, "On", false) == false)
		nberrors++;
	check_abort();

	write_history("Switch On the Beam steerer (TDKLambda MultiChannel GH1/GV1 to GH3/GV3)");
	if(send_cmd(gun_steerer_tdk, "On", false) == false)
		nberrors++;
	check_abort();

	write_history("Switch On the pre-buncher steerer (TDKLambda MultiChannel GH4/GV4)");
	if(send_cmd(prebuncher_steerer_tdk, "On", false) == false)
		nberrors++;
	check_abort();

/************************************************
 * Set values of ELIN/R-GUN/352M device
 ************************************************/
//////////////////////////////////////////////////////////////// TODO !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
// 	Tango::DevString strtmp;
// 	bool read_ok = read_string_set_point(gun,"PulseType",&strtmp,false);
// 	if(read_ok)
// 	{
// 		if(strcasecmp(strtmp,"LONG") == 0)
// 		{
// 			write_history("Switch on 352Mhz");
// 			if(set_bool_value(gun,"In352Mhz",true,false) == false)
// 				nberrors++;
// 		}
// 		else
// 		{
// 			write_history("Switch off 352Mhz");
// 			if(set_bool_value(gun,"In352Mhz",false,false) == false)
// 				nberrors++;
// 		}
// 		DEBUG_STREAM << ">>>> Pulse Type = " << strtmp << endl;
// 		CORBA::string_free(strtmp);
// 	}
// 	else
// 	{
// 		nberrors++;
// 		WarnErrorReadingSetPoint("Short/Long pulse mode");
// 	}
// 	check_abort();

/************************************************
 * DevOn on HV devices
 ************************************************/
	write_history("Switch On Modulator 1 HV");
	if(send_cmd(mod1_HV,"Reset",false) == false)
		nberrors++;
	write_history("Switch On Modulator 2 HV");
	if(send_cmd(mod2_HV,"SoftReset",false) == false) // SoftReset doesn't reset the Daresbury
		nberrors++;
   sleep(1);
	check_abort();
	if(send_cmd(mod1_HV,"On",false) == false) // the 2 Modulators HVPS are controlled with the same relay
		nberrors++;
	if(send_cmd(mod2_HV,"SoftOn",false) == false) // SoftOn doesn't send a command on the OnRelay.
		nberrors++;
	write_history("Switch On Gun HV");
	check_abort();
	if(send_cmd(gun_HV,"On",false) == false)
		nberrors++;
   sleep(1);

	check_abort();
	write_history("Switch On Modulator running");
	if(send_cmd(mod1,"On",false) == false)
		nberrors++;
	if(send_cmd(mod2,"SoftOn",false) == false)
		nberrors++;
   sleep(1);
	check_abort();
	write_history("Switch On Beam");
	if(send_cmd(gun,"On",false) == false)
		nberrors++;
   check_abort();

/**************************************************************
 * Set the nominal set point to mod1_HV and mod2_HV device
 *************************************************************/
	write_history("Set the Modulator 1 High Voltage");
	if(send_cmd(mod1_HV,"SetHV",false) == false)
		nberrors++;
	check_abort();
	write_history("Set the Modulator 2 High Voltage");
	if(send_cmd(mod2_HV,"SetHV",false) == false)
		nberrors++;
	check_abort();

	// http://jira.esrf.fr:8080/jira/browse/ACSS-466
	sleep(1);

/******************
 * Switch On RF
 *****************/
	write_history("Switch On RF");
	if(send_cmd(rf_run,"On",false) == false)
		nberrors++;
	write_history("End macro ON");

	if(nberrors > 0)
	{
		{
			omni_mutex_lock l(mutex);
			seq_obj->error = true;
		}
		write_history("Sequence failed with errors !");
		INFO_STREAM << ">>>> LinacThread ON sequence ended with " << nberrors << " errors !" << endl;
	}
	else
	{
		INFO_STREAM << ">>>> LinacThread ON sequence ended successfully!" << endl;
	}
}

  /////////////////////////////////////////////////////////////////////////////
 //                          MACRO OFF                                      //
/////////////////////////////////////////////////////////////////////////////
void LinacSeqThread::macro_OFF()
{
	// TODO : add some check_abort()
	DEBUG_STREAM << ">>>> LinacThread OFF sequence!" << endl;
	vector <Tango::DevDouble> set_values_vector;

	/*********************************
 	 * Issue DevOff on the devices   *
	 *********************************/
	write_history("Begin macro Off");
	int nberrors = 0;

/************************************************
 * Set  set point of mod1_HV and mod2_HV to 0 to avoid short circuit of the HV
 * to the ground
 ************************************************/
	write_history("Set the Modulator 1 High Voltage to 0");
	if(send_cmd(mod1_HV,"HVZero",false) == false)
		nberrors++;
	check_abort();
	write_history("Set the Modulator 2 High Voltage to 0");
	if(send_cmd(mod2_HV,"HVZero",false) == false)
		nberrors++;
	sleep(1); /* let the time to the capacity to discharge */
	check_abort();
	write_history("Switch Off the Modulators HV");
	if(send_cmd(mod1_HV,"Off",false) == false) // the 2 Modulators HVPS are controlled with the same relay
		nberrors++;
	if(send_cmd(mod2_HV,"SoftOff",false) == false) // SoftOff doesn't send any command to the OffRelay
		nberrors++;
	check_abort();
	write_history("Switch Off the Gun HV");
	if(send_cmd(gun_HV,"Off",false) == false)
		nberrors++;
	check_abort();
// /************************************************
//  * set the current in bruker to 0
//  ************************************************/
	send_cmd(focus_beam1,"ZeroCurrent",false);
	send_cmd(focus_beam2,"ZeroCurrent",false);
	send_cmd(focus_steer,"ZeroCurrent",false);

/*
	The following part should not be necessary. When the current is off, the
	TDKLambda do not lose it's current value. When turning on again,
	the correct set point will be here.
*/


// /********************************************************
//  * set the current in TDKLambda to zero (focus + steerer).
//  ********************************************************/
//	write_history("Setting zero current on TDKLambda MultiChannel focusing and steering devices.");

	/* B1-B4 */
// 	set_values_vector.clear();
// 	for (unsigned int i=0; i < 4; i++) set_values_vector.push_back( (Tango::DevDouble) 0.0 );
// 	set_double_array_attribute_values(gun_focus_b1b4_tdk, "Current", set_values_vector);
//
// 	/* GH1/GV1 to GH3/GV3 */
// 	set_values_vector.clear();
// 	for (unsigned int i=0; i < 6; i++) set_values_vector.push_back( (Tango::DevDouble) 0.0 );
// 	set_double_array_attribute_values(gun_steerer_tdk, "Current", set_values_vector);
//
// 	/* GH4/GV4 */
// 	set_values_vector.clear();
// 	for (unsigned int i=0; i < 2; i++) set_values_vector.push_back( (Tango::DevDouble) 0.0 );
// 	set_double_array_attribute_values(prebuncher_steerer_tdk, "Current", set_values_vector);

	sleep(1);

// /**********************************************************
//  * switch off TDKLambda on focusing and steerering devices.
//  **********************************************************/
	write_history("Switch Off the Beam1 focussing (TDKLambda MultiChannel Coils B1-B4)");
	if(send_cmd(gun_focus_b1b4_tdk, "Off", false) == false)
		nberrors++;
	check_abort();

	write_history("Switch Off the Beam steerer (TDKLambda MultiChannel GH1/GV1 to GH3/GV3)");
	if(send_cmd(gun_steerer_tdk, "Off", false) == false)
		nberrors++;
	check_abort();

	write_history("Switch Off the pre-buncher steerer (TDKLambda MultiChannel GH4/GV4)");
	if(send_cmd(prebuncher_steerer_tdk, "Off", false) == false)
		nberrors++;
	check_abort();


/******************************************************
 * switch off Brucker focussing and steering  devices
 ******************************************************/
	write_history("Switch Off the Beam1 focussing (BruckerMch)");
	if(send_cmd(focus_beam1,"Off",false) == false)
		nberrors++;
	check_abort();

	write_history("Switch Off the Beam2 focussing");
	if(send_cmd(focus_beam2,"Off",false) == false)
		nberrors++;
	check_abort();

	write_history("Switch Off the steerers");
	if(send_cmd(focus_steer,"Off",false) == false)
		nberrors++;
	check_abort();

	write_history("Switch Off the Modulator auxiliaries");
	if(send_cmd(mod1_aux,"Off",false) == false)
		nberrors++;
	if(send_cmd(mod2_aux,"SoftOff",false) == false)
		nberrors++;
	check_abort();

	write_history("Switch Off the Gun auxiliaries");
	if(send_cmd(gun_aux,"Off",false) == false)
		nberrors++;
	check_abort();

	sleep(1); // we don't stop everything in the same moment - the electric network like it better
	write_history("Switch Off the Klystron 1 focussing");
	send_cmd(focus_klystron1,"ZeroCurrent",false);
	write_history("Switch Off the Klystron 2 focussing");
	send_cmd(focus_klystron2,"ZeroCurrent",false);
	sleep(1);
	if(send_cmd(focus_klystron1,"Off",false) == false)
		nberrors++;
	if(send_cmd(focus_klystron2,"Off",false) == false)
		nberrors++;
	check_abort();

/************************************************
 * open 352M Relay
 ************************************************/
//	write_history("Switch off 352Mhz");
//	if(set_bool_value(gun,"In352Mhz",false,false) == false)
//		nberrors++;

	write_history("End macro Off");

	if(nberrors > 0)
	{
		{
			omni_mutex_lock l(mutex);
			seq_obj->error = true;
		}
		write_history("Sequence failed with errors !");
		INFO_STREAM << ">>>> LinacThread OFF sequence ended with " << nberrors << " errors !" << endl;
	}
	else
	{
		INFO_STREAM << ">>>> LinacThread OFF sequence ended successfully!" << endl;
	}
}

  /////////////////////////////////////////////////////////////////////////////
 //                          MACRO STANDBY                                  //
/////////////////////////////////////////////////////////////////////////////
void LinacSeqThread::macro_STANDBY()
{
	// TODO : add some check_abort()
	DEBUG_STREAM << ">>>> LinacThread STANDBY sequence!" << endl;
	write_history ("Begin macro Standby");
	int nberrors = 0;

	check_abort();

	write_history("Switch Off the beam");
	if(send_cmd(gun,"Off",false) == false)
		nberrors++;

 /************************************************
 * Test the state of the ELIN/GUN/AUX device
 ************************************************/
	gun_aux_state = get_state(gun_aux,"Gun Auxiliary");
   switch (gun_aux_state)
   {
	case Tango::OFF:
//			removed after discussion with Injection staff
// 		write_history("Set the Gun heating voltage");
// 		if(set_double_value(gun_aux,"HeatV",val.gun_heating_v,false) == false)
// 			nberrors++;
// 		check_abort();
		write_history("Switch On the gun auxiliaries");
		if(send_cmd(gun_aux,"On",false) == false)
			nberrors++;
		break;

	case Tango::ON:
		write_history("Switch Off the gun HV");
      if(send_cmd(gun_HV,"Off",false) == false)
			nberrors++;
		break;

	case Tango::STANDBY:
	case Tango::FAULT:
		break;

	default:
		break;
   }
	check_abort();

	write_history("Open the economy relay");
	if(set_bool_value(mod1_aux,"Economy",false,false) == false)
		nberrors++;
	if(set_bool_value(mod2_aux,"Economy",false,false) == false)
		nberrors++;
	check_abort();

/************************************************
 * Test the state of the ELIN/MOD/AUX device
 ************************************************/
	mod2_aux_state = get_state(mod2_aux,"Modulator 2 Auxiliary");
	if(mod2_aux_state == Tango::FAULT)
	{
		write_history("The modulator auxiliaries are Fault");
	}
	else
	{
		mod1_aux_state = get_state(mod1_aux,"Modulator 1 Auxiliary");
		switch (mod1_aux_state)
  	 	{
		case Tango::OFF:
			write_history("Switch On the modulator auxiliaries");
			if(send_cmd(mod1_aux,"On",false) == false)
				nberrors++;
			if(send_cmd(mod2_aux,"SoftOn",false) == false)
				nberrors++;
			break;
		case Tango::ALARM:
		case Tango::UNKNOWN:
/************************************************
 * Set  set point of mod1_HV and mod2_HV to 0 to avoid short circuit of the HV
 * to the ground
 ************************************************/
			write_history("Set the Modulator 1 High Voltage to 0");
			if(send_cmd(mod1_HV,"HVZero",false) == false)
				nberrors++;
			check_abort();
			write_history("Set the Modulator 2 High Voltage to 0");
			if(send_cmd(mod2_HV,"HVZero",false) == false)
				nberrors++;
			sleep(1); /* let the time to the capacity to discharge */
			check_abort();
			write_history("Switch Off the Modulators HV");
			if(send_cmd(mod1_HV,"Off",false) == false) // the 2 Modulators HVPS are controlled with the same relay
				nberrors++;
			if(send_cmd(mod2_HV,"SoftOff",false) == false)
				nberrors++;
			write_history("Switch On the modulator auxiliaries");
			if(send_cmd(mod1_aux,"On",false) == false)
				nberrors++;
			if(send_cmd(mod2_aux,"SoftOn",false) == false)
				nberrors++;
			break;
		case Tango::ON:

			// http://jira.esrf.fr:8080/jira/browse/ACSS-466
			write_history("Switch RF OFF");
			if(send_cmd(rf_run,"Off",false) == false)
				nberrors++;
			sleep(1);

/************************************************
 * Set  set point of mod1_HV and mod2_HV to 0 to avoid short circuit of the HV
 * to the ground
 ************************************************/
			write_history("Set the Modulator 1 High Voltage to 0");
			if(send_cmd(mod1_HV,"HVZero",false) == false)
				nberrors++;
			check_abort();
			write_history("Set the Modulator 2 High Voltage to 0");
			if(send_cmd(mod2_HV,"HVZero",false) == false)
				nberrors++;
			sleep(1); /* let the time to the capacity to discharge */
			check_abort();
			write_history("Switch Off the Modulators HV");
			if(send_cmd(mod1_HV,"Off",false) == false) // the 2 Modulators HVPS are controlled with the same relay
				nberrors++;
			if(send_cmd(mod2_HV,"SoftOff",false) == false)
				nberrors++;
			break;
		case Tango::INIT:
 		case Tango::MOVING:
			write_history("The modulator auxiliaries are Warming up");
			break;

		case Tango::FAULT:
			write_history("The modulator auxiliaries are Fault");
			break;
		default:
			break;
		 }
		}


/*****************************************************
 * Set values of focussing / steering and turn on()
 *****************************************************/
	write_history("Set the Klystron 1 focussing currents");
	if(send_cmd(focus_klystron1,"SetCurrent",false) == false)
		nberrors++;
	check_abort();
	write_history("Set the Klystron 2 focussing currents");
	if(send_cmd(focus_klystron2,"SetCurrent",false) == false)
		nberrors++;
	check_abort();
	write_history("Set the Beam1 focussing currents");
	if(send_cmd(focus_beam1,"SetCurrent",false) == false)
		nberrors++;
	check_abort();
	write_history("Set the Beam2 focussing currents");
	if(send_cmd(focus_beam2,"SetCurrent",false) == false)
		nberrors++;
	check_abort();
	write_history("Set the Steering currents");
	if(send_cmd(focus_steer,"SetCurrent",false) == false)
		nberrors++;
	check_abort();

/********************************************************
 *	Turn on focusing / steering TDKLambda power supply.
 *  The current set point is not restored since the
 * 	TDKLambda power supply memorises it.
 ********************************************************/
	write_history("Switch ON the Beam1 focussing (TDKLambda MultiChannel Coils B1-B4)");
	if(send_cmd(gun_focus_b1b4_tdk, "On", false) == false)
		nberrors++;
	check_abort();

	write_history("Switch On the Beam steerer (TDKLambda MultiChannel GH1/GV1 to GH3/GV3)");
	if(send_cmd(gun_steerer_tdk, "On", false) == false)
		nberrors++;
	check_abort();

	write_history("Switch On the pre-buncher steerer (TDKLambda MultiChannel GH4/GV4)");
	if(send_cmd(prebuncher_steerer_tdk, "On", false) == false)
		nberrors++;
	check_abort();


/************************************************
 * Terminate the sequence.
 ************************************************/
 	write_history("End of macro command Standby");

 	if(nberrors > 0)
 	{
 		{
 			omni_mutex_lock l(mutex);
 			seq_obj->error = true;
 		}
 		write_history("Sequence failed with errors !");
 		INFO_STREAM << ">>>> LinacThread STANDBY sequence ended with " << nberrors << " errors !" << endl;
 	}
 	else
 	{
 		INFO_STREAM << ">>>> LinacThread STANDBY sequence ended successfully!" << endl;
 	}
}

  /////////////////////////////////////////////////////////////////////////////
 //                          MACRO LOW HEATING                              //
/////////////////////////////////////////////////////////////////////////////
void LinacSeqThread::macro_LOWHEATING()
{
	// TODO : add some check_abort()
	DEBUG_STREAM << ">>>> LinacThread LOW HEATING sequence!" << endl;
	int nberrors = 0;
	write_history ("Begin macro Economy");
	mod2_aux_state = get_state(mod2_aux,"Modulator 2 Auxiliary");
	if(mod2_aux_state == Tango::FAULT)
	{
		write_history("The modulator auxiliaries are Fault");
		write_history ("Close the economy relay");
		if(set_bool_value(mod2_aux,"Economy",true,false) == false)
			nberrors++;
		usleep(100000); // wait 100 ms before to change the heating voltage of the Chroma heater power supply
		write_history ("Set the heating voltage of the modulator 1 to economy voltage");
		if(set_bool_value(mod1_aux,"Economy",true,false) == false)
			nberrors++;
	}
	else
	{
		mod1_aux_state = get_state(mod1_aux,"Modulator 1 Auxiliary");
		switch (mod1_aux_state)
		{
		case Tango::OFF:
			write_history ("Close the economy relay");
			if(set_bool_value(mod2_aux,"Economy",true,false) == false)
				nberrors++;
			usleep(100000); // wait 100 ms before to change the heating voltage of the Chroma heater power supply
			write_history ("Set the heating voltage of the modulator 1 to economy voltage");
			if(set_bool_value(mod1_aux,"Economy",true,false) == false)
				nberrors++;
			check_abort();
			write_history("Switch On the modulator auxiliaries");
			if(send_cmd(mod1_aux,"On",false) == false)
				nberrors++;
			if(send_cmd(mod2_aux,"SoftOn",false) == false)
				nberrors++;
			break;
		case Tango::ALARM:
		case Tango::UNKNOWN:
/************************************************
 * Set  set point of mod1_HV and mod2_HV to 0 to avoid short circuit of the HV
 * to the ground
 ************************************************/
			write_history("Set the Modulator 1 High Voltage to 0");
			if(send_cmd(mod1_HV,"HVZero",false) == false)
				nberrors++;
			check_abort();
			write_history("Set the Modulator 2 High Voltage to 0");
			if(send_cmd(mod2_HV,"HVZero",false) == false)
				nberrors++;
			sleep(1); /* let the time to the capacity to discharge */
			check_abort();
			write_history("Switch Off the Modulators HV");
			if(send_cmd(mod1_HV,"Off",false) == false) // the 2 Modulators HVPS are controlled with the same relay
				nberrors++;
			if(send_cmd(mod2_HV,"SoftOff",false) == false)
				nberrors++;
			check_abort();
			write_history ("Close the economy relay");
			if(set_bool_value(mod2_aux,"Economy",true,false) == false)
				nberrors++;
			usleep(100000); // wait 100 ms before to change the heating voltage of the Chroma heater power supply
			write_history ("Set the heating voltage of the modulator 1 to economy voltage");
			if(set_bool_value(mod1_aux,"Economy",true,false) == false)
				nberrors++;
			check_abort();
			write_history("Switch On the modulator auxiliaries");
			if(send_cmd(mod1_aux,"On",false) == false)
				nberrors++;
			if(send_cmd(mod2_aux,"SoftOn",false) == false)
				nberrors++;
			break;
		case Tango::ON:
/************************************************
 * Set  set point of mod1_HV and mod2_HV to 0 to avoid short circuit of the HV
 * to the ground
 ************************************************/
			write_history("Set the Modulator 1 High Voltage to 0");
			if(send_cmd(mod1_HV,"HVZero",false) == false)
				nberrors++;
			check_abort();
			write_history("Set the Modulator 2 High Voltage to 0");
			if(send_cmd(mod2_HV,"HVZero",false) == false)
				nberrors++;
			sleep(1); /* let the time to the capacity to discharge */
			check_abort();
			write_history("Switch Off the Modulators HV");
			if(send_cmd(mod1_HV,"Off",false) == false) // the 2 Modulators HVPS are controlled with the same relay
				nberrors++;
			if(send_cmd(mod2_HV,"SoftOff",false) == false)
				nberrors++;
			check_abort();
			write_history ("Close the economy relay");
			if(set_bool_value(mod2_aux,"Economy",true,false) == false)
				nberrors++;
			usleep(100000); // wait 100 ms before to change the heating voltage of the Chroma heater power supply
			write_history ("Set the heating voltage of the modulator 1 to economy voltage");
			if(set_bool_value(mod1_aux,"Economy",true,false) == false)
				nberrors++;
			break;
		case Tango::INIT:
 		case Tango::MOVING:
  			write_history ("The modulator auxiliaries are Warming up");
   			write_history ("Close the economy relay");
			if(set_bool_value(mod2_aux,"Economy",true,false) == false)
				nberrors++;
			usleep(100000); // wait 100 ms before to change the heating voltage of the Chroma heater power supply
			write_history ("Set the heating voltage of the modulator 1 to economy voltage");
			if(set_bool_value(mod1_aux,"Economy",true,false) == false)
				nberrors++;
			break;
		case Tango::FAULT:
			write_history ("The modulator auxiliaries are in Fault !");
   			write_history ("Close the economy relay");
			if(set_bool_value(mod2_aux,"Economy",true,false) == false)
				nberrors++;
			usleep(100000); // wait 100 ms before to change the heating voltage of the Chroma heater power supply
			write_history ("Set the heating voltage of the modulator 1 to economy voltage");
			if(set_bool_value(mod1_aux,"Economy",true,false) == false)
				nberrors++;
			break;

		default:
			break;
  		}
	}
	check_abort();

/************************************************
 * Test the state of the ELIN/GUN/AUX device
 ************************************************/
 	gun_aux_state = get_state(gun_aux,"Gun Auxiliary");
   switch (gun_aux_state)
   {
	case Tango::OFF:
		write_history("Switch On the gun auxiliaries");
		if(send_cmd(gun_aux,"On",false) == false)
			nberrors++;
		break;

	case Tango::ON:
	case Tango::ALARM:
		write_history("Switch Off the gun HV");
      if(send_cmd(gun_HV,"Off",false) == false)
			nberrors++;
		break;

	case Tango::INIT:
	case Tango::FAULT:
		break;

	default:
		break;

   }
	check_abort();

/************************************************
 * set the current in bruker to 0
 ************************************************/
	send_cmd(focus_beam1,"ZeroCurrent",false);
	send_cmd(focus_beam2,"ZeroCurrent",false);
	send_cmd(focus_steer,"ZeroCurrent",false);
	sleep(1);
/************************************************
 * switch off Bruker focussing and steering  devices
 ************************************************/
	write_history("Switch Off the Beam1 focussing");
	if(send_cmd(focus_beam1,"Off",false) == false)
		nberrors++;
	check_abort();
	write_history("Switch Off the Beam2 focussing");
	if(send_cmd(focus_beam2,"Off",false) == false)
		nberrors++;
	check_abort();
	write_history("Switch Off the steerers");
	if(send_cmd(focus_steer,"Off",false) == false)
		nberrors++;
	sleep(1); // we don't stop everything in the same moment - the electric network like it better
	check_abort();
	write_history("Switch Off the Klystron 1 focussing");
	send_cmd(focus_klystron1,"ZeroCurrent",false);
	write_history("Switch Off the Klystron 2 focussing");
	send_cmd(focus_klystron2,"ZeroCurrent",false);
	sleep(1);
	if(send_cmd(focus_klystron1,"Off",false) == false)
		nberrors++;
	if(send_cmd(focus_klystron2,"Off",false) == false)
		nberrors++;
	check_abort();

// /**********************************************************
//  * switch off TDKLambda focusing and steerering devices.
//  * The current set point is not lost.
//  **********************************************************/
	write_history("Switch Off the Beam1 focussing (TDKLambda MultiChannel Coils B1-B4)");
	if(send_cmd(gun_focus_b1b4_tdk, "Off", false) == false)
		nberrors++;
	check_abort();

	write_history("Switch Off the Beam steerer (TDKLambda MultiChannel GH1/GV1 to GH3/GV3)");
	if(send_cmd(gun_steerer_tdk, "Off", false) == false)
		nberrors++;
	check_abort();

	write_history("Switch Off the pre-buncher steerer (TDKLambda MultiChannel GH4/GV4)");
	if(send_cmd(prebuncher_steerer_tdk, "Off", false) == false)
		nberrors++;
	check_abort();

/************************************************
 * open ELIN/R-GUN/352M device
 ************************************************/
// 	write_history("Switch off 352Mhz");
//	if(set_bool_value(gun,"In352Mhz",false,false) == false)
//		nberrors++;
//	check_abort();
/************************************************
 * reset the focussing and steering devices
 ************************************************/
	write_history("Reset the Beam1 focussing");
	if(send_cmd(focus_beam1,"Reset",false) == false)
		nberrors++;
	write_history("Reset the Beam2 focussing");
	if(send_cmd(focus_beam2,"Reset",false) == false)
		nberrors++;
	write_history("Reset the steerers");
	if(send_cmd(focus_steer,"Reset",false) == false)
		nberrors++;
	write_history("Reset the Klystron 1 focussing");
	if(send_cmd(focus_klystron1,"Reset",false) == false)
		nberrors++;
	write_history("Reset the Klystron 2 focussing");
	if(send_cmd(focus_klystron2,"Reset",false) == false)
		nberrors++;

	write_history("End macro Economy");
	if(nberrors > 0)
	{
		{
			omni_mutex_lock l(mutex);
			seq_obj->error = true;
		}
		write_history("Sequence failed with errors !");
		INFO_STREAM << ">>>> LinacThread LOWHEATING sequence ended with " << nberrors << " errors !" << endl;
	}
	else
	{
		INFO_STREAM << ">>>> LinacThread LOWHEATING sequence ended successfully!" << endl;
	}
}

  /////////////////////////////////////////////////////////////////////////////
 //                          MACRO LOAD SETTINGS                            //
/////////////////////////////////////////////////////////////////////////////
void LinacSeqThread::macro_LOAD_SETTINGS()
{
	DEBUG_STREAM << ">>>> LinacThread LOAD SETTINGS sequence!" << endl;
	vector <Tango::DevDouble> set_current;
	vector <Tango::DevDouble> set_voltage;

	write_history ("Begin of config file selection");

	int nberrors = 0;
#ifndef SIMU
	Values * val;
	FILE * configfile;
#endif
	string filename;
	{
		omni_mutex_lock l(mutex);
		filename = seq_obj->filename;
	}


#ifdef SIMU
	write_history ("Loading all the settings...");
	write_history("Set the Modulator 1 High Voltage");
	write_history("Set the Modulator 2 High Voltage");
	write_history("Set the Modulator 1 VPFN");
	write_history("Set the Modulator 2 VPFN");
	write_history("Set the Buncher Phase");
	write_history("Set the Pre-Buncher Phase");
	write_history("Set the Pre-Buncher Attenuation");
	write_history("Set the Section2 Phase");
	write_history("Set the Gun heating voltage");
	write_history("Set the Gun grid voltage");
	write_history("Set the Gun pulse voltage");
	write_history("Set the Gun pulse length");
	write_history("Set the Gun High Voltage");
	write_history("Set the RF Frequency");
	write_history("Switch pulse mode");
	write_history("Set the Klystron focussing currents");
	write_history("Set the Beam1 focussing currents");
	write_history("Set the Beam2 focussing currents");
	write_history("Set the Steering currents");
	write_history("End of config file selection");
	{
		omni_mutex_lock l(mutex);
		seq_obj->isFileLoaded = true;
	}
	INFO_STREAM << ">>>> LinacThread LOAD SETTINGS sequence ended successfully!" << endl;
#else
	// open the file
	if((configfile = fopen(filename.c_str(),"rb")) == NULL)
	{
 		TangoSys_OMemStream o;
 		o << "can't open file " << filename << ":" << strerror(errno);
 		ERROR_STREAM << o.str() << endl;
 		Tango::Except::throw_exception
 		((const char *)"ErrorOpeningFile",
 		o.str(),
 		(const char *)"LinacSeqThread::macro_LOAD_SETTINGS()");
	}
	// read the file
	char stringtmp[40];
	if(fgets(stringtmp,38,configfile) == NULL)
	{
		ERROR_STREAM << "fgets error:" << strerror(errno) << endl;
	}
	printf("fgets return that : %s\n",stringtmp);
	if(strcmp(stringtmp,"#        ###   #     #    #     #####") == 0)
	{
		// New file format
		cout << "FORMAT OK" << endl;
		val = getValFromFile(filename.c_str(),defaultVal);
		if(val == NULL)
		{
			Tango::Except::throw_exception
			((const char *)"ErrorreadingFile",
			 (const char *)"Can't read File: Bad syntax",
			 (const char *)"LinacSeqThread::macro_LOAD_SETTINGS()");
		}
	}
	else
	{
		fclose(configfile);
		 Tango::Except::throw_exception
		((const char *)"ErrorreadingFile",
		 (const char *)"Can't read: bad file format",
		 (const char *)"LinacSeqThread::macro_LOAD_SETTINGS()");
	}

	// close the file
	fclose(configfile);

	// theses values will be used as default values in the future
	defaultVal = *val;

	// // change the file attribute
// 	*attr_File_read = new char[strlen(argin)+1];
// 	strcpy(*attr_File_read,argin);
// 	// Save the file name in the property startfile
// 	Tango::DbData data;
// 	data.clear();
// 	data.push_back(Tango::DbDatum("startfile"));
// 	data[0] << argin;
// 	get_db_device()->put_property(data);

	// debug trace to check the values read :
#define PRINT_DEBUG
#ifdef PRINT_DEBUG
//	printf( "SRCT limit\t%.3f mA\n",val->srct_limit);
	printf( "Focus KLY1_1\t%.3f A\n",val->focus_klyst1[0]);
   printf( "Focus KLY1_2\t%.3f A\n",val->focus_klyst1[1]);
   printf( "Focus KLY1_3\t%.3f A\n",val->focus_klyst1[2]);
   printf( "Focus KLY2_1\t%.3f A\n",val->focus_klyst2[0]);
   printf( "Focus KLY2_2\t%.3f A\n",val->focus_klyst2[1]);
   printf( "Focus KLY2_3\t%.3f A\n",val->focus_klyst2[2]);
   printf( "B1 coil\t\t%.3f A\n",val->focus_beam1[0]);
   printf( "B2 coil\t\t%.3f A\n",val->focus_beam1[1]);
   printf( "* B3 coil\t\t%.3f A\n",val->focus_beam1[6]);
   printf( "* B4 coil\t\t%.3f A\n",val->focus_beam1[7]);
   printf( "Buncher Solenoid %.3f A\n",val->focus_beam1[2]);
   printf( "Magnetic lens\t%.3f A\n",val->focus_beam1[3]);
   printf( "Triplet\t\t%.3f A\n",val->focus_beam1[4]);
   printf( "S1 solenoid\t%.3f A\n",val->focus_beam2[0]);
   printf( "S2 solenoid\t%.3f A\n",val->focus_beam2[1]);
   printf( "* ELIN/STEER/GH1\t%.3f A\n",val->steer_beam[0]);
   printf( "* ELIN/STEER/GV1\t%.3f A\n",val->steer_beam[1]);
   printf( "steer 2\t%.3f A\n",val->steer_beam[2]);
   printf( "steer 3\t%.3f A\n",val->steer_beam[3]);
   printf( "steer 4\t%.3f A\n",val->steer_beam[4]);
   printf( "steer 5\t%.3f A\n",val->steer_beam[5]);
   printf( "steer 6\t%.3f A\n",val->steer_beam[6]);
   printf( "steer 7\t%.3f A\n",val->steer_beam[7]);
   printf( "steer 8\t%.3f A\n",val->steer_beam[8]);
   printf( "steer 9\t%.3f A\n",val->steer_beam[9]);
   printf( "steer 10 %.3f A\n",val->steer_beam[10]);
   printf( "steer 11\t%.3f A\n",val->steer_beam[11]);
   printf( "steer 12\t%.3f A\n",val->steer_beam[12]);
   printf( "steer 13\t%.3f A\n",val->steer_beam[13]);
   printf( "steer 14\t%.3f A\n",val->steer_beam[14]);
   printf( "steer 15 %.3f A\n",val->steer_beam[15]);

   printf( "* ELIN/STEER/GH2 16 %.3f A\n",val->steer_beam[16]);
   printf( "* ELIN/STEER/GV2 17\t%.3f A\n",val->steer_beam[17]);
   printf( "* ELIN/STEER/GH3 18\t%.3f A\n",val->steer_beam[18]);
   printf( "* ELIN/STEER/GV3 19\t%.3f A\n",val->steer_beam[19]);
   printf( "* ELIN/STEER/GH4 20\t%.3f A\n",val->steer_beam[20]);
   printf( "* ELIN/STEER/GV4 21 %.3f A\n",val->steer_beam[21]);

   printf( "mod 1 hv \t%.3f kV\n",val->mod_hv_v[0]);
   printf( "mod 2 hv \t%.3f kV\n",val->mod_hv_v[1]);
   printf( "vpfn1\t\t%.3f kV\n",val->vpfn[0]);
   printf( "vpfn2\t\t%.3f kV\n",val->vpfn[1]);
   printf( "buncher phase\t%.1f deg\n",val->bunch_phase);
   printf( "pbuncher phase\t%.1f deg\n",val->pbunch_phase);
   printf( "pbuncher atten\t%.1f %%\n",val->pbunch_atten);
   printf( "section phase\t%.1f deg\n",val->section_phase);
   printf( "* gun heating v\t%.3f V\n",val->gun_heating_v);
   printf( "* gun grid v\t%.3f V\n",val->gun_grid_v);
   printf( "* gun pulse v\t%.2f V\n",val->gun_pulse_v);
   printf( "gun pulse leng\t%.2f �m\n",val->gun_pulse_l);
   printf( "gun hv\t%.2f kV\n",val->gun_hv_v);
   printf( "frequency\t%.2f MHz\n",val->frequency);
   if(val->short_pulse == false)
		printf("Long pulse\n");
   else
		printf("Short pulse\n");
	if(val->r352 == false)
		printf("352Mhz OFF\n");
	else
		printf("352Mhz ON\n");
   printf( "timer rf\t%.2f �s\n",val->timer_rf);
   printf( "timer mod1\t%.2f �s\n",val->timer_mod[0]);
   printf( "timer mod2\t%.2f �s\n",val->timer_mod[1]);
   printf( "timer mod1_s\t%.2f �s\n",val->timer_mod_s[0]);
   printf( "timer mod2_s\t%.2f �s\n",val->timer_mod_s[1]);
#endif /* PRINT_DEBUG */


	write_history ("Loading all the settings...");
	// Apply all the setting points

	/************************************************
	 * Set value of analog output devices
 	************************************************/
	write_history("Set the Modulator 1 High Voltage");
	if(set_double_value(mod1_HV,"HighVoltage",(Tango::DevDouble)val->mod_hv_v[0],false) == false)
		nberrors++;
	check_abort();
	write_history("Set the Modulator 2 High Voltage");
	if(set_double_value(mod2_HV,"HighVoltage",(Tango::DevDouble)val->mod_hv_v[1],false) == false)
		nberrors++;
	check_abort();
	write_history("Set the Modulator 1 VPFN");
	if(set_double_value(mod1,"VPFN",(Tango::DevDouble)val->vpfn[0],false) == false)
		nberrors++;
	check_abort();
	write_history("Set the Modulator 2 VPFN");
	if(set_double_value(mod2,"VPFN",(Tango::DevDouble)val->vpfn[1],false) == false)
		nberrors++;
	check_abort();
	write_history("Set the Buncher Phase");
	if(set_double_value(rf_run,"BunchPhase",(Tango::DevDouble)val->bunch_phase,false) == false)
		nberrors++;
	sleep(1);
	check_abort();
	write_history("Set the Pre-buncher phase");
	if(set_double_value(rf_run,"PBunchPhase",(Tango::DevDouble)val->pbunch_phase,false) == false)
		nberrors++;
	check_abort();
	write_history("Set the Pre-buncher attenuation");
	if(set_double_value(rf_run,"PBunchAttenu",(Tango::DevDouble)val->pbunch_atten,false) == false)
		nberrors++;
	check_abort();
	write_history("Set the Section2 Phase");
	if(set_double_value(rf_run,"Sect2Phase",(Tango::DevDouble)val->section_phase,false) == false)
		nberrors++;
	check_abort();

	/*
		 Voltage for Gun Heating, Grid and Pulse are sent via gun and gun_aux. This is needed for
		 negative GridVoltage conversion, and correct set Points on elin/beam/run device.
	*/
	write_history("Set the Gun Pulse Voltage");
	if(set_double_value(gun,"PulseV",(Tango::DevDouble)val->gun_pulse_v,false) == false)
		nberrors++;
	check_abort();

	write_history("Set the Gun Grid Voltage");
	if(set_double_value(gun,"GridV",(Tango::DevDouble)val->gun_grid_v,false) == false)
		nberrors++;
	check_abort();

	write_history("Set the GunAux Heating Voltage");
	if(set_double_value(gun_aux,"HeatV",(Tango::DevDouble)val->gun_heating_v,false) == false)
		nberrors++;
	check_abort();


	write_history("Set the Gun pulse length");
	if(set_double_value(gun,"PulseL",(Tango::DevDouble)val->gun_pulse_l,false) == false)
		nberrors++;
	check_abort();
	write_history("Set the Gun High Voltage");
	if(set_double_value(gun_HV,"HighVoltage",(Tango::DevDouble)val->gun_hv_v,false) == false)
		nberrors++;
	check_abort();
	write_history("Set the RF Frequency");
	if(set_double_value(rf_run,"Frequency",val->frequency,false) == false)
	nberrors++;
	check_abort();

	if(val->short_pulse == false)
	{
		write_history("Switch in long pulse mode");
		if(set_string_value(gun,"PulseType","LONG",false) == false) // Long pulse
			nberrors++;
    }
	else
	{
		write_history("Switch in short pulse mode");
		if(set_string_value(gun,"PulseType","SHORT",false) == false) // Short pulse
			nberrors++;
	}
	check_abort();
///////// do not switch the 352MHz in macro LOAD SETTINGS
// 	if(val->r352 == false)
// 	{
// 		write_history("Switch off 352Mhz");
// 		if(set_bool_value(gun,"In352Mhz",false,false) == false) // 352Mhz OFF
//				nberrors++;
// 	}
// 	else
// 	{
// 		write_history("Switch on 352Mhz");
// 		if(set_bool_value(gun,"In352Mhz",true,false) == false) // 352Mhz ON
//				nberrors++;
// 	}
// 	sleep(1);
// 	check_abort();
	/************************************************
	 * Set values of timers
	 ************************************************/
	write_history("Set the RF delay");
	if(set_double_value(rf_run,"Delay",(Tango::DevDouble)val->timer_rf,false) == false)
		nberrors++;
	check_abort();
	write_history("Set the Modulator 1 delay");
	if(set_double_value(mod1,"Delay",(Tango::DevDouble)val->timer_mod[0],false) == false)
		nberrors++;
	check_abort();
	write_history("Set the Modulator 2 delay");
	if(set_double_value(mod2,"Delay",(Tango::DevDouble)val->timer_mod[1],false) == false)
		nberrors++;
	check_abort();
	write_history("Set the Modulator 1 delay s");
	if(set_double_value(mod1,"DelayS",(Tango::DevDouble)val->timer_mod_s[0],false) == false)
		nberrors++;
	check_abort();
	write_history("Set the Modulator 2 delay s");
	if(set_double_value(mod2,"DelayS",(Tango::DevDouble)val->timer_mod_s[1],false) == false)
		nberrors++;
	check_abort();
	/************************************************
	 * Test the state of the ELIN/RF/RUN device
	 ************************************************/
// 	if(rf_run_state==Tango::ON)
// 	{
		/************************************************
		 * Set values of focussing devices
 		 ************************************************/

		set_current.clear();
		for(int i=0;i<3;i++)
			set_current.push_back(val->focus_klyst1[i]);
		write_history("Set the Klystron 1 focussing currents");
		if(set_dev_double_array(focus_klystron1,"Current",set_current,false) == false)
			nberrors++;
		set_current.clear();
		for(int i=0;i<3;i++)
			set_current.push_back(val->focus_klyst2[i]);
		write_history("Set the Klystron 2 focussing currents");
		if(set_dev_double_array(focus_klystron2,"Current",set_current,false) == false)
			nberrors++;
		sleep(1);
		set_current.clear();

		// B1B2 in focus_beam1[0] ..[1] are now handled by focusB1B4 (elin/b1b4/all)
		// Vedder: 14 June 2010: Changed i<6 to i<5 since elin/focus/spare
		// channel has been removed from elin/focus/beam1 properties in
		// BruckerMch/beam. It's value was previously stored in val->focus_beam1[5].
		for(int i=2;i<5;i++)
			set_current.push_back(val->focus_beam1[i]);
		check_abort();
		write_history("Set the Beam1 focussing currents");
		if(set_dev_double_array(focus_beam1,"Current",set_current,false) == false)
			nberrors++;
		check_abort();

		// Set B1B4 current value.
		set_current.clear();
		set_current.push_back(val->focus_beam1[0]);
		set_current.push_back(val->focus_beam1[1]);
		set_current.push_back(val->focus_beam1[6]);
		set_current.push_back(val->focus_beam1[7]);

		write_history("Set the gun focus (B1-B4 coils) focussing currents");
		if(set_dev_double_array(gun_focus_b1b4_tdk, "Current", set_current, false) == false)
			nberrors++;
		check_abort();

		set_current.clear();
		for(int i=0;i<2;i++)
			set_current.push_back(val->focus_beam2[i]);
		check_abort();
		write_history("Set the Beam2 focussing currents");
		if(set_dev_double_array(focus_beam2,"Current",set_current,false) == false)
			nberrors++;


		/*
			Do not push steer_beam[0] steer_beam[1]	anymore. These value are now handled by
			TDKLambda / GunSteerer device server.
		*/
		set_current.clear();
		for(int i=2;i<16;i++)
			set_current.push_back(val->steer_beam[i]);
		check_abort();
		write_history("Set the Brucker Steering currents");
		if(set_dev_double_array(focus_steer,"Current",set_current,false) == false)
			nberrors++;


		/*
			Set steer_beam[0], steer_beam[1] + steer_beam[16-19] corresponding to :

				-elin/steer/gh1
				-elin/steer/gv1
				-elin/steer/gh2
				-elin/steer/gv2
				-elin/steer/gh3
				-elin/steer/gv3

			Order is important and MUST follow elin/steer/gun DeviceList device property !
		*/
		set_current.clear();
		set_current.push_back(val->steer_beam[0]);
		set_current.push_back(val->steer_beam[1]);
		set_current.push_back(val->steer_beam[16]);
		set_current.push_back(val->steer_beam[17]);
		set_current.push_back(val->steer_beam[18]);
		set_current.push_back(val->steer_beam[19]);
		write_history("Set the TDKLambda Steering currents");
		if(set_dev_double_array(gun_steerer_tdk,"Current",set_current,false) == false)
			nberrors++;


		/*
			Set steer_beam[20-21] corresponding to :

				-elin/steer/gh4
				-elin/steer/gv4

			Order is important and MUST follow elin/steer/pbunch DeviceList device property !
		*/
		set_current.clear();
		set_current.push_back(val->steer_beam[20]);
		set_current.push_back(val->steer_beam[21]);
		write_history("Set the TDKLambda PreBuncher Steering currents");
		if(set_dev_double_array(prebuncher_steerer_tdk,"Current",set_current,false) == false)
			nberrors++;


//	}

	write_history("End of config file selection");
	defaultVal = *val;
	if(nberrors > 0)
	{
		{
			omni_mutex_lock l(mutex);
			seq_obj->error = true;
		}
		write_history("Sequence failed with errors !");
		INFO_STREAM << ">>>> LinacThread LOAD SETTINGS sequence ended with " << nberrors << " errors !" << endl;
	}
	else
	{
		{
			omni_mutex_lock l(mutex);
			seq_obj->isFileLoaded = true;
		}
		INFO_STREAM << ">>>> LinacThread LOAD SETTINGS sequence ended successfully!" << endl;
	}
#endif /* SIMU */
}

  /////////////////////////////////////////////////////////////////////////////
 //                          MACRO SAVE SETTINGS                            //
/////////////////////////////////////////////////////////////////////////////
/*
	If the parameter warnInPlaceOfExcept is true : Each catched exception on read set points
	will generate a detailed entry into the sequence history, but won't generate 'general'
	exception that will cause the save to fail. This allow to force save in case of problem.

	If the parameter warnInPlaceOfExcept is false : Each catched exception on read set points
	will generate a simple entry into the sequence history, but will generate 'general' exception
	that will cause the save to fail. In case of problem the save cannot be done.

*/
void LinacSeqThread::macro_SAVE_SETTINGS(string filename, bool warnInPlaceOfExcept)
{
	int nberrors = 0;
	DEBUG_STREAM << ">>>> LinacThread SAVE SETTINGS sequence!" << endl;
	DEBUG_STREAM << ">>>> Filename = " << filename << endl;
	write_history ("Begin to save configuration");

	Tango::DevDouble tmpdoubleval;
	Tango::DevVarDoubleArray tmpvardoublearray;
	Tango::DevString strtmp;
	bool read_ok;


	/*
	 *	Read all new TDKLambda focusing elements SET POINTS via GetCurrentSetPoints.
	 */
	write_history("Reading TDKLambda focussing currents (b1-b4) set points.");
	read_ok = read_set_points(gun_focus_b1b4_tdk, "GetCurrentSetPoints", &tmpvardoublearray, false);
	if(read_ok)
	{
#ifndef SIMU

		// elin/focus/b1Coil...
		defaultVal.focus_beam1[0] = tmpvardoublearray[0];
		DEBUG_STREAM << "defaultVal.focus_beam1[0] = " << defaultVal.focus_beam1[0] << endl;

		// elin/focus/b2Coil...
		defaultVal.focus_beam1[1] = tmpvardoublearray[1];
		DEBUG_STREAM << "defaultVal.focus_beam1[1] = " << defaultVal.focus_beam1[1] << endl;

		// elin/focus/b3Coil...
		defaultVal.focus_beam1[6] = tmpvardoublearray[2];
		DEBUG_STREAM << "defaultVal.focus_beam1[6] = " << defaultVal.focus_beam1[6] << endl;

		// elin/focus/b4Coil...
		defaultVal.focus_beam1[7] = tmpvardoublearray[3];
		DEBUG_STREAM << "defaultVal.focus_beam1[7] = " << defaultVal.focus_beam1[7] << endl;

#endif
	}
	else
	{
		nberrors++;
		if (warnInPlaceOfExcept) WarnErrorReadingSetPoint("TDKLambda focussing currents (b1-b4)");
		else write_history("**** ERROR **** Could not read TDKLambda focussing currents (b1-b4) set points.");
	}
	check_abort();

	/*
	 *	Read new TDKLambda steering (gh1/gv1 to gh3/gv3) elements SET POINTS via GetCurrentSetPoints.
	 */
	write_history("Reading TDKLambda steerer (gh1/gv1 to gh3/gv3) currents set points.");
	read_ok = read_set_points(gun_steerer_tdk, "GetCurrentSetPoints", &tmpvardoublearray, false);
	if(read_ok)
	{
#ifndef SIMU

		// elin/steer/gh1
		defaultVal.steer_beam[0] = tmpvardoublearray[0];
		DEBUG_STREAM << "defaultVal.steer_beam[0] = " << defaultVal.steer_beam[0] << endl;

		// elin/steer/gv1
		defaultVal.steer_beam[1] = tmpvardoublearray[1];
		DEBUG_STREAM << "defaultVal.steer_beam[1] = " << defaultVal.steer_beam[1] << endl;

		// elin/steer/gh2
		defaultVal.steer_beam[16] = tmpvardoublearray[2];
		DEBUG_STREAM << "defaultVal.steer_beam[16] = " << defaultVal.steer_beam[16] << endl;

		// elin/steer/gv2
		defaultVal.steer_beam[17] = tmpvardoublearray[3];
		DEBUG_STREAM << "defaultVal.steer_beam[17] = " << defaultVal.steer_beam[17] << endl;

		// elin/steer/gh3
		defaultVal.steer_beam[18] = tmpvardoublearray[4];
		DEBUG_STREAM << "defaultVal.steer_beam[18] = " << defaultVal.steer_beam[18] << endl;

		// elin/steer/gv3
		defaultVal.steer_beam[19] = tmpvardoublearray[5];
		DEBUG_STREAM << "defaultVal.steer_beam[19] = " << defaultVal.steer_beam[19] << endl;

#endif
	}
	else
	{
		nberrors++;
		if (warnInPlaceOfExcept) WarnErrorReadingSetPoint("TDKLambda steerer (gh1/gv1 to gh3/gv3)");
		else write_history("**** ERROR **** Could not read TDKLambda steerer (gh1/gv1 to gh3/gv3) currents set points.");

	}
	check_abort();

	/*
	 *	Read new TDKLambda steering (gh4/gv4) elements SET POINTS via GetCurrentSetPoints.
	 */
	write_history("Reading TDKLambda Pre-Buncher steerer (gh4/gv4) currents set points.");
	read_ok = read_set_points(prebuncher_steerer_tdk, "GetCurrentSetPoints", &tmpvardoublearray, false);
	if(read_ok)
	{
#ifndef SIMU

		// elin/steer/gh4
		defaultVal.steer_beam[20] = tmpvardoublearray[0];
		DEBUG_STREAM << "defaultVal.steer_beam[20] = " << defaultVal.steer_beam[20] << endl;

		// elin/steer/gv4
		defaultVal.steer_beam[21] = tmpvardoublearray[1];
		DEBUG_STREAM << "defaultVal.steer_beam[21] = " << defaultVal.steer_beam[21] << endl;
#endif
	}
	else
	{
		nberrors++;

		if (warnInPlaceOfExcept) WarnErrorReadingSetPoint("TDKLambda Pre-Buncher steerer (gh4/gv4)");
		else write_history("**** ERROR **** Could not read TDKLambda Pre-Buncher steerer (gh4/gv4) currents set points.");
	}
	check_abort();


	/***********************************************************************************************
	 *	Read new TDKLambda gun Heating, Grid and Pulse voltage SET POINTS via Gun/GunAux High level
	 *  device servers. It's necessary for coherence and gridV voltage conversion (negative).
	 ***********************************************************************************************/
	write_history("Reading GunAux  Heating voltage set point");
	read_ok = read_double_set_point(gun_aux,"HeatV",&tmpdoubleval,false);
	if(read_ok)
	{
		defaultVal.gun_heating_v = tmpdoubleval;
		DEBUG_STREAM << ">>>> gun heating = " << defaultVal.gun_heating_v << endl;
	}
	else
	{
		nberrors++;
		if (warnInPlaceOfExcept) WarnErrorReadingSetPoint("GunAux  Heating voltage");
		else write_history("**** ERROR **** Could not read GunAux  Heating voltage set point");
	}
	check_abort();

	write_history("Reading Gun  Pulse voltage set point");
	read_ok = read_double_set_point(gun,"PulseV",&tmpdoubleval,false);
	if(read_ok)
	{
		defaultVal.gun_pulse_v = tmpdoubleval;
		DEBUG_STREAM << ">>>> gun Pulse voltage = " << defaultVal.gun_pulse_v << endl;
	}
	else
	{
		nberrors++;
		if (warnInPlaceOfExcept) WarnErrorReadingSetPoint("Gun Pulse voltage");
		else write_history("**** ERROR **** Could not read Gun  Pulse voltage set point");
	}
	check_abort();

	write_history("Reading Gun  Grid voltage set point");
	read_ok = read_double_set_point(gun,"GridV",&tmpdoubleval,false);
	if(read_ok)
	{
		defaultVal.gun_grid_v = tmpdoubleval;
		DEBUG_STREAM << ">>>> gun Grid voltage = " << defaultVal.gun_grid_v << endl;
	}
	else
	{
		nberrors++;
		if (warnInPlaceOfExcept) WarnErrorReadingSetPoint("Gun Grid voltage");
		else write_history("**** ERROR **** Could not read Gun  Grid voltage set point");
	}
	check_abort();

	// read all the set points ...
	write_history("Reading Klystron 1 focussing currents set point");
	// Focus Klystron 1
	read_ok = read_set_points(focus_klystron1,"GetCurrentSetPoints",&tmpvardoublearray,false);
	if(read_ok)
	{
#ifndef SIMU
		for(int i=0; i<3; i++)
		{
			defaultVal.focus_klyst1[i] = tmpvardoublearray[i];
			DEBUG_STREAM << "defaultVal.focus_klyst1[" << i << "] = " << defaultVal.focus_klyst1[i] << endl;
		}
#endif
	}
	else
	{
		nberrors++;
		if (warnInPlaceOfExcept) WarnErrorReadingSetPoint("klystron 1 focussing");
		else write_history("**** ERROR **** Could not read klystron 1 focussing set currents");
	}
	check_abort();
	// Focus Klystron 2
	write_history("Reading Klystron 2 focussing currents set point");
	read_ok = read_set_points(focus_klystron2,"GetCurrentSetPoints",&tmpvardoublearray,false);
	if(read_ok)
	{
#ifndef SIMU
		for(int i=0; i<3; i++)
		{
			defaultVal.focus_klyst2[i] = tmpvardoublearray[i];
			DEBUG_STREAM << "defaultVal.focus_klyst2[" << i << "] = " << defaultVal.focus_klyst2[i] << endl;
		}
#endif
	}
	else
	{
		nberrors++;
		if (warnInPlaceOfExcept) WarnErrorReadingSetPoint("klystron 2 focussing");
		else write_history("**** ERROR **** Could not read klystron 2 focussing set currents");
	}
	check_abort();

	// Focus Beam1
	write_history("Reading Beam1 Brucker focussing currents set point");
	read_ok = read_set_points(focus_beam1,"GetCurrentSetPoints",&tmpvardoublearray,false);
	if(read_ok)
	{
#ifndef SIMU

		// Vedder: 14 June 2010: Changed i<4 to i<3 since elin/focus/spare
		// channel has been removed from elin/focus/beam1 properties in
		// BruckerMch/beam. It's value was previously stored in val->focus_beam1[5].
		for(int i=0; i<3; i++)
		{
			// 2 Brucker were replaced with zup. focus_beam[0-1] and focus_beam[6-7] are taken another device (gun_focus_b1b4_tdk).
			// Brucker values are stored in focus_beam1[2-5] now.
			defaultVal.focus_beam1[i+2] = tmpvardoublearray[i];
			DEBUG_STREAM << "defaultVal.focus_beam1[" << i << "] = " << defaultVal.focus_beam1[i] << endl;
			//cout << "focus beam["<< i + 2 << "]" << defaultVal.focus_beam1[i+2] << endl;
		}
#endif
	}
	else
	{
		nberrors++;
		if (warnInPlaceOfExcept) WarnErrorReadingSetPoint("beam1 focussing");
		else write_history("**** ERROR **** Could not read beam1 focussing set currents");
	}
	check_abort();

	// Focus Beam2
	write_history("Reading Beam2 focussing currents set point");
	read_ok = read_set_points(focus_beam2,"GetCurrentSetPoints",&tmpvardoublearray,false);
	if(read_ok)
	{
#ifndef SIMU
		defaultVal.focus_beam2[0] = tmpvardoublearray[0];
		defaultVal.focus_beam2[1] = tmpvardoublearray[1];
		DEBUG_STREAM << "defaultVal.focus_beam2[0] = " << defaultVal.focus_beam2[0] << endl;
		DEBUG_STREAM << "defaultVal.focus_beam2[1] = " << defaultVal.focus_beam2[1] << endl;
#endif
	}
	else
	{
		nberrors++;
		if (warnInPlaceOfExcept) WarnErrorReadingSetPoint("beam2 focussing");
		else write_history("**** ERROR **** Could not read beam2 focussing set currents");
	}
	check_abort();

	// steer beam
	write_history("Reading Steerers (Brucker) currents set point");
	read_ok = read_set_points(focus_steer,"GetCurrentSetPoints",&tmpvardoublearray,false);
	if(read_ok)
	{
#ifndef SIMU
		for(int i=0; i<14; i++)
		{
			// Two first Brucker were replaced with TDKLambda zup power supply.
			// So now they are 14 instead of 16 and start at index 2 of steer_beem array.
			defaultVal.steer_beam[i+2] = tmpvardoublearray[i];
			DEBUG_STREAM << "defaultVal.steer_beam[" << i << "] = " << defaultVal.steer_beam[i] << endl;
		}
#endif
	}
	else
	{
		nberrors++;
		if (warnInPlaceOfExcept) WarnErrorReadingSetPoint("steerers (Brucker)");
		else write_history("**** ERROR **** Could not read steerers (Brucker) set currents");
	}
	check_abort();

	// Modulators HV
	write_history("Reading Modulator 1 high voltage set point");
	read_ok = read_double_set_point(mod1_HV,"HighVoltage",&tmpdoubleval,false);
	if(read_ok)
	{
#ifndef SIMU
		defaultVal.mod_hv_v[0] = tmpdoubleval;
		DEBUG_STREAM << ">>>> mod 1 hv = " << defaultVal.mod_hv_v[0] << endl;
#endif
	}
	else
	{
		nberrors++;
		if (warnInPlaceOfExcept) WarnErrorReadingSetPoint("Modulator 1 high voltage");
		else write_history("**** ERROR **** Could not read Modulator 1 high voltage set point");
	}
	check_abort();

	write_history("Reading Modulator 2 high voltage set point");
	read_ok = read_double_set_point(mod2_HV,"HighVoltage",&tmpdoubleval,false);
	if(read_ok)
	{
#ifndef SIMU
		defaultVal.mod_hv_v[1] = tmpdoubleval;
		DEBUG_STREAM << ">>>> mod 2 hv = " << defaultVal.mod_hv_v[1] << endl;
#endif
	}
	else
	{
		nberrors++;
		if (warnInPlaceOfExcept) WarnErrorReadingSetPoint("Modulator 2 high voltage");
		else write_history("**** ERROR **** Could not read Modulator 2 high voltage set point");
	}

	// VPFN
	check_abort();
	write_history("Reading Modulator 1 VPFN set point");
	read_ok = read_double_set_point(mod1,"VPFN",&tmpdoubleval,false);
	if(read_ok)
	{
#ifndef SIMU
		defaultVal.vpfn[0] = tmpdoubleval;
		DEBUG_STREAM << ">>>> mod 1 VPFN = " << defaultVal.vpfn[0] << endl;
#endif
	}
	else
	{
		nberrors++;
		if (warnInPlaceOfExcept) WarnErrorReadingSetPoint("Modulator 1 VPFN");
		else write_history("**** ERROR **** Could not read Modulator 1 VPFN set point");
	}
	check_abort();

	write_history("Reading Modulator 2 VPFN set point");
	read_ok = read_double_set_point(mod2,"VPFN",&tmpdoubleval,false);
	if(read_ok)
	{
#ifndef SIMU
		defaultVal.vpfn[1] = tmpdoubleval;
		DEBUG_STREAM << ">>>> mod 2 VPFN = " << defaultVal.vpfn[1] << endl;
#endif
	}
	else
	{
		nberrors++;
		if (warnInPlaceOfExcept) WarnErrorReadingSetPoint("Modulator 2 VPFN");
		else write_history("**** ERROR **** Could not read Modulator 2 VPFN set point");
	}

	// Buncher Phase
	check_abort();
	write_history("Reading Buncher phase set point");
	read_ok = read_double_set_point(rf_run,"BunchPhase",&tmpdoubleval,false);
	if(read_ok)
	{
#ifndef SIMU
		defaultVal.bunch_phase = tmpdoubleval;
		DEBUG_STREAM << ">>>> Buncher Phase = " << defaultVal.bunch_phase << endl;
#endif
	}
	else
	{
		nberrors++;
		if (warnInPlaceOfExcept) WarnErrorReadingSetPoint("Buncher phase");
		else write_history("**** ERROR **** Could not read Buncher phase set point");
	}

	// PreBuncher Phase
	check_abort();
	write_history("Reading Pre-buncher phase set point");
	read_ok = read_double_set_point(rf_run,"PBunchPhase",&tmpdoubleval,false);
	if(read_ok)
	{
#ifndef SIMU
		defaultVal.pbunch_phase = tmpdoubleval;
		DEBUG_STREAM << ">>>> PreBuncher Phase = " << defaultVal.pbunch_phase << endl;
#endif
	}
	else
	{
		nberrors++;
		if (warnInPlaceOfExcept) WarnErrorReadingSetPoint("Pre-Buncher phase");
		else write_history("**** ERROR **** Could not read Pre-Buncher phase set point");
	}

	// PreBuncher Attenuation
	check_abort();
	write_history("Reading Pre-buncher attenuation set point");
	read_ok = read_double_set_point(rf_run,"PBunchAttenu",&tmpdoubleval,false);
	if(read_ok)
	{
#ifndef SIMU
		defaultVal.pbunch_atten = tmpdoubleval;
		DEBUG_STREAM << ">>>> PreBuncher Attenuation = " << defaultVal.pbunch_atten << endl;
#endif
	}
	else
	{
		nberrors++;
		if (warnInPlaceOfExcept) WarnErrorReadingSetPoint("Pre-Buncher attenuation");
		else write_history("**** ERROR **** Could not read Pre-buncher attenuation set point");
	}

	// Section Phase
	check_abort();
	write_history("Reading Section 2 phase set point");
	read_ok = read_double_set_point(rf_run,"Sect2Phase",&tmpdoubleval,false);
	if(read_ok)
	{
#ifndef SIMU
		defaultVal.section_phase = tmpdoubleval;
		DEBUG_STREAM << ">>>> section Phase = " << defaultVal.section_phase << endl;
#endif
	}
	else
	{
		nberrors++;
		if (warnInPlaceOfExcept) WarnErrorReadingSetPoint("Section phase");
		else write_history("**** ERROR **** Could not read Section phase set point");
	}

	// Pulse Length
	check_abort();
	write_history("Reading Gun pulse length set point");
	read_ok = read_double_set_point(gun,"PulseL",&tmpdoubleval,false);
	if(read_ok)
	{
#ifndef SIMU
		defaultVal.gun_pulse_l = tmpdoubleval;
		DEBUG_STREAM << ">>>> Gun Pulse Length = " << defaultVal.gun_pulse_l << endl;
#endif
	}
	else
	{
		nberrors++;
		if (warnInPlaceOfExcept) WarnErrorReadingSetPoint("Gun pulse length");
		else write_history("**** ERROR **** Could not read Gun pulse length set point");
	}

	// Gun HV
	check_abort();
	write_history("Reading Gun high voltage set point");
	read_ok = read_double_set_point(gun_HV,"HighVoltage",&tmpdoubleval,false);
	if(read_ok)
	{
#ifndef SIMU
		defaultVal.gun_hv_v = tmpdoubleval;
		DEBUG_STREAM << ">>>> Gun HV = " << defaultVal.gun_hv_v << endl;
#endif
	}
	else
	{
		nberrors++;
		if (warnInPlaceOfExcept) WarnErrorReadingSetPoint("Gun high voltage");
		else write_history("**** ERROR **** Could not read Gun high voltage set point");
	}

	// Frequency
	check_abort();
	write_history("Reading RF frequency set point");
	read_ok = read_double_set_point(rf_run,"Frequency",&tmpdoubleval,false);
	if(read_ok)
	{
		printf("---------------> frequency = %.6lf\n",tmpdoubleval);
#ifndef SIMU
		defaultVal.frequency = tmpdoubleval;
		//DEBUG_STREAM << ">>>> Frequency = " << (defaultVal.frequency/1e6)*3 << " MHz" << endl;
#endif
	}
	else
	{
		nberrors++;
		if (warnInPlaceOfExcept) WarnErrorReadingSetPoint("RF frequency");
		else write_history("**** ERROR **** Could not read RF frequency set point");
	}

	// Pulse Type
	check_abort();
	write_history("Reading Short/Long pulse mode set point");
	read_ok = read_string_set_point(gun,"PulseType",&strtmp,false);
	if(read_ok)
	{
#ifndef SIMU
		if(strcasecmp(strtmp,"LONG") == 0)
			defaultVal.short_pulse = false;
		else
			defaultVal.short_pulse = true;
#endif
		DEBUG_STREAM << ">>>> Pulse Type = " << strtmp << endl;
		CORBA::string_free(strtmp);
	}
	else
	{
		nberrors++;
		if (warnInPlaceOfExcept) WarnErrorReadingSetPoint("Short/long pulse mode");
		else write_history("**** ERROR **** Could not read Short/long pulse mode");
	}

	// RF Delay
	check_abort();
	write_history("Reading RF timer set point");
	read_ok = read_double_set_point(rf_run,"Delay",&tmpdoubleval,false);
	if(read_ok)
	{
#ifndef SIMU
		defaultVal.timer_rf = tmpdoubleval;
		DEBUG_STREAM << ">>>> Timer RF = " << defaultVal.timer_rf << endl;
#endif
	}
	else
	{
		nberrors++;
		if (warnInPlaceOfExcept) WarnErrorReadingSetPoint("RF Delay");
		else write_history("**** ERROR **** Could not read RF Delay set point");
	}

	// MOD 1 Delay
	check_abort();
	write_history("Reading Modulator 1 timer set point");
	read_ok = read_double_set_point(mod1,"Delay",&tmpdoubleval,false);
	if(read_ok)
	{
#ifndef SIMU
		defaultVal.timer_mod[0] = tmpdoubleval;
		DEBUG_STREAM << ">>>> Timer Modulator 1 = " << defaultVal.timer_mod[0] << endl;
#endif
	}
	else
	{
		nberrors++;
		if (warnInPlaceOfExcept) WarnErrorReadingSetPoint("Modulator 1 Delay");
		else write_history("**** ERROR **** Could not read Modulator 1 Delay set point");
	}

	// MOD 2 Delay
	check_abort();
	write_history("Reading Modulator 2 timer set point");
	read_ok = read_double_set_point(mod2,"Delay",&tmpdoubleval,false);
	if(read_ok)
	{
#ifndef SIMU
		defaultVal.timer_mod[1] = tmpdoubleval;
		DEBUG_STREAM << ">>>> Timer Modulator 2 = " << defaultVal.timer_mod[1] << endl;
#endif
	}
	else
	{
		nberrors++;
		if (warnInPlaceOfExcept) WarnErrorReadingSetPoint("Modulator 2 Delay");
		else write_history("**** ERROR **** Could not read Modulator 2 Delay set point");
	}

	// MOD 1 DelayS
	check_abort();
	write_history("Reading Modulator 1 timer s set point");
	read_ok = read_double_set_point(mod1,"DelayS",&tmpdoubleval,false);
	if(read_ok)
	{
#ifndef SIMU
		defaultVal.timer_mod_s[0] = tmpdoubleval;
		DEBUG_STREAM << ">>>> Timer Modulator S1 = " << defaultVal.timer_mod_s[0] << endl;
#endif
	}
	else
	{
		nberrors++;
		if (warnInPlaceOfExcept) WarnErrorReadingSetPoint("Modulator 1 Delay S");
		else write_history("**** ERROR **** Could not read Modulator 1 Delay S set point");
	}

	// MOD 2 DelayS
	check_abort();
	write_history("Reading Modulator 2 timer s set point");
	read_ok = read_double_set_point(mod2,"DelayS",&tmpdoubleval,false);
	if(read_ok)
	{
#ifndef SIMU
		defaultVal.timer_mod_s[1] = tmpdoubleval;
		DEBUG_STREAM << ">>>> Timer Modulator S2 = " << defaultVal.timer_mod_s[1] << endl;
#endif
	}
	else
	{
		nberrors++;
		if (warnInPlaceOfExcept) WarnErrorReadingSetPoint("Modulator 2 Delay S");
		else write_history("**** ERROR **** Could not read Modulator 2 Delay S set point");
	}
	check_abort();

	/* Throw an exception when there are errors and warnings do not replace Exception on read set points. */
	if((nberrors > 0) && (!warnInPlaceOfExcept))
	{
		write_history("**** ERROR  \tError(s) when reading set points !");
		write_history("**** WARNING\tThe file will not be saved");
		write_history("**** INFO   \t You can force the save with the command \"force save\"");
		Tango::Except::throw_exception
			((const char *)"ErrorReadingSetPoints",
			(const char *)"Error when reading the set points",
			(const char *)"LinacSeqThread::macro_SAVE_SETTINGS()");
	}

	string seqstatus = "Saving settings in file " + filename;
	write_history (seqstatus.c_str());
#ifndef SIMU
	// Save the settings in the file
	// Open the file
	// Error on file will always generate exception.
	if((configfile = fopen(filename.c_str(),"w")) == NULL)
	{
		write_history("Can't create the config file");
		TangoSys_OMemStream o;
		o << "can't open file " << filename << ":" << strerror(errno);
		ERROR_STREAM << o.str() << endl;
		Tango::Except::throw_exception
		((const char *)"ErrorOpeningFile",
		o.str(),
		(const char *)"LinacSeqThread::macro_SAVE_SETTINGS()");
	}
	// write settings in the file

	// ENTETE
	if(fprintf(configfile,"#        ###   #     #    #     #####\n") <= 0) exceptionWritingFile(filename.c_str());
	if(fprintf(configfile,"#         #    ##    #   # #   #     #\n") <= 0) exceptionWritingFile(filename.c_str());
	if(fprintf(configfile,"#         #    # #   #  #   #  #\n") <= 0)	exceptionWritingFile(filename.c_str());
	if(fprintf(configfile,"#         #    #  #  # #     # #\n") <= 0)	exceptionWritingFile(filename.c_str());
	if(fprintf(configfile,"#         #    #   # # ####### #\n") <= 0)	exceptionWritingFile(filename.c_str());
	if(fprintf(configfile,"#         #    #    ## #     # #     #\n") <= 0)	exceptionWritingFile(filename.c_str());
	if(fprintf(configfile,"#######  ###   #     # #     #  #####\n\n\n") <= 0)	exceptionWritingFile(filename.c_str());

	// save the settings in the file
	if(fprintf(configfile,"# Focus KLY1_1\t%.1f A\nelin/focus/kly1_1/current->__value:\t\t%.1f\n",defaultVal.focus_klyst1[0],defaultVal.focus_klyst1[0]) <= 0) exceptionWritingFile(filename.c_str());
	if(fprintf(configfile,"# Focus KLY1_2\t%.1f A\nelin/focus/kly1_2/current->__value:\t\t%.1f\n",defaultVal.focus_klyst1[1],defaultVal.focus_klyst1[1]) <= 0) exceptionWritingFile(filename.c_str());
	if(fprintf(configfile,"# Focus KLY1_3\t%.1f A\nelin/focus/kly1_3/current->__value:\t\t%.1f\n",defaultVal.focus_klyst1[2],defaultVal.focus_klyst1[2]) <= 0) exceptionWritingFile(filename.c_str());
	if(fprintf(configfile,"# Focus KLY2_1\t%.1f A\nelin/focus/kly2_1/current->__value:\t\t%.1f\n",defaultVal.focus_klyst2[0],defaultVal.focus_klyst2[0]) <= 0) exceptionWritingFile(filename.c_str());
	if(fprintf(configfile,"# Focus KLY2_2\t%.1f A\nelin/focus/kly2_2/current->__value:\t\t%.1f\n",defaultVal.focus_klyst2[1],defaultVal.focus_klyst2[1]) <= 0) exceptionWritingFile(filename.c_str());
	if(fprintf(configfile,"# Focus KLY2_3\t%.1f A\nelin/focus/kly2_3/current->__value:\t\t%.1f\n",defaultVal.focus_klyst2[2],defaultVal.focus_klyst2[2]) <= 0) exceptionWritingFile(filename.c_str());
	if(fprintf(configfile,"# B1 coil\t%.1f A\nelin/focus/b1coil/current->__value:\t\t%.2f\n",defaultVal.focus_beam1[0],defaultVal.focus_beam1[0]) <= 0) exceptionWritingFile(filename.c_str());
	if(fprintf(configfile,"# B2 coil\t%.1f A\nelin/focus/b2coil/current->__value:\t\t%.2f\n",defaultVal.focus_beam1[1],defaultVal.focus_beam1[1]) <= 0) exceptionWritingFile(filename.c_str());
	/* New B3-B4 */
	if(fprintf(configfile,"# B3 coil\t%.1f A\nelin/focus/b3coil/current->__value:\t\t%.2f\n",defaultVal.focus_beam1[6],defaultVal.focus_beam1[6]) <= 0) exceptionWritingFile(filename.c_str());
	if(fprintf(configfile,"# B4 coil\t%.1f A\nelin/focus/b4coil/current->__value:\t\t%.2f\n",defaultVal.focus_beam1[7],defaultVal.focus_beam1[7]) <= 0) exceptionWritingFile(filename.c_str());

	if(fprintf(configfile,"# Buncher Solenoid %.1f A\nelin/focus/buncher/current->__value:\t\t%.1f\n",defaultVal.focus_beam1[2],defaultVal.focus_beam1[2]) <= 0) exceptionWritingFile(filename.c_str());
	if(fprintf(configfile,"# Magnetic lens\t%.2f A\nelin/focus/lens/current->__value:\t\t%.2f\n",defaultVal.focus_beam1[3],defaultVal.focus_beam1[3]) <= 0) exceptionWritingFile(filename.c_str());
	if(fprintf(configfile,"# Triplet\t%.2f A\nelin/focus/triplet/current->__value:\t\t%.2f\n",defaultVal.focus_beam1[4],defaultVal.focus_beam1[4]) <= 0) exceptionWritingFile(filename.c_str());
	if(fprintf(configfile,"# S1 solenoid\t%.1f A\nelin/focus/sect1/current->__value:\t\t%.1f\n",defaultVal.focus_beam2[0],defaultVal.focus_beam2[0]) <= 0) exceptionWritingFile(filename.c_str());
	if(fprintf(configfile,"# S2 solenoid\t%.1f A\nelin/focus/sect2/current->__value:\t\t%.1f\n",defaultVal.focus_beam2[1],defaultVal.focus_beam2[1]) <= 0) exceptionWritingFile(filename.c_str());
	if(fprintf(configfile,"# ELIN/STEER/GH1\t%.2f A\nelin/steer/gh1/current->__value:\t\t%.2f\n",defaultVal.steer_beam[0],defaultVal.steer_beam[0]) <= 0) exceptionWritingFile(filename.c_str());
	if(fprintf(configfile,"# ELIN/STEER/GV1\t%.2f A\nelin/steer/gv1/current->__value:\t\t%.2f\n",defaultVal.steer_beam[1],defaultVal.steer_beam[1]) <= 0) exceptionWritingFile(filename.c_str());
	/* New GH2/GV2 - GH3/GV3 */
	if(fprintf(configfile,"# ELIN/STEER/GH2\t%.2f A\nelin/steer/gh2/current->__value:\t\t%.2f\n",defaultVal.steer_beam[16],defaultVal.steer_beam[16]) <= 0) exceptionWritingFile(filename.c_str());
	if(fprintf(configfile,"# ELIN/STEER/GV2\t%.2f A\nelin/steer/gv2/current->__value:\t\t%.2f\n",defaultVal.steer_beam[17],defaultVal.steer_beam[17]) <= 0) exceptionWritingFile(filename.c_str());
	if(fprintf(configfile,"# ELIN/STEER/GH3\t%.2f A\nelin/steer/gh3/current->__value:\t\t%.2f\n",defaultVal.steer_beam[18],defaultVal.steer_beam[18]) <= 0) exceptionWritingFile(filename.c_str());
	if(fprintf(configfile,"# ELIN/STEER/GV3\t%.2f A\nelin/steer/gv3/current->__value:\t\t%.2f\n",defaultVal.steer_beam[19],defaultVal.steer_beam[19]) <= 0) exceptionWritingFile(filename.c_str());

	/* New GH4/GV4 */
	if(fprintf(configfile,"# ELIN/STEER/GH4\t%.2f A\nelin/steer/gh4/current->__value:\t\t%.2f\n",defaultVal.steer_beam[20],defaultVal.steer_beam[20]) <= 0) exceptionWritingFile(filename.c_str());
	if(fprintf(configfile,"# ELIN/STEER/GV4\t%.2f A\nelin/steer/gv4/current->__value:\t\t%.2f\n",defaultVal.steer_beam[21],defaultVal.steer_beam[21]) <= 0) exceptionWritingFile(filename.c_str());

	if(fprintf(configfile,"# ELIN/STEER/BH1\t%.2f A\nelin/steer/bh1/current->__value:\t\t%.2f\n",defaultVal.steer_beam[2],defaultVal.steer_beam[2]) <= 0) exceptionWritingFile(filename.c_str());
	if(fprintf(configfile,"# ELIN/STEER/BV1\t%.2f A\nelin/steer/bv1/current->__value:\t\t%.2f\n",defaultVal.steer_beam[3],defaultVal.steer_beam[3]) <= 0) exceptionWritingFile(filename.c_str());
	if(fprintf(configfile,"# ELIN/STEER/BH2\t%.2f A\nelin/steer/bh2/current->__value:\t\t%.2f\n",defaultVal.steer_beam[4],defaultVal.steer_beam[4]) <= 0) exceptionWritingFile(filename.c_str());
	if(fprintf(configfile,"# ELIN/STEER/BV2\t%.2f A\nelin/steer/bv2/current->__value:\t\t%.2f\n",defaultVal.steer_beam[5],defaultVal.steer_beam[5]) <= 0) exceptionWritingFile(filename.c_str());
	if(fprintf(configfile,"# ELIN/STEER/S1H1\t%.2f A\nelin/steer/s1h1/current->__value:\t\t%.2f\n",defaultVal.steer_beam[6],defaultVal.steer_beam[6]) <= 0) exceptionWritingFile(filename.c_str());
	if(fprintf(configfile,"# ELIN/STEER/S1V1\t%.2f A\nelin/steer/s1v1/current->__value:\t\t%.2f\n",defaultVal.steer_beam[7],defaultVal.steer_beam[7]) <= 0) exceptionWritingFile(filename.c_str());
	if(fprintf(configfile,"# ELIN/STEER/S1H2\t%.2f A\nelin/steer/s1h2/current->__value:\t\t%.2f\n",defaultVal.steer_beam[8],defaultVal.steer_beam[8]) <= 0) exceptionWritingFile(filename.c_str());
	if(fprintf(configfile,"# ELIN/STEER/S1V2\t%.2f A\nelin/steer/s1v2/current->__value:\t\t%.2f\n",defaultVal.steer_beam[9],defaultVal.steer_beam[9]) <= 0) exceptionWritingFile(filename.c_str());
	if(fprintf(configfile,"# ELIN/STEER/TRIPLET\t%.2f A\nelin/steer/triplet/current->__value:\t\t%.2f\n",defaultVal.steer_beam[10],defaultVal.steer_beam[10]) <= 0) exceptionWritingFile(filename.c_str());
	if(fprintf(configfile,"# ELIN/STEER/S2H1\t%.2f A\nelin/steer/s2h1/current->__value:\t\t%.2f\n",defaultVal.steer_beam[11],defaultVal.steer_beam[11]) <= 0) exceptionWritingFile(filename.c_str());
	if(fprintf(configfile,"# ELIN/STEER/S2V1\t%.2f A\nelin/steer/s2v1/current->__value:\t\t%.2f\n",defaultVal.steer_beam[12],defaultVal.steer_beam[12]) <= 0) exceptionWritingFile(filename.c_str());
	if(fprintf(configfile,"# ELIN/STEER/S2H2\t%.2f A\nelin/steer/s2h2/current->__value:\t\t%.2f\n",defaultVal.steer_beam[13],defaultVal.steer_beam[13]) <= 0) exceptionWritingFile(filename.c_str());
	if(fprintf(configfile,"# ELIN/STEER/S2V2\t%.2f A\nelin/steer/s2v2/current->__value:\t\t%.2f\n",defaultVal.steer_beam[14],defaultVal.steer_beam[14]) <= 0) exceptionWritingFile(filename.c_str());
	if(fprintf(configfile,"# ELIN/STEER/CHAN16\t %.2f A\nelin/steer/chan16/current->__value:\t\t%.2f\n",defaultVal.steer_beam[15],defaultVal.steer_beam[15]) <= 0) exceptionWritingFile(filename.c_str());
	if(fprintf(configfile,"# mod 1 hv \t%.2f kV\nelin/mod1/hv/highvoltage->__value:\t\t%.2f\n",defaultVal.mod_hv_v[0],defaultVal.mod_hv_v[0]) <= 0) exceptionWritingFile(filename.c_str());
	if(fprintf(configfile,"# mod 2 hv \t%.2f kV\nelin/mod2/hv/highvoltage->__value:\t\t%.2f\n",defaultVal.mod_hv_v[1],defaultVal.mod_hv_v[1]) <= 0) exceptionWritingFile(filename.c_str());
	if(fprintf(configfile,"# vpfn1\t%.2f kV\nelin/mod1/run/vpfn->__value:\t\t\t%.2f\n",defaultVal.vpfn[0],defaultVal.vpfn[0]) <= 0) exceptionWritingFile(filename.c_str());
	if(fprintf(configfile,"# vpfn2\t%.2f kV\nelin/mod2/run/vpfn->__value:\t\t\t%.2f\n",defaultVal.vpfn[1],defaultVal.vpfn[1]) <= 0) exceptionWritingFile(filename.c_str());
	if(fprintf(configfile,"# buncher phase\t%.1f deg\nelin/rf/run/bunchphase->__value:\t\t%.1f\n",defaultVal.bunch_phase,defaultVal.bunch_phase) <= 0) exceptionWritingFile(filename.c_str());
	if(fprintf(configfile,"# pbuncher phase\t%.1f deg\nelin/rf/run/pbunchphase->__value:\t\t%.1f\n",defaultVal.pbunch_phase,defaultVal.pbunch_phase) <= 0) exceptionWritingFile(filename.c_str());
	if(fprintf(configfile,"# pbuncher atten\t%.1f %\nelin/rf/run/pbunchattenu->__value:\t\t%.1f\n",defaultVal.pbunch_atten,defaultVal.pbunch_atten) <= 0) exceptionWritingFile(filename.c_str());
	if(fprintf(configfile,"# section phase\t%.1f deg\nelin/rf/run/sect2phase->__value:\t\t%.1f\n",defaultVal.section_phase,defaultVal.section_phase) <= 0) exceptionWritingFile(filename.c_str());
	if(fprintf(configfile,"# gun heating v\t%.2f V\nelin/gun/aux/heatv->__value:\t\t\t%.2f\n",defaultVal.gun_heating_v,defaultVal.gun_heating_v) <= 0) exceptionWritingFile(filename.c_str());
	if(fprintf(configfile,"# gun grid v\t%.1f V\nelin/beam/run/gridv->__value:\t\t\t%.1f\n",defaultVal.gun_grid_v,defaultVal.gun_grid_v) <= 0) exceptionWritingFile(filename.c_str());
	if(fprintf(configfile,"# gun pulse v\t%.1f V\nelin/beam/run/pulsev->__value:\t\t\t%.1f\n",defaultVal.gun_pulse_v,defaultVal.gun_pulse_v) <= 0) exceptionWritingFile(filename.c_str());
	if(fprintf(configfile,"# gun pulse length\t%.2f �m\nelin/beam/run/pulsel->__value:\t\t\t%.2f\n",defaultVal.gun_pulse_l,defaultVal.gun_pulse_l) <= 0) exceptionWritingFile(filename.c_str());
	if(fprintf(configfile,"# gun hv\t%.1f kV\nelin/gun/hv/highvoltage->__value:\t\t%.1f\n",defaultVal.gun_hv_v,defaultVal.gun_hv_v) <= 0) exceptionWritingFile(filename.c_str());
	if(fprintf(configfile,"# frequency\t%.2f MHz\nelin/rf/run/frequency->__value:\t\t\t%.6f\n",defaultVal.frequency,defaultVal.frequency) <= 0) exceptionWritingFile(filename.c_str());
	if(defaultVal.short_pulse == false)
	{
		if(fprintf(configfile,"# Long pulse\nelin/beam/run/pulsetype->__value:\t\t\"LONG\"\n") <= 0)	exceptionWritingFile(filename.c_str());
	}
	else
	{
		if(fprintf(configfile,"# Short pulse\nelin/beam/run/pulsetype->__value:\t\t\"SHORT\"\n") <= 0)	exceptionWritingFile(filename.c_str());
	}
	if(fprintf(configfile,"# timer rf\t%.2f �s\nelin/rf/run/delay->__value:\t\t\t%.2f\n",defaultVal.timer_rf,defaultVal.timer_rf) <= 0)	exceptionWritingFile(filename.c_str());
	if(fprintf(configfile,"# timer mod1\t%.2f �s\nelin/mod1/run/delay->__value:\t\t\t%.2f\n",defaultVal.timer_mod[0],defaultVal.timer_mod[0]) <= 0)	exceptionWritingFile(filename.c_str());
	if(fprintf(configfile,"# timer mod2\t%.2f �s\nelin/mod2/run/delay->__value:\t\t\t%.2f\n",defaultVal.timer_mod[1],defaultVal.timer_mod[1]) <= 0)	exceptionWritingFile(filename.c_str());
	if(fprintf(configfile,"# timer mod1_s\t%.2f �s\nelin/mod1/run/delays->__value:\t\t\t%.2f\n",defaultVal.timer_mod_s[0],defaultVal.timer_mod_s[0]) <= 0)	exceptionWritingFile(filename.c_str());
	if(fprintf(configfile,"# timer mod2_s\t%.2f �s\nelin/mod2/run/delays->__value:\t\t\t%.2f\n",defaultVal.timer_mod_s[1],defaultVal.timer_mod_s[1]) <= 0)	exceptionWritingFile(filename.c_str());
	// close the file
	fclose(configfile);
	chmod(filename.c_str(), S_IWUSR|S_IRUSR|S_IWGRP|S_IRGRP|S_IROTH);
#endif /* SIMU */

	write_history ("End  to SAVE / FORCE SAVE configuration");
	if (nberrors > 0)
	{
		// If we are here, we had error but we do not throw exceptions. So we are in FORCE SAVE mode.
		{
			omni_mutex_lock l(mutex);
			seq_obj->error = true;
		}
		write_history("Errors during the execution of the sequence !");
		INFO_STREAM << ">>>> LinacThread FORCE SAVE sequence ended with " << nberrors << " errors !" << endl;
	}
	else
	{
		{
			omni_mutex_lock l(mutex);
			seq_obj->isFileLoaded = true;
		}
		if (warnInPlaceOfExcept) INFO_STREAM << ">>>> LinacThread FORCE SAVE sequence ended successfully!" << endl;
		else INFO_STREAM << ">>>> LinacThread SAVE sequence ended successfully!" << endl;
	}
}

/***********************************************************************
* Function:		Tango::DevState get_state()
*
* Description: read the state of a sub device
* Arg(s) In: the sub device
***********************************************************************/
Tango::DevState LinacSeqThread::get_state(Tango::DeviceProxy * device,const char* device_name)
{
	Tango::DevState deviceState = Tango::UNKNOWN;
	try
	{
		deviceState = device->state();
	}
	catch (Tango::DevFailed &e)
	{
		ERROR_STREAM << ">>>> LinacSeqThread::get_state: An exception occured!" << endl;
		Tango::Except::print_exception(e);
		ERROR_STREAM << "cannot read state of " << device_name << " device."<< endl;
		for (unsigned short i = 0; i<e.errors.length(); i++)
		{
			ERROR_STREAM << e.errors[i].desc.in() << endl;
		}
		deviceState = Tango::UNKNOWN;
	}
	return deviceState;
}

//
// LinacSeqThread::check_abort()
// Description : Check for sequence abort
// and throw an exception if the user want to abort the sequence
//
void LinacSeqThread::check_abort()
{
	omni_mutex_lock l(mutex);
	if ( seq_obj->quit == true )
	{
		// throw abort exception
		Tango::Except::throw_exception((const char *)"LinacSeqThread::Abort",
	      (const char *)"The sequence was aborted by the user!",
			(const char *)"LinacSeqThread::check_abort");
	}
}

//
// LinacSeqThread::set_double_value
// Description : This function will try to write the attribute attr_name
// on the device tangodev with the value attr_val
// if throwExcept = true
// 	It will throw Tango::DevFailed Exceptions in case of error and write the error message
// 	in the Linac SequenceHistory attribute.
// else it will not throw Tango::DevFailed Exceptions
//
bool LinacSeqThread::set_double_value(Tango::DeviceProxy *tangodev,const char *attr_name,Tango::DevDouble attr_val,bool throwExcept)
{
	Tango::DeviceAttribute attr(attr_name,attr_val);
	try
	{
		tangodev->write_attribute(attr);
	}
	catch (Tango::DevFailed &e)
	{
		Tango::Except::print_exception(e);
		// Add the exception description to the end of the sequence history.
		string tmp_status = "";
		unsigned short i;
		for (i = 0; i<(e.errors.length()-1); i++)
			tmp_status = (string) "**** ERROR **** " + e.errors[i].desc.in() + "\n";
		if(i == (e.errors.length()-1))
			tmp_status = (string) "**** ERROR **** " + e.errors[i].desc.in();
		write_history(tmp_status.c_str());
		ERROR_STREAM << tmp_status << endl;
		if(throwExcept == true)
			throw;
		return false;
	}
	return true;
}

//
// LinacSeqThread::set_string_value
// Description : This function will try to write the attribute attr_name
// on the device tangodev with the value attr_val
// if throwExcept = true
// 	It will throw Tango::DevFailed Exceptions in case of error and write the error message
// 	in the Linac SequenceHistory attribute.
// else it will not throw Tango::DevFailed Exceptions
//
bool LinacSeqThread::set_string_value(Tango::DeviceProxy *tangodev,const char *attr_name,string attr_val,bool throwExcept)
{
	Tango::DeviceAttribute attr(attr_name,attr_val);
	try
	{
		tangodev->write_attribute(attr);
	}
	catch (Tango::DevFailed &e)
	{
		Tango::Except::print_exception(e);
		// Add the exception description to the end of the sequence history.
		string tmp_status = "";
		unsigned short i = 0;
		for (i = 0; i<(e.errors.length()-1); i++)
			tmp_status = tmp_status + "**** ERROR **** " + e.errors[i].desc.in() + "\n";
		if ( i == (e.errors.length()-1))
			tmp_status = tmp_status + "**** ERROR **** " + e.errors[i].desc.in();
		write_history(tmp_status.c_str());
		ERROR_STREAM << tmp_status << endl;
		if(throwExcept == true)
			throw;
		return false;
	}
	return true;
}

//
// LinacSeqThread::set_bool_value
// Description : This function will try to write the attribute attr_name
// on the device tangodev with the value attr_val
// if throwExcept = true
// 	It will throw Tango::DevFailed Exceptions in case of error and write the error message
// 	in the Linac SequenceHistory attribute.
// else it will not throw Tango::DevFailed Exceptions
//
bool LinacSeqThread::set_bool_value(Tango::DeviceProxy *tangodev,const char *attr_name,bool attr_val,bool throwExcept)
{
	Tango::DeviceAttribute attr(attr_name,attr_val);
	try
	{
		tangodev->write_attribute(attr);
	}
	catch (Tango::DevFailed &e)
	{
		Tango::Except::print_exception(e);
		// Add the exception description to the end of the sequence history.
		string tmp_status = "";
		unsigned short i = 0;
		for (i = 0; i<(e.errors.length()-1); i++)
			tmp_status = tmp_status + "**** ERROR **** " + e.errors[i].desc.in() + "\n";
		if ( i == (e.errors.length()-1))
			tmp_status = tmp_status + "**** ERROR **** " + e.errors[i].desc.in();
		write_history(tmp_status.c_str());
		ERROR_STREAM << tmp_status << endl;
		if(throwExcept == true)
			throw;
		return false;
	}
	return true;
}

//
// LinacSeqThread::set_dev_double_array
// Description : This function will try to write the attribute attr_name (DevDouble array)
// on the device tangodev with the value attr_val
// if throwExcept = true
// 	It will throw Tango::DevFailed Exceptions in case of error and write the error message
// 	in the Linac SequenceHistory attribute.
// else it will not throw Tango::DevFailed Exceptions
//
bool LinacSeqThread::set_dev_double_array(Tango::DeviceProxy *tangodev,const char *attr_name,vector<Tango::DevDouble> attr_val,bool throwExcept)
{

	Tango::DeviceAttribute attr(attr_name,attr_val);
	try
	{
		tangodev->write_attribute(attr);
	}
	catch (Tango::DevFailed &e)
	{
		Tango::Except::print_exception(e);
		// Add the exception description to the end of the sequence history.
		string tmp_status = "";
		unsigned short i = 0;
		for (i = 0; i<(e.errors.length()-1); i++)
			tmp_status = tmp_status + "**** ERROR **** " + e.errors[i].desc.in() + "\n";
		if ( i == (e.errors.length()-1))
			tmp_status = tmp_status + "**** ERROR **** " + e.errors[i].desc.in();
		write_history(tmp_status.c_str());
		ERROR_STREAM << tmp_status << endl;
		if(throwExcept == true)
			throw;
		return false;
	}
	return true;
}

//
// LinacSeqThread::read_set_points
// Description : This function will try to read the set point of the focus
// on the device tangodev
// if throwExcept = true
// 	It will throw Tango::DevFailed Exceptions in case of error and write the error message
// 	in the Linac SequenceHistory attribute.
// else it will not throw Tango::DevFailed Exceptions
// set = Tango::DevDouble : the read and set points of the attribute
//
// return true if no pb
// return false if an error occured
bool LinacSeqThread::read_set_points(Tango::DeviceProxy *tangodev,const char *command,Tango::DevVarDoubleArray *setfocus,bool throwExcept)
{
	vector <double> setval;
	setval.clear();
	try
	{
		Tango::DeviceData foc_val = tangodev->command_inout( command );
		foc_val >> setval;
		int len = setval.size();
		setfocus->length(len);
		for(int i=0;i<len;i++)
		{
			(*setfocus)[i] = setval[i];
		}
		int anslength = setfocus->length();
		for(int j = 0; j<anslength ; j++)
			DEBUG_STREAM << "values[" << j << "] = " << (*setfocus)[j] << endl;
		return true;
	}
	catch(Tango::DevFailed &e)
	{
		Tango::Except::print_exception(e);
		// Add the exception description to the end of the sequence history.
		string tmp_status = "";
		unsigned short n = 0;
		for (n = 0; n<(e.errors.length()-1); n++)
			tmp_status = tmp_status + "**** ERROR **** " + e.errors[n].desc.in() + "\n";
		if(n == (e.errors.length()-1))
			tmp_status = tmp_status + "**** ERROR **** " + e.errors[n].desc.in();
		write_history(tmp_status.c_str());
		ERROR_STREAM << tmp_status << endl;
		if(throwExcept == true)
			throw;
		return false;
	}
}




//
// LinacSeqThread::read_double_set_point
// Description : This function will try to read the set point of the attribute attr_name
// on the device tangodev
// if throwExcept = true
// 	It will throw Tango::DevFailed Exceptions in case of error and write the error message
// 	in the Linac SequenceHistory attribute.
// else it will not throw Tango::DevFailed Exceptions
// set = Tango::DevDouble : the set point of the attribute
// return true if no pb
// return false if an error occured
//
bool LinacSeqThread::read_double_set_point(Tango::DeviceProxy *tangodev,const char *attr_name,Tango::DevDouble * setpoint,bool throwExcept)
{
	Tango::DevVarDoubleArray * attr_read_set_val;
	try
	{
		Tango::DeviceAttribute attr_value = tangodev->read_attribute(attr_name);
		attr_value >> attr_read_set_val ;
		*setpoint = (*attr_read_set_val)[1];
		delete attr_read_set_val;
		return true;
	}
	catch (Tango::DevFailed &e)
	{
		Tango::Except::print_exception(e);
		// Add the exception description to the end of the sequence history.
		string tmp_status = "";
		unsigned short i = 0;
		for (i = 0; i<(e.errors.length()-1); i++)
			tmp_status = tmp_status + "**** ERROR **** " + e.errors[i].desc.in() + "\n";
		if(i == (e.errors.length()-1))
			tmp_status = tmp_status + "**** ERROR **** " + e.errors[i].desc.in();
		write_history(tmp_status.c_str());
		ERROR_STREAM << tmp_status << endl;
		if(throwExcept == true)
			throw;
		return false;
	}
}

//
// LinacSeqThread::read_string_set_point
// Description : This function will try to read the set point of the attribute attr_name
// on the device tangodev
// if throwExcept = true
// 	It will throw Tango::DevFailed Exceptions in case of error and write the error message
// 	in the Linac SequenceHistory attribute.
// else it will not throw Tango::DevFailed Exceptions
// set = string * : the set point of the attribute
// return true if no pb
// return false if an error occured
//
bool LinacSeqThread::read_string_set_point(Tango::DeviceProxy *tangodev,const char *attr_name,Tango::DevString * setpoint,bool throwExcept)
{
	Tango::DevVarStringArray * attr_read_set_val;
	try
	{
		Tango::DeviceAttribute attr_value = tangodev->read_attribute(attr_name);
		attr_value >> attr_read_set_val ;
		*setpoint = CORBA::string_dup((*attr_read_set_val)[1]);
		delete attr_read_set_val;
		return true;
	}
	catch (Tango::DevFailed &e)
	{
		Tango::Except::print_exception(e);
		// Add the exception description to the end of the sequence history.
		string tmp_status = "";
		unsigned short i = 0;
		for (i = 0; i<(e.errors.length()-1); i++)
			tmp_status = tmp_status + "**** ERROR **** " + e.errors[i].desc.in() + "\n";
		if ( i == (e.errors.length()-1))
			tmp_status = tmp_status + "**** ERROR **** " + e.errors[i].desc.in();
		write_history(tmp_status.c_str());
		ERROR_STREAM << tmp_status << endl;
		if(throwExcept == true)
			throw;
		return false;
	}
}

//
// LinacSeqThread::read_bool_set_point
// Description : This function will try to read the set point of the attribute attr_name
// on the device tangodev
// if throwExcept = true
// 	It will throw Tango::DevFailed Exceptions in case of error and write the error message
// 	in the Linac SequenceHistory attribute.
// else it will not throw Tango::DevFailed Exceptions
// set = bool * : the set point of the attribute
// return true if no pb
// return false if an error occured
//
bool LinacSeqThread::read_bool_set_point(Tango::DeviceProxy *tangodev,const char *attr_name,bool * setpoint,bool throwExcept)
{
	Tango::DevVarBooleanArray * attr_read_set_val;
	try
	{
		Tango::DeviceAttribute attr_value = tangodev->read_attribute(attr_name);
		attr_value >> attr_read_set_val ;
		*setpoint = (*attr_read_set_val)[1];
		delete attr_read_set_val;
		return true;
	}
	catch (Tango::DevFailed &e)
	{
		Tango::Except::print_exception(e);
		// Add the exception description to the end of the sequence history.
		string tmp_status = "";
		unsigned short i = 0;
		for (i = 0; i<(e.errors.length()-1); i++)
			tmp_status = tmp_status + "**** ERROR **** " + e.errors[i].desc.in() + " \n";
		if(i == (e.errors.length()-1))
			tmp_status = tmp_status + "**** ERROR **** " + e.errors[i].desc.in();
		write_history(tmp_status.c_str());
		ERROR_STREAM << tmp_status << endl;
		if(throwExcept == true)
			throw;
		return false;
	}
}

//
// LinacSeqThread::send_cmd
// Description : This function will execute the command cmd
// on the device tangodev
// if throwExcept = true
// 	It will throw Tango::DevFailed Exceptions in case of error and write the error message
// 	in the Linac SequenceHistory attribute.
// else it will not throw Tango::DevFailed Exceptions
//
bool LinacSeqThread::send_cmd(Tango::DeviceProxy *tangodev,const char *cmd,bool throwExcept)
{
	try
	{
		tangodev->command_inout(cmd);
	}
	catch (Tango::DevFailed &e)
	{
		Tango::Except::print_exception(e);
		// Add the exception description to the end of the sequence history.
		string tmp_status = "";
		unsigned short i = 0;
		for (i = 0; i<(e.errors.length()-1); i++)
			tmp_status = tmp_status + "**** ERROR **** " + e.errors[i].desc.in() + "\n";
		if ( i == (e.errors.length()-1))
			tmp_status = tmp_status + "**** ERROR **** " + e.errors[i].desc.in();
		write_history(tmp_status.c_str());
		ERROR_STREAM << tmp_status << endl;
		if(throwExcept == true)
			throw;
		return false;
	}
	return true;
}

/* exceptionWritingFile function
 * This function will throw an ErrorWritingFile
 * argin = filename name of the file we tried to write
 */
void LinacSeqThread::exceptionWritingFile(const char * file_name)
{
	TangoSys_OMemStream o;
	o << "error writing file " << file_name << ":" << strerror(errno);
	ERROR_STREAM << o.str() << endl;
	fclose(configfile);
	Tango::Except::throw_exception
	((const char *)"ErrorWritingFile",
	o.str(),
	(const char *)"LinacSeqThread::macro_SAVE_SETTINGS() or macro_FORCE_SAVE()");
}

/* WarnErrorReadingSetPoint
 * This function will just write a message in the Linac history attribute
 * this message will warn the user a problem occured during the saving of the set point
 * of the equipment given in argument.
 */
void LinacSeqThread::WarnErrorReadingSetPoint(string equipment)
{
	string str1 = (string)"*** WARNING *** Could not read " + equipment + " set point";
	write_history(str1);
	string str2 = (string)"*** WARNING *** Saving the same " + equipment + " set point as in the last loaded or saved file";
	write_history(str2);
	string str3 = (string)"*** WARNING *** Check the " + equipment + " value saved in your file";
	write_history(str3);
}

/* set_timeout
 * This function will set the Timeout to the_timeout for the DeviceProxy given in parameter
 * In case of error, this function will add an error message into the sequence history
 */
void LinacSeqThread::set_timeout(Tango::DeviceProxy *dev, string dev_name, Tango::DevLong the_timeout)
{
	// set the timeout for the klystron 1 focussing devices
	if(dev != NULL)
	{
		try
		{
			dev->set_timeout_millis(the_timeout);
		}
		catch(Tango::DevFailed &e)
		{
			ERROR_STREAM << ">>>> An exception occured!" << endl;
			Tango::Except::print_exception(e);
			string tmp_status;
			tmp_status = "******* Initialization failed with errors!\n";

			for (unsigned short i = 0; i<e.errors.length(); i++)
			{
				tmp_status = tmp_status + "**** ERROR **** " + e.errors[i].desc.in() + "\n";
			}
			tmp_status = tmp_status + "Failed to set the timeout on ";
			tmp_status = tmp_status + dev_name + " device\n";

			omni_mutex_lock l(mutex);
			seq_obj->sequence_history.push_back (tmp_status);
			seq_obj->error = true;
		}
	}
}

//
// LinacSeqThread::set_double_array_attribute_values
// Description : This function write an attribute spectrum of double.
// on the device tangodev
// on attribute named attr of spectrum.
// values is a vector containing sequential values to be written.
// The method will not throw exception, but will log problems into sequence history.
//  Return true if everything is OK else return false.
//
bool LinacSeqThread::set_double_array_attribute_values(Tango::DeviceProxy *tango_device, const char *attr, vector <Tango::DevDouble> &values)
{
	try
	{
		Tango::DeviceAttribute valuesSpectrum(attr, values);
		tango_device->write_attribute(valuesSpectrum);
	}
	catch (Tango::DevFailed &e)
	{
		Tango::Except::print_exception(e);
		// Add the exception description to the end of the sequence history.
		string tmp_status = "";
		unsigned short i = 0;
		for (i = 0; i<(e.errors.length()-1); i++)
			tmp_status = tmp_status + "**** ERROR **** " + e.errors[i].desc.in() + "\n";
		if ( i == (e.errors.length()-1))
			tmp_status = tmp_status + "**** ERROR **** " + e.errors[i].desc.in();
		write_history(tmp_status.c_str());
		ERROR_STREAM << tmp_status << endl;
		return false;
	}
	return true;
}


}	// namespace
