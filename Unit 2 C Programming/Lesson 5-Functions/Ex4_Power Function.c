/*
 * Ex4.c
 *
 *  Created on: Aug 27, 2021
 *      Author: Ahmed
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int Power(int base, int power)
{
	if(power == 0)
		return 1;

	return base * Power(base, power-1);
}

int main()
{
	int base, power;

	printf("Enter base number: ");

	fflush(stdout);
	scanf("%d", &base);

	printf("Enter power number(positive integer): ");

	fflush(stdout);
	scanf("%d", &power);

	if(power < 0)
		return 0;

	printf("%d^%d = %d", base, power, Power(base, power));

	return 0;
}
