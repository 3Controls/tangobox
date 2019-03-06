/*----- PROTECTED REGION ID(LinacCoolingClass.cpp) ENABLED START -----*/
static const char *RcsId      = "$Id:  $";
static const char *TagName    = "$Name:  $";
static const char *CvsPath    = "$Source:  $";
static const char *SvnPath    = "$HeadURL:  $";
static const char *HttpServer = "http://www.esrf.eu/computing/cs/tango/tango_doc/ds_doc/";
//=============================================================================
//
// file :        LinacCoolingClass.cpp
//
// description : C++ source for the LinacCoolingClass.
//               A singleton class derived from DeviceClass.
//               It implements the command and attribute list
//               and all properties and methods required
//               by the LinacCooling once per process.
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


#include <tango.h>
#include <LinacCooling.h>
#include <LinacCoolingClass.h>

/*----- PROTECTED REGION END -----*/	//	LinacCoolingClass.cpp

//-------------------------------------------------------------------
/**
 *	Create LinacCoolingClass singleton and
 *	return it in a C function for Python usage
 */
//-------------------------------------------------------------------
extern "C" {
#ifdef _TG_WINDOWS_

__declspec(dllexport)

#endif

	Tango::DeviceClass *_create_LinacCooling_class(const char *name) {
		return LinacCooling_ns::LinacCoolingClass::init(name);
	}
}

