/*
 * Ex4.c
 *
 *  Created on: Aug 23, 2021
 *      Author: Ahmed
 */

#include <stdio.h>
#include <stdlib.h>

int main()
{
	int n;
	int arr[10];
	int element, location;

	printf("Enter no of elements : ");

	fflush(stdout);
	scanf("%d", &n);

	if(n<0 || n>10)
		return 0;

	int i;
	for(i=0; i<n; i++)
	{
		scanf("%d", &arr[i]);
	}

	if(n == 10)
		return 0;

	printf("Enter the element to be inserted : ");

	fflush(stdout);
	scanf("%d", &element);

	printf("Enter the location : ");

	fflush(stdout);
	scanf("%d", &location), location--;

	if(location > 10 || location < 0 || location > n+1)
		return 0;

	if(location == n)
	{
		arr[location] = element, n++;
		goto print;
	}

	i = n + 1 ;
	while(i--, i != location)
	{
		int temp = arr[i];
		arr[i] = arr[i-1];
		arr[i-1] = temp;
	}
	n++;
	arr[location] = element;

	print:
	for(i=0; i<n; i++)
	{
		printf("%d ", arr[i]);
	}

	return 0;
}
