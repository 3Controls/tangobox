/*----- PROTECTED REGION ID(LinacRFClass.cpp) ENABLED START -----*/
static const char *RcsId      = "$Id:  $";
static const char *TagName    = "$Name:  $";
static const char *CvsPath    = "$Source:  $";
static const char *SvnPath    = "$HeadURL:  $";
static const char *HttpServer = "http://www.esrf.eu/computing/cs/tango/tango_doc/ds_doc/";
//=============================================================================
//
// file :        LinacRFClass.cpp
//
// description : C++ source for the LinacRFClass.
//               A singleton class derived from DeviceClass.
//               It implements the command and attribute list
//               and all properties and methods required
//               by the LinacRF once per process.
//
// project :     Linac Radio Frequency
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
#include <LinacRF.h>
#include <LinacRFClass.h>

/*----- PROTECTED REGION END -----*/	//	LinacRFClass.cpp

//-------------------------------------------------------------------
/**
 *	Create LinacRFClass singleton and
 *	return it in a C function for Python usage
 */
//-------------------------------------------------------------------
extern "C" {
#ifdef _TG_WINDOWS_

__declspec(dllexport)

#endif

	Tango::DeviceClass *_create_LinacRF_class(const char *name) {
		return LinacRF_ns::LinacRFClass::init(name);
	}
}

