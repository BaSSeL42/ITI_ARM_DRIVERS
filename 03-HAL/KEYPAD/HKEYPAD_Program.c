/*
 * HKEYPAD_Program.c
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
#include "MRCC_Interface.h"
#include "MGPIO_Interface.h"
#include "HKEYPAD_Interface.h"
#include "HKEYPAD_Config.h"
/********************************************************************************************************************
*												Extern Variables
********************************************************************************************************************/
extern u8 KEYPAD_au8KeyValV2[HKEYPAD_NO_ROW][HKEYPAD_NO_COL];
extern str_KeyPad_pinConf_t HKEYPAD_strColPins[HKEYPAD_NO_COL];
extern str_KeyPad_pinConf_t HKEYPAD_strRowPins[HKEYPAD_NO_ROW];



static void delay_ms(u32 number_of_seconds);



void KEYPAD_vidInit_V2(void)
{
	u8 local_u8Col;
	u8 local_u8Row;
	MRCC_voidInitClock();
	MRCC_voidEnablePeripheralClock(MRCC_AHB1, HKEYPAD_PORT_CLOCK_1);

	for (local_u8Col = 0; local_u8Col <HKEYPAD_NO_COL ; local_u8Col++)
	{
		MGPIO_voidSetPinMode(HKEYPAD_strColPins[local_u8Col].enPinType, MGPIO_MODE_OUTPUT);
	}
	for (local_u8Row = 0; local_u8Row <HKEYPAD_NO_ROW ; local_u8Row++)
	{
		MGPIO_voidSetPinMode(HKEYPAD_strRowPins[local_u8Row].enPinType, MGPIO_MODE_INPUT);
	}
	for (local_u8Col = 0; local_u8Col <HKEYPAD_NO_COL ; local_u8Col++)
	{
		MGPIO_voidSetPinData(HKEYPAD_strColPins[local_u8Col].enPinType, MGPIO_PIN_HIGH );
	}
	for (local_u8Row = 0; local_u8Row <HKEYPAD_NO_ROW ; local_u8Row++)
	{
//		MGPIO_voidSetPinData(HKEYPAD_strRowPins[local_u8Row].enPinType, MGPIO_PIN_HIGH );
		MGPIO_voidPullType(HKEYPAD_strRowPins[local_u8Row].enPinType,MGPIO_PULL_UP);
	}
}


u8 KEYPAD_u8GetPressed_V2(void)
{
	static u8 local_u8KeyPressed = NO_KEY_PRESSED;
	u8 local_u8RowStatus;

	u8 local_u8Col;
	u8 local_u8Row;


	for(local_u8Col = 0; local_u8Col < HKEYPAD_NO_COL ;local_u8Col++)
	{
		MGPIO_voidSetPinData(HKEYPAD_strColPins[local_u8Col].enPinType, MGPIO_PIN_LOW );

		for(local_u8Row = 0;local_u8Row < HKEYPAD_NO_ROW;local_u8Row++)
		{
			MGPIO_voidGetPinData(HKEYPAD_strRowPins[local_u8Row].enPinType,&local_u8RowStatus );

			if(!local_u8RowStatus)
			{
				delay_ms(50);
				MGPIO_voidGetPinData(HKEYPAD_strRowPins[local_u8Row].enPinType,&local_u8RowStatus);
				if(!local_u8RowStatus)
				{
					local_u8KeyPressed = KEYPAD_au8KeyValV2[local_u8Row][local_u8Col];
				}
				delay_ms(50);
			}

		}

		MGPIO_voidSetPinData(HKEYPAD_strColPins[local_u8Col].enPinType, MGPIO_PIN_HIGH );
	}

	return local_u8KeyPressed;

}




static void delay_ms(u32 number_of_seconds)
{
	for (u32 i = 0; i < number_of_seconds; i++)
	{
		for (u32 j = 0 ; j < 2000 ; j++)
		{
			asm("NOP");
		}
	}
}

