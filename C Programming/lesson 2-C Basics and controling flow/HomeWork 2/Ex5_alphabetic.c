/*
 * Ex5.c
 *
 *  Created on: Aug 14, 2021
 *      Author: Ahmed
 */

#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

int main()
{
	char c;

	printf("Enter a character: ");

	fflush(stdout);
	scanf("%c", &c);

	printf("%c is%s an alphabet", c, (isalpha(c)) ? "" : " not");

	return 0;
}
