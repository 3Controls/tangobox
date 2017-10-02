/*----- PROTECTED REGION ID(LinacGun.h) ENABLED START -----*/
//=============================================================================
//
// file :        LinacGun.h
//
// description : Include file for the LinacGun class
//
// project :     Linac Gun
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


#ifndef LinacGun_H
#define LinacGun_H


#ifndef SIMU
#       include <API.h>
#       undef DevState
#endif
#include <tango.h>





/*----- PROTECTED REGION END -----*/	//	LinacGun.h

/**
 *  LinacGun class description:
 *    This class will manage the gun of the linac.
 *    The gun is the electrons source of the accelerator.
 *    It defines the pulsed characteristics of the electron beam (duration, rate).
 */

namespace LinacGun_ns
{
/*----- PROTECTED REGION ID(LinacGun::Additional Class Declarations) ENABLED START -----*/

//	Additional Class Declarations

/*----- PROTECTED REGION END -----*/	//	LinacGun::Additional Class Declarations

class LinacGun : public TANGO_BASE_CLASS
{

/*----- PROTECTED REGION ID(LinacGun::Data Members) ENABLED START -----*/

//	Add your own data members
public:
        Tango::DevDouble attr_PulseL_write;
        Tango::DevDouble attr_DeflectionDC_write;


/*----- PROTECTED REGION END -----*/	//	LinacGun::Data Members

//	Device property data members
public:
	//	Daresbury:	Name of the daresbury device.
	string	daresbury;
	//	GridV_adc:	ADC device to get the grid Voltage.
	string	gridV_adc;
	//	GridV_dac:	DAC device to set the grid voltage.
	string	gridV_dac;
	//	Offrelay:	Name of the relay used to switch off the gun.
	string	offrelay;
	//	Onrelay:	Name of the relay used to switch on the gun.
	string	onrelay;
	//	PulseL_dac:	DAC device to set the pulse length.
	string	pulseL_dac;
	//	Pulsetime:	Duration in milliseconds of the pulse to do on the pulsed relays.
	Tango::DevLong	pulsetime;
	//	PulseV_adc:	ADC device to get the pulse voltage.
	string	pulseV_adc;
	//	PulseV_dac:	DAC device to set the pulse voltage.
	string	pulseV_dac;
	//	Short_relay:	Name of the short relay device.
	string	short_relay;
	//	Stateonnum:	number of the interlock relay used to determine whether the Gun
	//  is on or not.
	Tango::DevDouble	stateonnum;
	//	Statepermnum:	Daresbury relay number which indicates if the device is allowed
	//  to be switched On.
	Tango::DevDouble	statepermnum;
	//	PulsePowerSupplyDeviceName:	This is the Tango name of the TDKLambda zup power supply used
	//  for the PulseV.
	string	pulsePowerSupplyDeviceName;
	//	GridPowerSupplyDeviceName:	This is the Tango name of the TDKLambda zup power supply used
	//  for the Grid.
	string	gridPowerSupplyDeviceName;
	//	DelayDeviceName:	Shot timing device name.
	//  VPDU board device name
	string	delayDeviceName;
	//	DeflexionDC_dac:	This is the tango device name of the SDac712 board to use, in order
	//  to handle set/read of the deflection direct current.
	string	deflexionDC_dac;
	//	Cleaning_relay_devicename:	This is the device name of the wago relay mapped on Cleaning attribute.
	string	cleaning_relay_devicename;

//	Attribute data members
public:
	Tango::DevDouble	*attr_PulseV_read;
	Tango::DevDouble	*attr_PulseL_read;
	Tango::DevDouble	*attr_GridV_read;
	Tango::DevString	*attr_PulseType_read;
	Tango::DevDouble	*attr_Delay_read;
	Tango::DevDouble	*attr_DeflectionDC_read;
	Tango::DevBoolean	*attr_Cleaning_read;

//	Constructors and destructors
public:
	/**
	 * Constructs a newly device object.
	 *
	 *	@param cl	Class.
	 *	@param s 	Device Name
	 */
	LinacGun(Tango::DeviceClass *cl,string &s);
	/**
	 * Constructs a newly device object.
	 *
	 *	@param cl	Class.
	 *	@param s 	Device Name
	 */
	LinacGun(Tango::DeviceClass *cl,const char *s);
	/**
	 * Constructs a newly device object.
	 *
	 *	@param cl	Class.
	 *	@param s 	Device name
	 *	@param d	Device description.
	 */
	LinacGun(Tango::DeviceClass *cl,const char *s,const char *d);
	/**
	 * The device object destructor.
	 */
	~LinacGun() {delete_device();};


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
	 *	Method      : LinacGun::read_attr_hardware()
	 *	Description : Hardware acquisition for attributes.
	 */
	//--------------------------------------------------------
	virtual void read_attr_hardware(vector<long> &attr_list);
	//--------------------------------------------------------
	/*
	 *	Method      : LinacGun::write_attr_hardware()
	 *	Description : Hardware writing for attributes.
	 */
	//--------------------------------------------------------
	virtual void write_attr_hardware(vector<long> &attr_list);

/**
 *	Attribute PulseV related methods
 *	Description: Pulse Voltage
 *
 *	Data type:	Tango::DevDouble
 *	Attr type:	Scalar
 */
	virtual void read_PulseV(Tango::Attribute &attr);
	virtual void write_PulseV(Tango::WAttribute &attr);
	virtual bool is_PulseV_allowed(Tango::AttReqType type);
/**
 *	Attribute PulseL related methods
 *	Description: Pulse length
 *
 *	Data type:	Tango::DevDouble
 *	Attr type:	Scalar
 */
	virtual void read_PulseL(Tango::Attribute &attr);
	virtual void write_PulseL(Tango::WAttribute &attr);
	virtual bool is_PulseL_allowed(Tango::AttReqType type);
/**
 *	Attribute GridV related methods
 *	Description: Grid Voltage
 *
 *	Data type:	Tango::DevDouble
 *	Attr type:	Scalar
 */
	virtual void read_GridV(Tango::Attribute &attr);
	virtual void write_GridV(Tango::WAttribute &attr);
	virtual bool is_GridV_allowed(Tango::AttReqType type);
/**
 *	Attribute PulseType related methods
 *	Description: Pulse Type :\nPossible values are : short or long
 *
 *	Data type:	Tango::DevString
 *	Attr type:	Scalar
 */
	virtual void read_PulseType(Tango::Attribute &attr);
	virtual void write_PulseType(Tango::WAttribute &attr);
	virtual bool is_PulseType_allowed(Tango::AttReqType type);
/**
 *	Attribute Delay related methods
 *	Description: 
 *
 *	Data type:	Tango::DevDouble
 *	Attr type:	Scalar
 */
	virtual void read_Delay(Tango::Attribute &attr);
	virtual void write_Delay(Tango::WAttribute &attr);
	virtual bool is_Delay_allowed(Tango::AttReqType type);
/**
 *	Attribute DeflectionDC related methods
 *	Description: This if the DC value applied to the DAC that handles\nthe deflection plate in the linac cleaning system.
 *
 *	Data type:	Tango::DevDouble
 *	Attr type:	Scalar
 */
	virtual void read_DeflectionDC(Tango::Attribute &attr);
	virtual void write_DeflectionDC(Tango::WAttribute &attr);
	virtual bool is_DeflectionDC_allowed(Tango::AttReqType type);
/**
 *	Attribute Cleaning related methods
 *	Description: This boolean value allow/prohibit cleaning system.\nIt only handle a relay given in property device.
 *
 *	Data type:	Tango::DevBoolean
 *	Attr type:	Scalar
 */
	virtual void read_Cleaning(Tango::Attribute &attr);
	virtual void write_Cleaning(Tango::WAttribute &attr);
	virtual bool is_Cleaning_allowed(Tango::AttReqType type);


