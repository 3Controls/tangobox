//=============================================================================
//
// file :         ShareData.h
//
// description :  This file defines the share data structure that will be 
// 				  used between acquisition thread and tango device server
//				  thread.
//                		
// project :      TANGO Device Server
//
// $Author: tappret $
//
// $Revision: 1.2 $
//
//
// copyleft :     European Synchrotron Radiation Facility
//                BP 220, Grenoble 38043
//                FRANCE
//
//=============================================================================

#ifndef SHARED_DATA_H
#define SHARED_DATA_H

#include <tango.h>

using namespace Tango;

// Should be identical to Pogo's spectrum size.
#define MAX_DEVICE_NUMBER	512

struct SharedData
{
	DevState calculatedState;
	string	 calculatedStatus;
	DevDouble sum;
	DevDouble mean;
	DevDouble rms;
	DevDouble stdDeviation;
	DevLong dataCollectionDuration;
	DevState subDevicesStates[MAX_DEVICE_NUMBER];
	DevDouble collectedData[MAX_DEVICE_NUMBER];
};

#endif


