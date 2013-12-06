
/*
 * sensor.c
 *
 *  Created on: Dec 4, 2013
 *      Author: C15Alex.Strom
 */
#include "sensor.h"
#include <msp430.h>

void initsensors(){

	                            // Set P1.0 to output direction


}

void middlesensor(){
	ADC10CTL0 &= ~ENC;
	ADC10CTL1 = INCH_4;                       // input A4
	ADC10AE0 |= BIT4;                         // PA.1 ADC option select
	ADC10CTL1 |= ADC10SSEL1|ADC10SSEL0;                // Select SMCLK
	ADC10CTL0 |= ENC + ADC10SC;             // Sampling and conversion start
		    __bis_SR_register(CPUOFF + GIE);        // LPM0, ADC10_ISR will force exit
		    if (ADC10MEM < 0x1FF)
		      P1OUT &= ~(0x01|0x06);                       // Clear P1.0 LED off
		    else
		      P1OUT |= (0x01|0x06);                        // Set P1.0 LED on

}
void leftsensor(){
	ADC10CTL0 &= ~ENC;
	ADC10CTL1 = INCH_5;                       // input A5
	ADC10AE0 |= BIT5;                         // PA.1 ADC option select
	ADC10CTL1 |= ADC10SSEL1|ADC10SSEL0;                // Select SMCLK
	 ADC10CTL0 |= ENC + ADC10SC;             // Sampling and conversion start
	    __bis_SR_register(CPUOFF + GIE);        // LPM0, ADC10_ISR will force exit
	    if (ADC10MEM < 0x1FF)
	      P1OUT &= ~(0x01|0x06);                       // Clear P1.0 LED off
	    else
	      P1OUT |= 0x01;                        // Set P1.0 LED on

}

void rightsensor(){
	ADC10CTL0 &= ~ENC;
		  ADC10CTL1 = INCH_3;                       // input A3
		  ADC10AE0 |= BIT3;                         // PA.1 ADC option select
		  ADC10CTL1 |= ADC10SSEL1|ADC10SSEL0;                // Select SMCLK
		  ADC10CTL0 |= ENC + ADC10SC;             // Sampling and conversion start
		  	    __bis_SR_register(CPUOFF + GIE);        // LPM0, ADC10_ISR will force exit
		  	    if (ADC10MEM < 0x1FF)
		  	      P1OUT &= ~(0x01|0x06);                       // Clear P1.0 LED off
		  	    else
		  	      P1OUT |= 0x01;                        // Set P1.0 LED on

}
