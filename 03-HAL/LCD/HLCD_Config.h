/*
 * HLCD_Config.h
 *
 *  Created on: Feb 5, 2023
 *      Author: hp
 */

#ifndef HLCD_CONFIG_H_
#define HLCD_CONFIG_H_

#define HLCD_LCD_PIN_NUMBER		11
#define HLCD_PIN_NUMBER		8


#define HLCD_RS_PORT_PIN		MGPIO_PINA0
#define HLCD_RW_PORT_PIN		MGPIO_PINA1
#define HLCD_EN_PORT_PIN		MGPIO_PINA2

#define HLCD_PORT_CLOCK_1			MRCC_GPIOB_EN
#define HLCD_PORT_CLOCK_2			MRCC_GPIOA_EN



typedef struct
{
	enu_pin_t enPinType;

}str_pinConf_t;


#endif /* HLCD_CONFIG_H_ */
