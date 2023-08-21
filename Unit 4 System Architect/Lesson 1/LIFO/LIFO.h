/* Ahmed Mohammed Hussanein Ali 
	Implementation of LIFO */

#ifndef LIFO_H_
#define LIFO_H_

#include "Platform_Types.h"

#define element_type uint32

/* Type definitions */
typedef struct
{
	uint32  length;
	element_type* base;
	element_type* head;
	uint32  count;	
} LIFO_t;

typedef enum
{
	LIFO_no_errors,
	LIFO_full,
	LIFO_not_full,
	LIFO_empty,
	LIFO_not_empty,
	LIFO_null
} LIFO_STATUS;

/* APIs */
LIFO_STATUS LIFO_init(LIFO_t *, element_type *, uint32);
LIFO_STATUS LIFO_push(LIFO_t *, element_type);
LIFO_STATUS LIFO_pop(LIFO_t *, element_type *);
LIFO_STATUS LIFO_is_empty(LIFO_t *);
LIFO_STATUS LIFO_is_full(LIFO_t *);




#endif