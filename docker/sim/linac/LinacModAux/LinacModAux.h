/*----- PROTECTED REGION ID(LinacModAux.h) ENABLED START -----*/
//=============================================================================
//
// file :        LinacModAux.h
//
// description : Include file for the LinacModAux class
//
// project :     Linac Modulator Auxiliary
//
// This file is part of Tango device class.
// 
// Tango is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// Tango is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
// 
// You should have received a copy of the GNU General Public License
// along with Tango.  If not, see <http://www.gnu.org/licenses/>.
// 
// $Author:  $
//
// $Revision:  $
// $Date:  $
//
// $HeadURL:  $
//
//=============================================================================
//                This file is generated by POGO
//        (Program Obviously used to Generate tango Object)
//=============================================================================


#ifndef LinacModAux_H
#define LinacModAux_H

#include <tango.h>





/*----- PROTECTED REGION END -----*/	//	LinacModAux.h

/**
 *  LinacModAux class description:
 *    This class will manage the modulator auxiliaries of the Linac.
 */

namespace LinacModAux_ns
{
/*----- PROTECTED REGION ID(LinacModAux::Additional Class Declarations) ENABLED START -----*/

//	Additional Class Declarations

/*----- PROTECTED REGION END -----*/	//	LinacModAux::Additional Class Declarations

class LinacModAux : public TANGO_BASE_CLASS
{

/*----- PROTECTED REGION ID(LinacModAux::Data Members) ENABLED START -----*/

//	Add your own data members
public:
    Tango::DevBoolean attr_Economy_write;



/*----- PROTECTED REGION END -----*/	//	LinacModAux::Data Members

//	Device property data members
public:
	//	Daresbury:	Name of the daresbury device.
	string	daresbury;
	//	Heat_time:	Heating time (in seconds).
	Tango::DevLong	heat_time;
	//	Interlocks_list:	list of interlocks.
	vector<Tango::DevDouble>	interlocks_list;
	//	Offrelay:	Name of the relay used to switch off the Modulator Auxiliary.
	string	offrelay;
	//	Onrelay:	Name of the relay used to switch on the Modulator Auxiliary.
	string	onrelay;
	//	Pulsetime:	Duration in milliseconds of the pulse to do on the pulsed relays.
	Tango::DevLong	pulsetime;
	//	Stateheatnum:	Daresbury relay number which indicates if the device is heating or not.
	Tango::DevDouble	stateheatnum;
	//	Stateonnum:	Daresbury relay number used to determine whether the modulator
	//  auxiliary is on or not.
	Tango::DevDouble	stateonnum;
	//	ThyratronHeatV_adc:	ADC device to read the Thyratron Heating Voltage.
	string	thyratronHeatV_adc;
	//	HeaterPS_device:	Heater Power Supply device name
	string	heaterPS_device;
	//	Economyrelay:	Name of the economy relay device.
	string	economyrelay;

//	Attribute data members
public:
	Tango::DevDouble	*attr_HeatI_read;
	Tango::DevDouble	*attr_HeatV_read;
	Tango::DevShort	*attr_Temporization_read;
	Tango::DevDouble	*attr_ThyratronHeatV_read;
	Tango::DevBoolean	*attr_Economy_read;

//	Constructors and destructors
public:
	/**
	 * Constructs a newly device object.
	 *
	 *	@param cl	Class.
	 *	@param s 	Device Name
	 */
	LinacModAux(Tango::DeviceClass *cl,string &s);
	/**
	 * Constructs a newly device object.
	 *
	 *	@param cl	Class.
	 *	@param s 	Device Name
	 */
	LinacModAux(Tango::DeviceClass *cl,const char *s);
	/**
	 * Constructs a newly device object.
	 *
	 *	@param cl	Class.
	 *	@param s 	Device name
	 *	@param d	Device description.
	 */
	LinacModAux(Tango::DeviceClass *cl,const char *s,const char *d);
	/**
	 * The device object destructor.
	 */
	~LinacModAux() {delete_device();};


//	Miscellaneous methods
public:
	/*
	 *	will be called at device destruction or at init command.
	 */
	void delete_device();
	/*
	 *	Initialize the device
	 */
	virtual void init_device();
	/*
	 *	Read the device properties from database
	 */
	void get_device_property();
	/*
	 *	Always executed method before execution command method.
	 */
	virtual void always_executed_hook();


//	Attribute methods
public:
	//--------------------------------------------------------
	/*
	 *	Method      : LinacModAux::read_attr_hardware()
	 *	Description : Hardware acquisition for attributes.
	 */
	//--------------------------------------------------------
	virtual void read_attr_hardware(vector<long> &attr_list);
	//--------------------------------------------------------
	/*
	 *	Method      : LinacModAux::write_attr_hardware()
	 *	Description : Hardware writing for attributes.
	 */
	//--------------------------------------------------------
	virtual void write_attr_hardware(vector<long> &attr_list);

/**
 *	Attribute HeatI related methods
 *	Description: Heating current
 *
 *	Data type:	Tango::DevDouble
 *	Attr type:	Scalar
 */
	virtual void read_HeatI(Tango::Attribute &attr);
	virtual bool is_HeatI_allowed(Tango::AttReqType type);
/**
 *	Attribute HeatV related methods
 *	Description: Heating Voltage
 *
 *	Data type:	Tango::DevDouble
 *	Attr type:	Scalar
 */
	virtual void read_HeatV(Tango::Attribute &attr);
	virtual bool is_HeatV_allowed(Tango::AttReqType type);
/**
 *	Attribute Temporization related methods
 *	Description: remaining time before the ON state.
 *
 *	Data type:	Tango::DevShort
 *	Attr type:	Scalar
 */
	virtual void read_Temporization(Tango::Attribute &attr);
	virtual bool is_Temporization_allowed(Tango::AttReqType type);
/**
 *	Attribute ThyratronHeatV related methods
 *	Description: Thyratron Heat Voltage.
 *
 *	Data type:	Tango::DevDouble
 *	Attr type:	Scalar
 */
	virtual void read_ThyratronHeatV(Tango::Attribute &attr);
	virtual bool is_ThyratronHeatV_allowed(Tango::AttReqType type);
/**
 *	Attribute Economy related methods
 *	Description: Economy mode.\nTrue = economy relay closed.\nFalse = economy relay open.
 *
 *	Data type:	Tango::DevBoolean
 *	Attr type:	Scalar
 */
	virtual void read_Economy(Tango::Attribute &attr);
	virtual void write_Economy(Tango::WAttribute &attr);
	virtual bool is_Economy_allowed(Tango::AttReqType type);


