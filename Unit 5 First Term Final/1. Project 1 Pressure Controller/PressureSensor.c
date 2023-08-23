
#include "PressureSensor.h"
#include "driver.h"


static int pressureVal = 0;

void (*p2PS_state) (void);

ePS_State_t PS_state;

void PS_Init(void)
{
	/* state name */
	PS_state = PS_Reading;

	/* state transition */
	p2PS_state = STATE(PS_Reading);
}

STATE_fn(PS_Reading)
{
	// state name
	PS_state = PS_Reading;

	// state action
	pressureVal = getPressureVal();
	PS_set_pressure_value(&pressureVal);

	// state transition
	p2PS_state = STATE(PS_Waiting);
}

STATE_fn(PS_Waiting)
{
	// state name
	PS_state = PS_Waiting;

	// state action
	Delay(100000);

	// state transition
	p2PS_state = STATE(PS_Reading);
}
