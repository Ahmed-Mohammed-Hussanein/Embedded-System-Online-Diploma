/*
 * Ex8.c
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

	printf("Enter the string  : ");

	fflush(stdout);
	gets(arr);

	printf("Reverse string is : ");

	int i;
	for(i=strlen(arr)-1; i>=0; i--)
	{
		printf("%c", arr[i]);

	}

	return 0;
}
