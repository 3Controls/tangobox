/*----- PROTECTED REGION ID(LinacModulatorClass.h) ENABLED START -----*/
//=============================================================================
//
// file :        LinacModulatorClass.h
//
// description : Include for the LinacModulator root class.
//               This class is the singleton class for
//                the LinacModulator device class.
//               It contains all properties and methods which the 
//               LinacModulator requires only once e.g. the commands.
//
// project :     LinacModulator
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


#ifndef LinacModulatorClass_H
#define LinacModulatorClass_H

#include <tango.h>
#include <LinacModulator.h>

/*----- PROTECTED REGION END -----*/	//	LinacModulatorClass.h


namespace LinacModulator_ns
{
/*----- PROTECTED REGION ID(LinacModulatorClass::classes for dynamic creation) ENABLED START -----*/


/*----- PROTECTED REGION END -----*/	//	LinacModulatorClass::classes for dynamic creation

//=========================================
//	Define classes for attributes
//=========================================
//	Attribute VPFN class definition
class VPFNAttrib: public Tango::Attr
{
public:
	VPFNAttrib():Attr("VPFN",
			Tango::DEV_DOUBLE, Tango::READ_WRITE) {};
	~VPFNAttrib() {};
	virtual void read(Tango::DeviceImpl *dev,Tango::Attribute &att)
		{(static_cast<LinacModulator *>(dev))->read_VPFN(att);}
	virtual void write(Tango::DeviceImpl *dev,Tango::WAttribute &att)
		{(static_cast<LinacModulator *>(dev))->write_VPFN(att);}
	virtual bool is_allowed(Tango::DeviceImpl *dev,Tango::AttReqType ty)
		{return (static_cast<LinacModulator *>(dev))->is_VPFN_allowed(ty);}
};

//	Attribute Delay class definition
class DelayAttrib: public Tango::Attr
{
public:
	DelayAttrib():Attr("Delay",
			Tango::DEV_DOUBLE, Tango::READ_WRITE) {};
	~DelayAttrib() {};
	virtual void read(Tango::DeviceImpl *dev,Tango::Attribute &att)
		{(static_cast<LinacModulator *>(dev))->read_Delay(att);}
	virtual void write(Tango::DeviceImpl *dev,Tango::WAttribute &att)
		{(static_cast<LinacModulator *>(dev))->write_Delay(att);}
	virtual bool is_allowed(Tango::DeviceImpl *dev,Tango::AttReqType ty)
		{return (static_cast<LinacModulator *>(dev))->is_Delay_allowed(ty);}
};

//	Attribute DelayS class definition
class DelaySAttrib: public Tango::Attr
{
public:
	DelaySAttrib():Attr("DelayS",
			Tango::DEV_DOUBLE, Tango::READ_WRITE) {};
	~DelaySAttrib() {};
	virtual void read(Tango::DeviceImpl *dev,Tango::Attribute &att)
		{(static_cast<LinacModulator *>(dev))->read_DelayS(att);}
	virtual void write(Tango::DeviceImpl *dev,Tango::WAttribute &att)
		{(static_cast<LinacModulator *>(dev))->write_DelayS(att);}
	virtual bool is_allowed(Tango::DeviceImpl *dev,Tango::AttReqType ty)
		{return (static_cast<LinacModulator *>(dev))->is_DelayS_allowed(ty);}
};

//	Attribute KlystronPeakI class definition
class KlystronPeakIAttrib: public Tango::Attr
{
public:
	KlystronPeakIAttrib():Attr("KlystronPeakI",
			Tango::DEV_DOUBLE, Tango::READ) {};
	~KlystronPeakIAttrib() {};
	virtual void read(Tango::DeviceImpl *dev,Tango::Attribute &att)
		{(static_cast<LinacModulator *>(dev))->read_KlystronPeakI(att);}
	virtual bool is_allowed(Tango::DeviceImpl *dev,Tango::AttReqType ty)
		{return (static_cast<LinacModulator *>(dev))->is_KlystronPeakI_allowed(ty);}
};

//	Attribute KlystronPeakV class definition
class KlystronPeakVAttrib: public Tango::Attr
{
public:
	KlystronPeakVAttrib():Attr("KlystronPeakV",
			Tango::DEV_DOUBLE, Tango::READ) {};
	~KlystronPeakVAttrib() {};
	virtual void read(Tango::DeviceImpl *dev,Tango::Attribute &att)
		{(static_cast<LinacModulator *>(dev))->read_KlystronPeakV(att);}
	virtual bool is_allowed(Tango::DeviceImpl *dev,Tango::AttReqType ty)
		{return (static_cast<LinacModulator *>(dev))->is_KlystronPeakV_allowed(ty);}
};

//	Attribute PeakPowerIn class definition
class PeakPowerInAttrib: public Tango::Attr
{
public:
	PeakPowerInAttrib():Attr("PeakPowerIn",
			Tango::DEV_DOUBLE, Tango::READ) {};
	~PeakPowerInAttrib() {};
	virtual void read(Tango::DeviceImpl *dev,Tango::Attribute &att)
		{(static_cast<LinacModulator *>(dev))->read_PeakPowerIn(att);}
	virtual bool is_allowed(Tango::DeviceImpl *dev,Tango::AttReqType ty)
		{return (static_cast<LinacModulator *>(dev))->is_PeakPowerIn_allowed(ty);}
};

//	Attribute PeakPowerOut class definition
class PeakPowerOutAttrib: public Tango::Attr
{
public:
	PeakPowerOutAttrib():Attr("PeakPowerOut",
			Tango::DEV_DOUBLE, Tango::READ) {};
	~PeakPowerOutAttrib() {};
	virtual void read(Tango::DeviceImpl *dev,Tango::Attribute &att)
		{(static_cast<LinacModulator *>(dev))->read_PeakPowerOut(att);}
	virtual bool is_allowed(Tango::DeviceImpl *dev,Tango::AttReqType ty)
		{return (static_cast<LinacModulator *>(dev))->is_PeakPowerOut_allowed(ty);}
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
	{return (static_cast<LinacModulator *>(dev))->is_On_allowed(any);}
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
	{return (static_cast<LinacModulator *>(dev))->is_Off_allowed(any);}
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
	{return (static_cast<LinacModulator *>(dev))->is_Reset_allowed(any);}
};

//	Command TimingOn class definition
class TimingOnClass : public Tango::Command
{
public:
	TimingOnClass(const char   *name,
	               Tango::CmdArgType in,
				   Tango::CmdArgType out,
				   const char        *in_desc,
				   const char        *out_desc,
				   Tango::DispLevel  level)
	:Command(name,in,out,in_desc,out_desc, level)	{};

