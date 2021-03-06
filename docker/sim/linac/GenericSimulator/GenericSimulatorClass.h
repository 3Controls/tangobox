/*----- PROTECTED REGION ID(GenericSimulatorClass.h) ENABLED START -----*/
//=============================================================================
//
// file :        GenericSimulatorClass.h
//
// description : Include for the GenericSimulator root class.
//               This class is the singleton class for
//                the GenericSimulator device class.
//               It contains all properties and methods which the 
//               GenericSimulator requires only once e.g. the commands.
//
// project :     GenericSimulator
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
// $Author: tappret $
//
// $Revision: 1.2 $
// $Date: 2013-08-08 09:50:39 $
//
// $HeadURL:  $
//
//=============================================================================
//                This file is generated by POGO
//        (Program Obviously used to Generate tango Object)
//=============================================================================


#ifndef GenericSimulatorClass_H
#define GenericSimulatorClass_H

#include <tango.h>
#include <GenericSimulator.h>


/*----- PROTECTED REGION END -----*/	//	GenericSimulatorClass.h


namespace GenericSimulator_ns
{
/*----- PROTECTED REGION ID(GenericSimulatorClass::classes for dynamic creation) ENABLED START -----*/


/*----- PROTECTED REGION END -----*/	//	GenericSimulatorClass::classes for dynamic creation

//=========================================
//	Define classes for attributes
//=========================================
//	Attribute Rocknroll class definition
class RocknrollAttrib: public Tango::Attr
{
public:
	RocknrollAttrib():Attr("Rocknroll",
			Tango::DEV_DOUBLE, Tango::READ_WRITE) {};
	~RocknrollAttrib() {};
	virtual void read(Tango::DeviceImpl *dev,Tango::Attribute &att)
		{(static_cast<GenericSimulator *>(dev))->read_Rocknroll(att);}
	virtual void write(Tango::DeviceImpl *dev,Tango::WAttribute &att)
		{(static_cast<GenericSimulator *>(dev))->write_Rocknroll(att);}
	virtual bool is_allowed(Tango::DeviceImpl *dev,Tango::AttReqType ty)
		{return (static_cast<GenericSimulator *>(dev))->is_Rocknroll_allowed(ty);}
};

//	Attribute Frequency class definition
class FrequencyAttrib: public Tango::Attr
{
public:
	FrequencyAttrib():Attr("Frequency",
			Tango::DEV_DOUBLE, Tango::READ_WRITE) {};
	~FrequencyAttrib() {};
	virtual void read(Tango::DeviceImpl *dev,Tango::Attribute &att)
		{(static_cast<GenericSimulator *>(dev))->read_Frequency(att);}
	virtual void write(Tango::DeviceImpl *dev,Tango::WAttribute &att)
		{(static_cast<GenericSimulator *>(dev))->write_Frequency(att);}
	virtual bool is_allowed(Tango::DeviceImpl *dev,Tango::AttReqType ty)
		{return (static_cast<GenericSimulator *>(dev))->is_Frequency_allowed(ty);}
};

//	Attribute Value class definition
class ValueAttrib: public Tango::Attr
{
public:
	ValueAttrib():Attr("Value",
			Tango::DEV_DOUBLE, Tango::READ_WRITE) {};
	~ValueAttrib() {};
	virtual void read(Tango::DeviceImpl *dev,Tango::Attribute &att)
		{(static_cast<GenericSimulator *>(dev))->read_Value(att);}
	virtual void write(Tango::DeviceImpl *dev,Tango::WAttribute &att)
		{(static_cast<GenericSimulator *>(dev))->write_Value(att);}
	virtual bool is_allowed(Tango::DeviceImpl *dev,Tango::AttReqType ty)
		{return (static_cast<GenericSimulator *>(dev))->is_Value_allowed(ty);}
};

//	Attribute Position class definition
class PositionAttrib: public Tango::Attr
{
public:
	PositionAttrib():Attr("Position",
			Tango::DEV_DOUBLE, Tango::READ_WRITE) {};
	~PositionAttrib() {};
	virtual void read(Tango::DeviceImpl *dev,Tango::Attribute &att)
		{(static_cast<GenericSimulator *>(dev))->read_Position(att);}
	virtual void write(Tango::DeviceImpl *dev,Tango::WAttribute &att)
		{(static_cast<GenericSimulator *>(dev))->write_Position(att);}
	virtual bool is_allowed(Tango::DeviceImpl *dev,Tango::AttReqType ty)
		{return (static_cast<GenericSimulator *>(dev))->is_Position_allowed(ty);}
};

//	Attribute Current class definition
class CurrentAttrib: public Tango::Attr
{
public:
	CurrentAttrib():Attr("Current",
			Tango::DEV_DOUBLE, Tango::READ_WRITE) {};
	~CurrentAttrib() {};
	virtual void read(Tango::DeviceImpl *dev,Tango::Attribute &att)
		{(static_cast<GenericSimulator *>(dev))->read_Current(att);}
	virtual void write(Tango::DeviceImpl *dev,Tango::WAttribute &att)
		{(static_cast<GenericSimulator *>(dev))->write_Current(att);}
	virtual bool is_allowed(Tango::DeviceImpl *dev,Tango::AttReqType ty)
		{return (static_cast<GenericSimulator *>(dev))->is_Current_allowed(ty);}
};

//	Attribute Interlocks class definition
class InterlocksAttrib: public Tango::SpectrumAttr
{
public:
	InterlocksAttrib():SpectrumAttr("Interlocks",
			Tango::DEV_SHORT, Tango::READ, 22) {};
	~InterlocksAttrib() {};
	virtual void read(Tango::DeviceImpl *dev,Tango::Attribute &att)
		{(static_cast<GenericSimulator *>(dev))->read_Interlocks(att);}
	virtual bool is_allowed(Tango::DeviceImpl *dev,Tango::AttReqType ty)
		{return (static_cast<GenericSimulator *>(dev))->is_Interlocks_allowed(ty);}
};


//=========================================
//	Define classes for commands
//=========================================
//	Command On class definition
class OnClass : public Tango::Command
{
public:
	OnClass(const char   *name,
	               Tango::CmdArgType in,
				   Tango::CmdArgType out,
				   const char        *in_desc,
				   const char        *out_desc,
				   Tango::DispLevel  level)
	:Command(name,in,out,in_desc,out_desc, level)	{};

