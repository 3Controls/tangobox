/*----- PROTECTED REGION ID(LinacGunAuxClass.cpp) ENABLED START -----*/
static const char *RcsId      = "$Id:  $";
static const char *TagName    = "$Name:  $";
static const char *CvsPath    = "$Source:  $";
static const char *SvnPath    = "$HeadURL:  $";
static const char *HttpServer = "http://www.esrf.eu/computing/cs/tango/tango_doc/ds_doc/";
//=============================================================================
//
// file :        LinacGunAuxClass.cpp
//
// description : C++ source for the LinacGunAuxClass.
//               A singleton class derived from DeviceClass.
//               It implements the command and attribute list
//               and all properties and methods required
//               by the LinacGunAux once per process.
//
// project :     Linac Gun Auxiliary
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
#include <LinacGunAux.h>
#include <LinacGunAuxClass.h>

/*----- PROTECTED REGION END -----*/	//	LinacGunAuxClass.cpp

//-------------------------------------------------------------------
/**
 *	Create LinacGunAuxClass singleton and
 *	return it in a C function for Python usage
 */
//-------------------------------------------------------------------
extern "C" {
#ifdef _TG_WINDOWS_

__declspec(dllexport)

#endif

	Tango::DeviceClass *_create_LinacGunAux_class(const char *name) {
		return LinacGunAux_ns::LinacGunAuxClass::init(name);
	}
}

