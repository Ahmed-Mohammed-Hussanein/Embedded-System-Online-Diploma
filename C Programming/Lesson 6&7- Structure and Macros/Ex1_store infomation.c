/*
	Author : Ahmed Mohammed
	Purpose: get information from user to structure and displaying it.
*/
#include <stdio.h>
#include <stdlib.h>

struct SStudent 
{
	char m_Name[32];
	int m_Roll;
	float m_Marks;
};

struct SStudent readStudent()
{
	struct SStudent READStudent;

	printf("\nEnter information of student:\n");

	printf("Enter name: ");
	gets(READStudent.m_Name);

	printf("Enter roll number: ");
	scanf("%d", &READStudent.m_Roll);

	printf("Enter marks: ");
	scanf("%f", &READStudent.m_Marks);

	return READStudent;
}

void printStudent(struct SStudent PRINTStudent)
{
	printf("\nDisplaying Information\n");
	printf("name: %s\n", PRINTStudent.m_Name);	
	printf("Roll Number: %d\n", PRINTStudent.m_Roll);	
	printf("Marks: %f\n", PRINTStudent.m_Marks);
}

int main()
{
	struct SStudent MAINStudent;

	system("cls");

	MAINStudent = readStudent();

	printStudent(MAINStudent);

	return 0;
}