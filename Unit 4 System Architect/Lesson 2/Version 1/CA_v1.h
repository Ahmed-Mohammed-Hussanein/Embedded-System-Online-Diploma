/*
 * CA_v0.h
 *
 *  Created on: Aug 14, 2023
 *      Author: Ahmed
 */

#ifndef INC_CA_V0_H_
#define INC_CA_V0_H_

#include "state.h"

typedef enum
{
	CA_Waiting = 0,
	CA_Driving = !CA_Waiting

} eCA_State_t;

extern void (*p2CA_state) (void);

STATE_FN(CA_Waiting);
STATE_FN(CA_Driving);

#endif /* INC_CA_V0_H_ */
