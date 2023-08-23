#ifndef _PRESSURE_SENSOR_H_
#define _PRESSURE_SENSOR_H_


#include "state.h"


typedef enum
{
	PS_Reading,
	PS_Waiting = !PS_Reading
	
} ePS_State_t;


extern void (*p2PS_state) (void);

void PS_Init(void);
STATE_fn(PS_Reading);
STATE_fn(PS_Waiting);


#endif 
