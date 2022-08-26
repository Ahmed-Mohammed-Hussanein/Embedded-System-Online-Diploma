/* Ahmed Mohammed Hussanein Ali 
	Test of LIFO */

#include <stdio.h>
#include <stdlib.h>
#include "LIFO.h"

#define SIZE 5

uint32 buffer[SIZE];

int main ()
{
	int i, item;
	LIFO_STATUS status;
	LIFO_t UART_buffer;
	status = LIFO_init(&UART_buffer, buffer, SIZE);
	if (status == LIFO_no_errors)
	{
		for (i = 0; i < 7; ++i)
		{
			status = LIFO_push(&UART_buffer, i);
			switch (status)
			{
				case LIFO_no_errors:
					printf("Push: %d\n", i);
					break;

				case LIFO_full:
					printf("The LIFO is full. \n");
					break;

				case LIFO_null:
					printf("NULL LIFO \n");
					break;
			}
		}

		for (i = 0; i < 7; ++i)
		{
			status = LIFO_pop(&UART_buffer, &item);
			switch (status)
			{
				case LIFO_no_errors:
					printf("Pop: %d\n", item);
					break;

				case LIFO_empty:
					printf("The LIFO is empty. \n");
					break;

				case LIFO_null:
					printf("NULL LIFO \n");
					break;
			}
		}
	}
	else
	{
		printf("NULL BUFFER. \n");
	}

	system("pause");
	return 0;
}