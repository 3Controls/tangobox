/*----- PROTECTED REGION ID(LinacModAuxStateMachine.cpp) ENABLED START -----*/
static const char *RcsId = "$Id:  $";
//=============================================================================
//
// file :        LinacModAuxStateMachine.cpp
//
// description : State machine file for the LinacModAux class
//
// project :     Linac Modulator Auxiliary
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

#include <LinacModAux.h>

/*----- PROTECTED REGION END -----*/	//	LinacModAux::LinacModAuxStateMachine.cpp

//================================================================
//  States   |  Description
//================================================================
//  FAULT    |  *
//  INIT     |  Low Heating state.
//  MOVING   |  *
//  OFF      |  *
//  ON       |  *
//  DISABLE  |  


namespace LinacModAux_ns
{
//=================================================
//		Attributes Allowed Methods
//=================================================

//--------------------------------------------------------
/**
 *	Method      : LinacModAux::is_HeatI_allowed()
 *	Description : Execution allowed for HeatI attribute
 */
//--------------------------------------------------------
bool LinacModAux::is_HeatI_allowed(TANGO_UNUSED(Tango::AttReqType type))
{

	//	Not any excluded states for HeatI attribute in read access.
	/*----- PROTECTED REGION ID(LinacModAux::HeatIStateAllowed_READ) ENABLED START -----*/
	
	/*----- PROTECTED REGION END -----*/	//	LinacModAux::HeatIStateAllowed_READ
	return true;
}

//--------------------------------------------------------
/**
 *	Method      : LinacModAux::is_HeatV_allowed()
 *	Description : Execution allowed for HeatV attribute
 */
//--------------------------------------------------------
bool LinacModAux::is_HeatV_allowed(TANGO_UNUSED(Tango::AttReqType type))
{

	//	Not any excluded states for HeatV attribute in read access.
	/*----- PROTECTED REGION ID(LinacModAux::HeatVStateAllowed_READ) ENABLED START -----*/
	
	/*----- PROTECTED REGION END -----*/	//	LinacModAux::HeatVStateAllowed_READ
	return true;
}

//--------------------------------------------------------
/**
 *	Method      : LinacModAux::is_Temporization_allowed()
 *	Description : Execution allowed for Temporization attribute
 */
//--------------------------------------------------------
bool LinacModAux::is_Temporization_allowed(TANGO_UNUSED(Tango::AttReqType type))
{

	//	Not any excluded states for Temporization attribute in read access.
	/*----- PROTECTED REGION ID(LinacModAux::TemporizationStateAllowed_READ) ENABLED START -----*/
	
	/*----- PROTECTED REGION END -----*/	//	LinacModAux::TemporizationStateAllowed_READ
	return true;
}

//--------------------------------------------------------
/**
 *	Method      : LinacModAux::is_ThyratronHeatV_allowed()
 *	Description : Execution allowed for ThyratronHeatV attribute
 */
//--------------------------------------------------------
bool LinacModAux::is_ThyratronHeatV_allowed(TANGO_UNUSED(Tango::AttReqType type))
{

	//	Not any excluded states for ThyratronHeatV attribute in read access.
	/*----- PROTECTED REGION ID(LinacModAux::ThyratronHeatVStateAllowed_READ) ENABLED START -----*/
	
	/*----- PROTECTED REGION END -----*/	//	LinacModAux::ThyratronHeatVStateAllowed_READ
	return true;
}

//--------------------------------------------------------
/**
 *	Method      : LinacModAux::is_Economy_allowed()
 *	Description : Execution allowed for Economy attribute
 */
//--------------------------------------------------------
bool LinacModAux::is_Economy_allowed(TANGO_UNUSED(Tango::AttReqType type))
{
	//	Not any excluded states for Economy attribute in Write access.
	/*----- PROTECTED REGION ID(LinacModAux::EconomyStateAllowed_WRITE) ENABLED START -----*/
	
	/*----- PROTECTED REGION END -----*/	//	LinacModAux::EconomyStateAllowed_WRITE

	//	Not any excluded states for Economy attribute in read access.
	/*----- PROTECTED REGION ID(LinacModAux::EconomyStateAllowed_READ) ENABLED START -----*/
	
	/*----- PROTECTED REGION END -----*/	//	LinacModAux::EconomyStateAllowed_READ
	return true;
}


//=================================================
//		Commands Allowed Methods
//=================================================

//--------------------------------------------------------
/**
 *	Method      : LinacModAux::is_On_allowed()
 *	Description : Execution allowed for On attribute
 */
//--------------------------------------------------------
bool LinacModAux::is_On_allowed(TANGO_UNUSED(const CORBA::Any &any))
{
	//	Not any excluded states for On command.
	/*----- PROTECTED REGION ID(LinacModAux::OnStateAllowed) ENABLED START -----*/
	
	/*----- PROTECTED REGION END -----*/	//	LinacModAux::OnStateAllowed
	return true;
}

//--------------------------------------------------------
/**
 *	Method      : LinacModAux::is_Off_allowed()
 *	Description : Execution allowed for Off attribute
 */
//--------------------------------------------------------
bool LinacModAux::is_Off_allowed(TANGO_UNUSED(const CORBA::Any &any))
{
	//	Not any excluded states for Off command.
	/*----- PROTECTED REGION ID(LinacModAux::OffStateAllowed) ENABLED START -----*/
	
	/*----- PROTECTED REGION END -----*/	//	LinacModAux::OffStateAllowed
	return true;
}

//--------------------------------------------------------
/**
 *	Method      : LinacModAux::is_Reset_allowed()
 *	Description : Execution allowed for Reset attribute
 */
//--------------------------------------------------------
bool LinacModAux::is_Reset_allowed(TANGO_UNUSED(const CORBA::Any &any))
{
	//	Not any excluded states for Reset command.
	/*----- PROTECTED REGION ID(LinacModAux::ResetStateAllowed) ENABLED START -----*/
	
	/*----- PROTECTED REGION END -----*/	//	LinacModAux::ResetStateAllowed
	return true;
}

//--------------------------------------------------------
/**
 *	Method      : LinacModAux::is_Standby_allowed()
 *	Description : Execution allowed for Standby attribute
 */
//--------------------------------------------------------
bool LinacModAux::is_Standby_allowed(TANGO_UNUSED(const CORBA::Any &any))
{
	//	Not any excluded states for Standby command.
	/*----- PROTECTED REGION ID(LinacModAux::StandbyStateAllowed) ENABLED START -----*/
	
	/*----- PROTECTED REGION END -----*/	//	LinacModAux::StandbyStateAllowed
	return true;
}

//--------------------------------------------------------
/**
 *	Method      : LinacModAux::is_LowHeating_allowed()
 *	Description : Execution allowed for LowHeating attribute
 */
//--------------------------------------------------------
bool LinacModAux::is_LowHeating_allowed(TANGO_UNUSED(const CORBA::Any &any))
{
	//	Not any excluded states for LowHeating command.
	/*----- PROTECTED REGION ID(LinacModAux::LowHeatingStateAllowed) ENABLED START -----*/
	
	/*----- PROTECTED REGION END -----*/	//	LinacModAux::LowHeatingStateAllowed
	return true;
}

//--------------------------------------------------------
/**
 *	Method      : LinacModAux::is_SoftOff_allowed()
 *	Description : Execution allowed for SoftOff attribute
 */
//--------------------------------------------------------
bool LinacModAux::is_SoftOff_allowed(TANGO_UNUSED(const CORBA::Any &any))
{
	//	Not any excluded states for SoftOff command.
	/*----- PROTECTED REGION ID(LinacModAux::SoftOffStateAllowed) ENABLED START -----*/
	
	/*----- PROTECTED REGION END -----*/	//	LinacModAux::SoftOffStateAllowed
	return true;
}

//--------------------------------------------------------
/**
 *	Method      : LinacModAux::is_SoftOn_allowed()
 *	Description : Execution allowed for SoftOn attribute
 */
//--------------------------------------------------------
bool LinacModAux::is_SoftOn_allowed(TANGO_UNUSED(const CORBA::Any &any))
{
	//	Not any excluded states for SoftOn command.
	/*----- PROTECTED REGION ID(LinacModAux::SoftOnStateAllowed) ENABLED START -----*/
	
	/*----- PROTECTED REGION END -----*/	//	LinacModAux::SoftOnStateAllowed
	return true;
}


/*----- PROTECTED REGION ID(LinacModAux::LinacModAuxStateAllowed.AdditionalMethods) ENABLED START -----*/

//	Additional Methods

/*----- PROTECTED REGION END -----*/	//	LinacModAux::LinacModAuxStateAllowed.AdditionalMethods

}	//	End of namespace
