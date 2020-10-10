#include "..//tm4c123gh6pm.h"
#include "DAC.h"
void DAC_Init(void)
{
	volatile unsigned long delay;		
	SYSCTL_RCGC2_R |=0x02;				// Enable clk for Port B
	delay=SYSCTL_RCGC2_R;				// delay to make sure that clk is enabled
	GPIO_PORTB_LOCK_R =0x4C4F434B;		//Unlock port B
	GPIO_PORTB_CR_R |= 0x0F;			// Enable Changes for PB0 - PB3
	GPIO_PORTB_AMSEL_R &= ~(0x0F);		//Disable analog mode for pins PB0-PB3
	GPIO_PORTB_AFSEL_R &= ~(0x0F);		//Disable Alternative Functions Mode for pins PB0 -PB3
	GPIO_PORTB_PCTL_R &= ~(0x0000FFFF);	//Disable PCTL fro pins PB0-PB3
	GPIO_PORTB_DEN_R |= 0x0F;			//Enable Digital for pins PB0-PB3
	GPIO_PORTB_DIR_R |= 0x0F;			//Configure PB0-PB3 as input pins  
	GPIO_PORTB_DR8R_R |=0x0F;			//Enable The Max Allowed current from Tiva c Register Control which is 8mA
}

void DAC_Out(unsigned long data)
{
  GPIO_PORTB_DATA_R=data;	// Write Data To external Dac Implementation
}
