/*
 * Ex7.c
 *
 *  Created on: Aug 14, 2021
 *      Author: Ahmed
 */

#include <stdio.h>
#include <stdlib.h>

int main()
{
	float a, b;

	printf("Enter value of a: ");

	fflush(stdout);
	scanf("%f", &a);

	printf("Enter value of b: ");

	fflush(stdout);
	scanf("%f", &b);

	a = a + b;
	b = a - b;
	a = a - b;

	printf("\nAfter swapping, value of a = %.2f", a);
	printf("\nAfter swapping, value of b = %.2f", b);

	return 0;
}
