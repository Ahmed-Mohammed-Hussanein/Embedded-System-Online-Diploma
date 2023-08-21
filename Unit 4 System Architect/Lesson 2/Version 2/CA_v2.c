/*
 * CA_v1.c
 *
 *  Created on: Aug 14, 2023
 *      Author: Ahmed
 */

#include <stdio.h>
#include <stdlib.h>

#include "CA_v2.h"

static int CA_distance = 0;
static int CA_threshold = 50;
static int CA_speed = 0;

void (*p2CA_state)(void);

eCA_StateId_t CA_state;

void US_send_distance(int *p2Distance)
{
	CA_distance = *p2Distance;
	printf("US_send_distance: distance = %d.\n", *p2Distance);
}

void CA_Init(void)
{
	// state name
	CA_state = CA_Waiting;
	printf("CA Init: CA_Waiting ......\n");

	// state transition
	p2CA_state = STATE(CA_Waiting);
}

STATE_fn(CA_Waiting)
{
	// state name
	CA_state = CA_Waiting;

	// state action
	CA_speed = 0;
	DC_get_speed(&CA_speed);

	// state transition
	p2CA_state = CA_distance > CA_threshold ? STATE(CA_Driving) : STATE(CA_Waiting);

	printf("CA_Waiting State: speed = %d, distance = %d.\n", CA_speed, CA_distance);
}

STATE_fn(CA_Driving)
{
	// state name
	CA_state = CA_Driving;

	// state action
	CA_speed = 30;
	DC_get_speed(&CA_speed);

	// state transition
	p2CA_state = CA_distance > CA_threshold ? STATE(CA_Driving) : STATE(CA_Waiting);

	printf("CA_Driving State: speed = %d, distance = %d.\n", CA_speed, CA_distance);
}
