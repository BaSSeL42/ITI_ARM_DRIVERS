/*
 * H7SEG_Program.c
 *
 *  Created on: Feb 4, 2023
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
#include "MSTK_Interface.h"
#include "HSEVSEG_Interface.h"
#include "HSEVSEG_cfg.h"
/********************************************************************************************************************
*												Extern Variables
********************************************************************************************************************/
extern u8 LED[SEG_SIZE];
extern str_pinConf_t pinArr[PIN_NUMBER];


/********************************************************************************************************************
*												Function Implementation
********************************************************************************************************************/
static u8 bitRead(u8 Copy_u8Index, u8 Copy_u8BitNum)
{
	return ( (Copy_u8Index >>Copy_u8BitNum )&1 );
}

void H7SEG_voidInit(void)
{
	MRCC_voidInitClock();
	MRCC_voidEnablePeripheralClock(MRCC_AHB1, MRCC_GPIOB_EN);
	for(u8 i = 0; i < PIN_NUMBER; i++)
	{
		MGPIO_voidSetPinMode(pinArr[i].enPinType, MGPIO_MODE_OUTPUT);
	}
}

void H7SEG_voidStart(void)
{
	for (u8 u8Counter = 0; u8Counter < SEG_SIZE; u8Counter++)
	{
		for (u8 u8PinCounter = 0; u8PinCounter < PIN_NUMBER; u8PinCounter++)
		{
			MGPIO_voidSetPinData(pinArr[u8PinCounter].enPinType, bitRead(LED[u8Counter],u8PinCounter));
		}
//		APP_voidDelay();
		_delay_ms(1000);
	}

//	MGPIO_voidSetPinData(pinArr[u8PinCounter].enPinType, bitRead(LED[u8Counter],u8PinCounter));

}



void H7SEG_voidCountDown(u8 Copy_u8StartValue)
{
//	u8 local_Index = Copy_u8StartValue;
	for (s8 s8Counter = Copy_u8StartValue; s8Counter >= 0; s8Counter--)
	{
		for (u8 u8PinCounter = 0; u8PinCounter < PIN_NUMBER; u8PinCounter++)
		{
			MGPIO_voidSetPinData(pinArr[u8PinCounter].enPinType, bitRead(LED[s8Counter],u8PinCounter));
		}
		_delay_ms(1000);
	}
}

void HLED_voidInit(void)
{
	MRCC_voidInitClock();
	MRCC_voidEnablePeripheralClock(MRCC_AHB1, MRCC_GPIOC_EN);

	MGPIO_voidSetPinMode(LED_PIN_1, MGPIO_MODE_OUTPUT);
	MGPIO_voidSetPinMode(LED_PIN_2, MGPIO_MODE_OUTPUT);
	MGPIO_voidSetPinMode(LED_PIN_3, MGPIO_MODE_OUTPUT);
}



//void APP_voidDelay(void)
//{
//	u32 i = 0;
//	for(i = 0; i < 2000000; i++)
//	{
//		asm("NOP");
//	}
//}
