/*
 * DC.h
 *
 *  Created on: Aug 14, 2023
 *      Author: Ahmed
 */

#ifndef INC_DC_H_
#define INC_DC_H_

#include "state.h"

typedef enum
{
	DC_Idle,
	DC_Busy = !DC_Idle

} eDC_StateID_t;

extern void (*p2DC_state)(void);

void DC_Init(void);
STATE_fn(DC_Idle);
STATE_fn(DC_Busy);

#endif /* INC_DC_H_ */
