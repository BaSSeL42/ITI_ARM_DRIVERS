/*
 * MEXTI_Private.h
 *
 *  Created on: Feb 11, 2023
 *      Author: hp
 */

#ifndef MEXTI_PRIVATE_H_
#define MEXTI_PRIVATE_H_

#define MEXTI_BASE_ADDRESS		0x40013C00

#define SYSCFG_BASE_ADDRESS		0x40013800

typedef struct
{
	volatile u32 IMR;
	volatile u32 EMR;
	volatile u32 RTSR;
	volatile u32 FTSR;
	volatile u32 SWIER;
	volatile u32 PR;

}MEXTI_t;



typedef struct
{
	volatile u32 MEMRMP;
	volatile u32 PMC;
	volatile u32 EXTICR[4];

}SYSCFG_t;

#define MEXIT		((MEXTI_t*)(MEXTI_BASE_ADDRESS))

#define SYSCFG		((SYSCFG_t*)(SYSCFG_BASE_ADDRESS + 0x08))

#endif /* MEXTI_PRIVATE_H_ */
