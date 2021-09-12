/*
 * Ex3.c
 *
 *  Created on: Aug 27, 2021
 *      Author: Ahmed
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void reverse(char* ptr)
{
	if(0 != *ptr)
		reverse(ptr+1);
	else
		return;

	printf("%c", *ptr);
}

int main()
{
	char sen[32];

	printf("Enter a sentence: ");

	fflush(stdout);
	fgets(sen, 32, stdin);

	reverse(sen);

	return 0;
}
