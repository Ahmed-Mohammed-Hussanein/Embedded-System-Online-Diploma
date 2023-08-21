/*
 * US.c
 *
 *  Created on: Aug 14, 2023
 *      Author: Ahmed
 */

#include <stdio.h>
#include <stdlib.h>

#include "US.h"

static int US_distance = 0;
void (*p2US_state)(void);

eUS_StateId_t US_state;

void US_Init(void)
{
	// state name
	US_state = US_Busy;
	printf("US Init ......\n");

	// state transition
	p2US_state = STATE(US_Busy);
}


STATE_fn(US_Busy)
{
	// state name
	US_state = US_Busy;

	// state action
	US_distance = (rand() % (100 - 0 + 1)) + 0;
	US_send_distance(&US_distance);

	// state transition
	p2US_state = STATE(US_Busy);

	printf("US_Busy state: US_distance = %d.\n", US_distance);
}
