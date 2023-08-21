/*
	Author : Ahmed Mohammed
	Purpose: Print a string in reverse using a pointer.
*/
#include <stdio.h>
#include <stdlib.h>

struct SEmployee
{
	char m_name[32];
	int m_ID;
};

int main()
{
	struct SEmployee emp1 = {"Alex", 1002}, emp2 = {"Jerry", 1003};
	struct SEmployee (*arr[2]) ;
	struct SEmployee *(*ptr2arr)[2] = &arr;
	arr[0] = &emp1;
	arr[1] = &emp2;

	system("cls");
	printf("Employee (1) Name: %s\n", (**ptr2arr)->m_name);
	printf("Employee (1) ID: %d\n", (**ptr2arr)->m_ID);

	printf("Employee (2) Name: %s\n", (*((*ptr2arr)+1))->m_name);
	printf("Employee (2) ID: %d\n", (*((*ptr2arr)+1))->m_ID);

	return 0;
}