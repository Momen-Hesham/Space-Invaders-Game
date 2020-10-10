#include "..//tm4c123gh6pm.h"
#include "SysTick.h"
#include "ADC.h"
#include "SW.h"

unsigned long *Readings1;
unsigned long *SW1;
void (*GameEngine1)(void);
void SysTick_Init(unsigned long period,unsigned long * SW_Ptr,unsigned long * Readings_Ptr,void (*Fun_Ptr)(void))
{
	NVIC_ST_CTRL_R =0;			//Disable Systick To Configure it 
	NVIC_ST_RELOAD_R =period-1;	// Set the reolad Value
	NVIC_ST_CURRENT_R =0;		//Reset The Current Register And the Zero Flag
	NVIC_SYS_PRI3_R |=((NVIC_SYS_PRI3_R &0x00FFFFFF)+0x2000000);//Priority 2
	SW1=SW_Ptr;
	Readings1=Readings_Ptr;
	NVIC_ST_CTRL_R =0x07;//Enable Systick With Interrupts
	GameEngine1=Fun_Ptr;
}

unsigned long temp=0;
void SysTick_Handler(void)
{
	//Read From Adc
	*Readings1=ADC0_In();
	//Read Switches
	*SW1=SW_In();
	//Go to Game Engine
	(*GameEngine1)();
}



