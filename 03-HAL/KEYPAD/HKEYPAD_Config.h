/*
 * HKEYPAD_Config.h
 *
 *  Created on: Feb 6, 2023
 *      Author: hp
 */

#ifndef HKEYPAD_CONFIG_H_
#define HKEYPAD_CONFIG_H_

typedef struct
{
	enu_pin_t enPinType;

}str_KeyPad_pinConf_t;





#define HKEYPAD_NO_COL		4
#define HKEYPAD_NO_ROW		4

#define NO_KEY_PRESSED		0


#define HKEYPAD_PORT_CLOCK_1		MRCC_GPIOA_EN


#endif /* HKEYPAD_CONFIG_H_ */
