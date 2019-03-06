/*----- PROTECTED REGION ID(LinacGunHVPSStateMachine.cpp) ENABLED START -----*/
static const char *RcsId = "$Id:  $";
//=============================================================================
//
// file :        LinacGunHVPSStateMachine.cpp
//
// description : State machine file for the LinacGunHVPS class
//
// project :     Linac Gun High Voltage Power Supply
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

#include <LinacGunHVPS.h>

/*----- PROTECTED REGION END -----*/	//	LinacGunHVPS::LinacGunHVPSStateMachine.cpp

//================================================================
//  States   |  Description
//================================================================
//  ON       |  *
//  OFF      |  *
//  DISABLE  |  *
//  FAULT    |  


namespace LinacGunHVPS_ns
{
//=================================================
//		Attributes Allowed Methods
//=================================================

//--------------------------------------------------------
/**
 *	Method      : LinacGunHVPS::is_HighVoltage_allowed()
 *	Description : Execution allowed for HighVoltage attribute
 */
//--------------------------------------------------------
bool LinacGunHVPS::is_HighVoltage_allowed(TANGO_UNUSED(Tango::AttReqType type))
{
	//	Not any excluded states for HighVoltage attribute in Write access.
	/*----- PROTECTED REGION ID(LinacGunHVPS::HighVoltageStateAllowed_WRITE) ENABLED START -----*/
	
	/*----- PROTECTED REGION END -----*/	//	LinacGunHVPS::HighVoltageStateAllowed_WRITE

	//	Not any excluded states for HighVoltage attribute in read access.
	/*----- PROTECTED REGION ID(LinacGunHVPS::HighVoltageStateAllowed_READ) ENABLED START -----*/
	
	/*----- PROTECTED REGION END -----*/	//	LinacGunHVPS::HighVoltageStateAllowed_READ
	return true;
}

//--------------------------------------------------------
/**
 *	Method      : LinacGunHVPS::is_Current_allowed()
 *	Description : Execution allowed for Current attribute
 */
//--------------------------------------------------------
bool LinacGunHVPS::is_Current_allowed(TANGO_UNUSED(Tango::AttReqType type))
{

	//	Not any excluded states for Current attribute in read access.
	/*----- PROTECTED REGION ID(LinacGunHVPS::CurrentStateAllowed_READ) ENABLED START -----*/
	
	/*----- PROTECTED REGION END -----*/	//	LinacGunHVPS::CurrentStateAllowed_READ
	return true;
}


//=================================================
//		Commands Allowed Methods
//=================================================

//--------------------------------------------------------
/**
 *	Method      : LinacGunHVPS::is_On_allowed()
 *	Description : Execution allowed for On attribute
 */
//--------------------------------------------------------
bool LinacGunHVPS::is_On_allowed(TANGO_UNUSED(const CORBA::Any &any))
{
	//	Not any excluded states for On command.
	/*----- PROTECTED REGION ID(LinacGunHVPS::OnStateAllowed) ENABLED START -----*/
	
	/*----- PROTECTED REGION END -----*/	//	LinacGunHVPS::OnStateAllowed
	return true;
}

//--------------------------------------------------------
/**
 *	Method      : LinacGunHVPS::is_Off_allowed()
 *	Description : Execution allowed for Off attribute
 */
//--------------------------------------------------------
bool LinacGunHVPS::is_Off_allowed(TANGO_UNUSED(const CORBA::Any &any))
{
	//	Not any excluded states for Off command.
	/*----- PROTECTED REGION ID(LinacGunHVPS::OffStateAllowed) ENABLED START -----*/
	
	/*----- PROTECTED REGION END -----*/	//	LinacGunHVPS::OffStateAllowed
	return true;
}

//--------------------------------------------------------
/**
 *	Method      : LinacGunHVPS::is_Reset_allowed()
 *	Description : Execution allowed for Reset attribute
 */
//--------------------------------------------------------
bool LinacGunHVPS::is_Reset_allowed(TANGO_UNUSED(const CORBA::Any &any))
{
	//	Not any excluded states for Reset command.
	/*----- PROTECTED REGION ID(LinacGunHVPS::ResetStateAllowed) ENABLED START -----*/
	
	/*----- PROTECTED REGION END -----*/	//	LinacGunHVPS::ResetStateAllowed
	return true;
}


/*----- PROTECTED REGION ID(LinacGunHVPS::LinacGunHVPSStateAllowed.AdditionalMethods) ENABLED START -----*/

//	Additional Methods

/*----- PROTECTED REGION END -----*/	//	LinacGunHVPS::LinacGunHVPSStateAllowed.AdditionalMethods

}	//	End of namespace