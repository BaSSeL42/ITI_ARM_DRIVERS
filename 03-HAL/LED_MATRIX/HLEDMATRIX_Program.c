/*
 * HLEDMATRIX_Program.c
 *
 *  Created on: Feb 10, 2023
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
#include "HLEDMATRIX_Interface.h"
#include "HLEDMATRIX_Config.h"
/********************************************************************************************************************
*												Extern Variables
********************************************************************************************************************/
extern str_ledMatrixPinConf_t colPinArr[LED_MATRIX_PIN_NUMBER];
extern str_ledMatrixPinConf_t rowPinArr[LED_MATRIX_PIN_NUMBER];
extern u8 ledMatrixArr[LED_MATRIX_PIN_NUMBER];
extern u8 ledMatrixArr_2[LED_MATRIX_PIN_NUMBER];

/********************************************************************************************************************
*												Function Implementation
********************************************************************************************************************/
void HLEDMATRIX_voidInit(void)
{
	MRCC_voidInitClock();
	MRCC_voidEnablePeripheralClock(MRCC_AHB1, LED_MATRIX_CLK_CFG);
	MRCC_voidEnablePeripheralClock(MRCC_AHB1, LED_MATRIX_CLK_CFG_1);
	for(u8 i = 0; i < LED_MATRIX_PIN_NUMBER; i++)
	{
		MGPIO_voidSetPinMode(colPinArr[i].enPinType, MGPIO_MODE_OUTPUT);
		MGPIO_voidSetPinMode(rowPinArr[i].enPinType, MGPIO_MODE_OUTPUT);
	}
	for(u8 i = 0; i < LED_MATRIX_PIN_NUMBER; i++)
	{
		MGPIO_voidSetPinData(colPinArr[i].enPinType, MGPIO_PIN_HIGH);
		MGPIO_voidSetPinData(rowPinArr[i].enPinType, MGPIO_PIN_LOW);
	}

}

void HLEDMATRIX_voidDisplay(void)
{
	for (u8 colPinIndex = 0; colPinIndex < LED_MATRIX_PIN_NUMBER; colPinIndex++)
	{
		MGPIO_voidSetPinData(colPinArr[colPinIndex].enPinType, MGPIO_PIN_LOW);

		for (u8 rowPinIndex = 0; rowPinIndex < LED_MATRIX_PIN_NUMBER; rowPinIndex++)
		{
			MGPIO_voidSetPinData(rowPinArr[rowPinIndex].enPinType, ((ledMatrixArr[colPinIndex] >> rowPinIndex)&1) );
		}
		_delay_ms(2);
		MGPIO_voidSetPinData(colPinArr[colPinIndex].enPinType, MGPIO_PIN_HIGH);
	}
}


void HLEDMATRIX_voidDisplay2(void)
{
	for (u8 colPinIndex = 0; colPinIndex < LED_MATRIX_PIN_NUMBER; colPinIndex++)
	{
		MGPIO_voidSetPinData(colPinArr[colPinIndex].enPinType, MGPIO_PIN_LOW);

		for (u8 rowPinIndex = 0; rowPinIndex < LED_MATRIX_PIN_NUMBER; rowPinIndex++)
		{
			MGPIO_voidSetPinData(rowPinArr[rowPinIndex].enPinType, ((ledMatrixArr_2[colPinIndex] >> rowPinIndex)&1) );
		}
		_delay_ms(2);
		MGPIO_voidSetPinData(colPinArr[colPinIndex].enPinType, MGPIO_PIN_HIGH);
	}
}






