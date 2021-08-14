/*
 * Ex8.c
 *
 *  Created on: Aug 14, 2021
 *      Author: Ahmed
 */

#include <stdlib.h>
#include <stdio.h>

int main()
{
	char operator;
	float operand1, operand2;

	printf("Enter operator either + or - or * or divide : ");

	fflush(stdout);
	scanf("%c", &operator);

	printf("Enter two operands: ");

	fflush(stdout);
	scanf("%f %f", &operand1, &operand2);

	switch(operator)
	{
	case '+':
		printf("%.1f + %.1f = %.1f", operand1, operand2, operand1 + operand2);
		break;

	case '-':
		printf("%.1f - %.1f = %.1f", operand1, operand2, operand1 - operand2);
		break;

	case '*':
		printf("%.1f * %.1f = %.1f", operand1, operand2, operand1 * operand2);
		break;

	case 'd':
		printf("%.1f / %.1f = %.1f", operand1, operand2, operand1 / operand2);
		break;
	}
	return 0;
}
