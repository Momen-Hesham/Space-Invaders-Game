
//Intialization of Timer2A With Interrupts,period Parameter is the RELOAD Value you want.
void Timer2A_Init(void (*PlayFunction)(void),unsigned long period);
//The Timer2A Handler
void Timer2A_Handler(void);
