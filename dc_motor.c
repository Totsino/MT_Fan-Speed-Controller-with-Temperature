/*
 * dc_motor.c
 *
 *  Created on: Oct 9, 2021
 *      Author: Youssef
 */


#include "dc_motor.h"
#include "gpio.h"
#include <avr/io.h>


void DcMotor_Init(void){

	//setting up pin directions

	GPIO_setupPinDirection(PORTB_ID, PIN0_ID , PIN_OUTPUT);
	GPIO_setupPinDirection(PORTB_ID, PIN1_ID , PIN_OUTPUT);
	GPIO_setupPinDirection(PORTB_ID, PIN3_ID , PIN_OUTPUT);


	// initially DC motor at stop state
	GPIO_writePin(PORTB_ID, PIN0_ID, LOGIC_LOW);
	GPIO_writePin(PORTB_ID, PIN1_ID, LOGIC_LOW);


}

void DcMotor_Rotate(DcMotor_State state,uint8 speed){

	switch(state){
	case STOP:
		GPIO_writePin(PORTB_ID, PIN0_ID, LOGIC_LOW);
		GPIO_writePin(PORTB_ID, PIN1_ID, LOGIC_LOW);
		break;
	case CW:
		GPIO_writePin(PORTB_ID, PIN0_ID, LOGIC_HIGH);
		GPIO_writePin(PORTB_ID, PIN1_ID, LOGIC_LOW);
		break;
	case A_CW:
		GPIO_writePin(PORTB_ID, PIN0_ID, LOGIC_LOW);
		GPIO_writePin(PORTB_ID, PIN1_ID, LOGIC_HIGH);
		break;
	}

	PWM_Timer0_Init(((speed*TIMER_MAX)/MOTOR_MAX_SPEED));


}


void PWM_Timer0_Init(uint8 duty_cycle)
{
	GPIO_setupPinDirection(PORTB_ID, PIN3_ID , PIN_OUTPUT);
	TCNT0 = 0; //Set Timer Initial value
	OCR0  = duty_cycle; // Set Compare Value
	DDRB  = DDRB | (1<<PB3); //set PB3/OC0 as output pin --> pin where the PWM signal is generated from MC.

	/* Configure timer control register
	 * 1. Fast PWM mode FOC0=0
	 * 2. Fast PWM Mode WGM01=1 & WGM00=1
	 * 3. Clear OC0 when match occurs (non inverted mode) COM00=0 & COM01=1
	 * 4. clock = F_CPU/8 CS00=0 CS01=1 CS02=0
	 */
	TCCR0 = (1<<WGM00) | (1<<WGM01) | (1<<COM01) | (1<<CS01);
}
