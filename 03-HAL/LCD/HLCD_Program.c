/*
 * HLCD_Program.c
 *
 *  Created on: Feb 5, 2023
 *      Author: hp
 */

/********************************************************************************************************************
*												Standard Types LIB
********************************************************************************************************************/
#include <time.h>
#include <stdlib.h>
#include "LSTD_TYPES.h"
#include "LBIT_MATH.h"
/********************************************************************************************************************
*												Peripheral Files
********************************************************************************************************************/
#include "MRCC_Interface.h"
#include "MGPIO_Interface.h"
#include "HLCD_Interface.h"
#include "HLCD_Config.h"
/********************************************************************************************************************
*												Extern Variables
********************************************************************************************************************/
extern str_pinConf_t pin_Arr[HLCD_PIN_NUMBER];

/********************************************************************************************************************
*												Function Implementation
********************************************************************************************************************/
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



void LCD_vidInit(void)
{
	MRCC_voidInitClock();
	MRCC_voidEnablePeripheralClock(MRCC_AHB1, HLCD_PORT_CLOCK_1);
	MRCC_voidEnablePeripheralClock(MRCC_AHB1, HLCD_PORT_CLOCK_2);

	for(u8 i = 0; i < HLCD_PIN_NUMBER; i++)
	{
		MGPIO_voidSetPinMode(pin_Arr[i].enPinType, MGPIO_MODE_OUTPUT);
	}

	MGPIO_voidSetPinMode(HLCD_RS_PORT_PIN, MGPIO_MODE_OUTPUT);
	MGPIO_voidSetPinMode(HLCD_RW_PORT_PIN, MGPIO_MODE_OUTPUT);
	MGPIO_voidSetPinMode(HLCD_EN_PORT_PIN, MGPIO_MODE_OUTPUT);

	delay_ms(40);

	LCD_vidWritecmd(LCD_FUNC_SET_CMD);
	delay_ms(1);

	LCD_vidWritecmd(LCD_DSP_ON_OFF_CTRL_CMD);
	delay_ms(1);

	LCD_vidWritecmd(LCD_DSP_CLEAR_CMD);
	delay_ms(4);

	LCD_vidWritecmd(LCD_ENTRY_MOD_SET_CMD);
}




void LCD_vidWritecmd(u8 u8commandCopy)
{
	MGPIO_voidSetPinData(HLCD_RW_PORT_PIN, MGPIO_PIN_LOW); // WRITE
	MGPIO_voidSetPinData(HLCD_RS_PORT_PIN, MGPIO_PIN_LOW); // CMD

	for (u8 u8PinCounter = 0; u8PinCounter < HLCD_PIN_NUMBER; u8PinCounter++)
	{
		MGPIO_voidSetPinData(pin_Arr[u8PinCounter].enPinType, ((u8commandCopy >> u8PinCounter)&1) );
	}
	MGPIO_voidSetPinData(HLCD_EN_PORT_PIN, MGPIO_PIN_HIGH); //ENABLE high
	delay_ms(2);
	MGPIO_voidSetPinData(HLCD_EN_PORT_PIN, MGPIO_PIN_LOW); //ENABLE low
}




void LCD_vidWriteChar(u8 u8CharCopy)
{
	MGPIO_voidSetPinData(HLCD_RW_PORT_PIN, MGPIO_PIN_LOW); // WRITE
	MGPIO_voidSetPinData(HLCD_RS_PORT_PIN, MGPIO_PIN_HIGH); // DATA

	for (u8 u8PinCounter = 0; u8PinCounter < HLCD_PIN_NUMBER; u8PinCounter++)
	{
		MGPIO_voidSetPinData(pin_Arr[u8PinCounter].enPinType, ((u8CharCopy >> u8PinCounter)&1));
	}
	MGPIO_voidSetPinData(HLCD_EN_PORT_PIN, MGPIO_PIN_HIGH); //ENABLE high
	delay_ms(2);
	MGPIO_voidSetPinData(HLCD_EN_PORT_PIN, MGPIO_PIN_LOW); //ENABLE low
}



void LCD_ClrDisplay(void)
{
	LCD_vidWritecmd(LCD_DSP_CLEAR_CMD);
	delay_ms(4);
	LCD_vidWritecmd(LCD_RETURN_HOME_CMD);
	delay_ms(4);

}




void LCD_ShiftLeft(void)
{
	LCD_vidWritecmd(LCD_CURSOR_DSP_SHFT_CMD);
	delay_ms(1);

}





void LCD_gotoXY(u8 row,u8 pos)
{
	if (row==0 && pos < 16)
	{
		LCD_vidWritecmd((pos & 0x0F)| 0x80);
	}
	else if (row==1 && pos < 16)
	{
		LCD_vidWritecmd((pos & 0x0F)| 0xC0);
	}
}





void LCD_WriteString(u8* str)
{
	u16 count = 0;
	u8 string = str[count];
	while(string)
	{
		LCD_vidWriteChar(string);
		string = str[++count];
	}
}




void LCD_WriteInt(u32 number)
{
	u8 STR[index];
//	sprintf(STR, "%u", number);
	itoa(number, STR, 10);
	LCD_WriteString(STR);
//	Uint8_t ones = (Uint8_t) number % 10 + '0';
//	Uint8_t tens = (Uint8_t) number / 10 + '0';
//	//Uint8_t Char= (Uint8_t)number + '0';
//	if (tens != '0')
//		LCD_vidWriteChar(tens);
//	LCD_vidWriteChar(ones);
}



//void LCD_WriteArabic(u8 u8ArCharCopy)
//{
//	LCD_vidWritecmd(0x04);
//	LCD_vidWriteChar(u8ArCharCopy);
//}



//
//void LCD_vidCreatCustomChar(u8* pu8custom, u8 u8Location)
//{
//	if (u8Location < 8)  // CGRAM only store 8 characters
//	{
//		LCD_vidWritecmd(LCD_SET_CGRAM_ADDR_CMD + (u8Location*8));
//		delay_ms(1);
//		for (u8 i = 0; i < 8 ; i++)
//		{
//			LCD_vidWriteChar(pu8custom[i]);
//		}
//	}
//}