	TimingOnClass(const char   *name,
	               Tango::CmdArgType in,
				   Tango::CmdArgType out)
	:Command(name,in,out)	{};
	~TimingOnClass() {};
	
	virtual CORBA::Any *execute (Tango::DeviceImpl *dev, const CORBA::Any &any);
	virtual bool is_allowed (Tango::DeviceImpl *dev, const CORBA::Any &any)
	{return (static_cast<LinacModulator *>(dev))->is_TimingOn_allowed(any);}
};

//	Command SoftOn class definition
class SoftOnClass : public Tango::Command
{
public:
	SoftOnClass(const char   *name,
	               Tango::CmdArgType in,
				   Tango::CmdArgType out,
				   const char        *in_desc,
				   const char        *out_desc,
				   Tango::DispLevel  level)
	:Command(name,in,out,in_desc,out_desc, level)	{};

	SoftOnClass(const char   *name,
	               Tango::CmdArgType in,
				   Tango::CmdArgType out)
	:Command(name,in,out)	{};
	~SoftOnClass() {};
	
	virtual CORBA::Any *execute (Tango::DeviceImpl *dev, const CORBA::Any &any);
	virtual bool is_allowed (Tango::DeviceImpl *dev, const CORBA::Any &any)
	{return (static_cast<LinacModulator *>(dev))->is_SoftOn_allowed(any);}
};

//	Command SoftOff class definition
class SoftOffClass : public Tango::Command
{
public:
	SoftOffClass(const char   *name,
	               Tango::CmdArgType in,
				   Tango::CmdArgType out,
				   const char        *in_desc,
				   const char        *out_desc,
				   Tango::DispLevel  level)
	:Command(name,in,out,in_desc,out_desc, level)	{};

	SoftOffClass(const char   *name,
	               Tango::CmdArgType in,
				   Tango::CmdArgType out)
	:Command(name,in,out)	{};
	~SoftOffClass() {};
	
	virtual CORBA::Any *execute (Tango::DeviceImpl *dev, const CORBA::Any &any);
	virtual bool is_allowed (Tango::DeviceImpl *dev, const CORBA::Any &any)
	{return (static_cast<LinacModulator *>(dev))->is_SoftOff_allowed(any);}
};


/**
 *	The LinacModulatorClass singleton definition
 */

#ifdef _TG_WINDOWS_
class __declspec(dllexport)  LinacModulatorClass : public Tango::DeviceClass
#else
class LinacModulatorClass : public Tango::DeviceClass
#endif
{
	/*----- PROTECTED REGION ID(LinacModulatorClass::Additionnal DServer data members) ENABLED START -----*/
	
	
	/*----- PROTECTED REGION END -----*/	//	LinacModulatorClass::Additionnal DServer data members

	public:
		//	write class properties data members
		Tango::DbData	cl_prop;
		Tango::DbData	cl_def_prop;
		Tango::DbData	dev_def_prop;
	
		//	Method prototypes
		static LinacModulatorClass *init(const char *);
		static LinacModulatorClass *instance();
		~LinacModulatorClass();
		Tango::DbDatum	get_class_property(string &);
		Tango::DbDatum	get_default_device_property(string &);
		Tango::DbDatum	get_default_class_property(string &);
	
	protected:
		LinacModulatorClass(string &);
		static LinacModulatorClass *_instance;
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

#endif   //	LinacModulator_H