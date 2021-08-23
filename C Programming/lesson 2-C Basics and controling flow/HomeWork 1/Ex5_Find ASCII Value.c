/*
 * Ex5.c
 *
 *  Created on: Aug 14, 2021
 *      Author: Ahmed
 */

#include <stdio.h>
#include <stdlib.h>

int main()
{
	char c;

	printf("Enter a character: ");

	fflush(stdout);
	scanf("%c", &c);

	printf("ASCII value of %c = %d", c, c);

	return 0;
}
