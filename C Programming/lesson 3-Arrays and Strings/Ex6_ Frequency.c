/*
 * Ex6.c
 *
 *  Created on: Aug 23, 2021
 *      Author: Ahmed
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	char arr[32];
	char element;

	printf("Enter a string: ");

	fflush(stdout);
	gets(arr);

	printf("Enter a character to find frequency: ");

	fflush(stdout);
	scanf("%c", &element);

	int i, count = 0;
	for(i=0; i<strlen(arr); i++)
	{
		if(arr[i] == element)
			count++;
	}

	printf("Frequency of %c: %d", element, count);

	return 0;
}
