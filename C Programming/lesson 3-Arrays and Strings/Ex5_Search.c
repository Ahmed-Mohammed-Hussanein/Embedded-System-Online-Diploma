/*
 * Ex5.c
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
	int element;

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

	printf("Enter the element to be searched : ");

	fflush(stdout);
	scanf("%d", &element);

	for(i=0; i<n; i++)
	{
		if(arr[i] == element)
			break;
	}

	printf("Number found at location = %d", i+1);

	return 0;
}
