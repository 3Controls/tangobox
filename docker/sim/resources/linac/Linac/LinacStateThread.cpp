static const char *RcsId = "$Header: /segfs/tango/cvsroot/cppserver/machine/linac/linac/LinacStateThread.cpp,v 1.12 2009/08/14 07:15:17 vedder Exp $";
//+=============================================================================
//
// file :        LinacStateThread.cpp
//
// description : C++ source for the LinacStateThread. 
//
// project :     TANGO Device Server
//
// $Author: vedder $
//
// $Log: LinacStateThread.cpp,v $
// Revision 1.12  2009/08/14 07:15:17  vedder
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
// Revision 1.11  2006/10/25 13:30:10  bourtemb
// Add get_device_state_no_alarm() method to get the state of a device.
// If the device is in ALARM state, the variable n_alarm will not be incremented.
// Thus the alarm state of this device is not taken into account for the
// calculation of the linac global state.
// The Bruker alarms are not not taken into account for the calculation of
// the linac global state.
//
// Revision 1.10  2006/10/20 13:04:37  bourtemb
// Change the way to retrieve the state of the devices in get_device_state().
// No longer use the state() method directly.
// Use read_attribute("State") instead in order to get the state from the cache
// whenever it is possible.
//
// Revision 1.9  2006/10/20 08:38:37  bourtemb
// the sequencer state is now retrieved in the thread which get all the states
//
// Revision 1.8  2006/09/27 13:32:13  bourtemb
// add cvs log in the header file
//
//
// copyleft :   European Synchrotron Radiation Facility
//              BP 220, Grenoble 38043
//              FRANCE
//
//-=============================================================================


#include <LinacStateThread.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

namespace Linac_ns
{

LinacStateThread::LinacStateThread (Linac *obj, omni_mutex &m) : 
			omni_thread(),mutex(m),Tango::LogAdapter((Tango::DeviceImpl *)obj)
{
	DEBUG_STREAM << ">>>> LinacStateThread::LinacStateThread(): entering ....!" << endl;
	linacds = obj;
	DEBUG_STREAM << ">>>> retrieve sequences devices names" << endl;
	gun_aux_name 		= linacds->gun_aux_name;
	gun_name 		= linacds->gun_name;
	gun_HV_name 		= linacds->gun_HV_name;
	rf_run_name 		= linacds->rf_run_name;
	cooling_name 		= linacds->cooling_name;
	mod1_aux_name 		= linacds->mod1_aux_name;
	mod2_aux_name 		= linacds->mod2_aux_name;
	mod1_HV_name 		= linacds->mod1_HV_name;
	mod2_HV_name 		= linacds->mod2_HV_name;
	mod1_name 		= linacds->mod1_name;
	mod2_name 		= linacds->mod2_name;	
	focus_klystron1_name	= linacds->focus_klystron1_name;
	focus_klystron2_name	= linacds->focus_klystron2_name;
	focus_beam1_name	= linacds->focus_beam1_name;
	focus_beam2_name	= linacds->focus_beam2_name;
	focus_steer_name	= linacds->focus_steer_name;
	daresbury_name		= linacds->daresbury;
	sequencer_name		= linacds->sequencer;
	pss_interlocks_list	= linacds->pss_interlocks_list;
	
	//New Linac Gun addition:
	gun_focus_b1b4_tdk_name 	= linacds->gun_focus_b1b4_tdk_name;
	gun_steerer_tdk_name		= linacds->gun_steerer_tdk_name;
	prebuncher_steerer_tdk_name	= linacds->prebuncher_steerer_tdk_name;

	
	DEBUG_STREAM << ">>>> initialize Device Proxy Objects" << endl;
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
		daresburyds	= new Tango::DeviceProxy(daresbury_name.c_str());
		sequencer	= new Tango::DeviceProxy(sequencer_name.c_str());

		// New Linac Gun addition.
		gun_focus_b1b4_tdk 		= new Tango::DeviceProxy(gun_focus_b1b4_tdk_name.c_str());
		gun_steerer_tdk			= new Tango::DeviceProxy(gun_steerer_tdk_name.c_str());
		prebuncher_steerer_tdk	= new Tango::DeviceProxy(prebuncher_steerer_tdk_name.c_str());
		
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
		daresburyds->set_transparency_reconnection(true);
		sequencer->set_transparency_reconnection(true);
		
		// New Linac Gun addition
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
			
		for (unsigned int i = 0; i<e.errors.length(); i++)
		{
			tmp_status = tmp_status + "**** ERROR **** " + e.errors[i].desc.in() + "\n";
		}
		tmp_status = tmp_status + "Ensure the needed devices are well defined in the database\n";
		tmp_status = tmp_status + " and execute the INIT function of the Linac server\n";
		ERROR_STREAM << tmp_status << endl;
	}
	
