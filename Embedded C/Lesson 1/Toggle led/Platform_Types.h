#ifndef __PLATFORM_TYPES_H__
#define __PLATFORM_TYPES_H__

/* Little endian, 32 bit processor */
#define CPU_TYPE			CPU_TYPE_32
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
typedef unsigned short		uint16;

typedef signed int			sint32;
typedef unsigned int		uint32;

typedef float				float32;
typedef double				float64;

#endif