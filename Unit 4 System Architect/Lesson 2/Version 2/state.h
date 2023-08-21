/*
 * state.h
 *
 *  Created on: Aug 14, 2023
 *      Author: Ahmed
 */

#ifndef INC_STATE_H_
#define INC_STATE_H_

#define STATE_fn(STATE_NAME)	void STATE_NAME##_state(void)
#define STATE(STATE_NAME)			 STATE_NAME##_state

void US_send_distance(int *p2distance);
void DC_get_speed(int *p2Speed);


#endif /* INC_STATE_H_ */
