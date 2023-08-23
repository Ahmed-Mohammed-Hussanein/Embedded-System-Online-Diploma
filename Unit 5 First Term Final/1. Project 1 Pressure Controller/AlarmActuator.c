

#include "AlarmActuator.h"
#include "driver.h"


void (*p2AA_state) (void);

eAA_State_t AA_state;

void AA_start_alarm()
{
	p2AA_state = STATE(AA_AlarmOn);
}

void AA_stop_alarm()
{
	p2AA_state = STATE(AA_AlarmOff);
}

void AA_Init(void)
{
	/* state name */
	AA_state = AA_Waiting;

	/* state transition */
	p2AA_state = STATE(AA_Waiting);
}

STATE_fn(AA_Waiting)
{
	// state name
	AA_state = AA_Waiting;

	// state action

	// state transition
	p2AA_state = STATE(AA_Waiting);
}

STATE_fn(AA_AlarmOff)
{
	// state name
	AA_state = AA_AlarmOff;

	// state action
	Set_Alarm_actuator(1);

	// state transition
	p2AA_state = STATE(AA_Waiting);
}

STATE_fn(AA_AlarmOn)
{
	// state name
	AA_state = AA_AlarmOn;

	// state action
	Set_Alarm_actuator(0);

	// state transition
	p2AA_state = STATE(AA_Waiting);
}
