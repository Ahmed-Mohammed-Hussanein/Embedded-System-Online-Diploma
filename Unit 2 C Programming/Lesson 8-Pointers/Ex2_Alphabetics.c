/*
	Author : Ahmed Mohammed
	Purpose: Print all the alphabets using a pointer.
*/
#include <stdio.h>
#include <stdlib.h>

int main()
{
	char alpha = 'A';
	char* ptr2alpha = &alpha;

	system("cls");
	printf("The Alphabetic are:\n");
	while(*ptr2alpha <= 'Z')
	{
		printf("%c ", *ptr2alpha);
		(*ptr2alpha)++;
	}
	return 0;
}
