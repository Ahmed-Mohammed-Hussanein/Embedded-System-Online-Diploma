/*
 * Ex7.c
 *
 *  Created on: Aug 23, 2021
 *      Author: Ahmed
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	char arr[64];

	printf("Enter a string: ");

	fflush(stdout);
	gets(arr);

	int len;
	for(len=0; arr[len] != '\0'; len++);

	printf("Length of string: %d", len);

	return 0;
}
