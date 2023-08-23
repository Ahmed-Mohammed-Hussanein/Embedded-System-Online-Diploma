

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>

#include "Platform_Types.h"
#include "student_management.h"
#include "GUI.h"

void welcome_message();
void choice();


void add_student_file();
void add_student_manually();
void find_rl();
void find_fn();
void find_c();
void tot_s();
void del_s();
void up_s();
void show_s();

int main()
{
	hide_cursor();
	welcome_message();

	eStatus_t status = DB_Init(50);

	if(status == DB_NOK)
		exit(0);


	choice();

	return 0;
}


void add_student_file()
{
	FILE *p2File;
	p2File = fopen("database.txt", "r");

	if(p2File == NULL)
		exit(0);

	eStatus_t status = DB_Add(p2File);
	fclose(p2File);

	if(status == DB_NOK)
		exit(0);

	if(status == DB_FULL)
		printf("Database is full.\n\n");
}

void add_student_manually()
{
	eStatus_t status = DB_Add(stdin);
	if(status == DB_NOK)
		printf("Error\n\n"),
		exit(0);

	if(status == DB_FULL)
		printf("Database is full.\n\n");
}

void find_rl()
{
	uint32_t rNumber;
	printf("Enter Student roll number: ");
	
	fflush(stdin), fflush(stdout);
	scanf("%u", &rNumber);

	eStatus_t status = DB_Find_rollNumber(rNumber);

	if(status == DB_NOK)
		exit(0);

	if(status == DB_EMPTY)
		printf("Database is empty.\n\n");

	if(status == DB_NOT_FOUND)
		printf("Student has roll number %u does not exist.\n\n", rNumber);
}

void find_fn()
{
	uint8_t fName[32];
	printf("Enter Student first name: ");

	fflush(stdin), fflush(stdout);
	scanf("%s", fName);

	eStatus_t status = DB_Find_fName(fName);

	if(status == DB_NOK)
		exit(0);

	if(status == DB_EMPTY)
		printf("Database is empty.\n\n");

	if(status == DB_NOT_FOUND)
		printf("Student has first name %s does not exist.\n\n", fName);
}

void find_c()
{
	uint32_t cID;
	printf("Enter Student course ID: ");

	fflush(stdin), fflush(stdout);
	scanf("%u", &cID);

	eStatus_t status = DB_Find_courseID(cID);

	if(status == DB_NOK)
		exit(0);

	if(status == DB_EMPTY)
		printf("Database is empty.\n\n");

	if(status == DB_NOT_FOUND)
		printf("Student has course ID %u does not exist.\n\n", cID);
}

void tot_s()
{
	uint32_t tNumber;

	eStatus_t status = DB_totalNumberOfStudents(&tNumber);
	if(status == DB_NOK)
		exit(0);

	if(status == DB_EMPTY)
	{
		printf("Database is empty.\n");
		return;
	}

	printf("The Total Number Of Students is %u.\n\n", tNumber);
}

void del_s()
{
	uint32_t rNumber;
	printf("Enter Student roll number: ");
	
	fflush(stdin), fflush(stdout);
	scanf("%u", &rNumber);

	eStatus_t status = DB_deleteStudent(rNumber);

	if(status == DB_NOK)
		exit(0);

	if(status == DB_EMPTY)
	{
		printf("Database is empty.\n\n");
		return;
	}

	if(status == DB_NOT_FOUND)
	{
		printf("Student has course ID %u does not exist.\n\n", rNumber);
		return;
	}

	printf("Student is deleted Successfully.\n\n");
}

void up_s()
{
	uint32_t rNumber;
	printf("Enter Student roll number: ");
	
	fflush(stdin), fflush(stdout);
	scanf("%u", &rNumber);

	eStatus_t status = DB_updateStudent(rNumber);

	if(status == DB_NOK)
		exit(0);

	if(status == DB_EMPTY)
	{
		printf("Database is empty.\n\n");
		return;
	}

	if(status == DB_NOT_FOUND)
	{
		printf("Student has course ID %u does not exist.\n\n", rNumber);
		return;
	}

	printf("Student is updated Successfully.\n\n");
}

void show_s()
{
	eStatus_t status = DB_showAll();

	if(status == DB_NOK)
		exit(0);

	if(status == DB_EMPTY)
		printf("Database is empty.\n\n");
}


void welcome_message()
{
    set_cursor_position(32, 8);
    print_line();

    set_cursor_position(32, 9), printf("Welcome to project * Student Database Based on Queue *");
    set_cursor_position(32, 11), printf("Author: Ahmed Mohammed Hussanein.");
    set_cursor_position(32, 13), printf("Under supervisor: Eng.Keroles Shenouda.");
    set_cursor_position(32, 15), printf("Press any key to continue...");

    set_cursor_position(32, 16);
    print_line();

    getch();
}


void choice( )
{
    uint8_t pointer = 1;
    uint8_t pressedKey = 0;

    while(1)
    {

        system("cls");
        hide_cursor();

        set_cursor_position(32, 8);
        print_line();

        set_cursor_position(32, 9);  point_here(pointer, 0);  printf("What do you want to do?");
        set_cursor_position(32, 10); point_here(pointer, 1);  printf("1. Add Student Details Manually.");
        set_cursor_position(32, 11); point_here(pointer, 2);  printf("2. Add Student Details From Text File.");
        set_cursor_position(32, 12); point_here(pointer, 3);  printf("3. Find Student Details by Roll Number.");
        set_cursor_position(32, 13); point_here(pointer, 4);  printf("4. Find Student Details by First Name.");
        set_cursor_position(32, 14); point_here(pointer, 5);  printf("5. Find Student Details by Course ID.");
        set_cursor_position(32, 15); point_here(pointer, 6);  printf("6. Find Total Number Of Students.");
        set_cursor_position(32, 16); point_here(pointer, 7);  printf("7. Delete Student Details by Roll Number.");
        set_cursor_position(32, 17); point_here(pointer, 8);  printf("8. Update Student Details by Roll Number.");
        set_cursor_position(32, 18); point_here(pointer, 9);  printf("9. Show all Information.");
        set_cursor_position(32, 19); point_here(pointer, 10); printf("10. Exit.");

        point_here(pointer, 0);
        set_cursor_position(32, 20);
        print_line();


        while(1)
        {
            pressedKey = getch();
            if(pressedKey == 72)
            {
                pointer--;
                if(pointer == 0)
                    pointer = 10;

                break;
            }
            else if(pressedKey == 80)
            {
                pointer++;
                if(pointer == 11)
                    pointer = 1;

                break;
            }
            else if(pressedKey == VK_RETURN)
            {
            	system("cls");
                show_cursor();

                switch(pointer)
                {
                case 1:
                    add_student_manually();
                    break;

                case 2:
                    add_student_file();
                    break;

                case 3:
                    find_rl();
                    break;

                case 4:
                    find_fn();
                    break;

                case 5:
                    find_c();
                    break;

                case 6:
                    tot_s();
                    break;

                case 7:
                    del_s();
                    break;

                case 8:
                    up_s();
                    break;

                case 9:
                    show_s();
                    break;

                case 10:
                	delete_database();
                    exit(0);
                    break;
                }
                system("pause");
            }

            Sleep(100);
            break;
        }

        if ((pointer == 10) && (pressedKey == VK_RETURN))
            break;

    }
}