	// initilialize pss_interlocks variable
	Tango::DevLong module,num;
	double numtmp;
	pss_interlocks.clear();
	for(unsigned int j=0;j<pss_interlocks_list.size();j++)
	{
		module = (Tango::DevLong) pss_interlocks_list[j];
		numtmp =  pss_interlocks_list[j]*10;
		num = (Tango::DevLong)numtmp % 10;
		module = module - 1;
		num = (num -1) * 2;
		pss_interlocks.push_back(module);
		pss_interlocks.push_back(num);
	}
	
	start_undetached();
}

// method : LinacStateThread::clean_exit()
// This method is called when the thread must be killed
// It will free all the necessary resources
// and commit suicide (A major sin !)
void LinacStateThread::clean_exit()
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
	delete daresburyds;
	delete sequencer;
	
	// New Linac Gun addition
	delete gun_focus_b1b4_tdk;
	delete gun_steerer_tdk;
	delete prebuncher_steerer_tdk;
	
	DEBUG_STREAM << ">>>> Thread DEATH ..." << endl;
	exit();
}


//
// LinacStateThread::run_undetached 
//
void *LinacStateThread::run_undetached (void *arg)
{
	DEBUG_STREAM << ">>>> LinacStateThread starting up!" << endl;
	
	while(true)
	{
		DEBUG_STREAM << ">>>> Begining of While loop" <<endl;
		check_quit();
#ifdef PRINT_TIME
		double t1 = get_ticks();
#endif
		refresh_state();
#ifdef PRINT_TIME
		double t2 = get_ticks();
		printf("Time refresh_state = %.3f\n",t2-t1);
#endif
		usleep(25000); // 25 ms
	}
}

void LinacStateThread::check_quit()
{
	{
		omni_mutex_lock * l = new omni_mutex_lock(mutex);
		if(linacds->killthread == true)
		{
			delete l;
			clean_exit();
		}
		delete l;
	}
}

