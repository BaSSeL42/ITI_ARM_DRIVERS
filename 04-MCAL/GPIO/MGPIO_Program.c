 /**************************************************************
 *  AUTHOR 				: Bassel Yasser
 *  Version 			: V0.0.0
 *  Date				: 4 - 2 - 2023
 *  Description 		: MGPIO_Program.c --> Function Implementation
 *  Module Features		:
 *  						01- MGPIO_voidSetPinMode()
 *  						02- MGPIO_voidSetPinData()
							03-	MGPIO_voidGetPinData()
							04-	MGPIO_voidPullType()
							05-	MGPIO_voidPinOutSpeed()
							06-	MGPIO_voidSetPinOutputType()
 *****************************************************************************/

/********************************************************************************************************************
*												Standard Types LIB
********************************************************************************************************************/
#include "LSTD_TYPES.h"
#include "LBIT_MATH.h"
/********************************************************************************************************************
*												Peripheral Files
********************************************************************************************************************/
#include "MGPIO_Private.h"
#include "MGPIO_Interface.h"
#include "MGPIO_Config.h"
/********************************************************************************************************************
*												Global Variables
********************************************************************************************************************/
volatile u32* GPIO_MODER[3] 	= { GPIOA_MODER, GPIOB_MODER, GPIOC_MODER };
volatile u32* GPIO_ODR[3]   	= { GPIOA_ODR, GPIOB_ODR, GPIOC_ODR };
volatile u32* GPIO_IDR[3]   	= { GPIOA_IDR, GPIOB_IDR, GPIOC_IDR };
volatile u32* GPIO_PUPDR[3] 	= { GPIOA_PUPDR, GPIOB_PUPDR, GPIOC_PUPDR };
volatile u32* GPIO_OSPEEDR[3] 	= { GPIOA_OSPEEDR, GPIOB_OSPEEDR, GPIOC_OSPEEDR };
volatile u32* GPIO_OTYPER[3] 	= { GPIOA_OTYPER, GPIOB_OTYPER, GPIOC_OTYPER };


/********************************************************************************************************************
 *  										Function Implementation
*******************************************************************************************************************/
void MGPIO_voidSetPinMode(enu_pin_t Copy_enPinNum, enu_pinMode_t Copy_enPinMode)
{
	u8 local_u8PortNum;
	u16 local_u16PinNum;
	if(Copy_enPinNum < MGPIO_PIN_INVALID && Copy_enPinMode < MGPIO_MODE_INVALID)
	{
		local_u8PortNum = Copy_enPinNum / 16;
		local_u16PinNum = (Copy_enPinNum % 16)*2;

		switch (Copy_enPinMode)
		{
			case MGPIO_MODE_INPUT	:CLR_BIT(*GPIO_MODER[local_u8PortNum], (local_u16PinNum + 1)); CLR_BIT(*GPIO_MODER[local_u8PortNum], local_u16PinNum);	 break;
			case MGPIO_MODE_OUTPUT	:CLR_BIT(*GPIO_MODER[local_u8PortNum], (local_u16PinNum + 1)); SET_BIT(*GPIO_MODER[local_u8PortNum], local_u16PinNum);	 break;
			case MGPIO_MODE_ALTF	:SET_BIT(*GPIO_MODER[local_u8PortNum], (local_u16PinNum + 1)); CLR_BIT(*GPIO_MODER[local_u8PortNum], local_u16PinNum);	 break;
			case MGPIO_MODE_ANALOG	:SET_BIT(*GPIO_MODER[local_u8PortNum], (local_u16PinNum + 1)); SET_BIT(*GPIO_MODER[local_u8PortNum], local_u16PinNum);	 break;
			default: break;
		}
	}else
	{

	}

	return;
}


/********************************************************************************************************************/
void MGPIO_voidSetPinData(enu_pin_t Copy_enPinNum, u8 Copy_PinValue)
{
	u8 local_u8PortNum;
	u16 local_u16PinNum;
	if(Copy_enPinNum < MGPIO_PIN_INVALID)
	{
		local_u8PortNum = Copy_enPinNum / 16;
		local_u16PinNum = Copy_enPinNum % 16;

		switch (Copy_PinValue)
		{
			case MGPIO_PIN_LOW	: CLR_BIT(*GPIO_ODR[local_u8PortNum], local_u16PinNum);	 break;
			case MGPIO_PIN_HIGH	: SET_BIT(*GPIO_ODR[local_u8PortNum], local_u16PinNum);	 break;
			default: break;
		}
	}else
	{

	}

	return;

}
/********************************************************************************************************************/
void MGPIO_voidGetPinData(enu_pin_t Copy_enPinNum , u8* Ref_pu8PinVal)
{
	u8 local_u8PortNum;
	u16 local_u16PinNum;


	if(Copy_enPinNum < MGPIO_PIN_INVALID && Ref_pu8PinVal != NULL)
	{
		local_u8PortNum = Copy_enPinNum / 16;
		local_u16PinNum = Copy_enPinNum % 16;

		*Ref_pu8PinVal = GET_BIT(*GPIO_IDR[local_u8PortNum], local_u16PinNum);

	}else
	{

	}
	return;
}
/********************************************************************************************************************/

