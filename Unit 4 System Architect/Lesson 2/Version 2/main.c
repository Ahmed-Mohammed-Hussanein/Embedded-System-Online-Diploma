/*
 * main.c
 *
 *  Created on: Aug 14, 2023
 *      Author: Ahmed
 */

#include <stdio.h>
#include <stdlib.h>

#include "US.h"
#include "CA_v2.h"
#include "DC.h"

void wait(int n)
{
	int i, j;
	for(i = 0; i < n; i++)
	{
		for(j = 0; j < 100000; j++);
	}
}

void setup(void)
{
	// init all drivers
	// init IRQ
	// init HAL US_driver and DC_driver
	// init BLOCK
	// set states pointers for each block
	US_Init();
	CA_Init();
	DC_Init();
}

int main()
{
	setup();

	while(1)
	{
		p2US_state();
		p2CA_state();
		p2DC_state();

		wait(1000);
	}

	return 0;
}
