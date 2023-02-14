/*
 * HLEDMATRIX_Config.h
 *
 *  Created on: Feb 10, 2023
 *      Author: hp
 */

#ifndef HLEDMATRIX_CONFIG_H_
#define HLEDMATRIX_CONFIG_H_


#define LED_MATRIX_PIN_NUMBER 		8
#define LED_MATRIX_CLK_CFG			MRCC_GPIOB_EN
#define LED_MATRIX_CLK_CFG_1		MRCC_GPIOC_EN

typedef struct
{
	enu_pin_t enPinType;

}str_ledMatrixPinConf_t;



#endif /* HLEDMATRIX_CONFIG_H_ */
