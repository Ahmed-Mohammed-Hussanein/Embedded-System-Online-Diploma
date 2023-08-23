

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Platform_Types.h"
#include "FIFO.h"
#include "student_management.h"
#include "GUI.h"

FIFO_t dataBase;

static void print_data(sStudent_Data_t *xStudent)
{
	printf("Student Roll ID: %hu\n", xStudent->Roll_Id);
	printf("Student Name: %s %s\n", xStudent->FirstName, xStudent->LastName);
	printf("Student GPA: %f\n", xStudent->GPA);
	
	uint8_t i;
	for(i = 0; i < 5; ++i)
	{
		printf("Student Course %u ID: %hu\n", i+1, xStudent->CourseId[i]);
	}

	print_line();
}

static sint32_t search(sStudent_Data_t xStudent[], uint32_t length, uint16_t key)
{
	uint32_t i;
	for(i = 0; i < length; ++i)
	{
		if(xStudent[i].Roll_Id == key)
		{
			return i;
		}
	}

	return -1;
}

static void get_data_from_file(FILE *p2File)
{
	sStudent_Data_t newStudent;
	sint32_t isExist;

	printf("Reading Data from Text File.\n\n");

	while(!feof(p2File))
	{	
	fscanf(p2File, "%u %s %s %f %hu %hu %hu %hu %hu", &newStudent.Roll_Id, newStudent.FirstName, newStudent.LastName,
		&newStudent.GPA, &newStudent.CourseId[0], &newStudent.CourseId[1], &newStudent.CourseId[2], &newStudent.CourseId[3],
		&newStudent.CourseId[4]
		);

	isExist = search(dataBase.base, dataBase.count, newStudent.Roll_Id);
	if(isExist != -1)
	{
		printf("This ID %u is already in use.\n", newStudent.Roll_Id);
		print_line();
		continue;
	}
	
	print_data(&newStudent);
	FIFO_Enqueue(&dataBase, &newStudent);
	}
}

static void get_data_from_sdin(sStudent_Data_t *xStudent, uint8_t updateFlag)
{
	uint8_t temp[32];

	printf("Enter Student Roll ID: ");

	fflush(stdin), fflush(stdout);
	fgets(temp, 32, stdin);
	xStudent->Roll_Id = atoi(temp);

	sint32_t isExist = search(dataBase.base, dataBase.count, xStudent->Roll_Id);

	while(isExist != -1)
	{
		printf("ID %u is already exist.\n", xStudent->Roll_Id);
		printf("Enter Another Roll ID: ");

		fflush(stdin), fflush(stdout);
		fgets(temp, 32, stdin);
		xStudent->Roll_Id = atoi(temp);

		isExist = search(dataBase.base, dataBase.count, xStudent->Roll_Id);
	}

	printf("Enter Student First Name: ");
	
	fflush(stdin), fflush(stdout);
	scanf("%s", xStudent->FirstName);

	printf("Enter Student Last Name: ");
	
	fflush(stdin), fflush(stdout);
	scanf("%s", xStudent->LastName);

	printf("Enter Student GPA: ");

	fflush(stdin), fflush(stdout);
	fgets(temp, 32, stdin);
	xStudent->GPA = atof(temp);

	uint8_t i;
	for(i = 0; i < 5; ++i)
	{
		printf("Enter Student Course %u ID: ", i+1);

		fflush(stdin), fflush(stdout);
		fgets(temp, 32, stdin);
		xStudent->CourseId[i] = atoi(temp);
	}
}

static void shift_left(sStudent_Data_t *xBuffer, uint32_t index)
{
	uint32_t i;
	for(i = index; i < dataBase.count - 1; ++i)
	{
		xBuffer[i] = xBuffer[i+1];
	}

	dataBase.head--;
	dataBase.count--;
}

eStatus_t DB_Init(uint32_t initSize)
{
	element_type *p2Buffer = (element_type*)malloc(initSize * sizeof(element_type));

	FIFO_STATUS status = FIFO_Init(&dataBase, p2Buffer, initSize);

	if(status == FIFO_no_errors)
	{
		return DB_OK;
	}

	return DB_NOK;
}


