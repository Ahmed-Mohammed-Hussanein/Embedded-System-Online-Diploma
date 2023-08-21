/*
 * main.c
 *
 *  Created on: Aug 11, 2023
 *      Author: Ahmed
 */

#include <stdio.h>
#include <stdlib.h>

#include "CA_v1.h"

void wait(int n)
{
	int i, j;
	for(i = 0; i < n; i++)
	{
		for(j = 0; j < 100000; j++);
	}
}

void setup()
{
	// init all drivers
	// init IRQ
	// init HAL US_driver and DC_driver
	// init BLOCK
	// set states pointers for each block
	p2CA_state = STATE(CA_Waiting);
}

int main()
{
	setup();

	while(1)
	{
		p2CA_state();

		wait(1000);
	}

	return 0;
}