	//--------------------------------------------------------
	/**
	 *	Method      : LinacModAux::add_dynamic_attributes()
	 *	Description : Add dynamic attributes if any.
	 */
	//--------------------------------------------------------
	void add_dynamic_attributes();




//	Command related methods
public:
	/**
	 *	Command State related method
	 *	Description: This command gets the device state (stored in its <i>device_state</i> data member) and returns it to the caller.
	 *
	 *	@returns State Code
	 */
	virtual Tango::DevState dev_state();
	/**
	 *	Command Status related method
	 *	Description: This command gets the device status (stored in its <i>device_status</i> data member) and returns it to the caller.
	 *
	 *	@returns Status description
	 */
	virtual Tango::ConstDevString dev_status();
	/**
	 *	Command On related method
	 *	Description: 
	 *
	 */
	virtual void on();
	virtual bool is_On_allowed(const CORBA::Any &any);
	/**
	 *	Command Off related method
	 *	Description: 
	 *
	 */
	virtual void off();
	virtual bool is_Off_allowed(const CORBA::Any &any);
	/**
	 *	Command Reset related method
	 *	Description: 
	 *
	 */
	virtual void reset();
	virtual bool is_Reset_allowed(const CORBA::Any &any);
	/**
	 *	Command Standby related method
	 *	Description: Put the auxiliary in Standby State.
	 *
	 */
	virtual void standby();
	virtual bool is_Standby_allowed(const CORBA::Any &any);
	/**
	 *	Command LowHeating related method
	 *	Description: Put the auxiliary in low heating state.
	 *
	 */
	virtual void low_heating();
	virtual bool is_LowHeating_allowed(const CORBA::Any &any);
	/**
	 *	Command SoftOff related method
	 *	Description: Specify that we would like to reach Off state.
	 *               Do not execute Pulse command on the OffRelay.
	 *
	 */
	virtual void soft_off();
	virtual bool is_SoftOff_allowed(const CORBA::Any &any);
	/**
	 *	Command SoftOn related method
	 *	Description: Specify that we would like to reach On state.
	 *               Do not execute Pulse command on the OnRelay.
	 *
	 */
	virtual void soft_on();
	virtual bool is_SoftOn_allowed(const CORBA::Any &any);


	//--------------------------------------------------------
	/**
	 *	Method      : LinacModAux::add_dynamic_commands()
	 *	Description : Add dynamic commands if any.
	 */
	//--------------------------------------------------------
	void add_dynamic_commands();

/*----- PROTECTED REGION ID(LinacModAux::Additional Method prototypes) ENABLED START -----*/

//	Additional Method prototypes
protected :	
	long OnDate;
	Tango::DeviceProxy * daresburyds;
	Tango::DeviceProxy * EcoRelayds;
	Tango::DeviceProxy * OffRelayds;
	Tango::DeviceProxy * OnRelayds;
	Tango::DeviceProxy * HeaterPSds;
	Tango::DeviceProxy * ThyratronHeatVadcds;
	Tango::DevState HeaterPSState;
	Tango::DevState DaresburyState;
	vector<Tango::DevLong> interlocks;
	vector<unsigned char> intlk_states;
	vector<string> intlk_desc;
	string thestatus;
	Tango::DevState n_state;
	Tango::DevState thestate;
	Tango::DevState lastState;
	struct timespec pulsewaittime;
	void read_adc_val(Tango::DeviceProxy * adcds,Tango::DevDouble *readval);
	void evalue_state();

/*----- PROTECTED REGION END -----*/	//	LinacModAux::Additional Method prototypes
};

/*----- PROTECTED REGION ID(LinacModAux::Additional Classes Definitions) ENABLED START -----*/

//	Additional Classes Definitions

/*----- PROTECTED REGION END -----*/	//	LinacModAux::Additional Classes Definitions

}	//	End of namespace

#endif   //	LinacModAux_H
