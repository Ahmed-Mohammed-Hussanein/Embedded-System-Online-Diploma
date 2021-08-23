/*
 * Ex1.c
 *
 *  Created on: Aug 23, 2021
 *      Author: Ahmed
 */

#include <stdio.h>
#include <stdlib.h>

int main()
{
	float a[2][2];
	float b[2][2];

	printf("Enter the elements of the 1st matrix\n");

	int i,j;
	for(i=0; i < 2; i++)
	{
		for(j=0; j < 2; j++)
		{
			printf("Enter a%d%d: ", i+1, j+1);
			fflush(stdout);
			scanf("%f", &a[i][j]);
		}
	}

	printf("Enter the elements of the 2nd matrix\n");

	for(i=0; i < 2; i++)
	{
		for(j=0; j < 2; j++)
		{
			printf("Enter b%d%d: ", i+1, j+1);
			fflush(stdout);
			scanf("%f", &b[i][j]);
		}
	}

	printf("\nSum Of Matrix:\n");

	for(i=0; i < 2; i++)
	{
		for(j=0; j < 2; j++)
		{
			printf("%.1f  ", a[i][j]+b[i][j]);
		}
		printf("\n");
	}

	return 0;
}
