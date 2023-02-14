/*
 * MSTK_Program.c
 *
 *  Created on: Feb 7, 2023
 *      Author: hp
 */


/*********************************************************************/
/*					Standard Types LIB								 */
/*********************************************************************/

#include "LSTD_TYPES.h"
#include "LBIT_MATH.h"
/*********************************************************************/
/*					Peripheral Files 								*/
/*********************************************************************/
#include "MSTK_Private.h"
#include "MSTK_Interface.h"
#include "MSTK_Config.h"


/*********************************************************************/
/*					Function Implementation 								*/
/********************************************************************/
void MSTK_voidInit(void)
{
	// Enable Systick Interrupt  -clock = AHB/8  -stop Systick
	MSTK->CTRL = 0x00000002;
}

void MSTK_voidTimerState(STK_STATE_t Copy_uddtState)
{
	if(Copy_uddtState == MSTK_ENABLE)
	{
		SET_BIT(MSTK->CTRL, 0);
	}
	else if (Copy_uddtState == MSTK_DISABLE)
	{
		CLR_BIT(MSTK->CTRL, 0);
	}else
	{
		/* Do nothing */
	}
}

void MSTK_voidINTStatus(STK_INT_STATE_t Copy_uddtINTState)
{
	if(Copy_uddtINTState == MSTK_INT_ENABLE)
	{
		SET_BIT(MSTK->CTRL, 1);
	}
	else if (Copy_uddtINTState == MSTK_INT_DISABLE)
	{
		CLR_BIT(MSTK->CTRL, 1);
	}else
	{
		/* Do nothing */
	}
}

/* suppose that the Clock System AHB = HSI = 16 MHz,
 * F_TIMER = AHB?8
 * TICK_TIME = 1 / 2MHz  = 0.5 us
 * 1 ms ---> 1000 micro ---> 2000 ticks
 */
void _delay_ms(u32 Copy_u32Delay)
{
	// Intialize Timer
	MSTK_voidInit(); // INT --> Enable, AHB/8 , Timer stop
	// polling
	MSTK_voidINTStatus(MSTK_INT_DISABLE);
	// load Reg
	MSTK->LOAD = Copy_u32Delay * 2000;  // single shoot
	// VAL Reg (Reset --> Reload)
	MSTK->VAL = 0;
	// Enable Timer
	MSTK_voidTimerState(MSTK_ENABLE);
	// wait Flag Polling
	while(MSTK_u8ReadFlag() == 0);
	// Stop Timer
	MSTK_voidTimerState(MSTK_DISABLE);
}


void _delay_us(u32 Copy_u32Delay)
{
	// Intialize Timer
	MSTK_voidInit(); // INT --> Enable, AHB/8 , Timer stop
	// polling
	MSTK_voidINTStatus(MSTK_INT_DISABLE);
	// load Reg
	MSTK->LOAD = Copy_u32Delay * 2;  // single shoot
	// VAL Reg (Reset --> Reload)
	MSTK->VAL = 0;
	// Enable Timer
	MSTK_voidTimerState(MSTK_ENABLE);
	// wait Flag Polling
	while(MSTK_u8ReadFlag() == 0);
	// Stop Timer
	MSTK_voidTimerState(MSTK_DISABLE);
}

u8 MSTK_u8ReadFlag(void)
{
	return ( GET_BIT(MSTK->CTRL,16) );
}

void MSTK_voidSetCallBack( void(*PFunc)(void) )
{
	// TODO
}


void MSTK_voidStart(u32 Copy_u32Preload)
{
	// load Reg
	MSTK->LOAD = Copy_u32Preload;  // single shoot
	// VAL Reg (Reset --> Reload)
	MSTK->VAL = 0;
	// Enable Timer
	MSTK_voidTimerState(MSTK_ENABLE);
	// wait Flag Polling or Handled by interrupt
//	while(MSTK_u8ReadFlag() == 0);

}