namespace LinacRF_ns
{
//===================================================================
//	Initialize pointer for singleton pattern
//===================================================================
LinacRFClass *LinacRFClass::_instance = NULL;

//--------------------------------------------------------
/**
 * method : 		LinacRFClass::LinacRFClass(string &s)
 * description : 	constructor for the LinacRFClass
 *
 * @param s	The class name
 */
//--------------------------------------------------------
LinacRFClass::LinacRFClass(string &s):Tango::DeviceClass(s)
{
	cout2 << "Entering LinacRFClass constructor" << endl;
	set_default_property();
	write_class_property();

	/*----- PROTECTED REGION ID(LinacRFClass::constructor) ENABLED START -----*/
	
	/*----- PROTECTED REGION END -----*/	//	LinacRFClass::constructor

	cout2 << "Leaving LinacRFClass constructor" << endl;
}

//--------------------------------------------------------
/**
 * method : 		LinacRFClass::~LinacRFClass()
 * description : 	destructor for the LinacRFClass
 */
//--------------------------------------------------------
LinacRFClass::~LinacRFClass()
{
	/*----- PROTECTED REGION ID(LinacRFClass::destructor) ENABLED START -----*/
	
	/*----- PROTECTED REGION END -----*/	//	LinacRFClass::destructor

	_instance = NULL;
}


//--------------------------------------------------------
/**
 * method : 		LinacRFClass::init
 * description : 	Create the object if not already done.
 *                  Otherwise, just return a pointer to the object
 *
 * @param	name	The class name
 */
//--------------------------------------------------------
LinacRFClass *LinacRFClass::init(const char *name)
{
	if (_instance == NULL)
	{
		try
		{
			string s(name);
			_instance = new LinacRFClass(s);
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
 * method : 		LinacRFClass::instance
 * description : 	Check if object already created,
 *                  and return a pointer to the object
 */
//--------------------------------------------------------
LinacRFClass *LinacRFClass::instance()
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
	((static_cast<LinacRF *>(device))->on());
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
	((static_cast<LinacRF *>(device))->off());
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
	((static_cast<LinacRF *>(device))->reset());
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
	((static_cast<LinacRF *>(device))->timing_on());
	return new CORBA::Any();
}


//===================================================================
//	Properties management
//===================================================================
//--------------------------------------------------------
/**
 *	Method      : LinacRFClass::get_class_property()
 *	Description : Get the class property for specified name.
 */
//--------------------------------------------------------
Tango::DbDatum LinacRFClass::get_class_property(string &prop_name)
{
	for (unsigned int i=0 ; i<cl_prop.size() ; i++)
		if (cl_prop[i].name == prop_name)
			return cl_prop[i];
	//	if not found, returns  an empty DbDatum
	return Tango::DbDatum(prop_name);
}

//--------------------------------------------------------
/**
 *	Method      : LinacRFClass::get_default_device_property()
 *	Description : Return the default value for device property.
 */
//--------------------------------------------------------
Tango::DbDatum LinacRFClass::get_default_device_property(string &prop_name)
{
	for (unsigned int i=0 ; i<dev_def_prop.size() ; i++)
		if (dev_def_prop[i].name == prop_name)
			return dev_def_prop[i];
	//	if not found, return  an empty DbDatum
	return Tango::DbDatum(prop_name);
}

//--------------------------------------------------------
/**
 *	Method      : LinacRFClass::get_default_class_property()
 *	Description : Return the default value for class property.
 */
//--------------------------------------------------------
Tango::DbDatum LinacRFClass::get_default_class_property(string &prop_name)
{
	for (unsigned int i=0 ; i<cl_def_prop.size() ; i++)
		if (cl_def_prop[i].name == prop_name)
			return cl_def_prop[i];
	//	if not found, return  an empty DbDatum
	return Tango::DbDatum(prop_name);
}


//--------------------------------------------------------
/**
 *	Method      : LinacRFClass::set_default_property()
 *	Description : Set default property (class and device) for wizard.
 *                For each property, add to wizard property name and description.
 *                If default value has been set, add it to wizard property and
 *                store it in a DbDatum.
 */
//--------------------------------------------------------
void LinacRFClass::set_default_property()
{
	string	prop_name;
	string	prop_desc;
	string	prop_def;
	vector<string>	vect_data;

	//	Set Default Class Properties

	//	Set Default device Properties
	prop_name = "Bunchphase";
	prop_desc = "Name of the buncher phase device.";
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
	prop_desc = "Name of the device used to get and set the Delay attribute.";
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
	prop_name = "Mastersource";
	prop_desc = "Name of the Tango Mastersource device.";
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
	prop_name = "Pbunchatt_adc";
	prop_desc = "Name of the prebuncher attenuation ADC device.";
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
	prop_name = "Pbunchatt_dac";
	prop_desc = "Name of the prebuncher attenuation DAC device.";
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
	prop_name = "Pbunchphase";
	prop_desc = "Name of the pbuncher phase device.";
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
	prop_name = "Secphase_dac";
	prop_desc = "Name of the section 2 phase DAC device.";
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
	prop_desc = "number of the interlock relay used to determine whether the RF\nis on or not";
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
	prop_name = "Bunchphase_adc";
	prop_desc = "Name of the Buncher Phase Adc device.\nThis property is not used if the phase is controlled by a Paragon.\nIt is used only with the vpap controller.";
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
	prop_desc = "Name of the relay used to switch off RF.";
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
	prop_desc = "Name of the relay used to switch on RF.";
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
	prop_name = "Modulator";
	prop_desc = "Name of the Modulator device used in the reset command.\nReset command will call the Reset command of the modulator.";
	prop_def  = "elin/mod1/run";
	vect_data.clear();
	vect_data.push_back("elin/mod1/run");
	if (prop_def.length()>0)
	{
		Tango::DbDatum	data(prop_name);
		data << vect_data ;
		dev_def_prop.push_back(data);
		add_wiz_dev_prop(prop_name, prop_desc,  prop_def);
	}
	else
		add_wiz_dev_prop(prop_name, prop_desc);
	prop_name = "AtPermitDeviceName";
	prop_desc = "Device where to get the commands/attributes to map the AtPermit\nattribute.";
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
	prop_name = "PhPermitDeviceName";
	prop_desc = "Device where to get the commands/attributes to map the PhPermit\nattribute.";
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
 *	Method      : LinacRFClass::write_class_property()
 *	Description : Set class description fields as property in database
 */
//--------------------------------------------------------
void LinacRFClass::write_class_property()
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
	string	str_title("Linac Radio Frequency");
	title << str_title;
	data.push_back(title);

	//	Put Description
	Tango::DbDatum	description("Description");
	vector<string>	str_desc;
	str_desc.push_back("This class will manage the Linac RadioFrequency.");
	str_desc.push_back("The three structures of the linac (buncher - section 1 - section 2) consist of");
	str_desc.push_back("coupled wave guide cavities, through which a high frequency electromagnetic wave");
	str_desc.push_back("passes at the same speed than the electrons.");
	str_desc.push_back("The electrons are adjusted to the peak of the RF wave,");
	str_desc.push_back("they are then subjected to the maximum electrical field.");
	str_desc.push_back("The phase of the section1 is the reference;");
	str_desc.push_back("phases of the RF in buncher and section 2 are matched to get the electrons");
	str_desc.push_back("adjusted to the peak of the RF wave.");
	description << str_desc;
	data.push_back(description);

	//	put cvs or svn location
	string	filename("LinacRF");
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
 *	Method      : LinacRFClass::device_factory()
 *	Description : Create the device object(s)
 *                and store them in the device list
 */
//--------------------------------------------------------
void LinacRFClass::device_factory(const Tango::DevVarStringArray *devlist_ptr)
{
	/*----- PROTECTED REGION ID(LinacRFClass::device_factory_before) ENABLED START -----*/
	
	//	Add your own code
	
	/*----- PROTECTED REGION END -----*/	//	LinacRFClass::device_factory_before

	//	Create devices and add it into the device list
	for (unsigned long i=0 ; i<devlist_ptr->length() ; i++)
	{
		cout4 << "Device name : " << (*devlist_ptr)[i].in() << endl;
		device_list.push_back(new LinacRF(this, (*devlist_ptr)[i]));
	}

	//	Manage dynamic attributes if any
	erase_dynamic_attributes(devlist_ptr, get_class_attr()->get_attr_list());

	//	Export devices to the outside world
	for (unsigned long i=1 ; i<=devlist_ptr->length() ; i++)
	{
		//	Add dynamic attributes if any
		LinacRF *dev = static_cast<LinacRF *>(device_list[device_list.size()-i]);
		dev->add_dynamic_attributes();

		//	Check before if database used.
		if ((Tango::Util::_UseDb == true) && (Tango::Util::_FileDb == false))
			export_device(dev);
		else
			export_device(dev, dev->get_name().c_str());
	}

	/*----- PROTECTED REGION ID(LinacRFClass::device_factory_after) ENABLED START -----*/
	
	//	Add your own code
	
	/*----- PROTECTED REGION END -----*/	//	LinacRFClass::device_factory_after
}
//--------------------------------------------------------
/**
 *	Method      : LinacRFClass::attribute_factory()
 *	Description : Create the attribute object(s)
 *                and store them in the attribute list
 */
//--------------------------------------------------------
void LinacRFClass::attribute_factory(vector<Tango::Attr *> &att_list)
{
	/*----- PROTECTED REGION ID(LinacRFClass::attribute_factory_before) ENABLED START -----*/
	
	//	Add your own code
	
	/*----- PROTECTED REGION END -----*/	//	LinacRFClass::attribute_factory_before
	//	Attribute : Frequency
	FrequencyAttrib	*frequency = new FrequencyAttrib();
	Tango::UserDefaultAttrProp	frequency_prop;
	frequency_prop.set_description("Frequency");
	frequency_prop.set_label("Frequency");
	frequency_prop.set_unit("MHz");
	frequency_prop.set_standard_unit("MHz");
	frequency_prop.set_display_unit("MHz");
	frequency_prop.set_format("%8.3f");
	//	max_value	not set for Frequency
	//	min_value	not set for Frequency
	//	max_alarm	not set for Frequency
	//	min_alarm	not set for Frequency
	//	max_warning	not set for Frequency
	//	min_warning	not set for Frequency
	//	delta_t	not set for Frequency
	//	delta_val	not set for Frequency
	
	frequency->set_default_properties(frequency_prop);
	//	Not Polled
	frequency->set_disp_level(Tango::OPERATOR);
	frequency->set_memorized();
	frequency->set_memorized_init(true);
	att_list.push_back(frequency);

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

	//	Attribute : PBunchPhase
	PBunchPhaseAttrib	*pbunchphase = new PBunchPhaseAttrib();
	Tango::UserDefaultAttrProp	pbunchphase_prop;
	pbunchphase_prop.set_description("PreBuncher Phase");
	pbunchphase_prop.set_label("PreBuncher Phase");
	pbunchphase_prop.set_unit("deg");
	pbunchphase_prop.set_standard_unit("deg");
	pbunchphase_prop.set_display_unit("deg");
	pbunchphase_prop.set_format("%4.1f");
	//	max_value	not set for PBunchPhase
	//	min_value	not set for PBunchPhase
	//	max_alarm	not set for PBunchPhase
	//	min_alarm	not set for PBunchPhase
	//	max_warning	not set for PBunchPhase
	//	min_warning	not set for PBunchPhase
	//	delta_t	not set for PBunchPhase
	//	delta_val	not set for PBunchPhase
	
	pbunchphase->set_default_properties(pbunchphase_prop);
	//	Not Polled
	pbunchphase->set_disp_level(Tango::OPERATOR);
	pbunchphase->set_memorized();
	pbunchphase->set_memorized_init(true);
	att_list.push_back(pbunchphase);

	//	Attribute : PBunchAttenu
	PBunchAttenuAttrib	*pbunchattenu = new PBunchAttenuAttrib();
	Tango::UserDefaultAttrProp	pbunchattenu_prop;
	pbunchattenu_prop.set_description("PreBuncher Attenuation");
	pbunchattenu_prop.set_label("PreBuncher Attenuation");
	pbunchattenu_prop.set_unit("%");
	pbunchattenu_prop.set_standard_unit("%");
	pbunchattenu_prop.set_display_unit("%");
	pbunchattenu_prop.set_format("%4.1f");
	//	max_value	not set for PBunchAttenu
	//	min_value	not set for PBunchAttenu
	//	max_alarm	not set for PBunchAttenu
	//	min_alarm	not set for PBunchAttenu
	//	max_warning	not set for PBunchAttenu
	//	min_warning	not set for PBunchAttenu
	//	delta_t	not set for PBunchAttenu
	//	delta_val	not set for PBunchAttenu
	
	pbunchattenu->set_default_properties(pbunchattenu_prop);
	//	Not Polled
	pbunchattenu->set_disp_level(Tango::OPERATOR);
	pbunchattenu->set_memorized();
	pbunchattenu->set_memorized_init(true);
	att_list.push_back(pbunchattenu);

	//	Attribute : BunchPhase
	BunchPhaseAttrib	*bunchphase = new BunchPhaseAttrib();
	Tango::UserDefaultAttrProp	bunchphase_prop;
	bunchphase_prop.set_description("Buncher Phase");
	bunchphase_prop.set_label("Buncher Phase");
	bunchphase_prop.set_unit("deg");
	bunchphase_prop.set_standard_unit("deg");
	bunchphase_prop.set_display_unit("deg");
	bunchphase_prop.set_format("%4.1f");
	//	max_value	not set for BunchPhase
	//	min_value	not set for BunchPhase
	//	max_alarm	not set for BunchPhase
	//	min_alarm	not set for BunchPhase
	//	max_warning	not set for BunchPhase
	//	min_warning	not set for BunchPhase
	//	delta_t	not set for BunchPhase
	//	delta_val	not set for BunchPhase
	
	bunchphase->set_default_properties(bunchphase_prop);
	//	Not Polled
	bunchphase->set_disp_level(Tango::OPERATOR);
	bunchphase->set_memorized();
	bunchphase->set_memorized_init(true);
	att_list.push_back(bunchphase);

	//	Attribute : Sect2Phase
	Sect2PhaseAttrib	*sect2phase = new Sect2PhaseAttrib();
	Tango::UserDefaultAttrProp	sect2phase_prop;
	sect2phase_prop.set_description("Section 2 Phase.");
	sect2phase_prop.set_label("Section 2 Phase");
	sect2phase_prop.set_unit("deg");
	sect2phase_prop.set_standard_unit("deg");
	sect2phase_prop.set_display_unit("deg");
	sect2phase_prop.set_format("%4.1f");
	//	max_value	not set for Sect2Phase
	//	min_value	not set for Sect2Phase
	//	max_alarm	not set for Sect2Phase
	//	min_alarm	not set for Sect2Phase
	//	max_warning	not set for Sect2Phase
	//	min_warning	not set for Sect2Phase
	//	delta_t	not set for Sect2Phase
	//	delta_val	not set for Sect2Phase
	
	sect2phase->set_default_properties(sect2phase_prop);
	//	Not Polled
	sect2phase->set_disp_level(Tango::OPERATOR);
	sect2phase->set_memorized();
	sect2phase->set_memorized_init(true);
	att_list.push_back(sect2phase);

	//	Attribute : AtPermit
	AtPermitAttrib	*atpermit = new AtPermitAttrib();
	Tango::UserDefaultAttrProp	atpermit_prop;
	//	description	not set for AtPermit
	//	label	not set for AtPermit
	//	unit	not set for AtPermit
	//	standard_unit	not set for AtPermit
	//	display_unit	not set for AtPermit
	//	format	not set for AtPermit
	//	max_value	not set for AtPermit
	//	min_value	not set for AtPermit
	//	max_alarm	not set for AtPermit
	//	min_alarm	not set for AtPermit
	//	max_warning	not set for AtPermit
	//	min_warning	not set for AtPermit
	//	delta_t	not set for AtPermit
	//	delta_val	not set for AtPermit
	
	atpermit->set_default_properties(atpermit_prop);
	//	Not Polled
	atpermit->set_disp_level(Tango::OPERATOR);
	//	Not Memorized
	att_list.push_back(atpermit);

	//	Attribute : PhPermit
	PhPermitAttrib	*phpermit = new PhPermitAttrib();
	Tango::UserDefaultAttrProp	phpermit_prop;
	//	description	not set for PhPermit
	//	label	not set for PhPermit
	//	unit	not set for PhPermit
	//	standard_unit	not set for PhPermit
	//	display_unit	not set for PhPermit
	//	format	not set for PhPermit
	//	max_value	not set for PhPermit
	//	min_value	not set for PhPermit
	//	max_alarm	not set for PhPermit
	//	min_alarm	not set for PhPermit
	//	max_warning	not set for PhPermit
	//	min_warning	not set for PhPermit
	//	delta_t	not set for PhPermit
	//	delta_val	not set for PhPermit
	
	phpermit->set_default_properties(phpermit_prop);
	//	Not Polled
	phpermit->set_disp_level(Tango::OPERATOR);
	//	Not Memorized
	att_list.push_back(phpermit);


	//	Create a list of static attributes
	create_static_attribute_list(get_class_attr()->get_attr_list());
	/*----- PROTECTED REGION ID(LinacRFClass::attribute_factory_after) ENABLED START -----*/
	
	//	Add your own code
	
	/*----- PROTECTED REGION END -----*/	//	LinacRFClass::attribute_factory_after
}
//--------------------------------------------------------
/**
 *	Method      : LinacRFClass::pipe_factory()
 *	Description : Create the pipe object(s)
 *                and store them in the pipe list
 */
//--------------------------------------------------------
void LinacRFClass::pipe_factory()
{
	/*----- PROTECTED REGION ID(LinacRFClass::pipe_factory_before) ENABLED START -----*/
	
	//	Add your own code
	
	/*----- PROTECTED REGION END -----*/	//	LinacRFClass::pipe_factory_before
	/*----- PROTECTED REGION ID(LinacRFClass::pipe_factory_after) ENABLED START -----*/
	
	//	Add your own code
	
	/*----- PROTECTED REGION END -----*/	//	LinacRFClass::pipe_factory_after
}
//--------------------------------------------------------
/**
 *	Method      : LinacRFClass::command_factory()
 *	Description : Create the command object(s)
 *                and store them in the command list
 */
//--------------------------------------------------------
void LinacRFClass::command_factory()
{
	/*----- PROTECTED REGION ID(LinacRFClass::command_factory_before) ENABLED START -----*/
	
	//	Add your own code
	
	/*----- PROTECTED REGION END -----*/	//	LinacRFClass::command_factory_before


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

	/*----- PROTECTED REGION ID(LinacRFClass::command_factory_after) ENABLED START -----*/
	
	//	Add your own code
	
	/*----- PROTECTED REGION END -----*/	//	LinacRFClass::command_factory_after
}

//===================================================================
//	Dynamic attributes related methods
//===================================================================

//--------------------------------------------------------
/**
 * method : 		LinacRFClass::create_static_attribute_list
 * description : 	Create the a list of static attributes
 *
 * @param	att_list	the ceated attribute list
 */
//--------------------------------------------------------
void LinacRFClass::create_static_attribute_list(vector<Tango::Attr *> &att_list)
{
	for (unsigned long i=0 ; i<att_list.size() ; i++)
	{
		string att_name(att_list[i]->get_name());
		transform(att_name.begin(), att_name.end(), att_name.begin(), ::tolower);
		defaultAttList.push_back(att_name);
	}

	cout2 << defaultAttList.size() << " attributes in default list" << endl;

	/*----- PROTECTED REGION ID(LinacRFClass::create_static_att_list) ENABLED START -----*/
	
	/*----- PROTECTED REGION END -----*/	//	LinacRFClass::create_static_att_list
}


//--------------------------------------------------------
/**
 * method : 		LinacRFClass::erase_dynamic_attributes
 * description : 	delete the dynamic attributes if any.
 *
 * @param	devlist_ptr	the device list pointer
 * @param	list of all attributes
 */
//--------------------------------------------------------
void LinacRFClass::erase_dynamic_attributes(const Tango::DevVarStringArray *devlist_ptr, vector<Tango::Attr *> &att_list)
{
	Tango::Util *tg = Tango::Util::instance();

	for (unsigned long i=0 ; i<devlist_ptr->length() ; i++)
	{
		Tango::DeviceImpl *dev_impl = tg->get_device_by_name(((string)(*devlist_ptr)[i]).c_str());
		LinacRF *dev = static_cast<LinacRF *> (dev_impl);

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
	/*----- PROTECTED REGION ID(LinacRFClass::erase_dynamic_attributes) ENABLED START -----*/
	
	/*----- PROTECTED REGION END -----*/	//	LinacRFClass::erase_dynamic_attributes
}

//--------------------------------------------------------
/**
 *	Method      : LinacRFClass::get_attr_by_name()
 *	Description : returns Tango::Attr * object found by name
 */
//--------------------------------------------------------
Tango::Attr *LinacRFClass::get_attr_object_by_name(vector<Tango::Attr *> &att_list, string attname)
{
	vector<Tango::Attr *>::iterator it;
	for (it=att_list.begin() ; it<att_list.end() ; ++it)
		if ((*it)->get_name()==attname)
			return (*it);
	//	Attr does not exist
	return NULL;
}


/*----- PROTECTED REGION ID(LinacRFClass::Additional Methods) ENABLED START -----*/

/*----- PROTECTED REGION END -----*/	//	LinacRFClass::Additional Methods
} //	namespace