/***********************************************************************
* Function:		void get_all_state()
* 
* Description:	get the state of all sub devices involved in the global state
* 					computation and count the errors.
***********************************************************************/
void LinacStateThread::get_all_state()
{
	DEBUG_STREAM << "LinacStateThread::get_all_state(): Entering ..." << endl;
	n_alarm=0;
	n_fault=0;
	n_unknown=0;
// 	
// 	double t0 = get_ticks();
// 	try{	gun_aux->read_attribute_asynch("State",cb_gun_aux);}
// 	catch(Tango::DevFailed &e)	{	Tango::Except::print_exception(e);	}
// 	try{	gun_HV->read_attribute_asynch("State",cb_gun_hv);}
// 	catch(Tango::DevFailed &e)	{	Tango::Except::print_exception(e);	}
// 	try
// 	{
// 		gun->read_attribute_asynch("State",cb_gun);
// 		
// 	}
// 	catch(Tango::DevFailed &e)	{	Tango::Except::print_exception(e);	}
// 	try
// 	{
// 		rf_run->read_attribute_asynch("State",cb_rf);
// 		
// 	}
// 	catch(Tango::DevFailed &e)	{	Tango::Except::print_exception(e);	}
// 	try
// 	{
// 		cooling->read_attribute_asynch("State",cb_cooling);
// 		
// 	}
// 	catch(Tango::DevFailed &e)	{	Tango::Except::print_exception(e);	}
// 	try
// 	{
// 		mod1_aux->read_attribute_asynch("State",cb_mod1_aux);
// 		
// 	}
// 	catch(Tango::DevFailed &e)	{	Tango::Except::print_exception(e);	}
// 	try
// 	{
// 		mod2_aux->read_attribute_asynch("State",cb_mod2_aux);
// 		
// 	}
// 	catch(Tango::DevFailed &e)	{	Tango::Except::print_exception(e);	}
// 	try
// 	{
// 		mod1_HV->read_attribute_asynch("State",cb_mod1_hv);
// 		
// 	}
// 	catch(Tango::DevFailed &e)	{	Tango::Except::print_exception(e);	}
// 	try
// 	{
// 		mod2_HV->read_attribute_asynch("State",cb_mod2_hv);
// 		
// 	}
// 	catch(Tango::DevFailed &e)	{	Tango::Except::print_exception(e);	}
// 	try
// 	{
// 		mod1->read_attribute_asynch("State",cb_mod1);
// 		
// 	}
// 	catch(Tango::DevFailed &e)	{	Tango::Except::print_exception(e);	}
// 	try
// 	{
// 		mod2->read_attribute_asynch("State",cb_mod2);
// 		
// 	}
// 	catch(Tango::DevFailed &e)	{	Tango::Except::print_exception(e);	}
// 	try
// 	{
// 		focus_klystron->read_attribute_asynch("State",cb_focus_klystron);
// 		
// 	}
// 	catch(Tango::DevFailed &e)	{	Tango::Except::print_exception(e);	}
// 	try
// 	{
// 		focus_beam1->read_attribute_asynch("State",cb_focus_beam1);
// 		
// 	}
// 	catch(Tango::DevFailed &e)	{	Tango::Except::print_exception(e);	}
// 	try
// 	{
// 		focus_beam2->read_attribute_asynch("State",cb_focus_beam2);
// 		
// 	}
// 	catch(Tango::DevFailed &e)	{	Tango::Except::print_exception(e);	}	try
// 	{
// 		focus_steer->read_attribute_asynch("State",cb_steerers);
// 		
// 	}
// 	catch(Tango::DevFailed &e)	{	Tango::Except::print_exception(e);	}
// 	
// 	double t1 = get_ticks();
// 	
// 	double max_asyn_time = 2000;
// 	// try
// // 	{
// // 		omni_mutex_lock l(mutex);
// // 		max_asyn_time = linacds->attr_SRCT_Limit_write;
// // 	}
// // 	catch(Tango::DevFailed &e) { Tango::Except::print_exception(e); }
// 	
// 	try
// 	{
// 		gun_aux->get_asynch_replies((long) max_asyn_time);
// 		gun_HV->get_asynch_replies((long) max_asyn_time);
// 		gun->get_asynch_replies((long) max_asyn_time);
// 		rf_run->get_asynch_replies((long) max_asyn_time);
// 		cooling->get_asynch_replies((long) max_asyn_time);
// 		mod1_aux->get_asynch_replies((long) max_asyn_time);
// 		mod2_aux->get_asynch_replies((long) max_asyn_time);
// 		mod1_HV->get_asynch_replies((long) max_asyn_time);
// 		mod2_HV->get_asynch_replies((long) max_asyn_time);
// 		mod1->get_asynch_replies((long) max_asyn_time);
// 		mod2->get_asynch_replies((long) max_asyn_time);
// 		focus_klystron->get_asynch_replies((long) max_asyn_time);
// 		focus_beam1->get_asynch_replies((long) max_asyn_time);
// 		focus_beam2->get_asynch_replies((long) max_asyn_time);
// 		focus_steer->get_asynch_replies((long) max_asyn_time);
// 		
// 	}
// 	catch(Tango::DevFailed &e)	{	Tango::Except::print_exception(e);	}
// 	
// 	double t2 = get_ticks();
// 	
// 	gun_aux_state 			= cb_gun_aux.readState;
// 	gun_HV_state 			= cb_gun_hv.readState;
// 	gun_state 				= cb_gun.readState;
// 	rf_run_state 			= cb_rf.readState;
// 	cooling_state 			= cb_cooling.readState;
// 	mod1_aux_state 		= cb_mod1_aux.readState;
// 	mod2_aux_state 		= cb_mod2_aux.readState;
// 	mod1_HV_state 			= cb_mod1_hv.readState;
// 	mod2_HV_state 			= cb_mod2_hv.readState;
// 	mod1_state 				= cb_mod1.readState;
// 	mod2_state 				= cb_mod2.readState;
// 	focus_klystron_state = cb_focus_klystron.readState;
// 	focus_beam1_state		= cb_focus_beam1.readState;
// 	focus_beam2_state		= cb_focus_beam2.readState;
// 	steerers_state			= cb_steerers.readState;
// 	
// 	double t3 = get_ticks();
// 	
// 	printf("Time read_attribute_asynch : %.3f ms\n",t1-t0);
// 	printf("Time get_asynch_replies : %.3f ms\n",t2-t1);
// 	printf("Time affectation states : %.3f ms\n",t3-t2);
// 	
// 	double t4 = get_ticks();
// 	update_variables_for_state(gun_aux_state);
// 	update_variables_for_state(gun_HV_state);
// 	update_variables_for_state(gun_state);
// 	update_variables_for_state(rf_run_state);
// 	update_variables_for_state(cooling_state);
// 	update_variables_for_state(mod1_aux_state);
// 	update_variables_for_state(mod2_aux_state);
// 	update_variables_for_state(mod1_HV_state);
// 	update_variables_for_state(mod2_HV_state);
// 	update_variables_for_state(mod1_state);
// 	update_variables_for_state(mod2_state);
// 	update_variables_for_state(focus_klystron_state);
// 	update_variables_for_state(focus_beam1_state);
// 	update_variables_for_state(focus_beam2_state);
// 	update_variables_for_state(steerers_state);
// 	double t5 = get_ticks();
// 	printf("Time update_variables_for_state : %.3f ms\n",t5-t4);
	
#ifdef PRINT_TIME
	double t6 = get_ticks();
#endif
	try { gun_aux_state 	= get_device_state(gun_aux,"Gun Auxiliary",gun_aux_name); }
	catch(Tango::DevFailed &e) { Tango::Except::print_exception(e); }
	try { gun_HV_state 	= get_device_state(gun_HV,"Gun HV",gun_HV_name); }
	catch(Tango::DevFailed &e) { Tango::Except::print_exception(e); }
	try { gun_state 	= get_device_state(gun,"Gun",gun_name); }
	catch(Tango::DevFailed &e) { Tango::Except::print_exception(e); }
	try { rf_run_state 	= get_device_state(rf_run,"RF",rf_run_name); }
	catch(Tango::DevFailed &e) { Tango::Except::print_exception(e); }
	try { cooling_state 	= get_device_state(cooling,"Cooling",cooling_name); }
	catch(Tango::DevFailed &e) { Tango::Except::print_exception(e); }
	try { mod1_aux_state	= get_device_state(mod1_aux,"Modulator 1 Auxiliary",mod1_name); }
	catch(Tango::DevFailed &e) { Tango::Except::print_exception(e); }
	try { mod2_aux_state	= get_device_state(mod2_aux,"Modulator 2 Auxiliary",mod2_name); }
	catch(Tango::DevFailed &e) { Tango::Except::print_exception(e); }
	try { mod1_HV_state 	= get_device_state(mod1_HV,"Modulator 1 HV",mod1_HV_name); }
	catch(Tango::DevFailed &e) { Tango::Except::print_exception(e); }
	try { mod2_HV_state 	= get_device_state(mod2_HV,"Modulator 2 HV",mod2_HV_name); }
	catch(Tango::DevFailed &e) { Tango::Except::print_exception(e); }
	try { mod1_state 	= get_device_state(mod1,"Modulator 1",mod1_name); }
	catch(Tango::DevFailed &e) { Tango::Except::print_exception(e); }
	try { mod2_state 	= get_device_state(mod2,"Modulator 2",mod2_name); }
	catch(Tango::DevFailed &e) { Tango::Except::print_exception(e); }
	try { focus_klystron1_state = get_device_state_no_alarm(focus_klystron1,"Focus Klystron 1",focus_klystron1_name); }
	catch(Tango::DevFailed &e) { Tango::Except::print_exception(e); }
	try { focus_klystron2_state = get_device_state(focus_klystron2,"Focus Klystron 2",focus_klystron2_name); }
	catch(Tango::DevFailed &e) { Tango::Except::print_exception(e); }
	try { focus_beam1_state = get_device_state_no_alarm(focus_beam1,"Focus Beam1",focus_beam1_name); }
	catch(Tango::DevFailed &e) { Tango::Except::print_exception(e); }
	try { focus_beam2_state = get_device_state_no_alarm(focus_beam2,"Focus Beam2",focus_beam2_name); }
	catch(Tango::DevFailed &e) { Tango::Except::print_exception(e); }
	try { steerers_state 	= get_device_state_no_alarm(focus_steer,"Steerers",focus_steer_name); }
	catch(Tango::DevFailed &e) { Tango::Except::print_exception(e); }
	try{ sequencer_state	= get_device_state(sequencer,"Sequencer",sequencer_name); }
	catch(Tango::DevFailed &e) { Tango::Except::print_exception(e); }

	// New Linac Gun addition:
	try{ gun_focus_b1b4_tdk_state	= get_device_state_no_alarm(gun_focus_b1b4_tdk, "Focus beam B1-B4", gun_focus_b1b4_tdk_name); }
	catch(Tango::DevFailed &e) { Tango::Except::print_exception(e); }

	try{ gun_steerer_tdk_state	= get_device_state_no_alarm(gun_steerer_tdk, "Gun Steerer TDKLambda  GH1/GV1-GH3/GV3", gun_steerer_tdk_name); }
	catch(Tango::DevFailed &e) { Tango::Except::print_exception(e); }

	try{ prebuncher_steerer_tdk_state	= get_device_state_no_alarm(prebuncher_steerer_tdk, "Gun Pre-Buncher Steerer TDKLambda  GH4/GV4", prebuncher_steerer_tdk_name); }
	catch(Tango::DevFailed &e) { Tango::Except::print_exception(e); }
	
	{
		omni_mutex_lock l(mutex);
		linacds->SequencerState = sequencer_state;
	}

	Tango::DeviceData argin;
	try
	{
		argin << pss_interlocks;
		Tango::DeviceData ans = daresburyds->command_inout("GetInterlockState",argin);
		ans >> pss_itlk_states;
		bool pss_linac_permit = true;
		for(unsigned int i=0;i<pss_itlk_states.size();i++)
		{
			if(pss_itlk_states[i] == 0)
			{
				pss_linac_permit = false;
			}
		}
		{
			omni_mutex_lock l(mutex);
			linacds->linac_permit = pss_linac_permit;
		}
	}
	catch(Tango::DevFailed &e)
	{
		Tango::Except::print_exception(e);
		n_unknown++;
		unknown_devices  = unknown_devices + "Daresbury (" + daresbury_name + ") : error getting PSS interlocks states !\n";
	}
	
#ifdef PRINT_TIME
	double t7 = get_ticks();
	printf("Time classic read Attribute : %.3f ms\n",t7-t6);
#endif
}