	//--------------------------------------------------------
	/**
	 *	Method      : LinacGun::add_dynamic_attributes()
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


	//--------------------------------------------------------
	/**
	 *	Method      : LinacGun::add_dynamic_commands()
	 *	Description : Add dynamic commands if any.
	 */
	//--------------------------------------------------------
	void add_dynamic_commands();

/*----- PROTECTED REGION ID(LinacGun::Additional Method prototypes) ENABLED START -----*/

//	Additional Method prototypes
protected :	
	Tango::DeviceProxy * daresburyds;
	Tango::DeviceProxy * OffRelayds;
	Tango::DeviceProxy * OnRelayds;
	Tango::DeviceProxy * ShortRelayds;
#ifndef SIMU
	bool tacoDelay_imported;
        devserver delay_tacods;
	DevShort Delay_State;
#endif

	// Cleaning device proxies.
	Tango::DeviceProxy * deflectionDCDS;
	Tango::DeviceProxy * cleaningRelayDS;

	Tango::DeviceProxy * gridPowerSupplyDS;
	Tango::DeviceProxy * pulsePowerSupplyDS;
	Tango::DeviceProxy * pulseLdacds;
	Tango::DeviceProxy * Linacds;
	Tango::DeviceProxy * myself;
	vector<Tango::DevLong> interlocks;
	vector<unsigned char> intlk_states;
	vector<string> intlk_desc;
	string thestatus;
	Tango::DevState n_state;
	Tango::DevState thestate;
	struct timespec pulsewaittime;
	void read_adc_val(Tango::DeviceProxy * adcds,Tango::DevDouble *readval);
	void update_setval(Tango::DeviceProxy * dacds,const char* attr_name,Tango::DevDouble *setvalue);
	void write_dac_val(Tango::DeviceProxy * dacds,Tango::DevDouble setvalue);
	void evalue_state();
/**
 *     list of interlocks.
 */
	vector<double>  interlocks_list;

/*----- PROTECTED REGION END -----*/	//	LinacGun::Additional Method prototypes
};

/*----- PROTECTED REGION ID(LinacGun::Additional Classes Definitions) ENABLED START -----*/

//	Additional Classes Definitions

/*----- PROTECTED REGION END -----*/	//	LinacGun::Additional Classes Definitions

}	//	End of namespace

#endif   //	LinacGun_H