/*
	Author : Ahmed Mohammed
	Purpose: Print a string in reverse using a pointer.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	char str[32];
	char* ptr2str = str;
	int i, len;

	system("cls");
	printf("Enter a String to be reversed: ");
	scanf("%s", str);

	len = strlen(str);
	ptr2str += len;

	printf("The reversed string: ");
	for(i = 0; i <= len; ++i)
		printf("%c", *ptr2str--);

	return 0;
}