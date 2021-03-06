/*----- PROTECTED REGION ID(LinacHVPS::ClassFactory.cpp) ENABLED START -----*/
static const char *RcsId = "$Header: /segfs/tango/cvsroot/cppserver/machine/linac/LinacHVPS/ClassFactory.cpp,v 1.5 2006/06/20 14:24:18 bourtemb Exp $";
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
// $Revision: 1.5 $
//
// $Log: ClassFactory.cpp,v $
// Revision 1.5  2006/06/20 14:24:18  bourtemb
// remove add_class(WagoRelay)
//
// Revision 1.4  2005/09/20 08:46:17  bourtemb
// WIN32 SIMU version
//
// Revision 1.3  2005/08/31 12:56:34  bourtemb
// update SIMU version
//
// Revision 1.2  2005/06/02 13:01:16  bourtemb
// add the possibility to handle SAdc150, SDac712 and WagoRelay devices internally
//
// Revision 1.1.1.1  2005/05/18 11:30:59  bourtemb
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
#include <LinacHVPSClass.h>
#ifndef SIMU
#include <SAdc150Class.h>
#include <SDac712Class.h>
#endif

/**
 *	Create LinacHVPSClass singleton and store it in DServer object.
 */

void Tango::DServer::class_factory()
{
#ifndef SIMU
	add_class(SAdc150_ns::SAdc150Class::init("SAdc150"));
	add_class(SDac712_ns::SDac712Class::init("SDac712"));
#endif
	add_class(LinacHVPS_ns::LinacHVPSClass::init("LinacHVPS"));

}
/*----- PROTECTED REGION END -----*/	//	LinacHVPS::ClassFactory.cpp
