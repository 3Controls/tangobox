/*----- PROTECTED REGION ID(LinacModulatorClass.cpp) ENABLED START -----*/
static const char *RcsId      = "$Id:  $";
static const char *TagName    = "$Name:  $";
static const char *CvsPath    = "$Source:  $";
static const char *SvnPath    = "$HeadURL:  $";
static const char *HttpServer = "http://www.esrf.eu/computing/cs/tango/tango_doc/ds_doc/";
//=============================================================================
//
// file :        LinacModulatorClass.cpp
//
// description : C++ source for the LinacModulatorClass.
//               A singleton class derived from DeviceClass.
//               It implements the command and attribute list
//               and all properties and methods required
//               by the LinacModulator once per process.
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


#include <tango.h>
#include <LinacModulator.h>
#include <LinacModulatorClass.h>

/*----- PROTECTED REGION END -----*/	//	LinacModulatorClass.cpp

//-------------------------------------------------------------------
/**
 *	Create LinacModulatorClass singleton and
 *	return it in a C function for Python usage
 */
//-------------------------------------------------------------------
extern "C" {
#ifdef _TG_WINDOWS_

__declspec(dllexport)

#endif

	Tango::DeviceClass *_create_LinacModulator_class(const char *name) {
		return LinacModulator_ns::LinacModulatorClass::init(name);
	}
}

