#ifndef _LINACSTRUCTURE_H
#define _LINACSTRUCTURE_H

#include <tango.h>

/*
	Changed focus_beam1[6] to focus_beam1[8] to handle 2 new devices:

		So now focus_beam is filled like this :
		---------------------------------------
		focus_beam1[0] = Zup B1 Coil
		focus_beam1[1] = Zup B2 Coil
		focus_beam1[2] = Previous Brucker
		focus_beam1[3] = Previous Brucker		
		focus_beam1[4] = Previous Brucker
		focus_beam1[5] = Previous Brucker
		focus_beam1[6] = Zup B3 Coil
		focus_beam1[7] = Zup B4 Coil
		
	Changed	steer_beam[16] to steer_beam[22] to handle 6 new devices.

		So now steer_beam is filled like this :
		---------------------------------------

		steer_beam[0]  = Zup elin/steer/gh1 in replacement of Brucker.
		steer_beam[1]  = Zup elin/steer/gv1 in replacement of Brucker.
		steer_beam[2]  = Previous Brucker
		steer_beam[3]  = Previous Brucker
		steer_beam[4]  = Previous Brucker
		steer_beam[5]  = Previous Brucker
		steer_beam[6]  = Previous Brucker
		steer_beam[7]  = Previous Brucker
		steer_beam[8]  = Previous Brucker
		steer_beam[9]  = Previous Brucker
		steer_beam[10] = Previous Brucker
		steer_beam[11] = Previous Brucker
		steer_beam[12] = Previous Brucker
		steer_beam[13] = Previous Brucker
		steer_beam[14] = Previous Brucker
		steer_beam[15] = Previous Brucker
		steer_beam[16] = Zup elin/steer/gh2 new power supply.
		steer_beam[17] = Zup elin/steer/gv2 new power supply
		steer_beam[18] = Zup elin/steer/gh3 new power supply
		steer_beam[19] = Zup elin/steer/gv3 new power supply
		steer_beam[20] = Zup elin/steer/gh4 new power supply (Prebuncher steerer)
		steer_beam[21] = Zup elin/steer/gv4 new power supply (Prebuncher steerer)

		Note that previous focus_beam1[6] and steer_beam[22] were filled with value
		read on power supplies.
	
*/
typedef	struct	_values
{
		Tango::DevDouble	focus_klyst1[6]; 	/* values of the object ELIN/FOCUS/KLYSTRON1 (modulator 1) */
		Tango::DevDouble	focus_klyst2[3]; 	/* values of the object ELIN/FOCUS/KLYSTRON1 (modulator 2) */
		Tango::DevDouble	focus_beam1[8]; 	/* values of the object ELIN/FOCUS/BEAM1 */
		Tango::DevDouble	focus_beam2[2]; 	/* Values of the object ELIN/FOCUS/BEAM2 */
		Tango::DevDouble	steer_beam[22]; 	/* Values of the object ELIN/STEER/1 */
		Tango::DevDouble	mod_hv_v[2]; 		/* Value of the object ELIN/MOD/HV-1 an 2 */
		Tango::DevDouble	vpfn[2]; 			/* Value of the objects ELIN/O-MOD/DEQ-1 and ELIN/O-MOD/DEQ-2 */
		Tango::DevDouble	bunch_phase; 		/* Value of the object ELIN/O-RF/BUN-PH */
		Tango::DevDouble	pbunch_phase; 		/* Value of the object ELIN/O-RF/PBUN-PH */
		Tango::DevDouble	pbunch_atten; 		/* Value of the object ELIN/O-RF/PBUN-AT */
		Tango::DevDouble	section_phase; 	/* Value of the object ELIN/O-RF/SEC-PH */
		Tango::DevDouble	gun_heating_v; 	/* Value of the object ELIN/O-GUN/HEAT-V */
		Tango::DevDouble	gun_grid_v; 		/* Value of the object ELIN/O-GUN/GRID-V */
		Tango::DevDouble	gun_pulse_v; 		/* Value of object ELIN/O-GUN/PUSLE-V */
		Tango::DevDouble	gun_pulse_l; 		/* Value of the object ELIN/O-GUN/PULSE-L */
		Tango::DevDouble	gun_hv_v; 			/* Value of the object ELIN/O-GUN/HV */
		Tango::DevDouble	frequency; 			/* Frequency value of the object ELIN/O-RF/FREQ */
		Tango::DevBoolean	short_pulse; 		/* Flag to indicate if the command DevOpen or DevClose should be performed on the object ELIN/R-GUN/SHORT */
		Tango::DevBoolean	r352; 				/* Flag to indicate if the command DevOpen or DevClose should be performed on the object ELIN/R-GUN/352M */
		Tango::DevDouble	timer_rf; 			/* Value of the object ELIN/T-RF/1 */
		Tango::DevDouble	timer_mod[2]; 		/* Value of the objects ELIN/T-MOD/1 and ELIN/T-MOD/2 */
		Tango::DevDouble	timer_mod_s[2]; 	/* Value of the objects ELIN/T-MOD/S1 and ELIN/T-MOD/S2 */
} Values;

#endif
