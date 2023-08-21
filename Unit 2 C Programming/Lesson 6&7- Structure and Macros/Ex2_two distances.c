/*
	Author : Ahmed Mohammed
	Purpose: Adding two distances in foot and inch.
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct SDistance
{
	int m_Feet;
	float m_Inch;
};

struct SDistance readDistance(unsigned char number)
{
	struct SDistance READDistance;

	(number == 1) ? printf("Enter information for 1st distance\n") : 
	printf("Enter information for 2nd distance\n");

	printf("Enter feet: ");
	scanf("%d", &READDistance.m_Feet);

	printf("Enter inch: ");
	scanf("%f", &READDistance.m_Inch);

	return READDistance;	
}

struct SDistance addDistance(struct SDistance A, struct SDistance B)
{
	struct SDistance C;

	C.m_Feet = A.m_Feet + B.m_Feet + (A.m_Inch + B.m_Inch)/12;
	C.m_Inch = fmod((A.m_Inch + B.m_Inch),12);

	return C;
}

int main()
{
	struct SDistance distance1, distance2, Result;

	system("cls");
	distance1 = readDistance(1);
	distance2 = readDistance(2);

	Result = addDistance(distance1, distance2);

	printf("Sum of distances = %d'-%.1f\"", Result.m_Feet, Result.m_Inch);
	return 0;
}