namespace LinacCooling_ns
{
//===================================================================
//	Initialize pointer for singleton pattern
//===================================================================
LinacCoolingClass *LinacCoolingClass::_instance = NULL;

//--------------------------------------------------------
/**
 * method : 		LinacCoolingClass::LinacCoolingClass(string &s)
 * description : 	constructor for the LinacCoolingClass
 *
 * @param s	The class name
 */
//--------------------------------------------------------
LinacCoolingClass::LinacCoolingClass(string &s):Tango::DeviceClass(s)
{
	cout2 << "Entering LinacCoolingClass constructor" << endl;
	set_default_property();
	write_class_property();

	/*----- PROTECTED REGION ID(LinacCoolingClass::constructor) ENABLED START -----*/
	
	/*----- PROTECTED REGION END -----*/	//	LinacCoolingClass::constructor

	cout2 << "Leaving LinacCoolingClass constructor" << endl;
}

//--------------------------------------------------------
/**
 * method : 		LinacCoolingClass::~LinacCoolingClass()
 * description : 	destructor for the LinacCoolingClass
 */
//--------------------------------------------------------
LinacCoolingClass::~LinacCoolingClass()
{
	/*----- PROTECTED REGION ID(LinacCoolingClass::destructor) ENABLED START -----*/
	
	/*----- PROTECTED REGION END -----*/	//	LinacCoolingClass::destructor

	_instance = NULL;
}


//--------------------------------------------------------
/**
 * method : 		LinacCoolingClass::init
 * description : 	Create the object if not already done.
 *                  Otherwise, just return a pointer to the object
 *
 * @param	name	The class name
 */
//--------------------------------------------------------
LinacCoolingClass *LinacCoolingClass::init(const char *name)
{
	if (_instance == NULL)
	{
		try
		{
			string s(name);
			_instance = new LinacCoolingClass(s);
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
 * method : 		LinacCoolingClass::instance
 * description : 	Check if object already created,
 *                  and return a pointer to the object
 */
//--------------------------------------------------------
LinacCoolingClass *LinacCoolingClass::instance()
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
	((static_cast<LinacCooling *>(device))->reset());
	return new CORBA::Any();
}


//===================================================================
//	Properties management
//===================================================================
//--------------------------------------------------------
/**
 *	Method      : LinacCoolingClass::get_class_property()
 *	Description : Get the class property for specified name.
 */
//--------------------------------------------------------
Tango::DbDatum LinacCoolingClass::get_class_property(string &prop_name)
{
	for (unsigned int i=0 ; i<cl_prop.size() ; i++)
		if (cl_prop[i].name == prop_name)
			return cl_prop[i];
	//	if not found, returns  an empty DbDatum
	return Tango::DbDatum(prop_name);
}

//--------------------------------------------------------
/**
 *	Method      : LinacCoolingClass::get_default_device_property()
 *	Description : Return the default value for device property.
 */
//--------------------------------------------------------
Tango::DbDatum LinacCoolingClass::get_default_device_property(string &prop_name)
{
	for (unsigned int i=0 ; i<dev_def_prop.size() ; i++)
		if (dev_def_prop[i].name == prop_name)
			return dev_def_prop[i];
	//	if not found, return  an empty DbDatum
	return Tango::DbDatum(prop_name);
}

//--------------------------------------------------------
/**
 *	Method      : LinacCoolingClass::get_default_class_property()
 *	Description : Return the default value for class property.
 */
//--------------------------------------------------------
Tango::DbDatum LinacCoolingClass::get_default_class_property(string &prop_name)
{
	for (unsigned int i=0 ; i<cl_def_prop.size() ; i++)
		if (cl_def_prop[i].name == prop_name)
			return cl_def_prop[i];
	//	if not found, return  an empty DbDatum
	return Tango::DbDatum(prop_name);
}


//--------------------------------------------------------
/**
 *	Method      : LinacCoolingClass::set_default_property()
 *	Description : Set default property (class and device) for wizard.
 *                For each property, add to wizard property name and description.
 *                If default value has been set, add it to wizard property and
 *                store it in a DbDatum.
 */
//--------------------------------------------------------
void LinacCoolingClass::set_default_property()
{
	string	prop_name;
	string	prop_desc;
	string	prop_def;
	vector<string>	vect_data;

	//	Set Default Class Properties

	//	Set Default device Properties
	prop_name = "BuncherTemp_adc";
	prop_desc = "ADC device to get the buncher temperature.";
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
	prop_name = "Daresbury";
	prop_desc = "Name of the Daresbury device.";
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
	prop_desc = "Interlocks list.";
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
	prop_name = "PbuncherTemp_adc";
	prop_desc = "ADC device to get the prebuncher temperature.";
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
	prop_name = "SectionTemp_adc";
	prop_desc = "ADC device to get the section temperature.";
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
	prop_desc = "Interlock number used to determine if the device is on or not.\n(ex 21.1";
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
	prop_name = "WaterTemp_adc";
	prop_desc = "ADC device to get the water temperature.";
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
 *	Method      : LinacCoolingClass::write_class_property()
 *	Description : Set class description fields as property in database
 */
//--------------------------------------------------------
void LinacCoolingClass::write_class_property()
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
	string	str_title("Linac cooling");
	title << str_title;
	data.push_back(title);

	//	Put Description
	Tango::DbDatum	description("Description");
	vector<string>	str_desc;
	str_desc.push_back("This class will manage the linac cooling.");
	description << str_desc;
	data.push_back(description);

	//	put cvs or svn location
	string	filename("LinacCooling");
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
 *	Method      : LinacCoolingClass::device_factory()
 *	Description : Create the device object(s)
 *                and store them in the device list
 */
//--------------------------------------------------------
void LinacCoolingClass::device_factory(const Tango::DevVarStringArray *devlist_ptr)
{
	/*----- PROTECTED REGION ID(LinacCoolingClass::device_factory_before) ENABLED START -----*/
	
	//	Add your own code
	
	/*----- PROTECTED REGION END -----*/	//	LinacCoolingClass::device_factory_before

	//	Create devices and add it into the device list
	for (unsigned long i=0 ; i<devlist_ptr->length() ; i++)
	{
		cout4 << "Device name : " << (*devlist_ptr)[i].in() << endl;
		device_list.push_back(new LinacCooling(this, (*devlist_ptr)[i]));
	}

	//	Manage dynamic attributes if any
	erase_dynamic_attributes(devlist_ptr, get_class_attr()->get_attr_list());

	//	Export devices to the outside world
	for (unsigned long i=1 ; i<=devlist_ptr->length() ; i++)
	{
		//	Add dynamic attributes if any
		LinacCooling *dev = static_cast<LinacCooling *>(device_list[device_list.size()-i]);
		dev->add_dynamic_attributes();

		//	Check before if database used.
		if ((Tango::Util::_UseDb == true) && (Tango::Util::_FileDb == false))
			export_device(dev);
		else
			export_device(dev, dev->get_name().c_str());
	}

	/*----- PROTECTED REGION ID(LinacCoolingClass::device_factory_after) ENABLED START -----*/
	
	//	Add your own code
	
	/*----- PROTECTED REGION END -----*/	//	LinacCoolingClass::device_factory_after
}
//--------------------------------------------------------
/**
 *	Method      : LinacCoolingClass::attribute_factory()
 *	Description : Create the attribute object(s)
 *                and store them in the attribute list
 */
//--------------------------------------------------------
void LinacCoolingClass::attribute_factory(vector<Tango::Attr *> &att_list)
{
	/*----- PROTECTED REGION ID(LinacCoolingClass::attribute_factory_before) ENABLED START -----*/
	
	//	Add your own code
	
	/*----- PROTECTED REGION END -----*/	//	LinacCoolingClass::attribute_factory_before
	//	Attribute : WaterTemp
	WaterTempAttrib	*watertemp = new WaterTempAttrib();
	Tango::UserDefaultAttrProp	watertemp_prop;
	watertemp_prop.set_description("Water Temperature");
	watertemp_prop.set_label("Water Temperature");
	watertemp_prop.set_unit("C");
	watertemp_prop.set_standard_unit("C");
	watertemp_prop.set_display_unit("C");
	watertemp_prop.set_format("%3.1f");
	//	max_value	not set for WaterTemp
	//	min_value	not set for WaterTemp
	//	max_alarm	not set for WaterTemp
	//	min_alarm	not set for WaterTemp
	//	max_warning	not set for WaterTemp
	//	min_warning	not set for WaterTemp
	//	delta_t	not set for WaterTemp
	//	delta_val	not set for WaterTemp
	
	watertemp->set_default_properties(watertemp_prop);
	//	Not Polled
	watertemp->set_disp_level(Tango::OPERATOR);
	//	Not Memorized
	att_list.push_back(watertemp);

	//	Attribute : PBuncherTemp
	PBuncherTempAttrib	*pbunchertemp = new PBuncherTempAttrib();
	Tango::UserDefaultAttrProp	pbunchertemp_prop;
	pbunchertemp_prop.set_description("PreBuncher Temperature");
	pbunchertemp_prop.set_label("PreBuncher Temperature");
	pbunchertemp_prop.set_unit("C");
	pbunchertemp_prop.set_standard_unit("C");
	pbunchertemp_prop.set_display_unit("C");
	pbunchertemp_prop.set_format("%3.1f");
	//	max_value	not set for PBuncherTemp
	//	min_value	not set for PBuncherTemp
	//	max_alarm	not set for PBuncherTemp
	//	min_alarm	not set for PBuncherTemp
	//	max_warning	not set for PBuncherTemp
	//	min_warning	not set for PBuncherTemp
	//	delta_t	not set for PBuncherTemp
	//	delta_val	not set for PBuncherTemp
	
	pbunchertemp->set_default_properties(pbunchertemp_prop);
	//	Not Polled
	pbunchertemp->set_disp_level(Tango::OPERATOR);
	//	Not Memorized
	att_list.push_back(pbunchertemp);

	//	Attribute : BuncherTemp
	BuncherTempAttrib	*bunchertemp = new BuncherTempAttrib();
	Tango::UserDefaultAttrProp	bunchertemp_prop;
	bunchertemp_prop.set_description("Buncher Temperature");
	bunchertemp_prop.set_label("Buncher Temperature");
	bunchertemp_prop.set_unit("C");
	bunchertemp_prop.set_standard_unit("C");
	bunchertemp_prop.set_display_unit("C");
	bunchertemp_prop.set_format("%3.1f");
	//	max_value	not set for BuncherTemp
	//	min_value	not set for BuncherTemp
	//	max_alarm	not set for BuncherTemp
	//	min_alarm	not set for BuncherTemp
	//	max_warning	not set for BuncherTemp
	//	min_warning	not set for BuncherTemp
	//	delta_t	not set for BuncherTemp
	//	delta_val	not set for BuncherTemp
	
	bunchertemp->set_default_properties(bunchertemp_prop);
	//	Not Polled
	bunchertemp->set_disp_level(Tango::OPERATOR);
	//	Not Memorized
	att_list.push_back(bunchertemp);

	//	Attribute : SectionTemp
	SectionTempAttrib	*sectiontemp = new SectionTempAttrib();
	Tango::UserDefaultAttrProp	sectiontemp_prop;
	sectiontemp_prop.set_description("Section Temperature");
	sectiontemp_prop.set_label("Section Temperature");
	sectiontemp_prop.set_unit("C");
	sectiontemp_prop.set_standard_unit("C");
	sectiontemp_prop.set_display_unit("C");
	sectiontemp_prop.set_format("%3.1f");
	//	max_value	not set for SectionTemp
	//	min_value	not set for SectionTemp
	//	max_alarm	not set for SectionTemp
	//	min_alarm	not set for SectionTemp
	//	max_warning	not set for SectionTemp
	//	min_warning	not set for SectionTemp
	//	delta_t	not set for SectionTemp
	//	delta_val	not set for SectionTemp
	
	sectiontemp->set_default_properties(sectiontemp_prop);
	//	Not Polled
	sectiontemp->set_disp_level(Tango::OPERATOR);
	//	Not Memorized
	att_list.push_back(sectiontemp);


	//	Create a list of static attributes
	create_static_attribute_list(get_class_attr()->get_attr_list());
	/*----- PROTECTED REGION ID(LinacCoolingClass::attribute_factory_after) ENABLED START -----*/
	
	//	Add your own code
	
	/*----- PROTECTED REGION END -----*/	//	LinacCoolingClass::attribute_factory_after
}
//--------------------------------------------------------
/**
 *	Method      : LinacCoolingClass::pipe_factory()
 *	Description : Create the pipe object(s)
 *                and store them in the pipe list
 */
//--------------------------------------------------------
void LinacCoolingClass::pipe_factory()
{
	/*----- PROTECTED REGION ID(LinacCoolingClass::pipe_factory_before) ENABLED START -----*/
	
	//	Add your own code
	
	/*----- PROTECTED REGION END -----*/	//	LinacCoolingClass::pipe_factory_before
	/*----- PROTECTED REGION ID(LinacCoolingClass::pipe_factory_after) ENABLED START -----*/
	
	//	Add your own code
	
	/*----- PROTECTED REGION END -----*/	//	LinacCoolingClass::pipe_factory_after
}
//--------------------------------------------------------
/**
 *	Method      : LinacCoolingClass::command_factory()
 *	Description : Create the command object(s)
 *                and store them in the command list
 */
//--------------------------------------------------------
void LinacCoolingClass::command_factory()
{
	/*----- PROTECTED REGION ID(LinacCoolingClass::command_factory_before) ENABLED START -----*/
	
	//	Add your own code
	
	/*----- PROTECTED REGION END -----*/	//	LinacCoolingClass::command_factory_before


	//	Command Reset
	ResetClass	*pResetCmd =
		new ResetClass("Reset",
			Tango::DEV_VOID, Tango::DEV_VOID,
			"",
			"",
			Tango::OPERATOR);
	command_list.push_back(pResetCmd);

	/*----- PROTECTED REGION ID(LinacCoolingClass::command_factory_after) ENABLED START -----*/
	
	//	Add your own code
	
	/*----- PROTECTED REGION END -----*/	//	LinacCoolingClass::command_factory_after
}

//===================================================================
//	Dynamic attributes related methods
//===================================================================

//--------------------------------------------------------
/**
 * method : 		LinacCoolingClass::create_static_attribute_list
 * description : 	Create the a list of static attributes
 *
 * @param	att_list	the ceated attribute list
 */
//--------------------------------------------------------
void LinacCoolingClass::create_static_attribute_list(vector<Tango::Attr *> &att_list)
{
	for (unsigned long i=0 ; i<att_list.size() ; i++)
	{
		string att_name(att_list[i]->get_name());
		transform(att_name.begin(), att_name.end(), att_name.begin(), ::tolower);
		defaultAttList.push_back(att_name);
	}

	cout2 << defaultAttList.size() << " attributes in default list" << endl;

	/*----- PROTECTED REGION ID(LinacCoolingClass::create_static_att_list) ENABLED START -----*/
	
	/*----- PROTECTED REGION END -----*/	//	LinacCoolingClass::create_static_att_list
}


//--------------------------------------------------------
/**
 * method : 		LinacCoolingClass::erase_dynamic_attributes
 * description : 	delete the dynamic attributes if any.
 *
 * @param	devlist_ptr	the device list pointer
 * @param	list of all attributes
 */
//--------------------------------------------------------
void LinacCoolingClass::erase_dynamic_attributes(const Tango::DevVarStringArray *devlist_ptr, vector<Tango::Attr *> &att_list)
{
	Tango::Util *tg = Tango::Util::instance();

	for (unsigned long i=0 ; i<devlist_ptr->length() ; i++)
	{
		Tango::DeviceImpl *dev_impl = tg->get_device_by_name(((string)(*devlist_ptr)[i]).c_str());
		LinacCooling *dev = static_cast<LinacCooling *> (dev_impl);

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
	/*----- PROTECTED REGION ID(LinacCoolingClass::erase_dynamic_attributes) ENABLED START -----*/
	
	/*----- PROTECTED REGION END -----*/	//	LinacCoolingClass::erase_dynamic_attributes
}

//--------------------------------------------------------
/**
 *	Method      : LinacCoolingClass::get_attr_by_name()
 *	Description : returns Tango::Attr * object found by name
 */
//--------------------------------------------------------
Tango::Attr *LinacCoolingClass::get_attr_object_by_name(vector<Tango::Attr *> &att_list, string attname)
{
	vector<Tango::Attr *>::iterator it;
	for (it=att_list.begin() ; it<att_list.end() ; ++it)
		if ((*it)->get_name()==attname)
			return (*it);
	//	Attr does not exist
	return NULL;
}


/*----- PROTECTED REGION ID(LinacCoolingClass::Additional Methods) ENABLED START -----*/

/*----- PROTECTED REGION END -----*/	//	LinacCoolingClass::Additional Methods
} //	namespace