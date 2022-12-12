/*
 * main.c
 *
 *  Created on: Oct 8, 2021
 *      Author: Youssef
 */


#include  <stdio.h>
#include "avr/io.h"
#include "adc.h"
#include "common_macros.h"
#include "lcd.h"
#include "lm35_sensor.h"
#include "dc_motor.h"



int main(){


	uint8 temp;

	ADC_ConfigType config1;
	config1.ref_volt= HALF_AVCC;
	config1.prescaler= FCPU_8;

	LCD_init();
	ADC_init(&config1);
	DcMotor_Init();


	while(1){

		temp = LM35_getTemperature();

		if (temp<30){
			DcMotor_Rotate(STOP ,0);
			LCD_displayStringRowColumn(0,0,"Fan is :OFF");
		}
		else if(30 <= temp && temp < 60){
			DcMotor_Rotate(CW,25);
			LCD_displayStringRowColumn(0,0,"Fan is :ON ");
		}
		else if(60 <= temp && temp < 90){
			DcMotor_Rotate(CW,50);
			LCD_displayStringRowColumn(0,0,"Fan is :ON ");
		}
		else if(90 <= temp && temp<120){
			DcMotor_Rotate(CW,75);
			LCD_displayStringRowColumn(0,0,"Fan is :ON ");
		}
		else{
			DcMotor_Rotate(CW ,100);
			LCD_displayStringRowColumn(0,0,"Fan is :ON ");
		}

		LCD_displayStringRowColumn(1,0,"Temp is :");
		LCD_intgerToString(temp);
		LCD_displayCharacter(' ');


	}

}
