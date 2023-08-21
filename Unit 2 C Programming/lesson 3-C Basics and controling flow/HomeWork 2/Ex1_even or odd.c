/*
 * Ex1.c
 *
 *  Created on: Aug 14, 2021
 *      Author: Ahmed
 */

#include <stdlib.h>
#include <stdio.h>

int main()
{
	int num;

	printf("Enter an integer you want to check: ");

	fflush(stdout);
	scanf("%d", &num);

	printf("%d is %s.", num, (num%2)?"odd":"even");

	return 0;
}
