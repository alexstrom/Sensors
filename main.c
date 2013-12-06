#include <msp430.h> 
#include "sensor.h"

/*
 * main.c
 */
int main(void)
{
	ADC10CTL0 = ADC10SHT_3 + ADC10ON + ADC10IE; // ADC10ON, interrupt enabled
	P1DIR |= (0x06|0x01);                            // Set P1.0 to output direction

  while (1)
  {
middlesensor();
leftsensor();
rightsensor();


  }

    return 0;
}

// ADC10 interrupt service routine
#pragma vector=ADC10_VECTOR
__interrupt void ADC10_ISR(void)
{
  __bic_SR_register_on_exit(CPUOFF);        // Clear CPUOFF bit from 0(SR)
}
