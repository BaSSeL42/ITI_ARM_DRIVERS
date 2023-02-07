/*
 * HKEYPAD_Config.c
 *
 *  Created on: Feb 6, 2023
 *      Author: hp
 */

/********************************************************************************************************************
*												Standard Types LIB
********************************************************************************************************************/
#include "LSTD_TYPES.h"
#include "LBIT_MATH.h"
/********************************************************************************************************************
*												Peripheral Files
********************************************************************************************************************/
#include "MGPIO_Interface.h"
#include "HKEYPAD_Config.h"



u8 KEYPAD_au8KeyValV2[HKEYPAD_NO_ROW][HKEYPAD_NO_COL] = {
		{
				1,  //ROW 0 COL 0
				2,	//ROW 0 COL 1
				3,  //ROW 0 COL 2
				4   //ROW 0 COL 3
		},
		{
				5,  //ROW 1 COL 0
				6,	//ROW 1 COL 1
				7,  //ROW 1 COL 2
				8   //ROW 1 COL 3
		},
		{
				9,   //ROW 2 COL 0
				10,	 //ROW 2 COL 1
				11,  //ROW 2 COL 2
				12   //ROW 2 COL 3
		},
		{
				13,  //ROW 3 COL 0
				14,	 //ROW 3 COL 1
				15,  //ROW 3 COL 2
				16   //ROW 3 COL 3
		}
};




str_KeyPad_pinConf_t HKEYPAD_strRowPins[HKEYPAD_NO_ROW] = {{MGPIO_PINA7},{MGPIO_PINA6},{MGPIO_PINA5},{MGPIO_PINA4} };



str_KeyPad_pinConf_t HKEYPAD_strColPins[HKEYPAD_NO_COL] ={ {MGPIO_PINA8}, {MGPIO_PINA9}, {MGPIO_PINA10}, {MGPIO_PINA11} };