void LinacStateThread::update_variables_for_state(Tango::DevState deviceState)
{
	switch(deviceState)
	{
		case(Tango::ALARM):
			n_alarm++;
			break;
		case(Tango::FAULT):
			n_fault++;
			break;
		case(Tango::UNKNOWN):
			n_unknown++;
			break;
                default:
                    ;
	}
}

/***********************************************************************
* Function:		void refresh_state()
* 
* Description:		evalue the state of the linac and switch it.
* 
***********************************************************************/
void LinacStateThread::refresh_state()
{
	//cout << "Linac::refresh_state(): Entering ..." << endl;
	Tango::DevState	newstate;
	newstate = Tango::UNKNOWN;
	unknown_devices = "";
	fault_devices = 	"";
	alarm_devices = 	"";
	get_all_state();
	/*
	state evaluation: if the elin/rf/run is ON, -> LINAC is ON.
	else if there is a sub-system in fault, -> LINAC is in FAULT.
	else if the filament sub systems are OFF, the linac is OFF
	else if the filament is warming-up and the low-heating relay is CLOSED, ->INIT
	(Warmup)
	else if the filament is warming-up and the low-heating relay is OPEN, ->MOVING
	if filaments are ON and we are not ON -> STANDBY
	*/
	//cout << " >>>>>>>>>>>>> n_fault = " << n_fault << ", n_unknown = " << n_unknown << ", n_alarm = " << n_alarm << endl;
	if(n_fault>0)	newstate=Tango::FAULT;
	else if(n_unknown>0) newstate=Tango::UNKNOWN;
	else if(n_alarm>0) newstate=Tango::ALARM;
	else if(gun_aux_state==Tango::OFF || gun_aux_state==Tango::DISABLE || mod1_aux_state==Tango::OFF || mod1_aux_state==Tango::DISABLE || mod2_aux_state==Tango::DISABLE) newstate = Tango::OFF;
 
	else if(gun_state==Tango::ON && rf_run_state==Tango::ON) newstate = Tango::ON;
	else
	{
		if(mod1_aux_state == Tango::INIT)
		{
			// economy relay is closed
			newstate = Tango::INIT;
		}
		else
		{
	   		if(gun_aux_state==Tango::MOVING || mod1_aux_state==Tango::MOVING)
  	 		{
        	 		newstate = Tango::MOVING;
    			}
		}
    		if(gun_aux_state==Tango::ON && mod1_aux_state==Tango::ON)
    		{
      			newstate = Tango::STANDBY;
    		}
	}
	{
		omni_mutex_lock l(mutex);
		linacds->fault_status = fault_devices;
		linacds->unknown_status = unknown_devices;
		linacds->alarm_status = alarm_devices;
		linacds->thestate = newstate;
	}
}

