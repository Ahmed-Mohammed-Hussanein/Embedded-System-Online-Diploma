#ifndef _ALARM_ACTUATOR_H_
#define _ALARM_ACTUATOR_H_


#include "state.h"


typedef enum
{
	AA_Waiting,
	AA_AlarmOff,
	AA_AlarmOn
	
} eAA_State_t;


extern void (*p2AA_state) (void);


void AA_Init(void);
STATE_fn(AA_Waiting);
STATE_fn(AA_AlarmOff);
STATE_fn(AA_AlarmOn);


#endif 