void MGPIO_voidPullType(enu_pin_t Copy_enPinNum, u8 Copy_PullType)
{
	u8 local_u8PortNum;
	u16 local_u16PinNum;
	if(Copy_enPinNum < MGPIO_PIN_INVALID)
	{
		local_u8PortNum = Copy_enPinNum / 16;
		local_u16PinNum = (Copy_enPinNum % 16)*2;

		switch (Copy_PullType)
		{
			case MGPIO_PULL_OFF		:CLR_BIT(*GPIO_PUPDR[local_u8PortNum], (local_u16PinNum + 1)); CLR_BIT(*GPIO_PUPDR[local_u8PortNum], local_u16PinNum);	 break;
			case MGPIO_PULL_UP		:CLR_BIT(*GPIO_PUPDR[local_u8PortNum], (local_u16PinNum + 1)); SET_BIT(*GPIO_PUPDR[local_u8PortNum], local_u16PinNum);	 break;
			case MGPIO_PULL_DOWN	:SET_BIT(*GPIO_PUPDR[local_u8PortNum], (local_u16PinNum + 1)); CLR_BIT(*GPIO_PUPDR[local_u8PortNum], local_u16PinNum);	 break;
			default: break;
		}
	}else
	{

	}

	return;
}

/********************************************************************************************************************/
void MGPIO_voidPinOutSpeed(enu_pin_t Copy_enPinNum, enu_gpioSpeed_t Copy_enPinSpeed)
{
	u8 local_u8PortNum;
	u16 local_u16PinNum;
	if(Copy_enPinNum < MGPIO_PIN_INVALID && Copy_enPinSpeed < MGPIO_SPEED_INVALID)
	{
		local_u8PortNum = Copy_enPinNum / 16;
		local_u16PinNum = (Copy_enPinNum % 16)*2;

		switch (Copy_enPinSpeed)
		{
			case MGPIO_OUTPUT_LOW_SPEED			:CLR_BIT(*GPIO_OSPEEDR[local_u8PortNum], (local_u16PinNum + 1)); CLR_BIT(*GPIO_OSPEEDR[local_u8PortNum], local_u16PinNum);	 break;
			case MGPIO_OUTPUT_MEDIUM_SPEED		:CLR_BIT(*GPIO_OSPEEDR[local_u8PortNum], (local_u16PinNum + 1)); SET_BIT(*GPIO_OSPEEDR[local_u8PortNum], local_u16PinNum);	 break;
			case MGPIO_OUTPUT_HIGH_SPEED		:SET_BIT(*GPIO_OSPEEDR[local_u8PortNum], (local_u16PinNum + 1)); CLR_BIT(*GPIO_OSPEEDR[local_u8PortNum], local_u16PinNum);	 break;
			case MGPIO_OUTPUT_VERYHIGH_SPEED	:SET_BIT(*GPIO_OSPEEDR[local_u8PortNum], (local_u16PinNum + 1)); SET_BIT(*GPIO_OSPEEDR[local_u8PortNum], local_u16PinNum);	 break;
			default: break;
		}
	}else
	{

	}

	return;
}

/********************************************************************************************************************/
void MGPIO_voidSetPinOutputType(enu_pin_t Copy_enPinNum, u8 Copy_PinOutputType)
{
	u8 local_u8PortNum;
	u16 local_u16PinNum;
	if(Copy_enPinNum < MGPIO_PIN_INVALID)
	{
		local_u8PortNum = Copy_enPinNum / 16;
		local_u16PinNum = Copy_enPinNum % 16;

		switch (Copy_PinOutputType)
		{
			case MGPIO_OUTPUT_PUSHPULL		: CLR_BIT(*GPIO_OTYPER[local_u8PortNum], local_u16PinNum);	 break;
			case MGPIO_OUTPUT_OPENDRAIN		: SET_BIT(*GPIO_OTYPER[local_u8PortNum], local_u16PinNum);	 break;
			default: break;
		}
	}else
	{

	}

	return;

}
