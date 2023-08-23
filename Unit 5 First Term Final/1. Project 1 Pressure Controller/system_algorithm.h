#ifndef _SYSTEM_ALGORITHM_H_
#define _SYSTEM_ALGORITHM_H_


#include "state.h"


typedef enum
{
	SA_Waiting,
	SA_Check = !SA_Waiting
	
} eSA_State_t;


extern void (*p2SA_state) (void);

void SA_Init(void);
STATE_fn(SA_Waiting);
STATE_fn(SA_Check);


#endif 
