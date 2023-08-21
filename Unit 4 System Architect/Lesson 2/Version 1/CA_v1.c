/*
 * CA_v0.c
 *
 *  Created on: Aug 14, 2023
 *      Author: Ahmed
 */

#include <stdio.h>
#include <stdlib.h>

#include "CA_v1.h"
#include "state.h"

static int CA_distance = 0;
static int CA_threshold = 50;
static int CA_speed = 0;

eCA_State_t CA_StateId;

void (*p2CA_state) (void);


STATE_FN(CA_Waiting)
{
	// set state id
	CA_StateId = CA_Waiting;

	// set CA_speed
	CA_speed = 0;

	// get CA_distance from US
	CA_distance = (rand() % (100 - 0 + 1)) + 0;

	// check the condition
	p2CA_state = CA_distance > CA_threshold ? STATE(CA_Driving) : STATE(CA_Waiting);


	printf("CA_Waiting State: speed = %d , distance = %d.\n", CA_speed, CA_distance);

}

STATE_FN(CA_Driving)
{
	// set state id
	CA_StateId = CA_Driving;

	// set CA_speed
	CA_speed = 50;

	// get CA_distance from US
	CA_distance = (rand() % (100 - 0 + 1)) + 0;

	// check the condition
	p2CA_state = CA_distance > CA_threshold ? STATE(CA_Driving) : STATE(CA_Waiting);

	printf("CA_Driving State: speed = %d, distance = %d.\n", CA_speed, CA_distance);
}
