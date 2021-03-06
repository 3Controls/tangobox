/*----- PROTECTED REGION ID(LinacSequencerStateMachine.cpp) ENABLED START -----*/
static const char *RcsId = "$Id:  $";
//=============================================================================
//
// file :        LinacSequencerStateMachine.cpp
//
// description : State machine file for the LinacSequencer class
//
// project :     Sequencer Server for LINAC
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

#include <LinacSequencer.h>

/*----- PROTECTED REGION END -----*/	//	LinacSequencer::LinacSequencerStateMachine.cpp

//================================================================
//  States   |  Description
//================================================================
//  ON       |  The sequencer is ready to run a new sequence.
//  MOVING   |  A sequence is currently running.
//  DISABLE  |  The last sequence failed during execution or was interrupted by the user.


namespace LinacSequencer_ns
{
//=================================================
//		Attributes Allowed Methods
//=================================================

//--------------------------------------------------------
/**
 *	Method      : LinacSequencer::is_IsFileLoaded_allowed()
 *	Description : Execution allowed for IsFileLoaded attribute
 */
//--------------------------------------------------------
bool LinacSequencer::is_IsFileLoaded_allowed(TANGO_UNUSED(Tango::AttReqType type))
{

	//	Not any excluded states for IsFileLoaded attribute in read access.
	/*----- PROTECTED REGION ID(LinacSequencer::IsFileLoadedStateAllowed_READ) ENABLED START -----*/
	
	/*----- PROTECTED REGION END -----*/	//	LinacSequencer::IsFileLoadedStateAllowed_READ
	return true;
}

//--------------------------------------------------------
/**
 *	Method      : LinacSequencer::is_SequenceHistory_allowed()
 *	Description : Execution allowed for SequenceHistory attribute
 */
//--------------------------------------------------------
bool LinacSequencer::is_SequenceHistory_allowed(TANGO_UNUSED(Tango::AttReqType type))
{

	//	Not any excluded states for SequenceHistory attribute in read access.
	/*----- PROTECTED REGION ID(LinacSequencer::SequenceHistoryStateAllowed_READ) ENABLED START -----*/
	
	/*----- PROTECTED REGION END -----*/	//	LinacSequencer::SequenceHistoryStateAllowed_READ
	return true;
}


//=================================================
//		Commands Allowed Methods
//=================================================

//--------------------------------------------------------
/**
 *	Method      : LinacSequencer::is_Abort_allowed()
 *	Description : Execution allowed for Abort attribute
 */
//--------------------------------------------------------
bool LinacSequencer::is_Abort_allowed(TANGO_UNUSED(const CORBA::Any &any))
{
	//	Not any excluded states for Abort command.
	/*----- PROTECTED REGION ID(LinacSequencer::AbortStateAllowed) ENABLED START -----*/
	
	/*----- PROTECTED REGION END -----*/	//	LinacSequencer::AbortStateAllowed
	return true;
}

//--------------------------------------------------------
/**
 *	Method      : LinacSequencer::is_LoadFile_allowed()
 *	Description : Execution allowed for LoadFile attribute
 */
//--------------------------------------------------------
bool LinacSequencer::is_LoadFile_allowed(TANGO_UNUSED(const CORBA::Any &any))
{
	//	Compare device state with not allowed states.
	if (get_state()==Tango::MOVING)
	{
	/*----- PROTECTED REGION ID(LinacSequencer::LoadFileStateAllowed) ENABLED START -----*/
	
	/*----- PROTECTED REGION END -----*/	//	LinacSequencer::LoadFileStateAllowed
		return false;
	}
	return true;
}

//--------------------------------------------------------
/**
 *	Method      : LinacSequencer::is_SaveFile_allowed()
 *	Description : Execution allowed for SaveFile attribute
 */
//--------------------------------------------------------
bool LinacSequencer::is_SaveFile_allowed(TANGO_UNUSED(const CORBA::Any &any))
{
	//	Compare device state with not allowed states.
	if (get_state()==Tango::MOVING)
	{
	/*----- PROTECTED REGION ID(LinacSequencer::SaveFileStateAllowed) ENABLED START -----*/
	
	/*----- PROTECTED REGION END -----*/	//	LinacSequencer::SaveFileStateAllowed
		return false;
	}
	return true;
}

//--------------------------------------------------------
/**
 *	Method      : LinacSequencer::is_ForceSave_allowed()
 *	Description : Execution allowed for ForceSave attribute
 */
//--------------------------------------------------------
bool LinacSequencer::is_ForceSave_allowed(TANGO_UNUSED(const CORBA::Any &any))
{
	//	Compare device state with not allowed states.
	if (get_state()==Tango::MOVING)
	{
	/*----- PROTECTED REGION ID(LinacSequencer::ForceSaveStateAllowed) ENABLED START -----*/
	
	/*----- PROTECTED REGION END -----*/	//	LinacSequencer::ForceSaveStateAllowed
		return false;
	}
	return true;
}

//--------------------------------------------------------
/**
 *	Method      : LinacSequencer::is_On_allowed()
 *	Description : Execution allowed for On attribute
 */
//--------------------------------------------------------
bool LinacSequencer::is_On_allowed(TANGO_UNUSED(const CORBA::Any &any))
{
	//	Compare device state with not allowed states.
	if (get_state()==Tango::MOVING)
	{
	/*----- PROTECTED REGION ID(LinacSequencer::OnStateAllowed) ENABLED START -----*/
	
	/*----- PROTECTED REGION END -----*/	//	LinacSequencer::OnStateAllowed
		return false;
	}
	return true;
}

//--------------------------------------------------------
/**
 *	Method      : LinacSequencer::is_Off_allowed()
 *	Description : Execution allowed for Off attribute
 */
//--------------------------------------------------------
bool LinacSequencer::is_Off_allowed(TANGO_UNUSED(const CORBA::Any &any))
{
	//	Compare device state with not allowed states.
	if (get_state()==Tango::MOVING)
	{
	/*----- PROTECTED REGION ID(LinacSequencer::OffStateAllowed) ENABLED START -----*/
	
	/*----- PROTECTED REGION END -----*/	//	LinacSequencer::OffStateAllowed
		return false;
	}
	return true;
}

//--------------------------------------------------------
/**
 *	Method      : LinacSequencer::is_LowHeating_allowed()
 *	Description : Execution allowed for LowHeating attribute
 */
//--------------------------------------------------------
bool LinacSequencer::is_LowHeating_allowed(TANGO_UNUSED(const CORBA::Any &any))
{
	//	Compare device state with not allowed states.
	if (get_state()==Tango::MOVING)
	{
	/*----- PROTECTED REGION ID(LinacSequencer::LowHeatingStateAllowed) ENABLED START -----*/
	
	/*----- PROTECTED REGION END -----*/	//	LinacSequencer::LowHeatingStateAllowed
		return false;
	}
	return true;
}

//--------------------------------------------------------
/**
 *	Method      : LinacSequencer::is_Standby_allowed()
 *	Description : Execution allowed for Standby attribute
 */
//--------------------------------------------------------
bool LinacSequencer::is_Standby_allowed(TANGO_UNUSED(const CORBA::Any &any))
{
	//	Compare device state with not allowed states.
	if (get_state()==Tango::MOVING)
	{
	/*----- PROTECTED REGION ID(LinacSequencer::StandbyStateAllowed) ENABLED START -----*/
	
	/*----- PROTECTED REGION END -----*/	//	LinacSequencer::StandbyStateAllowed
		return false;
	}
	return true;
}

//--------------------------------------------------------
/**
 *	Method      : LinacSequencer::is_Reset_allowed()
 *	Description : Execution allowed for Reset attribute
 */
//--------------------------------------------------------
bool LinacSequencer::is_Reset_allowed(TANGO_UNUSED(const CORBA::Any &any))
{
	//	Not any excluded states for Reset command.
	/*----- PROTECTED REGION ID(LinacSequencer::ResetStateAllowed) ENABLED START -----*/
	
	/*----- PROTECTED REGION END -----*/	//	LinacSequencer::ResetStateAllowed
	return true;
}


/*----- PROTECTED REGION ID(LinacSequencer::LinacSequencerStateAllowed.AdditionalMethods) ENABLED START -----*/

//	Additional Methods

/*----- PROTECTED REGION END -----*/	//	LinacSequencer::LinacSequencerStateAllowed.AdditionalMethods

}	//	End of namespace
