/*
 * US.h
 *
 *  Created on: Aug 14, 2023
 *      Author: Ahmed
 */

#ifndef INC_US_H_
#define INC_US_H_

#include "state.h"

typedef enum
{
	US_Busy

} eUS_StateId_t;


extern void (*p2US_state)(void);


void US_Init(void);
STATE_fn(US_Busy);


#endif /* INC_US_H_ */
