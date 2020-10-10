#include "..//tm4c123gh6pm.h"
#include "SW.h"

void SW_Init(void)
{
	volatile unsigned long delay;
	SYSCTL_RCGC2_R |= 0x00000010;	// enable clok 
	delay=SYSCTL_RCGC2_R;			// delay to make sure thqat clock is enabled
	GPIO_PORTE_LOCK_R = 0x4C4F434B; // Unlock PortE
	GPIO_PORTE_CR_R |=0x03;			//Enable Changes to PE0 & PE1
	GPIO_PORTE_AMSEL_R &= ~(0x03);	//Disable Analog Mode For PE0 &PE1
	GPIO_PORTE_AFSEL_R &= ~(0x03);	//Disable Alternative Function Mode For PE0 & PE1
	GPIO_PORTE_PCTL_R &= ~(0x03);	// Disable PCTL For PE0 & PE1
	GPIO_PORTE_DEN_R |= 0x03;		// Enable Digital Mode For PE0 & PE1
	GPIO_PORTE_DIR_R &= ~(0x03);	//Configure PE0 & PE1 as input pins
}

//Read The Input State of Switches
unsigned long SW_In(void)
{
	unsigned long result=0;
	result=(GPIO_PORTE_DATA_R & 0x00000003); // read PE0 & PE1 
	return result;				// result =1 @ PE0 switch pressed , result =2 @ PE1 switch pressed , result =3 @ both switches pressed
}
