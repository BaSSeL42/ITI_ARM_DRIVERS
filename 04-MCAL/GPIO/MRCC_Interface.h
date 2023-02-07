 /**************************************************************
 *  AUTHOR 				: Bassel Yasser
 *  Version 			: V0.0.0
 *  Date				: 1 - 2 - 2023
 *  Description 		: MRCC_Interface.h --> Function Prototypes
 *  Module Features		:
 *  						01- MRCC_voidInitClock(void)
 *  						02- MRCC_voidEnablePeripheralClock()
 *  						03- MRCC_voidDisablePeripheralClock()
 *  						04- MRCC_voidEnableSecuritySystem()
 *  						05- MRCC_voidDisableSecuritySystem()
 *****************************************************************************/
/* What i sell to customer
 *			- the Architect Give the API
 *								- The Name Of Function
 *								- What is the input
 *								- What is the output
 *								- Give some MACROs
 */
/************************************************************************
 *  						Header Guard Of File
 ***********************************************************************/
#ifndef MRCC_INTERFACE_H_
#define MRCC_INTERFACE_H_

/**************************** AHP1_Prescaller ***************************/

typedef enum
{
	MRCC_AHP_PRE1 = 7,
	MRCC_AHP_PRE2,
	MRCC_AHP_PRE4,
	MRCC_AHP_PRE8,
	MRCC_AHP_PRE16,
	MRCC_AHP_PRE32,
	MRCC_AHP_PRE64,
	MRCC_AHP_PRE128,
	MRCC_AHP_PRE256,
	MRCC_AHP_PRE512


}AHP1_PreScaller_t;

/**************************** APB1_Prescaller ***************************/

//typedef enum
//{
//	// TODO
//
//
//}APB1_PreScaller_t;


/**************************** APB2_Prescaller ***************************/

//typedef enum
//{
//	// TODO
//
//
//}APB2_PreScaller_t;
/**************************** BUS_NAME ***************************/

//#define MRCC_AHB1		0
//#define MRCC_AHB2		1
//#define MRCC_APB1		2
//#define MRCC_APB2		3

typedef enum
{
	MRCC_AHB1=0	,
	MRCC_AHB2	,
	MRCC_APB1	,
	MRCC_APB2
}BusName_t;

/**************************** CLKSRC_NAME ***************************/

#define HSI		0U
#define HSE		1U
#define PLL		2U

/**************************** HSESRC_NAME ***************************/

#define HSE_RC			0U
#define HSE_CRYSTAL		1U

/**************************** PLLSRC_NAME ***************************/

#define PLL_HSE			0U
#define PLL_HSI			1U

/**************************** MACROS : RCC AHB1 Peripheral Clock Enable Register ***************************/
#define MRCC_GPIOA_EN		0U
#define MRCC_GPIOB_EN		1U
#define MRCC_GPIOC_EN		2U
#define MRCC_GPIOD_EN		3U
#define MRCC_GPIOE_EN		4U
#define MRCC_GPIOH_EN		7U

#define MRCC_CRC_EN			12U

#define MRCC_DMA1_EN		21U
#define MRCC_DMA2_EN		22U


/**************************** MACROS : RCC AHB2 Peripheral Clock Enable Register ***************************/
// TODO

/**************************** MACROS : RCC APB1 Peripheral Clock Enable Register ***************************/
// TODO

/**************************** MACROS : RCC APB2 Peripheral Clock Enable Register ***************************/
// TODO







/**************************************************************************
 * 			Function Prototypes
 ***************************************************************************/

void MRCC_voidInitClock(void);
/***********************************************************************************/
/*			02- MRCC_voidEnablePeripheralClock()									*/
/* ----------------------------------------------------------------------------------
 * @func  : Enable peripheral Clock
 * @in[1] : Copy_uddtBusName
 * 				- MRCC_AHB1
 * 				- MRCC_AHB2
 * 				- MRCC_APB1
 * 				- MRCC_APB2
 * @in[2]  : Copy_u8PerNum  : the order of peripheral on selected register
 * @out    : void
 ************************************************************************************/
void MRCC_voidEnablePeripheralClock(BusName_t Copy_uddtBusName , u8 Copy_u8PerNum);
void MRCC_voidDisablePeripheralClock(BusName_t Copy_uddtBusName , u8 Copy_u8PerNum);
void MRCC_voidEnableSecuritySystem(void);
void MRCC_voidDisableSecuritySystem(void);


#endif /* MRCC_INTERFACE_H_ */
