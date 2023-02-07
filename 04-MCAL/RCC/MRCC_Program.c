 /**************************************************************
 *  AUTHOR 				: Bassel Yasser
 *  Version 			: V0.0.0
 *  Date				: 1 - 2 - 2023
 *  Description 		: MRCC_Program.c --> Function Implementation
 *  Module Features		:
 *  						01- MRCC_voidInitClock(void)
 *  						02- MRCC_voidEnablePeripheralClock()
 *  						03- MRCC_voidDisablePeripheralClock()
 *  						04- MRCC_voidEnableSecuritySystem()
 *  						05- MRCC_voidDisableSecuritySystem()
 *****************************************************************************/

/*********************************************************************/
/*					Standard Types LIB								 */
/*********************************************************************/

#include "LSTD_TYPES.h"
#include "LBIT_MATH.h"
/*********************************************************************/
/*					Peripheral Files 								*/
/*********************************************************************/
#include "MRCC_Private.h"
#include "MRCC_Interface.h"
#include "MRCC_Config.h"


/*********************************************************************/
/*					Function Implementation 								*/
/*********************************************************************/


void MRCC_voidInitClock(void)
{
	/***************** HSI *****************/

#if MRCC_CLKSRC == HSI
	/* step 1 : enable HSI */
		SET_BIT(RCC_CR, 0U);
	/* step 2 : wait until HSI Ready */
		while ( GET_BIT(RCC_CR, 1) == 0 );
	/* step 3 : Switch to HSI */
		CLR_BIT(RCC_CFGR, 0U);
		CLR_BIT(RCC_CFGR, 1U);

	/***************** HSE *****************/
#elif MRCC_CLKSRC == HSE
	/* step 1 : EN HSE */
		SET_BIT(RCC_CR, 16U);
	/* Step 2 : wait until HSE Ready */
		while ( GET_BIT(RCC_CR, 17) == 0 );
	/***************** HSI RC source *****************/
#if MRCC_HSERC == HSE_RC
	/* Step 3 : EN byPass */
		SET_BIT(RCC_CR, 18U);
	/* Step 4 : switch to HSE */
		SET_BIT(RCC_CFGR, 0U);
		CLR_BIT(RCC_CFGR, 1U);
	/***************** HSI Crystal source *****************/
#elif MRCC_HSERC == HSE_CRYSTAL
	/* Step 3 : Disabele byPass */
		CLR_BIT(RCC_CR, 18U);
	/* Step 4 : switch to HSE */
		SET_BIT(RCC_CFGR, 0U);
		CLR_BIT(RCC_CFGR, 1U);

#else
#warning "Invalid Option................"
#endif

	/***************** PLL *****************/
#elif MRCC_CLKSRC == PLL
	/***************** PLL --> HSE *****************/
#if MRCC_PLLSRC == PLL_HSE
	/* Step 1 : Enable HSE */
		SET_BIT(RCC_CR, 16U);
	/* Step 2 : wait until HSE Ready */
		while ( GET_BIT(RCC_CR, 17) == 0 );
	/* Step 3 : Enable PLL */
		SET_BIT(RCC_CR, 24U);
	/* Step 4 : wait until PLL Ready */
		while ( GET_BIT(RCC_CR, 25) == 0 );
	/* Step 5 : Switch PLL */
		CLR_BIT(RCC_CFGR, 0U);
		SET_BIT(RCC_CFGR, 1U);
	/***************** PLL --> HSI *****************/
#elif MRCC_PLLSRC == PLL_HSI
	/* Step 1 : Enable HSI */
		SET_BIT(RCC_CR, 0U);
	/* Step 2 : wait until HSI Ready */
		while ( GET_BIT(RCC_CR, 1) == 0 );
	/* Step 3 : Enable PLL */
		SET_BIT(RCC_CR, 24U);
	/* Step 4 : wait until PLL Ready */
		while ( GET_BIT(RCC_CR, 25) == 0 );
	/* Step 5 : Switch PLL */
		CLR_BIT(RCC_CFGR, 0U);
		SET_BIT(RCC_CFGR, 1U);

#else
#warning "Invalid Option................"
#endif

#else
#warning "Invalid Option.........."
#endif

}


void MRCC_voidEnablePeripheralClock(BusName_t Copy_uddtBusName , u8 Copy_u8PerNum)
{
	switch (Copy_uddtBusName)
	{
		case MRCC_AHB1 	: SET_BIT(RCC_AHB1ENR, Copy_u8PerNum); break;
		case MRCC_AHB2 	: SET_BIT(RCC_AHB2ENR, Copy_u8PerNum); break;
		case MRCC_APB1 	: SET_BIT(RCC_APB1ENR, Copy_u8PerNum); break;
		case MRCC_APB2 	: SET_BIT(RCC_APB2ENR, Copy_u8PerNum); break;
		default			: /* do nothing */ break;
	}
}
void MRCC_voidDisablePeripheralClock(BusName_t Copy_uddtBusName , u8 Copy_u8PerNum)
{
	switch (Copy_uddtBusName)
	{
		case MRCC_AHB1 	: CLR_BIT(RCC_AHB1ENR, Copy_u8PerNum); break;
		case MRCC_AHB2 	: CLR_BIT(RCC_AHB2ENR, Copy_u8PerNum); break;
		case MRCC_APB1 	: CLR_BIT(RCC_APB1ENR, Copy_u8PerNum); break;
		case MRCC_APB2 	: CLR_BIT(RCC_APB2ENR, Copy_u8PerNum); break;
		default			: /* do nothing */ break;
	}
}
void MRCC_voidEnableSecuritySystem(void)
{
	SET_BIT(RCC_CR, 19);
}
void MRCC_voidDisableSecuritySystem(void)
{
	CLR_BIT(RCC_CR, 19);
}

