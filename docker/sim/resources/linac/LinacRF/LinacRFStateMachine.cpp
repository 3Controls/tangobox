/*----- PROTECTED REGION ID(LinacRFStateMachine.cpp) ENABLED START -----*/
static const char *RcsId = "$Id:  $";
//=============================================================================
//
// file :        LinacRFStateMachine.cpp
//
// description : State machine file for the LinacRF class
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

#include <LinacRF.h>

/*----- PROTECTED REGION END -----*/	//	LinacRF::LinacRFStateMachine.cpp

//================================================================
//  States   |  Description
//================================================================
//  ON       |  *
//  OFF      |  *
//  DISABLE  |  *
//  FAULT    |  *
//  UNKNOWN  |  


namespace LinacRF_ns
{
//=================================================
//		Attributes Allowed Methods
//=================================================

//--------------------------------------------------------
/**
 *	Method      : LinacRF::is_Frequency_allowed()
 *	Description : Execution allowed for Frequency attribute
 */
//--------------------------------------------------------
bool LinacRF::is_Frequency_allowed(TANGO_UNUSED(Tango::AttReqType type))
{
	//	Not any excluded states for Frequency attribute in Write access.
	/*----- PROTECTED REGION ID(LinacRF::FrequencyStateAllowed_WRITE) ENABLED START -----*/
	
	/*----- PROTECTED REGION END -----*/	//	LinacRF::FrequencyStateAllowed_WRITE

	//	Not any excluded states for Frequency attribute in read access.
	/*----- PROTECTED REGION ID(LinacRF::FrequencyStateAllowed_READ) ENABLED START -----*/
	
	/*----- PROTECTED REGION END -----*/	//	LinacRF::FrequencyStateAllowed_READ
	return true;
}

//--------------------------------------------------------
/**
 *	Method      : LinacRF::is_Delay_allowed()
 *	Description : Execution allowed for Delay attribute
 */
//--------------------------------------------------------
bool LinacRF::is_Delay_allowed(TANGO_UNUSED(Tango::AttReqType type))
{
	//	Not any excluded states for Delay attribute in Write access.
	/*----- PROTECTED REGION ID(LinacRF::DelayStateAllowed_WRITE) ENABLED START -----*/
	
	/*----- PROTECTED REGION END -----*/	//	LinacRF::DelayStateAllowed_WRITE

	//	Not any excluded states for Delay attribute in read access.
	/*----- PROTECTED REGION ID(LinacRF::DelayStateAllowed_READ) ENABLED START -----*/
	
	/*----- PROTECTED REGION END -----*/	//	LinacRF::DelayStateAllowed_READ
	return true;
}

//--------------------------------------------------------
/**
 *	Method      : LinacRF::is_PBunchPhase_allowed()
 *	Description : Execution allowed for PBunchPhase attribute
 */
//--------------------------------------------------------
bool LinacRF::is_PBunchPhase_allowed(TANGO_UNUSED(Tango::AttReqType type))
{
	//	Not any excluded states for PBunchPhase attribute in Write access.
	/*----- PROTECTED REGION ID(LinacRF::PBunchPhaseStateAllowed_WRITE) ENABLED START -----*/
	
	/*----- PROTECTED REGION END -----*/	//	LinacRF::PBunchPhaseStateAllowed_WRITE

	//	Not any excluded states for PBunchPhase attribute in read access.
	/*----- PROTECTED REGION ID(LinacRF::PBunchPhaseStateAllowed_READ) ENABLED START -----*/
	
	/*----- PROTECTED REGION END -----*/	//	LinacRF::PBunchPhaseStateAllowed_READ
	return true;
}

//--------------------------------------------------------
/**
 *	Method      : LinacRF::is_PBunchAttenu_allowed()
 *	Description : Execution allowed for PBunchAttenu attribute
 */
//--------------------------------------------------------
bool LinacRF::is_PBunchAttenu_allowed(TANGO_UNUSED(Tango::AttReqType type))
{
	//	Not any excluded states for PBunchAttenu attribute in Write access.
	/*----- PROTECTED REGION ID(LinacRF::PBunchAttenuStateAllowed_WRITE) ENABLED START -----*/
	
	/*----- PROTECTED REGION END -----*/	//	LinacRF::PBunchAttenuStateAllowed_WRITE

	//	Not any excluded states for PBunchAttenu attribute in read access.
	/*----- PROTECTED REGION ID(LinacRF::PBunchAttenuStateAllowed_READ) ENABLED START -----*/
	
	/*----- PROTECTED REGION END -----*/	//	LinacRF::PBunchAttenuStateAllowed_READ
	return true;
}

//--------------------------------------------------------
/**
 *	Method      : LinacRF::is_BunchPhase_allowed()
 *	Description : Execution allowed for BunchPhase attribute
 */
//--------------------------------------------------------
bool LinacRF::is_BunchPhase_allowed(TANGO_UNUSED(Tango::AttReqType type))
{
	//	Not any excluded states for BunchPhase attribute in Write access.
	/*----- PROTECTED REGION ID(LinacRF::BunchPhaseStateAllowed_WRITE) ENABLED START -----*/
	
	/*----- PROTECTED REGION END -----*/	//	LinacRF::BunchPhaseStateAllowed_WRITE

	//	Not any excluded states for BunchPhase attribute in read access.
	/*----- PROTECTED REGION ID(LinacRF::BunchPhaseStateAllowed_READ) ENABLED START -----*/
	
	/*----- PROTECTED REGION END -----*/	//	LinacRF::BunchPhaseStateAllowed_READ
	return true;
}

//--------------------------------------------------------
/**
 *	Method      : LinacRF::is_Sect2Phase_allowed()
 *	Description : Execution allowed for Sect2Phase attribute
 */
//--------------------------------------------------------
bool LinacRF::is_Sect2Phase_allowed(TANGO_UNUSED(Tango::AttReqType type))
{
	//	Not any excluded states for Sect2Phase attribute in Write access.
	/*----- PROTECTED REGION ID(LinacRF::Sect2PhaseStateAllowed_WRITE) ENABLED START -----*/
	
	/*----- PROTECTED REGION END -----*/	//	LinacRF::Sect2PhaseStateAllowed_WRITE

	//	Not any excluded states for Sect2Phase attribute in read access.
	/*----- PROTECTED REGION ID(LinacRF::Sect2PhaseStateAllowed_READ) ENABLED START -----*/
	
	/*----- PROTECTED REGION END -----*/	//	LinacRF::Sect2PhaseStateAllowed_READ
	return true;
}

//--------------------------------------------------------
/**
 *	Method      : LinacRF::is_AtPermit_allowed()
 *	Description : Execution allowed for AtPermit attribute
 */
//--------------------------------------------------------
bool LinacRF::is_AtPermit_allowed(TANGO_UNUSED(Tango::AttReqType type))
{
	//	Not any excluded states for AtPermit attribute in Write access.
	/*----- PROTECTED REGION ID(LinacRF::AtPermitStateAllowed_WRITE) ENABLED START -----*/
	
	/*----- PROTECTED REGION END -----*/	//	LinacRF::AtPermitStateAllowed_WRITE

	//	Not any excluded states for AtPermit attribute in read access.
	/*----- PROTECTED REGION ID(LinacRF::AtPermitStateAllowed_READ) ENABLED START -----*/
	
	/*----- PROTECTED REGION END -----*/	//	LinacRF::AtPermitStateAllowed_READ
	return true;
}

//--------------------------------------------------------
/**
 *	Method      : LinacRF::is_PhPermit_allowed()
 *	Description : Execution allowed for PhPermit attribute
 */
//--------------------------------------------------------
bool LinacRF::is_PhPermit_allowed(TANGO_UNUSED(Tango::AttReqType type))
{
	//	Not any excluded states for PhPermit attribute in Write access.
	/*----- PROTECTED REGION ID(LinacRF::PhPermitStateAllowed_WRITE) ENABLED START -----*/
	
	/*----- PROTECTED REGION END -----*/	//	LinacRF::PhPermitStateAllowed_WRITE

	//	Not any excluded states for PhPermit attribute in read access.
	/*----- PROTECTED REGION ID(LinacRF::PhPermitStateAllowed_READ) ENABLED START -----*/
	
	/*----- PROTECTED REGION END -----*/	//	LinacRF::PhPermitStateAllowed_READ
	return true;
}


//=================================================
//		Commands Allowed Methods
//=================================================

//--------------------------------------------------------
/**
 *	Method      : LinacRF::is_On_allowed()
 *	Description : Execution allowed for On attribute
 */
//--------------------------------------------------------
bool LinacRF::is_On_allowed(TANGO_UNUSED(const CORBA::Any &any))
{
	//	Not any excluded states for On command.
	/*----- PROTECTED REGION ID(LinacRF::OnStateAllowed) ENABLED START -----*/
	
	/*----- PROTECTED REGION END -----*/	//	LinacRF::OnStateAllowed
	return true;
}

//--------------------------------------------------------
/**
 *	Method      : LinacRF::is_Off_allowed()
 *	Description : Execution allowed for Off attribute
 */
//--------------------------------------------------------
bool LinacRF::is_Off_allowed(TANGO_UNUSED(const CORBA::Any &any))
{
	//	Not any excluded states for Off command.
	/*----- PROTECTED REGION ID(LinacRF::OffStateAllowed) ENABLED START -----*/
	
	/*----- PROTECTED REGION END -----*/	//	LinacRF::OffStateAllowed
	return true;
}

//--------------------------------------------------------
/**
 *	Method      : LinacRF::is_Reset_allowed()
 *	Description : Execution allowed for Reset attribute
 */
//--------------------------------------------------------
bool LinacRF::is_Reset_allowed(TANGO_UNUSED(const CORBA::Any &any))
{
	//	Not any excluded states for Reset command.
	/*----- PROTECTED REGION ID(LinacRF::ResetStateAllowed) ENABLED START -----*/
	
	/*----- PROTECTED REGION END -----*/	//	LinacRF::ResetStateAllowed
	return true;
}

//--------------------------------------------------------
/**
 *	Method      : LinacRF::is_TimingOn_allowed()
 *	Description : Execution allowed for TimingOn attribute
 */
//--------------------------------------------------------
bool LinacRF::is_TimingOn_allowed(TANGO_UNUSED(const CORBA::Any &any))
{
	//	Not any excluded states for TimingOn command.
	/*----- PROTECTED REGION ID(LinacRF::TimingOnStateAllowed) ENABLED START -----*/
	
	/*----- PROTECTED REGION END -----*/	//	LinacRF::TimingOnStateAllowed
	return true;
}


/*----- PROTECTED REGION ID(LinacRF::LinacRFStateAllowed.AdditionalMethods) ENABLED START -----*/

//	Additional Methods

/*----- PROTECTED REGION END -----*/	//	LinacRF::LinacRFStateAllowed.AdditionalMethods

}	//	End of namespace