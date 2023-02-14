/*
 * MEXTI_Program.c
 *
 *  Created on: Feb 11, 2023
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
#include "MEXTI_Private.h"
#include "MEXTI_Interface.h"
#include "MEXTI_Config.h"



ptrFunc callBack = NULL;

/*********************************************************************/
/*					Function Implementation 								*/
/*********************************************************************/

void MEXTI_voidEnableEXTI(MEXTI_MR_t Copy_enuExtiLine)
{
	if (Copy_enuExtiLine < MEXTI_MR_INVALID)
	{
		SET_BIT(MEXIT->IMR, Copy_enuExtiLine);
	}
}
void MEXTI_voidDisableEXTI(MEXTI_MR_t Copy_enuExtiLine)
{
	if (Copy_enuExtiLine < MEXTI_MR_INVALID)
	{
		CLR_BIT(MEXIT->IMR, Copy_enuExtiLine);
	}
}

void MEXTI_SetEXTISenseCtrl(MEXTI_MR_t Copy_enuExtiLine, MEXTI_STATE_t Copy_enuSenseCtrl)
{
	if (Copy_enuExtiLine < MEXTI_MR_INVALID && Copy_enuSenseCtrl < MEXTI_STATE_INVALID)
	{
		switch (Copy_enuSenseCtrl)
		{
			case MEXTI_RISING_EDGE	: SET_BIT(MEXIT->RTSR, Copy_enuExtiLine );  CLR_BIT(MEXIT->FTSR, Copy_enuExtiLine );	break;
			case MEXTI_FALLING_EDGE	: SET_BIT(MEXIT->FTSR, Copy_enuExtiLine );  CLR_BIT(MEXIT->RTSR, Copy_enuExtiLine );	break;
			case MEXTI_ON_CHANGE	: SET_BIT(MEXIT->RTSR, Copy_enuExtiLine );	SET_BIT(MEXIT->FTSR, Copy_enuExtiLine );	break;
			default : /* do nothing */ 			break;
		}
	}
}

void MEXTI_voidEnableEXTI_Event(MEXTI_MR_t Copy_enuExtiLine)
{
	if (Copy_enuExtiLine < MEXTI_MR_INVALID)
	{
		SET_BIT(MEXIT->EMR, Copy_enuExtiLine);
	}
}
void MEXTI_voidDisableEXTI_Event(MEXTI_MR_t Copy_enuExtiLine)
{
	if (Copy_enuExtiLine < MEXTI_MR_INVALID)
	{
		CLR_BIT(MEXIT->EMR, Copy_enuExtiLine);
	}
}

void MEXTI_voidSwInterruptEventEnable(MEXTI_MR_t Copy_enuExtiLine)
{
	if (Copy_enuExtiLine < MEXTI_MR_INVALID)
	{
		SET_BIT(MEXIT->SWIER, Copy_enuExtiLine);
	}
}
void MEXTI_voidSwInterruptEventDisable(MEXTI_MR_t Copy_enuExtiLine)
{
	if (Copy_enuExtiLine < MEXTI_MR_INVALID)
	{
		CLR_BIT(MEXIT->SWIER, Copy_enuExtiLine);
	}
}

void MEXTI_voidClearEXTIFlag(MEXTI_MR_t Copy_enuExtiLine)
{
	if (Copy_enuExtiLine < MEXTI_MR_INVALID)
	{
		SET_BIT(MEXIT->PR, Copy_enuExtiLine);
	}
}

void MEXTI_voidSetExtiLineConfig(MEXTI_MR_t Copy_enuExtiLine, MEXTI_PORT_t Copy_enuGpioPortNum )
{
	SYSCFG->EXTICR[Copy_enuExtiLine / 4U] &= ~(0xF << ((Copy_enuExtiLine % 4U)*4U));
	SYSCFG->EXTICR[Copy_enuExtiLine / 4U] |= (Copy_enuGpioPortNum << ((Copy_enuExtiLine % 4U)*4U));
}



/***************************************************/
//void MEXTI0_voidSetCallBack( ptrFunc Ref_pFunc  )
//{
//
//}
void MEXTI1_voidSetCallBack( ptrFunc Ref_pFunc )
{
	callBack = Ref_pFunc;
}




void EXTI0_IRQHandler(void)
{

}


void EXTI1_IRQHandler(void)
{
	callBack();
}
