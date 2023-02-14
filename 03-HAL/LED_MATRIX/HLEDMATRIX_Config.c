/*
 * HLEDMATRIX_Config.c
 *
 *  Created on: Feb 10, 2023
 *      Author: hp
 */


/********************************************************************************************************************
*												Standard Types LIB
********************************************************************************************************************/
#include "LSTD_TYPES.h"
#include "LBIT_MATH.h"
/********************************************************************************************************************
*												Peripheral Files
********************************************************************************************************************/
#include "MGPIO_Interface.h"
#include "HLEDMATRIX_Config.h"



u8 ledMatrixArr[LED_MATRIX_PIN_NUMBER] = {
		0x26, 0x49, 0x86, 0x80, 0x80, 0x86, 0x49, 0x26
};

u8 ledMatrixArr_2[LED_MATRIX_PIN_NUMBER] = {
		0x26, 0x49, 0x86, 0x80, 0x80, 0x84, 0x44, 0x24
};


str_ledMatrixPinConf_t colPinArr[LED_MATRIX_PIN_NUMBER] = { {MGPIO_PINB0}, {MGPIO_PINB1}, {MGPIO_PINB2}, {MGPIO_PINB3}, {MGPIO_PINB4}, {MGPIO_PINB5}, {MGPIO_PINB6}, {MGPIO_PINB7}};

str_ledMatrixPinConf_t rowPinArr[LED_MATRIX_PIN_NUMBER] = { {MGPIO_PINB8}, {MGPIO_PINB9}, {MGPIO_PINB10}, {MGPIO_PINB12}, {MGPIO_PINB13}, {MGPIO_PINB14}, {MGPIO_PINB15} ,{MGPIO_PINC13},};