	OnClass(const char   *name,
	               Tango::CmdArgType in,
				   Tango::CmdArgType out)
	:Command(name,in,out)	{};
	~OnClass() {};
	
	virtual CORBA::Any *execute (Tango::DeviceImpl *dev, const CORBA::Any &any);
	virtual bool is_allowed (Tango::DeviceImpl *dev, const CORBA::Any &any)
	{return (static_cast<GenericSimulator *>(dev))->is_On_allowed(any);}
};

//	Command Off class definition
class OffClass : public Tango::Command
{
public:
	OffClass(const char   *name,
	               Tango::CmdArgType in,
				   Tango::CmdArgType out,
				   const char        *in_desc,
				   const char        *out_desc,
				   Tango::DispLevel  level)
	:Command(name,in,out,in_desc,out_desc, level)	{};

	OffClass(const char   *name,
	               Tango::CmdArgType in,
				   Tango::CmdArgType out)
	:Command(name,in,out)	{};
	~OffClass() {};
	
	virtual CORBA::Any *execute (Tango::DeviceImpl *dev, const CORBA::Any &any);
	virtual bool is_allowed (Tango::DeviceImpl *dev, const CORBA::Any &any)
	{return (static_cast<GenericSimulator *>(dev))->is_Off_allowed(any);}
};

//	Command Reset class definition
class ResetClass : public Tango::Command
{
public:
	ResetClass(const char   *name,
	               Tango::CmdArgType in,
				   Tango::CmdArgType out,
				   const char        *in_desc,
				   const char        *out_desc,
				   Tango::DispLevel  level)
	:Command(name,in,out,in_desc,out_desc, level)	{};

