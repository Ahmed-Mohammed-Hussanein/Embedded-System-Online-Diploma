/* Ahmed Mohammed Hussanein Ali
	Student Database using Linked List
	*/

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "linkedList.h"
#include "Platform_Types.h"

static void get_data(struct SStudent **P2PStudent) /* Pass by reference */
{
	char temp[40];

    fflush(stdin), fflush(stdout);
	printf("Enter Student ID: ");
	gets(temp);
	(*P2PStudent)->StudentData.ID = atoi(temp);

	printf("Enter Student Name: ");
	gets((*P2PStudent)->StudentData.name);

	printf("Enter Student Height: ");
	gets(temp);
	(*P2PStudent)->StudentData.height = atof(temp);
}

static void print_data(struct SStudent *PStudent) /* Pass by value */
{
	printf("Student ID: %d\n", PStudent->StudentData.ID);
	printf("Student Name: %s\n", PStudent->StudentData.name);
	printf("Student Height: %f\n", PStudent->StudentData.height);
}

void add_to_list( struct SStudent ** P2PFisrtStudent )
{
	struct SStudent *PNewStudent = (struct SStudent*) malloc (sizeof(struct SStudent));
	struct SStudent *PLastStudent = NULL;

	/* no space in memory heap */
	if(NULL == PNewStudent)
    {
        printf("\n No space for memory heap.\n");
    }

	else
	{
		/* first node in linked list */
		if (NULL == *P2PFisrtStudent)
		{
			*P2PFisrtStudent = PNewStudent;
		}

		/* insert at last node */
		else
		{
			PLastStudent = *P2PFisrtStudent;
			while (NULL != PLastStudent->PNextStudent)
				PLastStudent = PLastStudent->PNextStudent;

			PLastStudent->PNextStudent = PNewStudent;
		}

		/* get information of the student */
		get_data(&PNewStudent);
		/* set PNextStudent = NULL */
		PNewStudent->PNextStudent = NULL;

		printf("\n Student is added successfully.\n");
	}
}

void delete_from_list( struct SStudent ** P2PFisrtStudent, uint32 id )
{
	struct SStudent *PSelectedStudent = *P2PFisrtStudent;
	struct SStudent *PPreviousStudent = NULL;

	/* if the list is empty */
	if (NULL == *P2PFisrtStudent)
	{
        printf("\n The list is empty.\n");
        return;
    }

	/* not empty list */
	else
	{
		/* Search for certain student */
		while (NULL != PSelectedStudent)
		{
			if (PSelectedStudent->StudentData.ID == id)
			{
				/* the wanted student is at first node */
				if(NULL == PPreviousStudent)
				{
					*P2PFisrtStudent = PSelectedStudent->PNextStudent;
				}

				/* not at first node */
				else
				{
					PPreviousStudent->PNextStudent = PSelectedStudent->PNextStudent;
				}

				printf("\n");
				print_data(PSelectedStudent);

				free(PSelectedStudent);

				printf("\n Student is deleted successfully.\n");
				return;
			}

			PPreviousStudent = PSelectedStudent;
			PSelectedStudent = PSelectedStudent->PNextStudent;
		}
	}

	/* id not found */
	printf("\n The ID you entered is not found.\n");
	return;
}

void delete_all_list( struct SStudent ** P2PFisrtStudent )
{
	struct SStudent *PSelectedStudent = *P2PFisrtStudent;
	struct SStudent *PTempStudent = NULL;

	/* empty list */
	if (NULL == *P2PFisrtStudent)
	{
		printf("\n The list is empty.\n");
	}

	/* not empty list */
	else
	{
		while (NULL != PSelectedStudent)
		{
			PTempStudent = PSelectedStudent;
			PSelectedStudent = PSelectedStudent->PNextStudent;

			free(PTempStudent);
			PTempStudent = PSelectedStudent;
		}

		*P2PFisrtStudent = NULL;
		printf("\n The database is deleted successfully.\n");
	}
}

