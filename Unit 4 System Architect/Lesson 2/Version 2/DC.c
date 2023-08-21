/*
 * DC.c
 *
 *  Created on: Aug 14, 2023
 *      Author: Ahmed
 */


#include <stdio.h>
#include <stdlib.h>

#include "DC.h"

static int DC_speed = 0;

void (*p2DC_state)(void);

eDC_StateID_t DC_state;

void DC_get_speed(int *p2Speed)
{
	if(*p2Speed != DC_speed)
	{
		DC_speed = *p2Speed;
		DC_state = DC_Busy;
		p2DC_state = STATE(DC_Busy);
	}


	printf("DC_get_speed: speed = %d.\n", DC_speed);
}

void DC_Init(void)
{
	// state name
	DC_state = DC_Idle;
	printf("DC Init: DC_Idle ......\n");

	// state transition
	p2DC_state = STATE(DC_Idle);
}

STATE_fn(DC_Idle)
{
	// state name
	DC_state = DC_Idle;

	// state action

	// state transition
	p2DC_state = STATE(DC_Idle);

	printf("DC_Idle State: speed = %d\n", DC_speed);
}

STATE_fn(DC_Busy)
{
	// state name
	DC_state = DC_Busy;

	// state action

	// state transition
	DC_state = DC_Idle;
	p2DC_state = STATE(DC_Idle);

	printf("DC_Busy State: speed = %d\n", DC_speed);
}
