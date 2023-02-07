 /**************************************************************
 *  AUTHOR 		: Bassel Yasser
 *  Version 	: V0.0.0
 *  Date		: 1 - 2 - 2023
 *  Description : MRCC_Config.h --> configuration
 **************************************************************/

#ifndef MRCC_CONFIG_H_
#define MRCC_CONFIG_H_

/*
 * - CLKSRC Options
 * 						1- HSI
 * 						2- HSE
 * 						3- PLL
 */

#define MRCC_CLKSRC		HSI


/*
 * - HSE Option:
 * 				1- HSE_RC
 * 				2- HSE_CRYSTAL
 */
#define MRCC_HSESRC		HSE_CRYSTAL


/*
 * - PLL Option:
 * 				1- PLL_HSE
 * 				2- PLL_HSI
 */
#define MRCC_PLLSRC		PLL_HSI




#endif /* MRCC_CONFIG_H_ */
