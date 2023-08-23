#ifndef _MONITOR_ALARM_H_
#define _MONITOR_ALARM_H_


#include "state.h"


typedef enum
{
	TurnOff,
	TurnOn,
	Waiting
	
} eMA_State_t;


extern void (*p2MA_state) (void);

void MA_Init(void);
STATE_fn(TurnOff);
STATE_fn(TurnOn);
STATE_fn(Waiting);


#endif 