/***********************************************************************
 * Function:		Tango::DevState get_device_state()
 * 
 * Description: read the state of a sub device
 * Arg(s) In: the sub device
 ***********************************************************************/
Tango::DevState LinacStateThread::get_device_state(Tango::DeviceProxy * device,const char* device_name, string full_device_name)
{
	Tango::DevState deviceState = Tango::UNKNOWN;
	try
	{
		Tango::DeviceAttribute devstateattr = device->read_attribute("State");
		devstateattr >> deviceState;
//		deviceState = device->state();
	}
	catch (Tango::DevFailed &e)
	{
		ERROR_STREAM << "Linac::get_device_state: An exception occured!" << endl;
		Tango::Except::print_exception(e);
		ERROR_STREAM << "cannot read state of " << device_name << " device."<< endl;			
		for (unsigned int i = 0; i<e.errors.length(); i++)
		{
			ERROR_STREAM << e.errors[i].desc.in() << endl;
		}
	}
	string desc_name(device_name);
	switch(deviceState)
	{
		case(Tango::ALARM):
			alarm_devices = alarm_devices + desc_name + " (" + full_device_name + ") is in ALARM state !\n";		
			n_alarm++;
			break;
		case(Tango::FAULT):
			fault_devices = fault_devices + desc_name + " (" + full_device_name + ") is in FAULT state !\n";
			n_fault++;
			break;
		case(Tango::UNKNOWN):
			unknown_devices  = unknown_devices + desc_name + " (" + full_device_name + ") is in UNKNOWN state !\n";
			n_unknown++;
			break;
                default:
                    ;
	}
	return deviceState;
}

