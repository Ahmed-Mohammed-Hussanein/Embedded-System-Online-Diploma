/*
	Author : Ahmed Mohammed
	Purpose: Adding two Complex Numbers.
*/
#include <stdio.h>
#include <stdlib.h>

struct SComplex
{
	float m_Real;
	float m_Imaginary;
};

struct SComplex readComplex(unsigned char number)
{
	struct SComplex READComplex;

	(number == 1) ? printf("For 1st complex number\n") : 
	printf("for 2nd complex number\n");

	printf("Enter real and imaginary respectively: ");
	scanf("%f %f", &READComplex.m_Real, &READComplex.m_Imaginary);

	return READComplex;	
}

struct SComplex addComplex(struct SComplex A, struct SComplex B)
{
	struct SComplex C;

	C.m_Real = A.m_Real + B.m_Real;
	C.m_Imaginary = (A.m_Imaginary + B.m_Imaginary);

	return C;
}

int main()
{
	struct SComplex Complex1, Complex2, Result;

	system("cls");
	Complex1 = readComplex(1);
	Complex2 = readComplex(2);

	Result = addComplex(Complex1, Complex2);

	printf("Sum = %.1f+%.1fi", Result.m_Real, Result.m_Imaginary);
	return 0;
}