#include "..//tm4c123gh6pm.h"
#include "LED.h"
void LED_Init(void)
{
	volatile unsigned long delay;
	SYSCTL_RCGC2_R|=0x00000010;		 //Enable clk for Port E
	delay=SYSCTL_RCGC2_R;			 //delay to make sure that the clk is enabled 
	GPIO_PORTE_LOCK_R = 0x4C4F434B;  //UnLock Port E
	GPIO_PORTE_CR_R |= 0x30;		 //Enable Changes for pins PE4 & PE5
	GPIO_PORTE_AFSEL_R &= ~(0x30);	 //Disable Alternative function mode for pins PE4 & PE5
	GPIO_PORTE_AMSEL_R &= ~(0x30);	 //Disable aAnalog mode for pins PE4 & PE5
	GPIO_PORTE_PCTL_R &= ~(0x30);	 // Disable PCTL for pins PE4 & PE5
	GPIO_PORTE_DIR_R |= 0x30;		 //configure pins PE4 & PE5 as output pins
	GPIO_PORTE_DEN_R|= 0x30;		 // Enable Digital Mode for pins PE4 & PE5
}

//Output the Input "data" to The Leds
void LED_Out(unsigned long data)
{
	if(data==0x01)
		GPIO_PORTE_DATA_R |= 0x10;
	else if(data==0x02)
		GPIO_PORTE_DATA_R |= 0x20;
	else if(data==0x03)
		GPIO_PORTE_DATA_R |= 0x30;
	else
		GPIO_PORTE_DATA_R &= ~(0x30);
}
