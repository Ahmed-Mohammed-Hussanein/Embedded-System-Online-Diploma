/*
 * Ex2.c
 *
 *  Created on: Aug 23, 2021
 *      Author: Ahmed
 */

#include <stdio.h>
#include <stdlib.h>

int main()
{
	int n;
	float data[10];

	printf("Enter the number of data: ");

	fflush(stdout);
	scanf("%d", &n);

	int i;
	for(i=0; i<n && n<=10; i++)
	{
		printf("%d.Enter number: ", i+1);
		fflush(stdout);
		scanf("%f", &data[i]);
	}

	float sum = 0;
	for(i=0; i<n && n<=10; i++)
	{
		sum += data[i];
	}

	if(n>0 && n<10)
		printf("Average = %.2f", sum/n);

	return 0;
}
