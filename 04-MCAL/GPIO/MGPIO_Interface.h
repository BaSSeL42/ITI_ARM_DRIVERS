 /**************************************************************
 *  AUTHOR 				: Bassel Yasser
 *  Version 			: V0.0.0
 *  Date				: 4 - 2 - 2023
 *  Description 		: MGPIO_Interface.h --> Function Prototypes
 *  Module Features		:
 *  						01- MGPIO_voidSetPinMode()
 *  						02- MGPIO_voidSetPinData()
							03-	MGPIO_voidGetPinData()
							04-	MGPIO_voidPullType()
							05-	MGPIO_voidPinOutSpeed()
							06-	MGPIO_voidSetPinOutputType()
 *****************************************************************************/

/*********************************************************************************************************
 *  										Header Guard Of File
 ********************************************************************************************************/
#ifndef MGPIO_INTERFACE_H_
#define MGPIO_INTERFACE_H_

/*********************************************************************************************************
 *  										MACROS
 ********************************************************************************************************/

/***********************   Pull Type    **************************/
#define MGPIO_PULL_OFF			0
#define MGPIO_PULL_UP			1
#define MGPIO_PULL_DOWN			2

/***********************   Pin Output Type    **************************/
#define MGPIO_OUTPUT_PUSHPULL		0
#define MGPIO_OUTPUT_OPENDRAIN		1

/***********************  Pin Value    **************************/
#define MGPIO_PIN_LOW			0
#define MGPIO_PIN_HIGH			1
#define MGPIO_PIN_TOG			2

/*********************************************************************************************************
 *  									User Defined Data Type
 ********************************************************************************************************/

/***********************   Port Selection    **************************/
typedef enum
{
	MGPIO_PORTA=0,
	MGPIO_PORTB,
	MGPIO_PORTC,
	MGPIO_PORT_INVALID

}enu_port_t;

/***********************   Pin Selection    **************************/
typedef enum
{
	MGPIO_PINA0 = 0,
	MGPIO_PINA1,
	MGPIO_PINA2,
	MGPIO_PINA3,
	MGPIO_PINA4,
	MGPIO_PINA5,
	MGPIO_PINA6,
	MGPIO_PINA7,
	MGPIO_PINA8,
	MGPIO_PINA9,
	MGPIO_PINA10,
	MGPIO_PINA11,
	MGPIO_PINA12,
	MGPIO_PINA13,
	MGPIO_PINA14,
	MGPIO_PINA15,

	MGPIO_PINB0,
	MGPIO_PINB1,
	MGPIO_PINB2,
	MGPIO_PINB3,
	MGPIO_PINB4,
	MGPIO_PINB5,
	MGPIO_PINB6,
	MGPIO_PINB7,
	MGPIO_PINB8,
	MGPIO_PINB9,
	MGPIO_PINB10,
	MGPIO_PINB11,
	MGPIO_PINB12,
	MGPIO_PINB13,
	MGPIO_PINB14,
	MGPIO_PINB15,

	MGPIO_PINC13 = 45,
	MGPIO_PINC14,
	MGPIO_PINC15,

	MGPIO_PIN_INVALID

}enu_pin_t;


/***********************   Pin Mode Selection    **************************/
typedef enum
{
	MGPIO_MODE_INPUT=0,
	MGPIO_MODE_OUTPUT,
	MGPIO_MODE_ALTF,
	MGPIO_MODE_ANALOG,

	MGPIO_MODE_INVALID

}enu_pinMode_t;

/***********************  Pin Speed Selection    **************************/
typedef enum
{
	MGPIO_OUTPUT_LOW_SPEED=0,
	MGPIO_OUTPUT_MEDIUM_SPEED,
	MGPIO_OUTPUT_HIGH_SPEED,
	MGPIO_OUTPUT_VERYHIGH_SPEED,

	MGPIO_SPEED_INVALID

}enu_gpioSpeed_t;


/********************************************************************************************************************
 *  										Function ProtoType
 *******************************************************************************************************************/
