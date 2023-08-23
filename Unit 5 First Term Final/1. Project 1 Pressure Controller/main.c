#include "PressureSensor.h"
#include "system_algorithm.h"
#include "monitor_alarm.h"
#include "AlarmActuator.h"

#include "driver.h"


void setup(void)
{
	// Init Hardware
	GPIO_INITIALIZATION();

	// Init states
	PS_Init();
	SA_Init();
	MA_Init();
	AA_Init();

}

int main ()
{	
	setup();

	while (1)
	{
		//Implement your Design
		p2PS_state();
		p2SA_state();
		p2MA_state();
		p2AA_state();


	}

}
