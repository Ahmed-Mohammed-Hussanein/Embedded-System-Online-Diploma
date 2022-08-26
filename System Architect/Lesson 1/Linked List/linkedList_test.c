/* Ahmed Mohammed ussanein Ali
	Student Database using Linked List
	*/

#include <stdio.h>
#include <stdlib.h>
#include "linkedList.h"

struct SStudent *gPhead = NULL;

typedef enum
{
	ADD = 1,
	DELETE,
	DELETE_ALL,
	DISPLAY,
	DISPLAY_ALL,
	LENGTH_ITER,
	LENGTH_RECUR,
	GET_NTH,
	GET_NTH_END,
	GET_MIDDLE,
	REVERSE
} OPTIONS;

void menu( void );

int main()
{
	int choice;
	uint32 id, index;
	menu();
	scanf("%d", &choice);

	system("cls");

	while(1)
	{
		switch(choice)
		{
			case ADD:
				add_to_list( &gPhead );
				break;

			case DELETE:
			    printf("Enter Student ID: ");
                scanf("%u", &id);
				delete_from_list( &gPhead, id);
				break;

			case DELETE_ALL:
				delete_all_list( &gPhead );
				break;

			case DISPLAY:
			    printf("Enter Student ID: ");
                scanf("%u", &id);
				display_from_list(gPhead, id);
				break;

			case DISPLAY_ALL:
				display_all_list( gPhead );
				break;

			case LENGTH_ITER:
				printf("The length of the list iterativly: %u\n", get_length_iter( gPhead ));
				break;

			case LENGTH_RECUR:
				printf("The length of the list recursivly: %u\n", get_length_recur( gPhead ));
				break;

            case GET_NTH:
                printf("Enter the index of the node: ");
                scanf("%u", &index);
                get_nth_node( gPhead, index );
                break;

            case GET_NTH_END:
                printf("Enter the index of the node: ");
                scanf("%u", &index);
                get_nth_from_end( gPhead, index );
                break;

            case GET_MIDDLE:
                get_middle_node( gPhead );
                break;

            case REVERSE:
                reverse_list( &gPhead );
                break;

			default:
			return 0;
		}

        system("pause");

		menu();
        scanf("%d", &choice);

        system("cls");
	}

	return 0;
}

void menu( void )
{
	system("cls");
	printf("\n===========================================\n");
	printf("1.  Add new student.\n");
	printf("2.  Delete a student.\n");
	printf("3.  Delete all database.\n");
	printf("4.  Display a student.\n");
	printf("5.  Display all database.\n");
	printf("6.  Length of the list iterative.\n");
	printf("7.  Length of the list recursive.\n");
	printf("8.  Get the nth node.\n");
	printf("9.  Get the nth node from end.\n");
	printf("10. Get the middle node.\n");
	printf("11. Reverse the list.\n");
	printf("12. Exit.\n");
	printf("===========================================\n");
	printf(" Enter a number (1:12) > ");
}
