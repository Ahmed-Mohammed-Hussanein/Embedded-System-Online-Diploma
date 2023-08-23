

#include "monitor_alarm.h"
#include "driver.h"

static int alarm_delay = 600000;

void (*p2MA_state) (void);

eMA_State_t MA_state;

void MA_high_pressure()
{
	p2MA_state = STATE(TurnOn);
}

void MA_Init(void)
{
	/* state name */
	MA_state = TurnOff;

	/* state transition */
	p2MA_state = STATE(TurnOff);
}

STATE_fn(TurnOff)
{
	// state name
	MA_state = TurnOff;

	// state action
	AA_stop_alarm();

	// state transition
	p2MA_state = STATE(TurnOff);
}

STATE_fn(TurnOn)
{
	// state name
	MA_state = TurnOn;

	// state action
	AA_start_alarm();

	// state transition
	p2MA_state = STATE(Waiting);
}

STATE_fn(Waiting)
{
	// state name
	MA_state = Waiting;

	// state action
	Delay(alarm_delay);

	// state transition
	p2MA_state = STATE(TurnOff);
}
