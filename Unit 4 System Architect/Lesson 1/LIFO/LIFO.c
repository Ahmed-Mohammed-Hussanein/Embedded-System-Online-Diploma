/* Ahmed Mohammed Hussanein Ali 
	Implementation of LIFO */

#include "LIFO.h"
#include "Platform_Types.h"

#define NULL (void*)0

LIFO_STATUS LIFO_init(LIFO_t *LIFO_buffer, element_type *buffer, uint32 length)
{
	/* NULL pointer passed */
	if ( NULL == buffer || NULL == LIFO_buffer || 0 >= length)
		return LIFO_null;

	/* every thing is ok */
	LIFO_buffer->head = buffer;
	LIFO_buffer->base = buffer;
	LIFO_buffer->length = length;
	LIFO_buffer->count = 0;

	return LIFO_no_errors;
}

LIFO_STATUS LIFO_push(LIFO_t *LIFO_buffer, element_type item)
{
	/* check if there is an error */
	LIFO_STATUS status = LIFO_is_full(LIFO_buffer);
	if (status != LIFO_not_full)
		return status;

	/* no errors */
	*(LIFO_buffer->head) = item;
	LIFO_buffer->head++;
	LIFO_buffer->count++;

	return LIFO_no_errors;
}

LIFO_STATUS LIFO_pop(LIFO_t *LIFO_buffer, element_type *item)
{
	/* check if there is an error */
	LIFO_STATUS status = LIFO_is_empty(LIFO_buffer);
	if (status != LIFO_not_empty)
		return status;

	/* no errors */
	LIFO_buffer->head--;
	*(item) = *(LIFO_buffer->head);
	LIFO_buffer->count--;

	return LIFO_no_errors;
}

LIFO_STATUS LIFO_is_empty(LIFO_t *LIFO_buffer)
{
	/* buffer is not found */
	if (NULL == LIFO_buffer || NULL == LIFO_buffer->head || NULL == LIFO_buffer->base)
		return LIFO_null;

	/* buffer is empty */
	if (0 == LIFO_buffer->count)
		return LIFO_empty;

	return LIFO_not_empty;
}

LIFO_STATUS LIFO_is_full(LIFO_t *LIFO_buffer)
{
	/* buffer is not found */
	if (NULL == LIFO_buffer || NULL == LIFO_buffer->head || NULL == LIFO_buffer->base)
		return LIFO_null;

	/* buffer is full */
	if (LIFO_buffer->count == LIFO_buffer->length)
		return LIFO_full;

	return LIFO_not_full;
}