/*
 * CA_v1.h
 *
 *  Created on: Aug 14, 2023
 *      Author: Ahmed
 */

#ifndef INC_CA_V1_H_
#define INC_CA_V1_H_

#include "state.h"

typedef enum
{
	CA_Waiting,
	CA_Driving = !CA_Waiting

} eCA_StateId_t;

extern void (*p2CA_state)(void);

void CA_Init(void);
STATE_fn(CA_Waiting);
STATE_fn(CA_Driving);


#endif /* INC_CA_V1_H_ */
