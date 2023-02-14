/*
 * MEXTI_Interface.h
 *
 *  Created on: Feb 11, 2023
 *      Author: hp
 */

//	MEXTI_PA0 = 0,
//	MEXTI_PB0,
//	MEXTI_PC0,
//	MEXTI_PD0,
//	MEXTI_PE0,
//	MEXTI_PH0 = 7,
//
//	MEXTI_PA1 	,
//	MEXTI_PB1	,
//	MEXTI_PC1	,
//	MEXTI_PD1	,
//	MEXTI_PE1	,
//	MEXTI_PH1 = 15,
//
//	MEXTI_PA2 	,
//	MEXTI_PB2	,
//	MEXTI_PC2	,
//	MEXTI_PD2	,
//	MEXTI_PE2	,
//	MEXTI_PH2 = 23,
//
//	MEXTI_PA3 	,
//	MEXTI_PB3	,
//	MEXTI_PC3	,
//	MEXTI_PD3	,
//	MEXTI_PE3	,
//	MEXTI_PH3 = 31,

#ifndef MEXTI_INTERFACE_H_
#define MEXTI_INTERFACE_H_

//#define MEXTI_FALLING_EDGE		0
//#define MEXTI_RISING_EDGE		1
//#define MEXTI_ON_CHANGE			2




typedef enum
{
	MEXTI_MR0 = 0,
	MEXTI_MR1 	,
	MEXTI_MR2 	,
	MEXTI_MR3  	,
	MEXTI_MR4   ,
	MEXTI_MR5   ,
	MEXTI_MR6   ,
	MEXTI_MR7   ,
	MEXTI_MR8   ,
	MEXTI_MR9   ,
	MEXTI_MR10  ,
	MEXTI_MR11  ,
	MEXTI_MR12  ,
	MEXTI_MR13  ,
	MEXTI_MR14  ,
	MEXTI_MR15  ,
	MEXTI_MR16  ,
	MEXTI_MR17  ,
	MEXTI_MR18  ,
	MEXTI_MR21 = 21  	,
	MEXTI_MR22  		,
	MEXTI_MR_INVALID

}MEXTI_MR_t;



typedef enum
{
	MEXTI_RISING_EDGE = 0,
	MEXTI_FALLING_EDGE,
	MEXTI_ON_CHANGE,
	MEXTI_STATE_INVALID

}MEXTI_STATE_t;


typedef enum
{
	MEXTI_PORTA=0,
	MEXTI_PORTB,
	MEXTI_PORTC,
	MEXTI_PORTD,
	MEXTI_PORTE,
	MEXTI_PORTH = 7,

	MRXTI_PORT_INVALID,



}MEXTI_PORT_t;


typedef void(*ptrFunc)(void);


void MEXTI_voidEnableEXTI(MEXTI_MR_t Copy_enuExtiLine);
void MEXTI_voidDisableEXTI(MEXTI_MR_t Copy_enuExtiLine);

void MEXTI_SetEXTISenseCtrl(MEXTI_MR_t Copy_enuExtiLine, MEXTI_STATE_t Copy_enuSenseCtrl);

void MEXTI_voidEnableEXTI_Event(MEXTI_MR_t Copy_enuExtiLine);
void MEXTI_voidDisableEXTI_Event(MEXTI_MR_t Copy_enuExtiLine);

void MEXTI_voidSwInterruptEventEnable(MEXTI_MR_t Copy_enuExtiLine);
void MEXTI_voidSwInterruptEventDisable(MEXTI_MR_t Copy_enuExtiLine);

void MEXTI_voidClearEXTIFlag(MEXTI_MR_t Copy_enuExtiLine);

void MEXTI_voidSetExtiLineConfig( MEXTI_MR_t Copy_enuExtiLine, MEXTI_PORT_t Copy_enuGpioPortNum );


/***************************************************/
void MEXTI0_voidSetCallBack( ptrFunc Ref_pFunc );
void MEXTI1_voidSetCallBack( ptrFunc Ref_pFunc );

#endif /* MEXTI_INTERFACE_H_ */
