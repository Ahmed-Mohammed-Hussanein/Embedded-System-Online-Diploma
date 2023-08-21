/*
 * Ex7.c
 *
 *  Created on: Aug 14, 2021
 *      Author: Ahmed
 */

#include <stdlib.h>
#include <stdio.h>

int main()
{
	int n, factorial = 1;

	printf("Enter an integer: ");

	fflush(stdout);
	scanf("%d", &n);

	if(n > 0)
	{
		int i;
		for(i=1; i < n+1; i++)
			factorial *= i;

		printf("Factorial = %d", factorial);
	}

	else
		printf("Error!!! Factorial of negative number doesn't exist.");

	return 0;
}
