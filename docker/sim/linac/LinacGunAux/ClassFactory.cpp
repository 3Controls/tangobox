/*----- PROTECTED REGION ID(LinacGunAux::ClassFactory.cpp) ENABLED START -----*/
static const char *RcsId = "$Header: /segfs/tango/cvsroot/cppserver/machine/linac/LinacGunAux/ClassFactory.cpp,v 1.5 2009/07/15 13:36:46 vedder Exp $";
//+=============================================================================
//
// file :        ClassFactory.cpp
//
// description : C++ source for the class_factory method of the DServer
//               device class. This method is responsible to create
//               all class singletin for a device server. It is called
//               at device server startup
//
// project :     TANGO Device Server
//
// $Author: vedder $
//
// $Revision: 1.5 $
//
// $Log: ClassFactory.cpp,v $
// Revision 1.5  2009/07/15 13:36:46  vedder
// Add powerSupplyDeviceName property : TDKLambda device name.
//
// Remove no more used SDac SAdc deviceproxy, replaced by TDKLambdaZup:
// 	Tango::DeviceProxy * HeatIadcds;
// 	Tango::DeviceProxy * HeatVadcds;
// 	Tango::DeviceProxy * HeatVdacds;
//
// Modify : void LinacGunAux::read_HeatI(Tango::Attribute &attr) to use ZUP.
// Modify :void LinacGunAux::read_HeatV(Tango::Attribute &attr) to use ZUP.
// Modify : void LinacGunAux::write_HeatV(Tango::WAttribute &attr) to use ZUP.
// Commented out : void LinacGunAux::update_setval(Tango::DeviceProxy * dacds,const char* attr_name,Tango::DevDouble *setvalue)
// Commented out : void LinacGunAux::write_dac_val(Tango::DeviceProxy * dacds,Tango::DevDouble setvalue)
// Commented out : void LinacGunAux::read_adc_val(Tango::DeviceProxy * adcds, Tango::DevDouble *readval)
//
// Commented out : All related to SAdc150 class.
// Commented out : All related to SDac712 class.
//
// Adapted Makefile to these modifications.
//
// Note : The choice has been made to keep the TDKLambda (zup) class in a different
// device server since it already includes Serial, MultiChannelPowerSupply and
// TDKlamda classes.
//
// Revision 1.4  2006/06/20 13:55:57  bourtemb
// remove add_class(WagoRelay)
//
// Revision 1.3  2005/09/20 13:20:59  bourtemb
// WIN32 SIMU version
//
// Revision 1.2  2005/06/02 13:01:10  bourtemb
// add the possibility to handle SAdc150, SDac712 and WagoRelay devices internally
//
// Revision 1.1.1.1  2005/05/18 11:29:28  bourtemb
// Imported using TkCVS
//
//
// copyleft :    European Synchrotron Radiation Facility
//               BP 220, Grenoble 38043
//               FRANCE
//
//-=============================================================================
//
//  		This file is generated by POGO
//	(Program Obviously used to Generate tango Object)
//
//         (c) - Software Engineering Group - ESRF
//=============================================================================


#include <tango.h>
#include <LinacGunAuxClass.h>
#ifndef SIMU
//#include <SAdc150Class.h>
//#include <SDac712Class.h>
#endif

/**
 *	Create LinacGunAuxClass singleton and store it in DServer object.
 */

void Tango::DServer::class_factory()
{
#ifndef SIMU
//	add_class(SAdc150_ns::SAdc150Class::init("SAdc150"));
//	add_class(SDac712_ns::SDac712Class::init("SDac712"));
#endif
	add_class(LinacGunAux_ns::LinacGunAuxClass::init("LinacGunAux"));
}
/*----- PROTECTED REGION END -----*/	//	LinacGunAux::ClassFactory.cpp
