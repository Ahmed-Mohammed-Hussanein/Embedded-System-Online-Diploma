/*
 * Ex4.c
 *
 *  Created on: Aug 14, 2021
 *      Author: Ahmed
 */

#include <stdio.h>
#include <stdlib.h>

int main()
{
	float float1, float2;

	printf("Enter two integers: ");

	fflush(stdout);
	scanf("%f %f", &float1, &float2);

	printf("Product: %f", float1 * float2);

	return 0;
}
