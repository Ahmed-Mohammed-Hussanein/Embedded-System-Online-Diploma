/*
 * Ex6.c
 *
 *  Created on: Aug 14, 2021
 *      Author: Ahmed
 */

#include <stdlib.h>
#include <stdio.h>

int main()
{
	int n, sum = 0;

	printf("Enter an integer: ");

	fflush(stdout);
	scanf("%d", &n);

	int i;
	for(i=1; i < n+1; i++)
		sum += i;

	printf("Sum = %d", sum);

	return 0;
}
