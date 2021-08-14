/*
 * Ex4.c
 *
 *  Created on: Aug 14, 2021
 *      Author: Ahmed
 */

#include <stdlib.h>
#include <stdio.h>

int main()
{
	float num1;

	printf("Enter a number: ");

	fflush(stdout);
	scanf("%f", &num1);

	if(num1 > 0)
		printf("%.2f is positive.", num1);

	else if(num1 < 0)
		printf("%.2f is negative.", num1);

	else
		printf("You entered zero.");

	return 0;
}
