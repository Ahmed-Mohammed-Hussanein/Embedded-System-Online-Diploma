/* Ahmed Mohammed Hussanein Ali 
	Implementation of FIFO */

#ifndef FIFO_H_
#define FIFO_H_

#include "Platform_Types.h"

#define element_type uint32

/* Type definitions */
typedef struct
{
	uint32  length;
	element_type* base;
	element_type* head;
	element_type* tail;
	uint32  count;	
} FIFO_t;

typedef enum
{
	FIFO_no_errors,
	FIFO_full,
	FIFO_not_full,
	FIFO_empty,
	FIFO_not_empty,
	FIFO_null
} FIFO_STATUS;

/* APIs */
FIFO_STATUS FIFO_init(FIFO_t *, element_type *, uint32);
FIFO_STATUS FIFO_enqueue(FIFO_t *, element_type);
FIFO_STATUS FIFO_dequeue(FIFO_t *, element_type *);
FIFO_STATUS FIFO_is_empty(FIFO_t *);
FIFO_STATUS FIFO_is_full(FIFO_t *);




#endif