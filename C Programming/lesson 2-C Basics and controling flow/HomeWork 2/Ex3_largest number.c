/*
 * Ex3.c
 *
 *  Created on: Aug 14, 2021
 *      Author: Ahmed
 */

#include <stdlib.h>
#include <stdio.h>

int main()
{
	float num1, num2, num3;

	printf("Enter three numbers: ");

	fflush(stdout);
	scanf("%f %f %f", &num1, &num2, &num3);

	float max = (num1 > num2) ? num1 : num2;
	max = (max > num1) ? max : num1;
	max = (max > num2) ? max : num2;

	printf("Largest number = %.2f", max);

	return 0;
}
