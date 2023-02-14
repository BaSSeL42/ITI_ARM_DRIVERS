 /**************************************************************
 *  AUTHOR 				: Bassel Yasser
 *  Version 			: V0.0.0
 *  Date				: 7 - 2 - 2023
 *  Description 		: MSTK_Interface.h --> Function Prototypes
 *  Module Features		:
 *  						01-
 *  						02-
							03-
							04-
							05-
							06-
 *****************************************************************************/


/********************************************************************************************************************
*												File Guard
********************************************************************************************************************/

#ifndef MSTK_INTERFACE_H_
#define MSTK_INTERFACE_H_

/*********************************************************************************************************
 *  										MACROS
 ********************************************************************************************************/



/*********************************************************************************************************
 *  									User Defined Data Type
 ********************************************************************************************************/
typedef enum
{
	MSTK_DISABLE= 0	,
	MSTK_ENABLE
}STK_STATE_t;


typedef enum
{
	MSTK_INT_DISABLE= 0	,
	MSTK_INT_ENABLE
}STK_INT_STATE_t;


/********************************************************************************************************************
 *  										Function ProtoType
 *******************************************************************************************************************/
/*
 * on configuration
 * AHB1 or AHB1/8
 * Enable INT
 * Stop Timer
 */
void MSTK_voidInit(void);

void MSTK_voidTimerState(STK_STATE_t Copy_uddtState);  // control state

void MSTK_voidINTStatus(STK_INT_STATE_t Copy_uddtINTState);

//void MSTK_voidDelay_ms(u32 delay);
void _delay_ms(u32 Copy_u32Delay);

//void MSTK_voidDelay_us(u32 delay);
void _delay_us(u32 Copy_u32Delay);

u8 MSTK_u8ReadFlag(void);

void MSTK_voidSetCallBack( void(*PFunc)(void) );

void MSTK_voidStart(u32 Copy_u32Preload);


#endif /* MSTK_INTERFACE_H_ */
