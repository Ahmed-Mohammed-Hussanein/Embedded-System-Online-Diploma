/*
	Author : Ahmed Mohammed
	Purpose: How to handle the pointers in the program.
*/
#include <stdio.h>
#include <stdlib.h>

#define GET_STRING(a) #a

int main()
{
	system("cls");
	int m = 29;
	printf("Address of %s : 0x%p\n", GET_STRING(m), &m);
	printf("Value of %s : %d\n\n", GET_STRING(m), m);

	int *ab = &m;
	printf("Now %s is assigned with the Address of %s.\n", GET_STRING(ab), GET_STRING(m));
	printf("Address of pointer %s : 0x%p\n", GET_STRING(ab), &ab);
	printf("Content of pointer %s : %d\n\n", GET_STRING(ab), *ab);

	m = 34;
	printf("The value of %s assigned to %d now.\n", GET_STRING(m), m);
	printf("Address of pointer %s : 0x%p\n", GET_STRING(ab), &ab);
	printf("Content of pointer %s : %d\n\n", GET_STRING(ab), *ab);

	*ab = 7;
	printf("The pointer variable %s is assigned with the value %d now.\n", GET_STRING(ab), *ab);
	printf("Address of %s : 0x%p\n", GET_STRING(m), &m);
	printf("Value of %s : %d\n\n", GET_STRING(m), m);
	return 0;
}