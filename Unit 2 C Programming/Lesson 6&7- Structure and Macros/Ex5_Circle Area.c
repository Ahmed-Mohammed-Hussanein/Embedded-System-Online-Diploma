/*
	Author : Ahmed Mohammed
	Purpose: get the radius of the circle and print the area.
*/
#include <stdio.h>
#include <stdlib.h>

#define Pi 3.14159

#define GET_AREA(r) Pi*r*r

int main()
{
	double radius;
	system("cls");
	printf("Enter the radius: ");
	scanf("%lf", &radius);
	printf("Area = %.2lf", GET_AREA(radius));

	return 0;
}