void display_from_list( struct SStudent * PSelectedStudent, uint32 id )
{
	/* if the list is empty */
	if (NULL == PSelectedStudent)
    {
        printf("\n The list is empty.\n");
        return;
    }

	/* not empty list */
	else
	{
		/* Search for certain student */
		while (NULL != PSelectedStudent)
		{
			if (PSelectedStudent->StudentData.ID == id)
			{
				/* print information of the student */
				print_data(PSelectedStudent);
				printf("\n The data is displayed.\n");
				return;
			}

			PSelectedStudent = PSelectedStudent->PNextStudent;
		}
	}

	/* id not found */
	printf("\n The ID you entered is not found.\n");
	return;
}

void display_all_list( struct SStudent * PSelectedStudent )
{
	uint32 i = 1;
	/* if the list is empty */
	if (NULL == PSelectedStudent)
    {
        printf("\n The list is empty.\n");
    }

	/* not empty list */
	else
	{
		/* Search for certain student */
		while (NULL != PSelectedStudent)
		{
			/* print information of the student */
			printf("Record number %d:\n\n", i++);
			print_data(PSelectedStudent);
			printf("========================================\n");

			PSelectedStudent = PSelectedStudent->PNextStudent;
		}
		printf("\n The data is displayed.\n");
	}
}

uint32 get_length_iter( struct SStudent * PNavigator )
{
	uint32 length = 0;

	while (NULL != PNavigator)
	{
		length++;
		PNavigator = PNavigator->PNextStudent;
	}

	return length;
}

uint32 get_length_recur( struct SStudent * PNavigator )
{
	if (NULL == PNavigator)
	{
		return 0;
	}

	return (1 + get_length_recur(PNavigator->PNextStudent));
}

void get_nth_node(struct SStudent * PNavigator, uint32 n)
{
    if (NULL == PNavigator)
    {
        printf("\n The list is empty.\n");
        return;
    }

    /* n starts with value 0 */
    while(n--)
    {
        PNavigator = PNavigator->PNextStudent;
        if (NULL == PNavigator)
        {
            printf("\n The index you entered is exceeded the length of the list.\n");
            return;
        }
    }

    print_data(PNavigator);
    printf("\n The data is displayed.\n");
    return;
}

void get_nth_from_end(struct SStudent * PRef, uint32 n) /* from user, n starts with 1 */
{
	struct SStudent * PMain = PRef;

	if (NULL == PRef)
    {
        printf("\n The list is empty.\n");
        return;
    }

	/* n starts with value 0 */
	n--;
	while(n--)
	{
		PRef = PRef->PNextStudent;

		/* n is greater than length of the list */
		if (NULL == PRef)
        {
            printf("\n The index you entered is exceeded the length of the list.\n");
			return;
        }
	}

	while(NULL != PRef->PNextStudent)
	{
		PRef = PRef->PNextStudent;
		PMain = PMain->PNextStudent;
	}

	/* return data */
	print_data(PMain);
	printf("\n The data is displayed.\n");
	return;
}

void get_middle_node(struct SStudent * PFast)
{
    struct SStudent * PSlow = PFast;

    if (NULL == PFast)
    {
        printf("\n The list is empty.\n");
    }

    else
    {
        while (NULL != PFast->PNextStudent && NULL != PFast->PNextStudent->PNextStudent)
        {
            PFast = PFast->PNextStudent->PNextStudent;
            PSlow = PSlow->PNextStudent;
        }

        /* return data */
        print_data(PSlow);
        printf("\n The data is displayed.\n");
    }
}

void reverse_list(struct SStudent ** P2PFisrtStudent)
{
    struct SStudent * PCurrent = *P2PFisrtStudent;
    struct SStudent * PNext = PCurrent;
    struct SStudent * PPrevious = NULL;

    if(NULL == PCurrent)
    {
        printf("\n The list is empty.\n");
    }

    else
    {

        while (NULL != PCurrent)
        {
            PNext = PCurrent->PNextStudent;
            PCurrent->PNextStudent = PPrevious;
            PPrevious = PCurrent;
            PCurrent = PNext;
        }

        *P2PFisrtStudent = PPrevious;
        printf("\nThe list is reversed.\n");
    }
}

