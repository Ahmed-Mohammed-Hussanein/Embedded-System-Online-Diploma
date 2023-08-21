/* Ahmed Mohammed Hussanein Ali
	Student Database using Linked List
	*/

#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_

#include "Platform_Types.h"

/* types definintion */
typedef struct
{
	char name[40];
	uint32 ID;
	float32 height;
} SData;

struct SStudent
{
	SData StudentData;
	struct SStudent *PNextStudent;
};



/* APIs */
void add_to_list( struct SStudent ** );
void delete_from_list( struct SStudent **, uint32 );
void delete_all_list( struct SStudent ** );
void display_from_list( struct SStudent *, uint32 );
void display_all_list( struct SStudent * );

uint32 get_length_iter( struct SStudent * );
uint32 get_length_recur( struct SStudent * );
void get_nth_node(struct SStudent *, uint32 );
void get_nth_from_end(struct SStudent *, uint32 );
void get_middle_node(struct SStudent *);
void reverse_list(struct SStudent **);



#endif