/***********************************************************************************/
/*			01- MGPIO_voidSetPinMode()									*/
/* ----------------------------------------------------------------------------------
 * @func  : Pin Mode configuration
 * @in[1] : Copy_enPinNum
 * 				- MGPIO_PINA0 ~ MGPIO_PINC15
 * @in[2]  : Copy_enPinMode  :
 * 				- MGPIO_MODE_INPUT
 * 				- MGPIO_MODE_OUTPUT
 * 				- MGPIO_MODE_ALTF
 * 				- MGPIO_MODE_ANALOG
 * @out    : void
 ************************************************************************************/
void MGPIO_voidSetPinMode		(enu_pin_t Copy_enPinNum, enu_pinMode_t Copy_enPinMode);

/***********************************************************************************/
/*			02- MGPIO_voidSetPinData()									*/
/* ----------------------------------------------------------------------------------
 * @func  : Set output pin to low or high
 * @in[1] : Copy_enPinNum
 * 				- MGPIO_PINA0 ~ MGPIO_PINC15
 *
 * @in[2]  : Copy_PinValue  :
 * 				- MGPIO_PIN_LOW
 * 				- MGPIO_PIN_HIGH
 * @out    : void
 ************************************************************************************/
void MGPIO_voidSetPinData		(enu_pin_t Copy_enPinNum, u8 Copy_PinValue);

/***********************************************************************************/
/*			03- MGPIO_voidGetPinData()									*/
/* ----------------------------------------------------------------------------------
 * @func  : Get pin Value
 * @in[1] : Copy_enPinNum
 * 				- MGPIO_PINA0 ~ MGPIO_PINC15
 *
 * @in[2]  : Ref_pu8PinVal  : Reference to variable where the value status store on it
 * @out    : void
 ************************************************************************************/
void MGPIO_voidGetPinData		(enu_pin_t Copy_enPinNum , u8* Ref_pu8PinVal);

/***********************************************************************************/
/*			04- MGPIO_voidPullType()									*/
/* ----------------------------------------------------------------------------------
 * @func  : Set Pull Mode
 * @in[1] : Copy_enPinNum
 * 				- MGPIO_PINA0 ~ MGPIO_PINC15
 *
 * @in[2]  : Copy_PullType  :
 * 				- MGPIO_PULL_OFF
 * 				- MGPIO_PULL_UP
 * 				- MGPIO_PULL_DOWN
 * @out    : void
 ************************************************************************************/
void MGPIO_voidPullType			(enu_pin_t Copy_enPinNum, u8 Copy_PullType);

/***********************************************************************************/
/*			05- MGPIO_voidPinOutSpeed()									*/
/* ----------------------------------------------------------------------------------
 * @func  : Set Pin Speed
 * @in[1] : Copy_enPinNum
 * 				- MGPIO_PINA0 ~ MGPIO_PINC15
 *
 * @in[2]  : Copy_enPinSpeed  :
 * 				- MGPIO_OUTPUT_LOW_SPEED
 * 				- MGPIO_OUTPUT_MEDIUM_SPEED
 * 				- MGPIO_OUTPUT_HIGH_SPEED
 * 				- MGPIO_OUTPUT_VERYHIGH_SPEED
 * @out    : void
 ************************************************************************************/
void MGPIO_voidPinOutSpeed		(enu_pin_t Copy_enPinNum, enu_gpioSpeed_t Copy_enPinSpeed);

/***********************************************************************************/
/*			06- MGPIO_voidSetPinOutputType()									*/
/* ----------------------------------------------------------------------------------
 * @func  : Set Pin output State
 * @in[1] : Copy_enPinNum
 * 				- MGPIO_PINA0 ~ MGPIO_PINC15
 *
 * @in[2]  : Copy_PinOutputType  :
 * 				- MGPIO_OUTPUT_PUSHPULL
 * 				- MGPIO_OUTPUT_OPENDRAIN
 * @out    : void
 ************************************************************************************/
void MGPIO_voidSetPinOutputType	(enu_pin_t Copy_enPinNum, u8 Copy_PinOutputType);





#endif /* MGPIO_INTERFACE_H_ */
