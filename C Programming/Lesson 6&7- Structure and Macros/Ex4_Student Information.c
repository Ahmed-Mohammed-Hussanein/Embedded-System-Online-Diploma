/*
	Author : Ahmed Mohammed
	Purpose: get student information from user to structure and displaying it.
*/
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct SStudent 
{
	char m_Name[32];
	unsigned int m_Roll;
	float m_Marks;
};

struct SStudent readStudent(unsigned char rollNumber)
{
	struct SStudent READStudent;

	printf("\n\nFor roll number %u\n", rollNumber);
	printf("Enter name: ");
	fflush(stdin);
	gets(READStudent.m_Name);
	READStudent.m_Roll = rollNumber;
	printf("Enter marks: ");
	scanf("%f", &READStudent.m_Marks);

	return READStudent;
}

void printStudent(struct SStudent PRINTStudent)
{
	printf("Information for roll number %u:\n", PRINTStudent.m_Roll);
	printf("Name: %s\n", PRINTStudent.m_Name);		
	printf("Marks: %f\n\n", PRINTStudent.m_Marks);
}

int main()
{
	struct SStudent MAINStudent[10];
	int currentNumber = 0, i = 0;
	system("cls");
	printf("\n\nEnter information of students:");
	do
	{
		MAINStudent[currentNumber] = readStudent(currentNumber);
		++currentNumber;
		printf("Do you want to enter another student(y/n):");
	}while(currentNumber <=10 && getch() == 'y');
	printf("\n\nDisplaying information of students:\n\n");
	for(; i < currentNumber; ++i)
	{
		printStudent(MAINStudent[i]);
	}
	return 0;
}