/*
 * hal.h
 *
 *  Created on: Mar 31, 2023
 *      Author: pc user
 */

#ifndef HAL_H_
#define HAL_H_

int PWM_flag;
int state;

void LED_blink(int n);

void inline ISR_0();
void inline ISR_1();
void inline ISR_2();
void inline ISR_3();


#endif /* HAL_H_ */
