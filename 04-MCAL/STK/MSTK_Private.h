 /**************************************************************
 *  AUTHOR 				: Bassel Yasser
 *  Version 			: V0.0.0
 *  Date				: 7 - 2 - 2023
 *  Description 		: MSTK_Private.h --> Register Description
 *****************************************************************************/


/********************************************************************************************************************
*												File Guard
********************************************************************************************************************/
#ifndef MSTK_PRIVATE_H_
#define MSTK_PRIVATE_H_

#define SYSTICK_BASE_ADDRESS		0xE000E010


typedef struct
{
	volatile u32 CTRL;
	volatile u32 LOAD;
	volatile u32 VAL;
	volatile u32 CALIB;

}stk_t;



#define MSTK	((stk_t*)(SYSTICK_BASE_ADDRESS))
/*********************************************************************************************************
 *  										MACROS
********************************************************************************************************/



#endif /* MSTK_PRIVATE_H_ */