	ResetClass(const char   *name,
	               Tango::CmdArgType in,
				   Tango::CmdArgType out)
	:Command(name,in,out)	{};
	~ResetClass() {};
	
	virtual CORBA::Any *execute (Tango::DeviceImpl *dev, const CORBA::Any &any);
	virtual bool is_allowed (Tango::DeviceImpl *dev, const CORBA::Any &any)
	{return (static_cast<GenericSimulator *>(dev))->is_Reset_allowed(any);}
};

//	Command GetInterlockState class definition
class GetInterlockStateClass : public Tango::Command
{
public:
	GetInterlockStateClass(const char   *name,
	               Tango::CmdArgType in,
				   Tango::CmdArgType out,
				   const char        *in_desc,
				   const char        *out_desc,
				   Tango::DispLevel  level)
	:Command(name,in,out,in_desc,out_desc, level)	{};

	GetInterlockStateClass(const char   *name,
	               Tango::CmdArgType in,
				   Tango::CmdArgType out)
	:Command(name,in,out)	{};
	~GetInterlockStateClass() {};
	
	virtual CORBA::Any *execute (Tango::DeviceImpl *dev, const CORBA::Any &any);
	virtual bool is_allowed (Tango::DeviceImpl *dev, const CORBA::Any &any)
	{return (static_cast<GenericSimulator *>(dev))->is_GetInterlockState_allowed(any);}
};

//	Command GetInterlockDescription class definition
class GetInterlockDescriptionClass : public Tango::Command
{
public:
	GetInterlockDescriptionClass(const char   *name,
	               Tango::CmdArgType in,
				   Tango::CmdArgType out,
				   const char        *in_desc,
				   const char        *out_desc,
				   Tango::DispLevel  level)
	:Command(name,in,out,in_desc,out_desc, level)	{};

	GetInterlockDescriptionClass(const char   *name,
	               Tango::CmdArgType in,
				   Tango::CmdArgType out)
	:Command(name,in,out)	{};
	~GetInterlockDescriptionClass() {};
	
	virtual CORBA::Any *execute (Tango::DeviceImpl *dev, const CORBA::Any &any);
	virtual bool is_allowed (Tango::DeviceImpl *dev, const CORBA::Any &any)
	{return (static_cast<GenericSimulator *>(dev))->is_GetInterlockDescription_allowed(any);}
};

//	Command SetInterlockState class definition
class SetInterlockStateClass : public Tango::Command
{
public:
	SetInterlockStateClass(const char   *name,
	               Tango::CmdArgType in,
				   Tango::CmdArgType out,
				   const char        *in_desc,
				   const char        *out_desc,
				   Tango::DispLevel  level)
	:Command(name,in,out,in_desc,out_desc, level)	{};

	SetInterlockStateClass(const char   *name,
	               Tango::CmdArgType in,
				   Tango::CmdArgType out)
	:Command(name,in,out)	{};
	~SetInterlockStateClass() {};
	
	virtual CORBA::Any *execute (Tango::DeviceImpl *dev, const CORBA::Any &any);
	virtual bool is_allowed (Tango::DeviceImpl *dev, const CORBA::Any &any)
	{return (static_cast<GenericSimulator *>(dev))->is_SetInterlockState_allowed(any);}
};

//	Command StopPolling class definition
class StopPollingClass : public Tango::Command
{
public:
	StopPollingClass(const char   *name,
	               Tango::CmdArgType in,
				   Tango::CmdArgType out,
				   const char        *in_desc,
				   const char        *out_desc,
				   Tango::DispLevel  level)
	:Command(name,in,out,in_desc,out_desc, level)	{};

	StopPollingClass(const char   *name,
	               Tango::CmdArgType in,
				   Tango::CmdArgType out)
	:Command(name,in,out)	{};
	~StopPollingClass() {};
	