eStatus_t DB_Add(FILE *p2File)
{
	FIFO_STATUS status = FIFO_Is_full(&dataBase);

	if(status == FIFO_null || p2File == NULL)
		return DB_NOK;

	if(status == FIFO_full)
		return DB_FULL;

	if(p2File == stdin)
	{
		sStudent_Data_t newStudent;
		get_data_from_sdin(&newStudent, 0);

		FIFO_Enqueue(&dataBase, &newStudent);
	}
	else
	{
		get_data_from_file(p2File);
	}

	return DB_OK;
}

eStatus_t DB_updateStudent(uint32_t rollNumber)
{
	FIFO_STATUS status = FIFO_Is_empty(&dataBase);
	if(status == FIFO_null)
		return DB_NOK;

	else if(status == FIFO_empty)
		return DB_EMPTY;

	sStudent_Data_t tempStudent;

	uint32_t i;
	for(i = 0; i < dataBase.count; ++i)
	{
		if(dataBase.base[i].Roll_Id == rollNumber)
		{
			print_data(&dataBase.base[i]);
			memset(&dataBase.base[i], 0, sizeof(sStudent_Data_t));
			get_data_from_sdin(&tempStudent, 1);
			dataBase.base[i] = tempStudent;
			return DB_OK;
		}
	}

	return DB_NOT_FOUND;
}

eStatus_t DB_deleteStudent(uint32_t rollNumber)
{
	FIFO_STATUS status = FIFO_Is_empty(&dataBase);
	if(status == FIFO_null)
		return DB_NOK;

	else if(status == FIFO_empty)
		return DB_EMPTY;

	uint32_t i;
	for(i = 0; i < dataBase.count; ++i)
	{
		if(dataBase.base[i].Roll_Id == rollNumber)
		{
			print_data(&dataBase.base[i]);
			shift_left(&dataBase.base[0], i);
			return DB_OK;
		}
	}

	return DB_NOT_FOUND;
}

eStatus_t DB_Find_rollNumber(uint32_t rollNumber)
{
	FIFO_STATUS status = FIFO_Is_empty(&dataBase);
	if(status == FIFO_null)
		return DB_NOK;

	else if(status == FIFO_empty)
		return DB_EMPTY;

	uint32_t i;
	for(i = 0; i < dataBase.count; ++i)
	{
		if(dataBase.base[i].Roll_Id == rollNumber)
		{
			print_data(&dataBase.base[i]);
			return DB_OK;
		}
	}

	
	return DB_NOT_FOUND;
}

eStatus_t DB_Find_fName(uint8_t fname[])
{
	FIFO_STATUS status = FIFO_Is_empty(&dataBase);
	if(status == FIFO_null)
		return DB_NOK;

	else if(status == FIFO_empty)
		return DB_EMPTY;

	uint8_t flag = 0;
	uint32_t i;
	for(i = 0; i < dataBase.count; ++i)
	{
		if(!strcmp(dataBase.base[i].FirstName, fname))
		{
			flag = 1;
			print_data(&dataBase.base[i]);
		}
	}

	if(flag == 1)
		return DB_OK;
	
	return DB_NOT_FOUND;
}

eStatus_t DB_Find_courseID(uint32_t courseID)
{
	FIFO_STATUS status = FIFO_Is_empty(&dataBase);
	if(status == FIFO_null)
		return DB_NOK;

	else if(status == FIFO_empty)
		return DB_EMPTY;

	uint8_t flag = 0;

	uint32_t i, j;
	for(i = 0; i < dataBase.count; ++i)
	{
		for(j = 0; j < 5; ++j)
		{
			if(dataBase.base[i].CourseId[j] == courseID)
			{
				print_data(&dataBase.base[i]);
				flag = 1;
			}
		}
	}

	if(flag == 0)
		return DB_NOT_FOUND;

	return DB_OK;
}

eStatus_t DB_totalNumberOfStudents(uint32_t *tNumber)
{
	FIFO_STATUS status = FIFO_Is_empty(&dataBase);
	if(status == FIFO_null)
		return DB_NOK;

	else if(status == FIFO_empty)
		return DB_EMPTY;

	*tNumber = dataBase.count;
	return DB_OK;
}

eStatus_t DB_showAll()
{
	FIFO_STATUS status = FIFO_Is_empty(&dataBase);
	if(status == FIFO_null)
		return DB_NOK;

	else if(status == FIFO_empty)
		return DB_EMPTY;

	uint32_t i;
	for(i = 0; i < dataBase.count; ++i)
	{
		print_data(&dataBase.base[i]);
	}

	return DB_OK;
}

void delete_database()
{
	free(dataBase.base);
}