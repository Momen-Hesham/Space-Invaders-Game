
//Intialization of Systick With Interrupts,period Parameter is the RELOAD Value you want.
void SysTick_Init(unsigned long period,unsigned long * SW_Ptr,unsigned long * Readings_Ptr,void (*Fun_Ptr)(void));
//The Systick Handler
void SysTick_Handler(void);
