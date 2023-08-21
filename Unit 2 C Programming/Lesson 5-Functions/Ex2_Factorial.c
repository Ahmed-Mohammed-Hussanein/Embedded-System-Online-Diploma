/*
 * Ex2.c
 *
 *  Created on: Aug 27, 2021
 *      Author: Ahmed
 */

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int Factorial(int n)
{
	if(n == 0 || n == 1)
		return 1;

	return n * Factorial(n-1);
}

int main()
{
	printf("Enter an positive integer: ");

	int n;

	fflush(stdout);
	scanf("%d", &n);

	if(n<0)
		return 0;

	printf("Factorial of %d = %d", n, Factorial(n));

	return 0;
}
