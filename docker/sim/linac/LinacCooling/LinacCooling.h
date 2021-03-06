/*----- PROTECTED REGION ID(LinacCooling.h) ENABLED START -----*/
//=============================================================================
//
// file :        LinacCooling.h
//
// description : Include file for the LinacCooling class
//
// project :     Linac cooling
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


#ifndef LinacCooling_H
#define LinacCooling_H

#include <tango.h>





/*----- PROTECTED REGION END -----*/	//	LinacCooling.h

/**
 *  LinacCooling class description:
 *    This class will manage the linac cooling.
 */

namespace LinacCooling_ns
{
/*----- PROTECTED REGION ID(LinacCooling::Additional Class Declarations) ENABLED START -----*/

//	Additional Class Declarations

/*----- PROTECTED REGION END -----*/	//	LinacCooling::Additional Class Declarations

class LinacCooling : public TANGO_BASE_CLASS
{

/*----- PROTECTED REGION ID(LinacCooling::Data Members) ENABLED START -----*/

//	Add your own data members
public:



/*----- PROTECTED REGION END -----*/	//	LinacCooling::Data Members

//	Device property data members
public:
	//	BuncherTemp_adc:	ADC device to get the buncher temperature.
	string	buncherTemp_adc;
	//	Daresbury:	Name of the Daresbury device.
	string	daresbury;
	//	Interlocks_list:	Interlocks list.
	vector<Tango::DevDouble>	interlocks_list;
	//	PbuncherTemp_adc:	ADC device to get the prebuncher temperature.
	string	pbuncherTemp_adc;
	//	Pulsetime:	Duration in milliseconds of the pulse to do on the pulsed relays.
	Tango::DevLong	pulsetime;
	//	SectionTemp_adc:	ADC device to get the section temperature.
	string	sectionTemp_adc;
	//	Stateonnum:	Interlock number used to determine if the device is on or not.
	//  (ex 21.1
	Tango::DevDouble	stateonnum;
	//	WaterTemp_adc:	ADC device to get the water temperature.
	string	waterTemp_adc;

//	Attribute data members
public:
	Tango::DevDouble	*attr_WaterTemp_read;
	Tango::DevDouble	*attr_PBuncherTemp_read;
	Tango::DevDouble	*attr_BuncherTemp_read;
	Tango::DevDouble	*attr_SectionTemp_read;

//	Constructors and destructors
public:
	/**
	 * Constructs a newly device object.
	 *
	 *	@param cl	Class.
	 *	@param s 	Device Name
	 */
	LinacCooling(Tango::DeviceClass *cl,string &s);
	/**
	 * Constructs a newly device object.
	 *
	 *	@param cl	Class.
	 *	@param s 	Device Name
	 */
	LinacCooling(Tango::DeviceClass *cl,const char *s);
	/**
	 * Constructs a newly device object.
	 *
	 *	@param cl	Class.
	 *	@param s 	Device name
	 *	@param d	Device description.
	 */
	LinacCooling(Tango::DeviceClass *cl,const char *s,const char *d);
	/**
	 * The device object destructor.
	 */
	~LinacCooling() {delete_device();};


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
	 *	Method      : LinacCooling::read_attr_hardware()
	 *	Description : Hardware acquisition for attributes.
	 */
	//--------------------------------------------------------
	virtual void read_attr_hardware(vector<long> &attr_list);

/**
 *	Attribute WaterTemp related methods
 *	Description: Water Temperature
 *
 *	Data type:	Tango::DevDouble
 *	Attr type:	Scalar
 */
	virtual void read_WaterTemp(Tango::Attribute &attr);
	virtual bool is_WaterTemp_allowed(Tango::AttReqType type);
/**
 *	Attribute PBuncherTemp related methods
 *	Description: PreBuncher Temperature
 *
 *	Data type:	Tango::DevDouble
 *	Attr type:	Scalar
 */
	virtual void read_PBuncherTemp(Tango::Attribute &attr);
	virtual bool is_PBuncherTemp_allowed(Tango::AttReqType type);
/**
 *	Attribute BuncherTemp related methods
 *	Description: Buncher Temperature
 *
 *	Data type:	Tango::DevDouble
 *	Attr type:	Scalar
 */
	virtual void read_BuncherTemp(Tango::Attribute &attr);
	virtual bool is_BuncherTemp_allowed(Tango::AttReqType type);
/**
 *	Attribute SectionTemp related methods
 *	Description: Section Temperature
 *
 *	Data type:	Tango::DevDouble
 *	Attr type:	Scalar
 */
	virtual void read_SectionTemp(Tango::Attribute &attr);
	virtual bool is_SectionTemp_allowed(Tango::AttReqType type);


	//--------------------------------------------------------
	/**
	 *	Method      : LinacCooling::add_dynamic_attributes()
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
	 *	Command Reset related method
	 *	Description: 
	 *
	 */
	virtual void reset();
	virtual bool is_Reset_allowed(const CORBA::Any &any);


	//--------------------------------------------------------
	/**
	 *	Method      : LinacCooling::add_dynamic_commands()
	 *	Description : Add dynamic commands if any.
	 */
	//--------------------------------------------------------
	void add_dynamic_commands();

/*----- PROTECTED REGION ID(LinacCooling::Additional Method prototypes) ENABLED START -----*/

//	Additional Method prototypes
protected :	
	Tango::DeviceProxy * daresburyds;
	Tango::DeviceProxy * WaterTempadcds;
	Tango::DeviceProxy * PBuncherTempadcds;
	Tango::DeviceProxy * BuncherTempadcds;
	Tango::DeviceProxy * SectionTempadcds;
	Tango::DevState		n_state;
	Tango::DevState		thestate;
	vector<Tango::DevLong> interlocks;
	vector<unsigned char> intlk_states;
	vector<string> intlk_desc;
	string thestatus;
	void evalue_state();

/*----- PROTECTED REGION END -----*/	//	LinacCooling::Additional Method prototypes
};

/*----- PROTECTED REGION ID(LinacCooling::Additional Classes Definitions) ENABLED START -----*/

//	Additional Classes Definitions

/*----- PROTECTED REGION END -----*/	//	LinacCooling::Additional Classes Definitions

}	//	End of namespace

#endif   //	LinacCooling_H
