/*
 * dc_motor.h
 *
 *  Created on: Oct 9, 2021
 *      Author: Youssef
 */

#ifndef DC_MOTOR_H_
#define DC_MOTOR_H_


#include "std_types.h"
#define MOTOR_MAX_SPEED 100
#define TIMER_MAX 255
typedef enum
{
	STOP,CW,A_CW
}DcMotor_State;


void DcMotor_Init(void);
void DcMotor_Rotate(DcMotor_State state,uint8 speed);
void PWM_Timer0_Init(uint8 duty_cycle);

#endif /* DC_MOTOR_H_ */
