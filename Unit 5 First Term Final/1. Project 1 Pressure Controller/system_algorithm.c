

#include "system_algorithm.h"

static int pVal = 0;
static int pThreshold = 20;

void (*p2SA_state) (void);

eSA_State_t SA_state;

void PS_set_pressure_value(int *p2PressureValue)
{
	pVal = *p2PressureValue;
	p2SA_state = STATE(SA_Check);
}

void SA_Init(void)
{
	/* state name */
	SA_state = SA_Waiting;

	/* state transition */
	p2SA_state = STATE(SA_Waiting);
}

STATE_fn(SA_Waiting)
{
	// state name
	SA_state = SA_Waiting;

	// state action

	// state transition
	p2SA_state = STATE(SA_Waiting);
}

STATE_fn(SA_Check)
{
	// state name
	SA_state = SA_Check;

	// state action
	if(pVal >= pThreshold)
	{
		MA_high_pressure();
	}

	// state transition
	p2SA_state = STATE(SA_Waiting);
}
