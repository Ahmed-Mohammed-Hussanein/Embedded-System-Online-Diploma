/*
 * Platform_Types.h
 *
 *  Created on: Aug 9, 2022
 *      Author: Ahmed
 */

#ifndef PLATFORM_TYPES_H_
#define PLATFORM_TYPES_H_

#define CPU_TYPE_8        8
#define CPU_TYPE_16      16
#define CPU_TYPE_32      32

#define MSB_FIRST        0
#define LSB_FIRST        1

#define HIGH_BYTE_FIRST  0
#define LOW_BYTE_FIRST   1

/* Little endian, 32 bit processor */
#define CPU_TYPE			    CPU_TYPE_32
#define CPU_BIT_ORDER   	LSB_FIRST
#define CPU_BYTE_ORDER  	LOW_BYTE_FIRST

typedef unsigned char 		boolean;

#ifndef TRUE
#define TRUE  (boolean) 1
#endif

#ifndef FALSE
#define FALSE (boolean) 0
#endif


typedef signed char			sint8;
typedef unsigned char		uint8;

typedef signed short		sint16;
typedef unsigned short  uint16;

typedef signed int			sint32;
typedef unsigned int		uint32;

typedef float				    float32;
typedef double				  float64;

#endif /* PLATFORM_TYPES_H_ */
