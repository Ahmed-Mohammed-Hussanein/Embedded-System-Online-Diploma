/*
 * Ex3.c
 *
 *  Created on: Aug 14, 2021
 *      Author: Ahmed
 */

#include <stdio.h>
#include <stdlib.h>

int main()
{
	int int1, int2;

	printf("Enter two integers: ");

	fflush(stdout);
	scanf("%d %d", &int1, &int2);

	printf("Sum: %d", int1 + int2);


	return 0;
}
