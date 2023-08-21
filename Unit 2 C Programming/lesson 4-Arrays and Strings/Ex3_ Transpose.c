/*
 * Ex3.c
 *
 *  Created on: Aug 23, 2021
 *      Author: Ahmed
 */

#include <stdio.h>
#include <stdlib.h>

int main()
{
	int row, col;
	int matrix[10][10];

	printf("Enter row and column of matrix: ");

	fflush(stdout);
	scanf("%d %d", &row, &col);

	if(row>10 || row<0 || col>10 || col<0)
		return 0;

	printf("Enter elements of matrix:\n");

	int i,j;
	for(i=0; i<row; i++)
	{
		for(j=0; j<col; j++)
		{
			printf("Enter element a%d%d: ", i+1, j+1);

			fflush(stdout);
			scanf("%d", &matrix[i][j]);
		}
	}

	printf("Entered Matrix:\n");

	for(i=0; i<row; i++)
	{
		for(j=0; j<col; j++)
		{
			printf("%d ", matrix[i][j]);
		}
		printf("\n");
	}

	printf("Transpose of Matrix:\n");

	for(j=0; j<col; j++)
	{
		for(i=0; i<row; i++)
		{
			printf("%d ", matrix[i][j]);
		}
		printf("\n");
	}

	return 0;
}