namespace LinacModulator_ns
{
//===================================================================
//	Initialize pointer for singleton pattern
//===================================================================
LinacModulatorClass *LinacModulatorClass::_instance = NULL;

//--------------------------------------------------------
/**
 * method : 		LinacModulatorClass::LinacModulatorClass(string &s)
 * description : 	constructor for the LinacModulatorClass
 *
 * @param s	The class name
 */
//--------------------------------------------------------
LinacModulatorClass::LinacModulatorClass(string &s):Tango::DeviceClass(s)
{
	cout2 << "Entering LinacModulatorClass constructor" << endl;
	set_default_property();
	write_class_property();

	/*----- PROTECTED REGION ID(LinacModulatorClass::constructor) ENABLED START -----*/
	
	/*----- PROTECTED REGION END -----*/	//	LinacModulatorClass::constructor

	cout2 << "Leaving LinacModulatorClass constructor" << endl;
}

//--------------------------------------------------------
/**
 * method : 		LinacModulatorClass::~LinacModulatorClass()
 * description : 	destructor for the LinacModulatorClass
 */
//--------------------------------------------------------
LinacModulatorClass::~LinacModulatorClass()
{
	/*----- PROTECTED REGION ID(LinacModulatorClass::destructor) ENABLED START -----*/
	
	/*----- PROTECTED REGION END -----*/	//	LinacModulatorClass::destructor

	_instance = NULL;
}


//--------------------------------------------------------
/**
 * method : 		LinacModulatorClass::init
 * description : 	Create the object if not already done.
 *                  Otherwise, just return a pointer to the object
 *
 * @param	name	The class name
 */
//--------------------------------------------------------
LinacModulatorClass *LinacModulatorClass::init(const char *name)
{
	if (_instance == NULL)
	{
		try
		{
			string s(name);
			_instance = new LinacModulatorClass(s);
		}
		catch (bad_alloc &)
		{
			throw;
		}
	}
	return _instance;
}

//--------------------------------------------------------
/**
 * method : 		LinacModulatorClass::instance
 * description : 	Check if object already created,
 *                  and return a pointer to the object
 */
//--------------------------------------------------------
LinacModulatorClass *LinacModulatorClass::instance()
{
	if (_instance == NULL)
	{
		cerr << "Class is not initialised !!" << endl;
		exit(-1);
	}
	return _instance;
}



//===================================================================
//	Command execution method calls
//===================================================================
//--------------------------------------------------------
/**
 * method : 		OnClass::execute()
 * description : 	method to trigger the execution of the command.
 *
 * @param	device	The device on which the command must be executed
 * @param	in_any	The command input data
 *
 *	returns The command output data (packed in the Any object)
 */
//--------------------------------------------------------
CORBA::Any *OnClass::execute(Tango::DeviceImpl *device, TANGO_UNUSED(const CORBA::Any &in_any))
{
	cout2 << "OnClass::execute(): arrived" << endl;
	((static_cast<LinacModulator *>(device))->on());
	return new CORBA::Any();
}

//--------------------------------------------------------
/**
 * method : 		OffClass::execute()
 * description : 	method to trigger the execution of the command.
 *
 * @param	device	The device on which the command must be executed
 * @param	in_any	The command input data
 *
 *	returns The command output data (packed in the Any object)
 */
//--------------------------------------------------------
CORBA::Any *OffClass::execute(Tango::DeviceImpl *device, TANGO_UNUSED(const CORBA::Any &in_any))
{
	cout2 << "OffClass::execute(): arrived" << endl;
	((static_cast<LinacModulator *>(device))->off());
	return new CORBA::Any();
}

//--------------------------------------------------------
/**
 * method : 		ResetClass::execute()
 * description : 	method to trigger the execution of the command.
 *
 * @param	device	The device on which the command must be executed
 * @param	in_any	The command input data
 *
 *	returns The command output data (packed in the Any object)
 */
//--------------------------------------------------------
CORBA::Any *ResetClass::execute(Tango::DeviceImpl *device, TANGO_UNUSED(const CORBA::Any &in_any))
{
	cout2 << "ResetClass::execute(): arrived" << endl;
	((static_cast<LinacModulator *>(device))->reset());
	return new CORBA::Any();
}

//--------------------------------------------------------
/**
 * method : 		TimingOnClass::execute()
 * description : 	method to trigger the execution of the command.
 *
 * @param	device	The device on which the command must be executed
 * @param	in_any	The command input data
 *
 *	returns The command output data (packed in the Any object)
 */
//--------------------------------------------------------
CORBA::Any *TimingOnClass::execute(Tango::DeviceImpl *device, TANGO_UNUSED(const CORBA::Any &in_any))
{
	cout2 << "TimingOnClass::execute(): arrived" << endl;
	((static_cast<LinacModulator *>(device))->timing_on());
	return new CORBA::Any();
}

//--------------------------------------------------------
/**
 * method : 		SoftOnClass::execute()
 * description : 	method to trigger the execution of the command.
 *
 * @param	device	The device on which the command must be executed
 * @param	in_any	The command input data
 *
 *	returns The command output data (packed in the Any object)
 */
//--------------------------------------------------------
CORBA::Any *SoftOnClass::execute(Tango::DeviceImpl *device, TANGO_UNUSED(const CORBA::Any &in_any))
{
	cout2 << "SoftOnClass::execute(): arrived" << endl;
	((static_cast<LinacModulator *>(device))->soft_on());
	return new CORBA::Any();
}

//--------------------------------------------------------
/**
 * method : 		SoftOffClass::execute()
 * description : 	method to trigger the execution of the command.
 *
 * @param	device	The device on which the command must be executed
 * @param	in_any	The command input data
 *
 *	returns The command output data (packed in the Any object)
 */
//--------------------------------------------------------
CORBA::Any *SoftOffClass::execute(Tango::DeviceImpl *device, TANGO_UNUSED(const CORBA::Any &in_any))
{
	cout2 << "SoftOffClass::execute(): arrived" << endl;
	((static_cast<LinacModulator *>(device))->soft_off());
	return new CORBA::Any();
}


//===================================================================
//	Properties management
//===================================================================
//--------------------------------------------------------
/**
 *	Method      : LinacModulatorClass::get_class_property()
 *	Description : Get the class property for specified name.
 */
//--------------------------------------------------------
Tango::DbDatum LinacModulatorClass::get_class_property(string &prop_name)
{
	for (unsigned int i=0 ; i<cl_prop.size() ; i++)
		if (cl_prop[i].name == prop_name)
			return cl_prop[i];
	//	if not found, returns  an empty DbDatum
	return Tango::DbDatum(prop_name);
}

//--------------------------------------------------------
/**
 *	Method      : LinacModulatorClass::get_default_device_property()
 *	Description : Return the default value for device property.
 */
//--------------------------------------------------------
Tango::DbDatum LinacModulatorClass::get_default_device_property(string &prop_name)
{
	for (unsigned int i=0 ; i<dev_def_prop.size() ; i++)
		if (dev_def_prop[i].name == prop_name)
			return dev_def_prop[i];
	//	if not found, return  an empty DbDatum
	return Tango::DbDatum(prop_name);
}

//--------------------------------------------------------
/**
 *	Method      : LinacModulatorClass::get_default_class_property()
 *	Description : Return the default value for class property.
 */
//--------------------------------------------------------
Tango::DbDatum LinacModulatorClass::get_default_class_property(string &prop_name)
{
	for (unsigned int i=0 ; i<cl_def_prop.size() ; i++)
		if (cl_def_prop[i].name == prop_name)
			return cl_def_prop[i];
	//	if not found, return  an empty DbDatum
	return Tango::DbDatum(prop_name);
}


//--------------------------------------------------------
/**
 *	Method      : LinacModulatorClass::set_default_property()
 *	Description : Set default property (class and device) for wizard.
 *                For each property, add to wizard property name and description.
 *                If default value has been set, add it to wizard property and
 *                store it in a DbDatum.
 */
//--------------------------------------------------------
void LinacModulatorClass::set_default_property()
{
	string	prop_name;
	string	prop_desc;
	string	prop_def;
	vector<string>	vect_data;

	//	Set Default Class Properties

	//	Set Default device Properties
	prop_name = "Daresbury";
	prop_desc = "Name of the daresbury device.";
	prop_def  = "";
	vect_data.clear();
	if (prop_def.length()>0)
	{
		Tango::DbDatum	data(prop_name);
		data << vect_data ;
		dev_def_prop.push_back(data);
		add_wiz_dev_prop(prop_name, prop_desc,  prop_def);
	}
	else
		add_wiz_dev_prop(prop_name, prop_desc);
	prop_name = "Delay_name";
	prop_desc = "Name of the device used to read and set the Delay Attribute.";
	prop_def  = "";
	vect_data.clear();
	if (prop_def.length()>0)
	{
		Tango::DbDatum	data(prop_name);
		data << vect_data ;
		dev_def_prop.push_back(data);
		add_wiz_dev_prop(prop_name, prop_desc,  prop_def);
	}
	else
		add_wiz_dev_prop(prop_name, prop_desc);
	prop_name = "DelayS_name";
	prop_desc = "Name of the device used to read and set the DelayS Attribute.";
	prop_def  = "";
	vect_data.clear();
	if (prop_def.length()>0)
	{
		Tango::DbDatum	data(prop_name);
		data << vect_data ;
		dev_def_prop.push_back(data);
		add_wiz_dev_prop(prop_name, prop_desc,  prop_def);
	}
	else
		add_wiz_dev_prop(prop_name, prop_desc);
	prop_name = "Interlocks_list";
	prop_desc = "list of interlocks.";
	prop_def  = "";
	vect_data.clear();
	if (prop_def.length()>0)
	{
		Tango::DbDatum	data(prop_name);
		data << vect_data ;
		dev_def_prop.push_back(data);
		add_wiz_dev_prop(prop_name, prop_desc,  prop_def);
	}
	else
		add_wiz_dev_prop(prop_name, prop_desc);
	prop_name = "KlystPeakI_adc";
	prop_desc = "Adc device used to get the Klystron Peak I value.";
	prop_def  = "";
	vect_data.clear();
	if (prop_def.length()>0)
	{
		Tango::DbDatum	data(prop_name);
		data << vect_data ;
		dev_def_prop.push_back(data);
		add_wiz_dev_prop(prop_name, prop_desc,  prop_def);
	}
	else
		add_wiz_dev_prop(prop_name, prop_desc);
	prop_name = "KlystPeakV_adc";
	prop_desc = "ADC device used to get the Klystron Peak V value.";
	prop_def  = "";
	vect_data.clear();
	if (prop_def.length()>0)
	{
		Tango::DbDatum	data(prop_name);
		data << vect_data ;
		dev_def_prop.push_back(data);
		add_wiz_dev_prop(prop_name, prop_desc,  prop_def);
	}
	else
		add_wiz_dev_prop(prop_name, prop_desc);
	prop_name = "Offrelay";
	prop_desc = "Name of the relay used to switch off the device.";
	prop_def  = "";
	vect_data.clear();
	if (prop_def.length()>0)
	{
		Tango::DbDatum	data(prop_name);
		data << vect_data ;
		dev_def_prop.push_back(data);
		add_wiz_dev_prop(prop_name, prop_desc,  prop_def);
	}
	else
		add_wiz_dev_prop(prop_name, prop_desc);
	prop_name = "Onrelay";
	prop_desc = "Name of the relay used to switch on the device.";
	prop_def  = "";
	vect_data.clear();
	if (prop_def.length()>0)
	{
		Tango::DbDatum	data(prop_name);
		data << vect_data ;
		dev_def_prop.push_back(data);
		add_wiz_dev_prop(prop_name, prop_desc,  prop_def);
	}
	else
		add_wiz_dev_prop(prop_name, prop_desc);
	prop_name = "PeakPowerIn_adc";
	prop_desc = "ADC device used to get Peak Power In value.";
	prop_def  = "";
	vect_data.clear();
	if (prop_def.length()>0)
	{
		Tango::DbDatum	data(prop_name);
		data << vect_data ;
		dev_def_prop.push_back(data);
		add_wiz_dev_prop(prop_name, prop_desc,  prop_def);
	}
	else
		add_wiz_dev_prop(prop_name, prop_desc);
	prop_name = "PeakPowerOut_adc";
	prop_desc = "ADC device used to get Peak Power Out value.";
	prop_def  = "";
	vect_data.clear();
	if (prop_def.length()>0)
	{
		Tango::DbDatum	data(prop_name);
		data << vect_data ;
		dev_def_prop.push_back(data);
		add_wiz_dev_prop(prop_name, prop_desc,  prop_def);
	}
	else
		add_wiz_dev_prop(prop_name, prop_desc);
	prop_name = "Pulsetime";
	prop_desc = "Duration in milliseconds of the pulse to do on the pulsed relays.";
	prop_def  = "";
	vect_data.clear();
	if (prop_def.length()>0)
	{
		Tango::DbDatum	data(prop_name);
		data << vect_data ;
		dev_def_prop.push_back(data);
		add_wiz_dev_prop(prop_name, prop_desc,  prop_def);
	}
	else
		add_wiz_dev_prop(prop_name, prop_desc);
	prop_name = "Resetrelay";
	prop_desc = "name of the reset relay.";
	prop_def  = "";
	vect_data.clear();
	if (prop_def.length()>0)
	{
		Tango::DbDatum	data(prop_name);
		data << vect_data ;
		dev_def_prop.push_back(data);
		add_wiz_dev_prop(prop_name, prop_desc,  prop_def);
	}
	else
		add_wiz_dev_prop(prop_name, prop_desc);
	prop_name = "Stateonnum";
	prop_desc = "number of the interlock relay used to determine whether the device\nis on or not.";
	prop_def  = "";
	vect_data.clear();
	if (prop_def.length()>0)
	{
		Tango::DbDatum	data(prop_name);
		data << vect_data ;
		dev_def_prop.push_back(data);
		add_wiz_dev_prop(prop_name, prop_desc,  prop_def);
	}
	else
		add_wiz_dev_prop(prop_name, prop_desc);
	prop_name = "Statepermnum";
	prop_desc = "Daresbury relay number which indicates if the device is allowed\nto be switched On.";
	prop_def  = "";
	vect_data.clear();
	if (prop_def.length()>0)
	{
		Tango::DbDatum	data(prop_name);
		data << vect_data ;
		dev_def_prop.push_back(data);
		add_wiz_dev_prop(prop_name, prop_desc,  prop_def);
	}
	else
		add_wiz_dev_prop(prop_name, prop_desc);
	prop_name = "VPFN_adc";
	prop_desc = "ADC device to get the VPFN value.";
	prop_def  = "";
	vect_data.clear();
	if (prop_def.length()>0)
	{
		Tango::DbDatum	data(prop_name);
		data << vect_data ;
		dev_def_prop.push_back(data);
		add_wiz_dev_prop(prop_name, prop_desc,  prop_def);
	}
	else
		add_wiz_dev_prop(prop_name, prop_desc);
	prop_name = "VPFN_dac";
	prop_desc = "DAC device used to set VPFN.";
	prop_def  = "";
	vect_data.clear();
	if (prop_def.length()>0)
	{
		Tango::DbDatum	data(prop_name);
		data << vect_data ;
		dev_def_prop.push_back(data);
		add_wiz_dev_prop(prop_name, prop_desc,  prop_def);
	}
	else
		add_wiz_dev_prop(prop_name, prop_desc);
}

//--------------------------------------------------------
/**
 *	Method      : LinacModulatorClass::write_class_property()
 *	Description : Set class description fields as property in database
 */
//--------------------------------------------------------
void LinacModulatorClass::write_class_property()
{
	//	First time, check if database used
	if (Tango::Util::_UseDb == false)
		return;

	Tango::DbData	data;
	string	classname = get_name();
	string	header;
	string::size_type	start, end;

	//	Put title
	Tango::DbDatum	title("ProjectTitle");
	string	str_title("LinacModulator");
	title << str_title;
	data.push_back(title);

	//	Put Description
	Tango::DbDatum	description("Description");
	vector<string>	str_desc;
	str_desc.push_back("The linac is equiped with two identical modulators, supplying two klystrons");
	str_desc.push_back("with the power necessary for the two 6 meters accelerating sections,");
	str_desc.push_back("and for the buncher.");
	str_desc.push_back("The klystrons are multicavity amplifiers.");
	str_desc.push_back("The two modulators are line type with a Pulse Forming Network (PFN)");
	str_desc.push_back("short circuited by a thyratron through the primary of a pulse transformer.");
	str_desc.push_back("The secondary of this transformer supplies the klystron cathode");
	str_desc.push_back("with a 280kV pulse.");
	description << str_desc;
	data.push_back(description);

	//	put cvs or svn location
	string	filename("LinacModulator");
	filename += "Class.cpp";

	// check for cvs information
	string	src_path(CvsPath);
	start = src_path.find("/");
	if (start!=string::npos)
	{
		end   = src_path.find(filename);
		if (end>start)
		{
			string	strloc = src_path.substr(start, end-start);
			//	Check if specific repository
			start = strloc.find("/cvsroot/");
			if (start!=string::npos && start>0)
			{
				string	repository = strloc.substr(0, start);
				if (repository.find("/segfs/")!=string::npos)
					strloc = "ESRF:" + strloc.substr(start, strloc.length()-start);
			}
			Tango::DbDatum	cvs_loc("cvs_location");
			cvs_loc << strloc;
			data.push_back(cvs_loc);
		}
	}

	// check for svn information
	else
	{
		string	src_path(SvnPath);
		start = src_path.find("://");
		if (start!=string::npos)
		{
			end = src_path.find(filename);
			if (end>start)
			{
				header = "$HeadURL: ";
				start = header.length();
				string	strloc = src_path.substr(start, (end-start));
				
				Tango::DbDatum	svn_loc("svn_location");
				svn_loc << strloc;
				data.push_back(svn_loc);
			}
		}
	}

	//	Get CVS or SVN revision tag
	
	// CVS tag
	string	tagname(TagName);
	header = "$Name: ";
	start = header.length();
	string	endstr(" $");
	
	end   = tagname.find(endstr);
	if (end!=string::npos && end>start)
	{
		string	strtag = tagname.substr(start, end-start);
		Tango::DbDatum	cvs_tag("cvs_tag");
		cvs_tag << strtag;
		data.push_back(cvs_tag);
	}
	
	// SVN tag
	string	svnpath(SvnPath);
	header = "$HeadURL: ";
	start = header.length();
	
	end   = svnpath.find(endstr);
	if (end!=string::npos && end>start)
	{
		string	strloc = svnpath.substr(start, end-start);
		
		string tagstr ("/tags/");
		start = strloc.find(tagstr);
		if ( start!=string::npos )
		{
			start = start + tagstr.length();
			end   = strloc.find(filename);
			string	strtag = strloc.substr(start, end-start-1);
			
			Tango::DbDatum	svn_tag("svn_tag");
			svn_tag << strtag;
			data.push_back(svn_tag);
		}
	}

	//	Get URL location
	string	httpServ(HttpServer);
	if (httpServ.length()>0)
	{
		Tango::DbDatum	db_doc_url("doc_url");
		db_doc_url << httpServ;
		data.push_back(db_doc_url);
	}

	//  Put inheritance
	Tango::DbDatum	inher_datum("InheritedFrom");
	vector<string> inheritance;
	inheritance.push_back("TANGO_BASE_CLASS");
	inher_datum << inheritance;
	data.push_back(inher_datum);

	//	Call database and and values
	get_db_class()->put_property(data);
}

//===================================================================
//	Factory methods
//===================================================================

//--------------------------------------------------------
/**
 *	Method      : LinacModulatorClass::device_factory()
 *	Description : Create the device object(s)
 *                and store them in the device list
 */
//--------------------------------------------------------
void LinacModulatorClass::device_factory(const Tango::DevVarStringArray *devlist_ptr)
{
	/*----- PROTECTED REGION ID(LinacModulatorClass::device_factory_before) ENABLED START -----*/
	
	//	Add your own code
	
	/*----- PROTECTED REGION END -----*/	//	LinacModulatorClass::device_factory_before

	//	Create devices and add it into the device list
	for (unsigned long i=0 ; i<devlist_ptr->length() ; i++)
	{
		cout4 << "Device name : " << (*devlist_ptr)[i].in() << endl;
		device_list.push_back(new LinacModulator(this, (*devlist_ptr)[i]));
	}

	//	Manage dynamic attributes if any
	erase_dynamic_attributes(devlist_ptr, get_class_attr()->get_attr_list());

	//	Export devices to the outside world
	for (unsigned long i=1 ; i<=devlist_ptr->length() ; i++)
	{
		//	Add dynamic attributes if any
		LinacModulator *dev = static_cast<LinacModulator *>(device_list[device_list.size()-i]);
		dev->add_dynamic_attributes();

		//	Check before if database used.
		if ((Tango::Util::_UseDb == true) && (Tango::Util::_FileDb == false))
			export_device(dev);
		else
			export_device(dev, dev->get_name().c_str());
	}

	/*----- PROTECTED REGION ID(LinacModulatorClass::device_factory_after) ENABLED START -----*/
	
	//	Add your own code
	
	/*----- PROTECTED REGION END -----*/	//	LinacModulatorClass::device_factory_after
}
//--------------------------------------------------------
/**
 *	Method      : LinacModulatorClass::attribute_factory()
 *	Description : Create the attribute object(s)
 *                and store them in the attribute list
 */
//--------------------------------------------------------
void LinacModulatorClass::attribute_factory(vector<Tango::Attr *> &att_list)
{
	/*----- PROTECTED REGION ID(LinacModulatorClass::attribute_factory_before) ENABLED START -----*/
	
	//	Add your own code
	
	/*----- PROTECTED REGION END -----*/	//	LinacModulatorClass::attribute_factory_before
	//	Attribute : VPFN
	VPFNAttrib	*vpfn = new VPFNAttrib();
	Tango::UserDefaultAttrProp	vpfn_prop;
	vpfn_prop.set_description("Voltage Pulse Forming Network.");
	vpfn_prop.set_label("VPFN");
	vpfn_prop.set_unit("kV");
	vpfn_prop.set_standard_unit("kV");
	vpfn_prop.set_display_unit("kV");
	vpfn_prop.set_format("%4.2f");
	//	max_value	not set for VPFN
	//	min_value	not set for VPFN
	//	max_alarm	not set for VPFN
	//	min_alarm	not set for VPFN
	//	max_warning	not set for VPFN
	//	min_warning	not set for VPFN
	//	delta_t	not set for VPFN
	//	delta_val	not set for VPFN
	
	vpfn->set_default_properties(vpfn_prop);
	//	Not Polled
	vpfn->set_disp_level(Tango::OPERATOR);
	vpfn->set_memorized();
	vpfn->set_memorized_init(true);
	att_list.push_back(vpfn);

	//	Attribute : Delay
	DelayAttrib	*delay = new DelayAttrib();
	Tango::UserDefaultAttrProp	delay_prop;
	delay_prop.set_description("Delay");
	delay_prop.set_label("Delay");
	delay_prop.set_unit("ms");
	delay_prop.set_standard_unit("ms");
	delay_prop.set_display_unit("ms");
	delay_prop.set_format("%5.2f");
	//	max_value	not set for Delay
	//	min_value	not set for Delay
	//	max_alarm	not set for Delay
	//	min_alarm	not set for Delay
	//	max_warning	not set for Delay
	//	min_warning	not set for Delay
	//	delta_t	not set for Delay
	//	delta_val	not set for Delay
	
	delay->set_default_properties(delay_prop);
	//	Not Polled
	delay->set_disp_level(Tango::OPERATOR);
	delay->set_memorized();
	delay->set_memorized_init(true);
	att_list.push_back(delay);

	//	Attribute : DelayS
	DelaySAttrib	*delays = new DelaySAttrib();
	Tango::UserDefaultAttrProp	delays_prop;
	delays_prop.set_description("DelayS");
	delays_prop.set_label("DelayS");
	delays_prop.set_unit("ms");
	delays_prop.set_standard_unit("ms");
	delays_prop.set_display_unit("ms");
	delays_prop.set_format("%5.2f");
	//	max_value	not set for DelayS
	//	min_value	not set for DelayS
	//	max_alarm	not set for DelayS
	//	min_alarm	not set for DelayS
	//	max_warning	not set for DelayS
	//	min_warning	not set for DelayS
	//	delta_t	not set for DelayS
	//	delta_val	not set for DelayS
	
	delays->set_default_properties(delays_prop);
	//	Not Polled
	delays->set_disp_level(Tango::OPERATOR);
	delays->set_memorized();
	delays->set_memorized_init(true);
	att_list.push_back(delays);

	//	Attribute : KlystronPeakI
	KlystronPeakIAttrib	*klystronpeaki = new KlystronPeakIAttrib();
	Tango::UserDefaultAttrProp	klystronpeaki_prop;
	klystronpeaki_prop.set_description("Klystron Peak current");
	klystronpeaki_prop.set_label("Klystron Peak I");
	klystronpeaki_prop.set_unit("Amperes");
	klystronpeaki_prop.set_standard_unit("Amperes");
	klystronpeaki_prop.set_display_unit("A");
	klystronpeaki_prop.set_format("%4.1f");
	//	max_value	not set for KlystronPeakI
	//	min_value	not set for KlystronPeakI
	//	max_alarm	not set for KlystronPeakI
	//	min_alarm	not set for KlystronPeakI
	//	max_warning	not set for KlystronPeakI
	//	min_warning	not set for KlystronPeakI
	//	delta_t	not set for KlystronPeakI
	//	delta_val	not set for KlystronPeakI
	
	klystronpeaki->set_default_properties(klystronpeaki_prop);
	//	Not Polled
	klystronpeaki->set_disp_level(Tango::OPERATOR);
	//	Not Memorized
	att_list.push_back(klystronpeaki);

	//	Attribute : KlystronPeakV
	KlystronPeakVAttrib	*klystronpeakv = new KlystronPeakVAttrib();
	Tango::UserDefaultAttrProp	klystronpeakv_prop;
	klystronpeakv_prop.set_description("Klystron Peak Voltage");
	klystronpeakv_prop.set_label("KlystronPeakV");
	klystronpeakv_prop.set_unit("kV");
	klystronpeakv_prop.set_standard_unit("kV");
	klystronpeakv_prop.set_display_unit("kV");
	klystronpeakv_prop.set_format("%4.1f");
	//	max_value	not set for KlystronPeakV
	//	min_value	not set for KlystronPeakV
	//	max_alarm	not set for KlystronPeakV
	//	min_alarm	not set for KlystronPeakV
	//	max_warning	not set for KlystronPeakV
	//	min_warning	not set for KlystronPeakV
	//	delta_t	not set for KlystronPeakV
	//	delta_val	not set for KlystronPeakV
	
	klystronpeakv->set_default_properties(klystronpeakv_prop);
	//	Not Polled
	klystronpeakv->set_disp_level(Tango::OPERATOR);
	//	Not Memorized
	att_list.push_back(klystronpeakv);

	//	Attribute : PeakPowerIn
	PeakPowerInAttrib	*peakpowerin = new PeakPowerInAttrib();
	Tango::UserDefaultAttrProp	peakpowerin_prop;
	peakpowerin_prop.set_description("Peak Power In");
	peakpowerin_prop.set_label("PeakPowerIn");
	peakpowerin_prop.set_unit("W");
	peakpowerin_prop.set_standard_unit("W");
	peakpowerin_prop.set_display_unit("W");
	peakpowerin_prop.set_format("%5.2f");
	//	max_value	not set for PeakPowerIn
	//	min_value	not set for PeakPowerIn
	//	max_alarm	not set for PeakPowerIn
	//	min_alarm	not set for PeakPowerIn
	//	max_warning	not set for PeakPowerIn
	//	min_warning	not set for PeakPowerIn
	//	delta_t	not set for PeakPowerIn
	//	delta_val	not set for PeakPowerIn
	
	peakpowerin->set_default_properties(peakpowerin_prop);
	//	Not Polled
	peakpowerin->set_disp_level(Tango::OPERATOR);
	//	Not Memorized
	att_list.push_back(peakpowerin);

	//	Attribute : PeakPowerOut
	PeakPowerOutAttrib	*peakpowerout = new PeakPowerOutAttrib();
	Tango::UserDefaultAttrProp	peakpowerout_prop;
	peakpowerout_prop.set_description("Peak Power Out.");
	peakpowerout_prop.set_label("PeakPowerOut");
	peakpowerout_prop.set_unit("MW");
	peakpowerout_prop.set_standard_unit("MW");
	peakpowerout_prop.set_display_unit("MW");
	peakpowerout_prop.set_format("%5.2f");
	//	max_value	not set for PeakPowerOut
	//	min_value	not set for PeakPowerOut
	//	max_alarm	not set for PeakPowerOut
	//	min_alarm	not set for PeakPowerOut
	//	max_warning	not set for PeakPowerOut
	//	min_warning	not set for PeakPowerOut
	//	delta_t	not set for PeakPowerOut
	//	delta_val	not set for PeakPowerOut
	
	peakpowerout->set_default_properties(peakpowerout_prop);
	//	Not Polled
	peakpowerout->set_disp_level(Tango::OPERATOR);
	//	Not Memorized
	att_list.push_back(peakpowerout);


	//	Create a list of static attributes
	create_static_attribute_list(get_class_attr()->get_attr_list());
	/*----- PROTECTED REGION ID(LinacModulatorClass::attribute_factory_after) ENABLED START -----*/
	
	//	Add your own code
	
	/*----- PROTECTED REGION END -----*/	//	LinacModulatorClass::attribute_factory_after
}
//--------------------------------------------------------
/**
 *	Method      : LinacModulatorClass::pipe_factory()
 *	Description : Create the pipe object(s)
 *                and store them in the pipe list
 */
//--------------------------------------------------------
void LinacModulatorClass::pipe_factory()
{
	/*----- PROTECTED REGION ID(LinacModulatorClass::pipe_factory_before) ENABLED START -----*/
	
	//	Add your own code
	
	/*----- PROTECTED REGION END -----*/	//	LinacModulatorClass::pipe_factory_before
	/*----- PROTECTED REGION ID(LinacModulatorClass::pipe_factory_after) ENABLED START -----*/
	
	//	Add your own code
	
	/*----- PROTECTED REGION END -----*/	//	LinacModulatorClass::pipe_factory_after
}
//--------------------------------------------------------
/**
 *	Method      : LinacModulatorClass::command_factory()
 *	Description : Create the command object(s)
 *                and store them in the command list
 */
//--------------------------------------------------------
void LinacModulatorClass::command_factory()
{
	/*----- PROTECTED REGION ID(LinacModulatorClass::command_factory_before) ENABLED START -----*/
	
	//	Add your own code
	
	/*----- PROTECTED REGION END -----*/	//	LinacModulatorClass::command_factory_before


	//	Command On
	OnClass	*pOnCmd =
		new OnClass("On",
			Tango::DEV_VOID, Tango::DEV_VOID,
			"",
			"",
			Tango::OPERATOR);
	command_list.push_back(pOnCmd);

	//	Command Off
	OffClass	*pOffCmd =
		new OffClass("Off",
			Tango::DEV_VOID, Tango::DEV_VOID,
			"",
			"",
			Tango::OPERATOR);
	command_list.push_back(pOffCmd);

	//	Command Reset
	ResetClass	*pResetCmd =
		new ResetClass("Reset",
			Tango::DEV_VOID, Tango::DEV_VOID,
			"",
			"",
			Tango::OPERATOR);
	command_list.push_back(pResetCmd);

	//	Command TimingOn
	TimingOnClass	*pTimingOnCmd =
		new TimingOnClass("TimingOn",
			Tango::DEV_VOID, Tango::DEV_VOID,
			"",
			"",
			Tango::OPERATOR);
	command_list.push_back(pTimingOnCmd);

	//	Command SoftOn
	SoftOnClass	*pSoftOnCmd =
		new SoftOnClass("SoftOn",
			Tango::DEV_VOID, Tango::DEV_VOID,
			"",
			"",
			Tango::OPERATOR);
	command_list.push_back(pSoftOnCmd);

	//	Command SoftOff
	SoftOffClass	*pSoftOffCmd =
		new SoftOffClass("SoftOff",
			Tango::DEV_VOID, Tango::DEV_VOID,
			"",
			"",
			Tango::OPERATOR);
	command_list.push_back(pSoftOffCmd);

	/*----- PROTECTED REGION ID(LinacModulatorClass::command_factory_after) ENABLED START -----*/
	
	//	Add your own code
	
	/*----- PROTECTED REGION END -----*/	//	LinacModulatorClass::command_factory_after
}

//===================================================================
//	Dynamic attributes related methods
//===================================================================

//--------------------------------------------------------
/**
 * method : 		LinacModulatorClass::create_static_attribute_list
 * description : 	Create the a list of static attributes
 *
 * @param	att_list	the ceated attribute list
 */
//--------------------------------------------------------
void LinacModulatorClass::create_static_attribute_list(vector<Tango::Attr *> &att_list)
{
	for (unsigned long i=0 ; i<att_list.size() ; i++)
	{
		string att_name(att_list[i]->get_name());
		transform(att_name.begin(), att_name.end(), att_name.begin(), ::tolower);
		defaultAttList.push_back(att_name);
	}

	cout2 << defaultAttList.size() << " attributes in default list" << endl;

	/*----- PROTECTED REGION ID(LinacModulatorClass::create_static_att_list) ENABLED START -----*/
	
	/*----- PROTECTED REGION END -----*/	//	LinacModulatorClass::create_static_att_list
}


//--------------------------------------------------------
/**
 * method : 		LinacModulatorClass::erase_dynamic_attributes
 * description : 	delete the dynamic attributes if any.
 *
 * @param	devlist_ptr	the device list pointer
 * @param	list of all attributes
 */
//--------------------------------------------------------
void LinacModulatorClass::erase_dynamic_attributes(const Tango::DevVarStringArray *devlist_ptr, vector<Tango::Attr *> &att_list)
{
	Tango::Util *tg = Tango::Util::instance();

	for (unsigned long i=0 ; i<devlist_ptr->length() ; i++)
	{
		Tango::DeviceImpl *dev_impl = tg->get_device_by_name(((string)(*devlist_ptr)[i]).c_str());
		LinacModulator *dev = static_cast<LinacModulator *> (dev_impl);

		vector<Tango::Attribute *> &dev_att_list = dev->get_device_attr()->get_attribute_list();
		vector<Tango::Attribute *>::iterator ite_att;
		for (ite_att=dev_att_list.begin() ; ite_att != dev_att_list.end() ; ++ite_att)
		{
			string att_name((*ite_att)->get_name_lower());
			if ((att_name == "state") || (att_name == "status"))
				continue;
			vector<string>::iterator ite_str = find(defaultAttList.begin(), defaultAttList.end(), att_name);
			if (ite_str == defaultAttList.end())
			{
				cout2 << att_name << " is a UNWANTED dynamic attribute for device " << (*devlist_ptr)[i] << endl;
				Tango::Attribute &att = dev->get_device_attr()->get_attr_by_name(att_name.c_str());
				dev->remove_attribute(att_list[att.get_attr_idx()], true, false);
				--ite_att;
			}
		}
	}
	/*----- PROTECTED REGION ID(LinacModulatorClass::erase_dynamic_attributes) ENABLED START -----*/
	
	/*----- PROTECTED REGION END -----*/	//	LinacModulatorClass::erase_dynamic_attributes
}

//--------------------------------------------------------
/**
 *	Method      : LinacModulatorClass::get_attr_by_name()
 *	Description : returns Tango::Attr * object found by name
 */
//--------------------------------------------------------
Tango::Attr *LinacModulatorClass::get_attr_object_by_name(vector<Tango::Attr *> &att_list, string attname)
{
	vector<Tango::Attr *>::iterator it;
	for (it=att_list.begin() ; it<att_list.end() ; ++it)
		if ((*it)->get_name()==attname)
			return (*it);
	//	Attr does not exist
	return NULL;
}


/*----- PROTECTED REGION ID(LinacModulatorClass::Additional Methods) ENABLED START -----*/

/*----- PROTECTED REGION END -----*/	//	LinacModulatorClass::Additional Methods
} //	namespace
