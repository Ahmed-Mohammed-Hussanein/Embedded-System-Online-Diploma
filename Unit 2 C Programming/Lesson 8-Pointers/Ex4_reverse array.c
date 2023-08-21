/*
	Author : Ahmed Mohammed
	Purpose: Print an array in reverse using a pointer.
*/
#include <stdio.h>
#include <stdlib.h>

int main()
{
	int numberOfelement, i;
	int arr[15];
	int* ptr2arr = arr;

	system("cls");
	printf("Enter the number of element to store data (max 15): ");
	scanf("%d", &numberOfelement);

	if(numberOfelement > 15)
		return 1;

	printf("Enter %d number of element in the array:\n", numberOfelement);
	for (i = 0; i < numberOfelement; ++i)
	{
		printf("element - %d: ", i+1);
		scanf("%d", ptr2arr);
		++ptr2arr;
	}

	puts("\nThe element of array in reverse order are :");
	for (--ptr2arr,i = numberOfelement - 1; i > -1; --i, --ptr2arr)
	{
		printf("element - %d: %d\n", i+1, *ptr2arr);
	}
	return 0;
}

