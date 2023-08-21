/* Ahmed Mohammed Hussanein Ali 
	Test of FIFO */

#include <stdio.h>
#include <stdlib.h>
#include "FIFO.h"

element_type buffer[5];

int main ()
{
	int i;
	element_type item;
	FIFO_STATUS status;
	FIFO_t UART_buffer;
	status = FIFO_init(&UART_buffer, buffer, 5);
	if (status == FIFO_no_errors)
	{
		for (i = 0; i < 7; ++i)
		{
			status = FIFO_enqueue(&UART_buffer, i);
			switch (status)
			{
				case FIFO_no_errors:
					printf("FIFO_enqueue: %d\n", i);
					break;

				case FIFO_full:
					printf("The FIFO is full. \n");
					break;

				case FIFO_null:
					printf("NULL FIFO \n");
					break;
			}
		}

		for (i = 0; i < 3; ++i)
		{
			status = FIFO_dequeue(&UART_buffer, &item);
			switch (status)
			{
				case FIFO_no_errors:
					printf("dequeue: %d\n", item);
					break;

				case FIFO_empty:
					printf("The FIFO is empty. \n");
					break;

				case FIFO_null:
					printf("NULL FIFO \n");
					break;
			}
		}

		for (i = 0; i < 7; ++i)
		{
			status = FIFO_enqueue(&UART_buffer, i);
			switch (status)
			{
				case FIFO_no_errors:
					printf("FIFO_enqueue: %d\n", i);
					break;

				case FIFO_full:
					printf("The FIFO is full. \n");
					break;

				case FIFO_null:
					printf("NULL FIFO \n");
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