/***********************************************************************
 * Function:		Tango::DevState get_device_state_no_alarm()
 * 
 * Description: read the state of a sub device
 * if the device is in alarm state, don't take it into account for 
 * the calculation of the linac global state
 * Arg(s) In: the sub device
 ***********************************************************************/
Tango::DevState LinacStateThread::get_device_state_no_alarm(Tango::DeviceProxy * device,const char* device_name, string full_device_name)
{
	Tango::DevState deviceState = Tango::UNKNOWN;
	try
	{
		Tango::DeviceAttribute devstateattr = device->read_attribute("State");
		devstateattr >> deviceState;
	}
	catch (Tango::DevFailed &e)
	{
		ERROR_STREAM << "Linac::get_device_state_no_alarm: An exception occured!" << endl;
		Tango::Except::print_exception(e);
		ERROR_STREAM << "cannot read state of " << device_name << " device."<< endl;			
		for (unsigned int i = 0; i<e.errors.length(); i++)
		{
			ERROR_STREAM << e.errors[i].desc.in() << endl;
		}
	}
	string desc_name(device_name);
	switch(deviceState)
	{
		case(Tango::ALARM):
			alarm_devices = alarm_devices + desc_name + " (" + full_device_name + ") is in ALARM state !\n";		
			// the device is not taken into account for the calculation of the Linac state :
			// n_alarm++; // the alarm is inhibited for this device
			break;
		case(Tango::FAULT):
			fault_devices = fault_devices + desc_name + " (" + full_device_name + ") is in FAULT state !\n";
			n_fault++;
			break;
		case(Tango::UNKNOWN):
			unknown_devices  = unknown_devices + desc_name + " (" + full_device_name + ") is in UNKNOWN state !\n";
			n_unknown++;
			break;
                default:
                    ;
	}
	return deviceState;
}


} // namespace
