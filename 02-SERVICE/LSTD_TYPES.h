/**************************************************************
 *  AUTHOR 		: Bassel Yasser
 *  Version 	: V0.0.0
 *  Date		: 25 - 1 - 2023
 *  Description : LSTD_TYPES.h
 **************************************************************/

/**********************************************************
 *				 HEADER GUARD OF FILE
 *********************************************************/
#ifndef LSTD_TYPES_H_
#define LSTD_TYPES_H_
/***************************************************
 * 					BOOLEAN VALUES
 **************************************************/
#ifndef FALSE
#define FALSE		(0U) // U is saffix --> unsigned integer
#endif

#ifndef TRUE
#define TRUE		(1U) // U is saffix --> unsigned integer
#endif

/***************************************************
 * 					DATA_TYPES
 **************************************************/
typedef unsigned char 				u8;
typedef unsigned short int 			u16;
typedef unsigned long int 			u32;

typedef signed char 				s8;
typedef signed short int 			s16;
typedef signed long int 			s32;

typedef float		 				f32;
typedef double 						f64;

//NULL is void pointer
#ifndef NULL
#define NULL						(void*)(0)
#endif




#endif /* LSTD_TYPES_H_ */
