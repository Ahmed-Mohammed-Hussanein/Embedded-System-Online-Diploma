#ifndef _STATE_H_
#define _STATE_H_


#include "Platform_Types.h"


#define STATE_fn(STATE_NAME) void STATE_NAME##_STATE(void)
#define STATE(STATE_NAME) 	 	  STATE_NAME##_STATE


void PS_set_pressure_value(int *p2PressureValue);
void MA_high_pressure();
void AA_start_alarm();
void AA_stop_alarm();



#endif
