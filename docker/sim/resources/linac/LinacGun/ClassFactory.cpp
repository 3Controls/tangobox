/*----- PROTECTED REGION ID(LinacGun::ClassFactory.cpp) ENABLED START -----*/
static const char *RcsId = "$Header: /segfs/tango/cvsroot/cppserver/machine/linac/LinacGun/ClassFactory.cpp,v 1.4 2006/06/20 13:45:26 bourtemb Exp $";
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
// $Author: bourtemb $
//
// $Revision: 1.4 $
//
// $Log: ClassFactory.cpp,v $
// Revision 1.4  2006/06/20 13:45:26  bourtemb
// remove add_class(WagoRelay)
//
// Revision 1.3  2005/09/20 13:12:31  bourtemb
// WIN32 SIMU version
//
// Revision 1.2  2005/06/02 13:00:32  bourtemb
// Add the possibility to handle SAdc150, WagoRelay and SDac712 devices internally.
//
// Revision 1.1.1.1  2005/05/18 11:27:47  bourtemb
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
#include <LinacGunClass.h>
#ifndef SIMU
#include <SAdc150Class.h>
#include <SDac712Class.h>
#endif

/**
 *	Create LinacGunClass singleton and store it in DServer object.
 */

void Tango::DServer::class_factory()
{
#ifndef SIMU
	add_class(SAdc150_ns::SAdc150Class::init("SAdc150"));
	add_class(SDac712_ns::SDac712Class::init("SDac712"));
#endif
	add_class(LinacGun_ns::LinacGunClass::init("LinacGun"));

}
/*----- PROTECTED REGION END -----*/	//	LinacGun::ClassFactory.cpp