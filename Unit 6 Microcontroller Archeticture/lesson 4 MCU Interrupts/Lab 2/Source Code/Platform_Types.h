#ifndef PLATFORM_TYPES_H_
#define PLATFORM_TYPES_H_

#define CPU_TYPE_8      8
#define CPU_TYPE_16    16
#define CPU_TYPE_32    32

/* Little endian, 32 bit processor */
#define CPU_TYPE			    CPU_TYPE_8
#define CPU_BIT_ORDER   	LSB_FIRST
#define CPU_BYTE_ORDER  	LOW_BYTE_FIRST

typedef unsigned char 		boolean;

#ifndef TRUE
  #define TRUE  (boolean) 1
#endif

#ifndef FALSE
  #define FALSE (boolean) 0
#endif


typedef signed char			                  sint8_t;
typedef unsigned char		                  uint8_t;
typedef volatile signed char              vsint8_t;
typedef volatile unsigned char            vuint8_t;

typedef signed short		                  sint16_t;
typedef unsigned short                    uint16_t;
typedef volatile signed short             vsint16_t;
typedef volatile unsigned short           vuint16_t;

typedef signed int			                  sint32_t;
typedef unsigned int		                  uint32_t;
typedef volatile signed int               vsint32_t;
typedef volatile unsigned int             vuint32_t;

typedef float				    float32_t;
typedef double				  float64_t;

#endif
