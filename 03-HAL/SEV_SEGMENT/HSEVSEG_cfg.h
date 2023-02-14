/*
 * H7SEG_cfg.h
 *
 *  Created on: Feb 4, 2023
 *      Author: hp
 */

#ifndef HSEVSEG_CFG_H_
#define HSEVSEG_CFG_H_

#define SEG_SIZE		10
#define PIN_NUMBER		7

#define LED_PIN_1		MGPIO_PINC13
#define LED_PIN_2		MGPIO_PINC14
#define LED_PIN_3		MGPIO_PINC15


typedef struct
{
	enu_pin_t enPinType;

}str_pinConf_t;


#endif /* HSEVSEG_CFG_H_ */