namespace LinacGunAux_ns
{
//===================================================================
//	Initialize pointer for singleton pattern
//===================================================================
LinacGunAuxClass *LinacGunAuxClass::_instance = NULL;

//--------------------------------------------------------
/**
 * method : 		LinacGunAuxClass::LinacGunAuxClass(string &s)
 * description : 	constructor for the LinacGunAuxClass
 *
 * @param s	The class name
 */
//--------------------------------------------------------
LinacGunAuxClass::LinacGunAuxClass(string &s):Tango::DeviceClass(s)
{
	cout2 << "Entering LinacGunAuxClass constructor" << endl;
	set_default_property();
	write_class_property();

	/*----- PROTECTED REGION ID(LinacGunAuxClass::constructor) ENABLED START -----*/
	
	/*----- PROTECTED REGION END -----*/	//	LinacGunAuxClass::constructor

	cout2 << "Leaving LinacGunAuxClass constructor" << endl;
}

//--------------------------------------------------------
/**
 * method : 		LinacGunAuxClass::~LinacGunAuxClass()
 * description : 	destructor for the LinacGunAuxClass
 */
//--------------------------------------------------------
LinacGunAuxClass::~LinacGunAuxClass()
{
	/*----- PROTECTED REGION ID(LinacGunAuxClass::destructor) ENABLED START -----*/
	
	/*----- PROTECTED REGION END -----*/	//	LinacGunAuxClass::destructor

	_instance = NULL;
}


//--------------------------------------------------------
/**
 * method : 		LinacGunAuxClass::init
 * description : 	Create the object if not already done.
 *                  Otherwise, just return a pointer to the object
 *
 * @param	name	The class name
 */
//--------------------------------------------------------
LinacGunAuxClass *LinacGunAuxClass::init(const char *name)
{
	if (_instance == NULL)
	{
		try
		{
			string s(name);
			_instance = new LinacGunAuxClass(s);
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
 * method : 		LinacGunAuxClass::instance
 * description : 	Check if object already created,
 *                  and return a pointer to the object
 */
//--------------------------------------------------------
LinacGunAuxClass *LinacGunAuxClass::instance()
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
	((static_cast<LinacGunAux *>(device))->on());
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
	((static_cast<LinacGunAux *>(device))->off());
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
	((static_cast<LinacGunAux *>(device))->reset());
	return new CORBA::Any();
}


//===================================================================
//	Properties management
//===================================================================
//--------------------------------------------------------
/**
 *	Method      : LinacGunAuxClass::get_class_property()
 *	Description : Get the class property for specified name.
 */
//--------------------------------------------------------
Tango::DbDatum LinacGunAuxClass::get_class_property(string &prop_name)
{
	for (unsigned int i=0 ; i<cl_prop.size() ; i++)
		if (cl_prop[i].name == prop_name)
			return cl_prop[i];
	//	if not found, returns  an empty DbDatum
	return Tango::DbDatum(prop_name);
}

//--------------------------------------------------------
/**
 *	Method      : LinacGunAuxClass::get_default_device_property()
 *	Description : Return the default value for device property.
 */
//--------------------------------------------------------
Tango::DbDatum LinacGunAuxClass::get_default_device_property(string &prop_name)
{
	for (unsigned int i=0 ; i<dev_def_prop.size() ; i++)
		if (dev_def_prop[i].name == prop_name)
			return dev_def_prop[i];
	//	if not found, return  an empty DbDatum
	return Tango::DbDatum(prop_name);
}

//--------------------------------------------------------
/**
 *	Method      : LinacGunAuxClass::get_default_class_property()
 *	Description : Return the default value for class property.
 */
//--------------------------------------------------------
Tango::DbDatum LinacGunAuxClass::get_default_class_property(string &prop_name)
{
	for (unsigned int i=0 ; i<cl_def_prop.size() ; i++)
		if (cl_def_prop[i].name == prop_name)
			return cl_def_prop[i];
	//	if not found, return  an empty DbDatum
	return Tango::DbDatum(prop_name);
}


//--------------------------------------------------------
/**
 *	Method      : LinacGunAuxClass::set_default_property()
 *	Description : Set default property (class and device) for wizard.
 *                For each property, add to wizard property name and description.
 *                If default value has been set, add it to wizard property and
 *                store it in a DbDatum.
 */
//--------------------------------------------------------
void LinacGunAuxClass::set_default_property()
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
	prop_name = "Heat_time";
	prop_desc = "Heating time (in seconds).";
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
	prop_name = "HeatI_adc";
	prop_desc = "ADC device to read the Heating Current.";
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
	prop_name = "HeatV_adc";
	prop_desc = "ADC device to read the Heating Voltage.";
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
	prop_name = "HeatV_dac";
	prop_desc = "DAC device to set the heating voltage.";
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
	prop_name = "Offrelay";
	prop_desc = "Name of the relay used to switch off the Gun Auxiliary.";
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
	prop_desc = "Name of the relay used to switch on the gun auxiliary.";
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
	prop_name = "Stateheatnum";
	prop_desc = "Daresbury relay number which indicates if the device is heating or not.";
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
	prop_desc = "Daresbury relay number used to determine whether the gun\nauxiliary is on or not.";
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
	prop_name = "PowerSupplyDeviceName";
	prop_desc = "This is the device name that points to the TDKLambda Zup\npower supply that is used instead of DAC/CAD.";
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
 *	Method      : LinacGunAuxClass::write_class_property()
 *	Description : Set class description fields as property in database
 */
//--------------------------------------------------------
void LinacGunAuxClass::write_class_property()
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
	string	str_title("Linac Gun Auxiliary");
	title << str_title;
	data.push_back(title);

	//	Put Description
	Tango::DbDatum	description("Description");
	vector<string>	str_desc;
	str_desc.push_back("This class will manage the gun auxiliary of the Linac.");
	description << str_desc;
	data.push_back(description);

	//	put cvs or svn location
	string	filename("LinacGunAux");
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
 *	Method      : LinacGunAuxClass::device_factory()
 *	Description : Create the device object(s)
 *                and store them in the device list
 */
//--------------------------------------------------------
void LinacGunAuxClass::device_factory(const Tango::DevVarStringArray *devlist_ptr)
{
	/*----- PROTECTED REGION ID(LinacGunAuxClass::device_factory_before) ENABLED START -----*/
	
	//	Add your own code
	
	/*----- PROTECTED REGION END -----*/	//	LinacGunAuxClass::device_factory_before

	//	Create devices and add it into the device list
	for (unsigned long i=0 ; i<devlist_ptr->length() ; i++)
	{
		cout4 << "Device name : " << (*devlist_ptr)[i].in() << endl;
		device_list.push_back(new LinacGunAux(this, (*devlist_ptr)[i]));
	}

	//	Manage dynamic attributes if any
	erase_dynamic_attributes(devlist_ptr, get_class_attr()->get_attr_list());

	//	Export devices to the outside world
	for (unsigned long i=1 ; i<=devlist_ptr->length() ; i++)
	{
		//	Add dynamic attributes if any
		LinacGunAux *dev = static_cast<LinacGunAux *>(device_list[device_list.size()-i]);
		dev->add_dynamic_attributes();

		//	Check before if database used.
		if ((Tango::Util::_UseDb == true) && (Tango::Util::_FileDb == false))
			export_device(dev);
		else
			export_device(dev, dev->get_name().c_str());
	}

	/*----- PROTECTED REGION ID(LinacGunAuxClass::device_factory_after) ENABLED START -----*/
	
	//	Add your own code
	
	/*----- PROTECTED REGION END -----*/	//	LinacGunAuxClass::device_factory_after
}
//--------------------------------------------------------
/**
 *	Method      : LinacGunAuxClass::attribute_factory()
 *	Description : Create the attribute object(s)
 *                and store them in the attribute list
 */
//--------------------------------------------------------
void LinacGunAuxClass::attribute_factory(vector<Tango::Attr *> &att_list)
{
	/*----- PROTECTED REGION ID(LinacGunAuxClass::attribute_factory_before) ENABLED START -----*/
	
	//	Add your own code
	
	/*----- PROTECTED REGION END -----*/	//	LinacGunAuxClass::attribute_factory_before
	//	Attribute : HeatI
	HeatIAttrib	*heati = new HeatIAttrib();
	Tango::UserDefaultAttrProp	heati_prop;
	heati_prop.set_description("Heating current");
	heati_prop.set_label("Heating current");
	heati_prop.set_unit("Amperes");
	heati_prop.set_standard_unit("Amperes");
	heati_prop.set_display_unit("A");
	heati_prop.set_format("%5.2f");
	//	max_value	not set for HeatI
	//	min_value	not set for HeatI
	//	max_alarm	not set for HeatI
	//	min_alarm	not set for HeatI
	//	max_warning	not set for HeatI
	//	min_warning	not set for HeatI
	//	delta_t	not set for HeatI
	//	delta_val	not set for HeatI
	
	heati->set_default_properties(heati_prop);
	//	Not Polled
	heati->set_disp_level(Tango::OPERATOR);
	//	Not Memorized
	att_list.push_back(heati);

	//	Attribute : HeatV
	HeatVAttrib	*heatv = new HeatVAttrib();
	Tango::UserDefaultAttrProp	heatv_prop;
	heatv_prop.set_description("Heating Voltage");
	heatv_prop.set_label("Heating Voltage");
	heatv_prop.set_unit("Volts");
	heatv_prop.set_standard_unit("Volts");
	heatv_prop.set_display_unit("V");
	heatv_prop.set_format("%5.2f");
	//	max_value	not set for HeatV
	//	min_value	not set for HeatV
	//	max_alarm	not set for HeatV
	//	min_alarm	not set for HeatV
	//	max_warning	not set for HeatV
	//	min_warning	not set for HeatV
	//	delta_t	not set for HeatV
	//	delta_val	not set for HeatV
	
	heatv->set_default_properties(heatv_prop);
	//	Not Polled
	heatv->set_disp_level(Tango::OPERATOR);
	heatv->set_memorized();
	heatv->set_memorized_init(true);
	att_list.push_back(heatv);

	//	Attribute : Temporization
	TemporizationAttrib	*temporization = new TemporizationAttrib();
	Tango::UserDefaultAttrProp	temporization_prop;
	temporization_prop.set_description("remaining time before the ON state.");
	temporization_prop.set_label("Temporization");
	temporization_prop.set_unit("seconds");
	temporization_prop.set_standard_unit("seconds");
	temporization_prop.set_display_unit("s");
	temporization_prop.set_format("%4d");
	//	max_value	not set for Temporization
	//	min_value	not set for Temporization
	//	max_alarm	not set for Temporization
	//	min_alarm	not set for Temporization
	//	max_warning	not set for Temporization
	//	min_warning	not set for Temporization
	//	delta_t	not set for Temporization
	//	delta_val	not set for Temporization
	
	temporization->set_default_properties(temporization_prop);
	//	Not Polled
	temporization->set_disp_level(Tango::OPERATOR);
	//	Not Memorized
	att_list.push_back(temporization);


	//	Create a list of static attributes
	create_static_attribute_list(get_class_attr()->get_attr_list());
	/*----- PROTECTED REGION ID(LinacGunAuxClass::attribute_factory_after) ENABLED START -----*/
	
	//	Add your own code
	
	/*----- PROTECTED REGION END -----*/	//	LinacGunAuxClass::attribute_factory_after
}
//--------------------------------------------------------
/**
 *	Method      : LinacGunAuxClass::pipe_factory()
 *	Description : Create the pipe object(s)
 *                and store them in the pipe list
 */
//--------------------------------------------------------
void LinacGunAuxClass::pipe_factory()
{
	/*----- PROTECTED REGION ID(LinacGunAuxClass::pipe_factory_before) ENABLED START -----*/
	
	//	Add your own code
	
	/*----- PROTECTED REGION END -----*/	//	LinacGunAuxClass::pipe_factory_before
	/*----- PROTECTED REGION ID(LinacGunAuxClass::pipe_factory_after) ENABLED START -----*/
	
	//	Add your own code
	
	/*----- PROTECTED REGION END -----*/	//	LinacGunAuxClass::pipe_factory_after
}
//--------------------------------------------------------
/**
 *	Method      : LinacGunAuxClass::command_factory()
 *	Description : Create the command object(s)
 *                and store them in the command list
 */
//--------------------------------------------------------
void LinacGunAuxClass::command_factory()
{
	/*----- PROTECTED REGION ID(LinacGunAuxClass::command_factory_before) ENABLED START -----*/
	
	//	Add your own code
	
	/*----- PROTECTED REGION END -----*/	//	LinacGunAuxClass::command_factory_before


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

	/*----- PROTECTED REGION ID(LinacGunAuxClass::command_factory_after) ENABLED START -----*/
	
	//	Add your own code
	
	/*----- PROTECTED REGION END -----*/	//	LinacGunAuxClass::command_factory_after
}

//===================================================================
//	Dynamic attributes related methods
//===================================================================

//--------------------------------------------------------
/**
 * method : 		LinacGunAuxClass::create_static_attribute_list
 * description : 	Create the a list of static attributes
 *
 * @param	att_list	the ceated attribute list
 */
//--------------------------------------------------------
void LinacGunAuxClass::create_static_attribute_list(vector<Tango::Attr *> &att_list)
{
	for (unsigned long i=0 ; i<att_list.size() ; i++)
	{
		string att_name(att_list[i]->get_name());
		transform(att_name.begin(), att_name.end(), att_name.begin(), ::tolower);
		defaultAttList.push_back(att_name);
	}

	cout2 << defaultAttList.size() << " attributes in default list" << endl;

	/*----- PROTECTED REGION ID(LinacGunAuxClass::create_static_att_list) ENABLED START -----*/
	
	/*----- PROTECTED REGION END -----*/	//	LinacGunAuxClass::create_static_att_list
}


//--------------------------------------------------------
/**
 * method : 		LinacGunAuxClass::erase_dynamic_attributes
 * description : 	delete the dynamic attributes if any.
 *
 * @param	devlist_ptr	the device list pointer
 * @param	list of all attributes
 */
//--------------------------------------------------------
void LinacGunAuxClass::erase_dynamic_attributes(const Tango::DevVarStringArray *devlist_ptr, vector<Tango::Attr *> &att_list)
{
	Tango::Util *tg = Tango::Util::instance();

	for (unsigned long i=0 ; i<devlist_ptr->length() ; i++)
	{
		Tango::DeviceImpl *dev_impl = tg->get_device_by_name(((string)(*devlist_ptr)[i]).c_str());
		LinacGunAux *dev = static_cast<LinacGunAux *> (dev_impl);

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
	/*----- PROTECTED REGION ID(LinacGunAuxClass::erase_dynamic_attributes) ENABLED START -----*/
	
	/*----- PROTECTED REGION END -----*/	//	LinacGunAuxClass::erase_dynamic_attributes
}

//--------------------------------------------------------
/**
 *	Method      : LinacGunAuxClass::get_attr_by_name()
 *	Description : returns Tango::Attr * object found by name
 */
//--------------------------------------------------------
Tango::Attr *LinacGunAuxClass::get_attr_object_by_name(vector<Tango::Attr *> &att_list, string attname)
{
	vector<Tango::Attr *>::iterator it;
	for (it=att_list.begin() ; it<att_list.end() ; ++it)
		if ((*it)->get_name()==attname)
			return (*it);
	//	Attr does not exist
	return NULL;
}


/*----- PROTECTED REGION ID(LinacGunAuxClass::Additional Methods) ENABLED START -----*/

/*----- PROTECTED REGION END -----*/	//	LinacGunAuxClass::Additional Methods
} //	namespace
