/*
 * adc.h
 *
 *  Created on: Oct 9, 2021
 *      Author: Youssef
 */

#ifndef ADC_H_
#define ADC_H_

/*
 * adc.h
 *
 *  Created on: Oct 2, 2021
 *      Author: Youssef
 */

#include "std_types.h"

#define ADC_MAXIMUM_VALUE 1023
#define ADC_REF_VOLT_VALUE 2.56


typedef enum
{
	AREF,AVCC,HALF_AVCC=3
}ADC_ReferenceVolatge;

typedef enum
{
	FCPU_2=1 , FCPU_4 , FCPU_8 , FCPU_16 , FCPU_32 , FCPU_64 , FCPU_128
}ADC_Prescaler;

typedef struct{
 ADC_ReferenceVolatge ref_volt;
 ADC_Prescaler prescaler;
}ADC_ConfigType;

void ADC_init(const ADC_ConfigType * Config_Ptr);
uint16 ADC_readChannel(uint8 ch_num);



#endif /* ADC_H_ */
