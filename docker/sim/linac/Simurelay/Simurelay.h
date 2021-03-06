/*----- PROTECTED REGION ID(Simurelay.h) ENABLED START -----*/
//=============================================================================
//
// file :        Simurelay.h
//
// description : Include file for the Simurelay class
//
// project :     simulation relay server
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


#ifndef Simurelay_H
#define Simurelay_H

#include <tango.h>





/*----- PROTECTED REGION END -----*/	//	Simurelay.h

/**
 *  Simurelay class description:
 *    Simulation relay server to test GUI of the Linac.
 */

namespace Simurelay_ns
{
/*----- PROTECTED REGION ID(Simurelay::Additional Class Declarations) ENABLED START -----*/

//	Additional Class Declarations

/*----- PROTECTED REGION END -----*/	//	Simurelay::Additional Class Declarations

class Simurelay : public Tango::Device_4Impl
{

/*----- PROTECTED REGION ID(Simurelay::Data Members) ENABLED START -----*/

//	Add your own data members
public:



/*----- PROTECTED REGION END -----*/	//	Simurelay::Data Members



//	Constructors and destructors
public:
	/**
	 * Constructs a newly device object.
	 *
	 *	@param cl	Class.
	 *	@param s 	Device Name
	 */
	Simurelay(Tango::DeviceClass *cl,string &s);
	/**
	 * Constructs a newly device object.
	 *
	 *	@param cl	Class.
	 *	@param s 	Device Name
	 */
	Simurelay(Tango::DeviceClass *cl,const char *s);
	/**
	 * Constructs a newly device object.
	 *
	 *	@param cl	Class.
	 *	@param s 	Device name
	 *	@param d	Device description.
	 */
	Simurelay(Tango::DeviceClass *cl,const char *s,const char *d);
	/**
	 * The device object destructor.
	 */	
	~Simurelay() {delete_device();};


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
	 *	Always executed method before execution command method.
	 */
	virtual void always_executed_hook();


//	Attribute methods
public:
	//--------------------------------------------------------
	/*
	 *	Method      : Simurelay::read_attr_hardware()
	 *	Description : Hardware acquisition for attributes.
	 */
	//--------------------------------------------------------
	virtual void read_attr_hardware(vector<long> &attr_list);


	//--------------------------------------------------------
	/**
	 *	Method      : Simurelay::add_dynamic_attributes()
	 *	Description : Add dynamic attributes if any.
	 */
	//--------------------------------------------------------
	void add_dynamic_attributes();



//	Command related methods
public:
	/**
	 *	Command Open related method
	 *	Description: 
	 *
	 */
	virtual void open();
	virtual bool is_Open_allowed(const CORBA::Any &any);
	/**
	 *	Command Close related method
	 *	Description: 
	 *
	 */
	virtual void close();
	virtual bool is_Close_allowed(const CORBA::Any &any);
	/**
	 *	Command Pulse related method
	 *	Description: 
	 *
	 *	@param argin 
	 */
	virtual void pulse(Tango::DevLong argin);
	virtual bool is_Pulse_allowed(const CORBA::Any &any);


/*----- PROTECTED REGION ID(Simurelay::Additional Method prototypes) ENABLED START -----*/

//	Additional Method prototypes
protected :

/*----- PROTECTED REGION END -----*/	//	Simurelay::Additional Method prototypes
};

/*----- PROTECTED REGION ID(Simurelay::Additional Classes Definitions) ENABLED START -----*/

//	Additional Classes Definitions

/*----- PROTECTED REGION END -----*/	//	Simurelay::Additional Classes Definitions

}	//	End of namespace

#endif   //	Simurelay_H