	virtual CORBA::Any *execute (Tango::DeviceImpl *dev, const CORBA::Any &any);
	virtual bool is_allowed (Tango::DeviceImpl *dev, const CORBA::Any &any)
	{return (static_cast<GenericSimulator *>(dev))->is_StopPolling_allowed(any);}
};

//	Command StartPolling class definition
class StartPollingClass : public Tango::Command
{
public:
	StartPollingClass(const char   *name,
	               Tango::CmdArgType in,
				   Tango::CmdArgType out,
				   const char        *in_desc,
				   const char        *out_desc,
				   Tango::DispLevel  level)
	:Command(name,in,out,in_desc,out_desc, level)	{};

	StartPollingClass(const char   *name,
	               Tango::CmdArgType in,
				   Tango::CmdArgType out)
	:Command(name,in,out)	{};
	~StartPollingClass() {};
	
	virtual CORBA::Any *execute (Tango::DeviceImpl *dev, const CORBA::Any &any);
	virtual bool is_allowed (Tango::DeviceImpl *dev, const CORBA::Any &any)
	{return (static_cast<GenericSimulator *>(dev))->is_StartPolling_allowed(any);}
};

//	Command changeState class definition
class changeStateClass : public Tango::Command
{
public:
	changeStateClass(const char   *name,
	               Tango::CmdArgType in,
				   Tango::CmdArgType out,
				   const char        *in_desc,
				   const char        *out_desc,
				   Tango::DispLevel  level)
	:Command(name,in,out,in_desc,out_desc, level)	{};

	changeStateClass(const char   *name,
	               Tango::CmdArgType in,
				   Tango::CmdArgType out)
	:Command(name,in,out)	{};
	~changeStateClass() {};
	
	virtual CORBA::Any *execute (Tango::DeviceImpl *dev, const CORBA::Any &any);
	virtual bool is_allowed (Tango::DeviceImpl *dev, const CORBA::Any &any)
	{return (static_cast<GenericSimulator *>(dev))->is_changeState_allowed(any);}
};


/**
 *	The GenericSimulatorClass singleton definition
 */

#ifdef _TG_WINDOWS_
class __declspec(dllexport)  GenericSimulatorClass : public Tango::DeviceClass
#else
class GenericSimulatorClass : public Tango::DeviceClass
#endif
{
	/*----- PROTECTED REGION ID(GenericSimulatorClass::Additionnal DServer data members) ENABLED START -----*/
	
	
	/*----- PROTECTED REGION END -----*/	//	GenericSimulatorClass::Additionnal DServer data members

	public:
		//	write class properties data members
		Tango::DbData	cl_prop;
		Tango::DbData	cl_def_prop;
		Tango::DbData	dev_def_prop;
	
		//	Method prototypes
		static GenericSimulatorClass *init(const char *);
		static GenericSimulatorClass *instance();
		~GenericSimulatorClass();
		Tango::DbDatum	get_class_property(string &);
		Tango::DbDatum	get_default_device_property(string &);
		Tango::DbDatum	get_default_class_property(string &);
	
	protected:
		GenericSimulatorClass(string &);
		static GenericSimulatorClass *_instance;
		void command_factory();
		void attribute_factory(vector<Tango::Attr *> &);
		void pipe_factory();
		void write_class_property();
		void set_default_property();
		void get_class_property();
		string get_cvstag();
		string get_cvsroot();
	
	private:
		void device_factory(const Tango::DevVarStringArray *);
		void create_static_attribute_list(vector<Tango::Attr *> &);
		void erase_dynamic_attributes(const Tango::DevVarStringArray *,vector<Tango::Attr *> &);
		vector<string>	defaultAttList;
		Tango::Attr *get_attr_object_by_name(vector<Tango::Attr *> &att_list, string attname);
};

}	//	End of namespace

#endif   //	GenericSimulator_H
