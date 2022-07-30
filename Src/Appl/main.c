
#include "TM4C123.h"
#include "Mcu_Hw.h"
//0x40000000,0xF000FFFF PUT THESE VALUES ON MEMORY MAP TO ALLOW ACCESS FOR SIMULATOR
//FREQ 80MHz

void IntCtrl_Init(void);
void Timer0A_Init(void);
void GPIO_Init(void);	
void Set_PWM_PF2(uint32 Freq,uint32 Duty_Cycle);

volatile unsigned int Counter0,Counter1,GDuty,GFreq,Periodic_Time,Time_On;


int main(){
	
	IntCtrl_Init();
	Timer0A_Init();
	
	
	Set_PWM_PF2(50,80); // Set BlueLed(PF2) Freq on 50Hz and Duty Cycle 80%   Known that Freq Range (From 1 Hz to 1MHz) Duty Cycle Range (From 0 to 100)
	
	while(1){
	
	
	
	
	
	}
	
}






  void IntCtrl_Init(){
	 
	/*TODO Configure Grouping\SubGrouping System in APINT register in SCB*/
   APINT = 0xFA050000|0x00000700; //MAKING PRIORITY GROUPING TO YYY
     
	/*TODO : Enable\Disable  NVIC_ENx and SCB_Sys Registers */
	 NVIC_EN0 |= (1<<19);
		 
 }
	
 
 
 void GPIO_Init(){
	 //Config for GPIO F Blue Led(PF2)
	 
	 SYSCTL->RCGCGPIO |= (1<<5);   //Enable clock on Port F
	 GPIOF->AFSEL &= ~(1<<2);  //disable alternate function
	 GPIOF->DIR |= (1<<2); //MAKE PF2 OUTPUT
	 GPIOF->DEN |= (1<<2);// DIGITAL I/O ENABLE FOR PF2
	 
	 
 }
 
 
 
 
 void Timer0A_Init(){
	 /*TODO :Enable Clock for TIMER0*/
		RCGTIMER |=(1<<0);
	 GPTMCTL &= ~(1<<0);
	
	 GPTMCFG = 0x00000000;
	 /*TODO : Configure TIM0A for periodic mode*/
	 GPTMTAMR |= (0x2<<0);

	 /*TODO : Set LDR VAL*/
	 GPTMTAILR =64000;
	 /*TODO : Enable Timeout Interrupts*/
	 GPTMIMR |=	0x1;
	 /*TODO : Stall Timer0A with debugger + Enable Timer0A*/
	 GPTMICR |= (1<<0);
	 GPTMCTL |=(1<<0)|(1<<1); 

 }
 
 void Set_PWM_PF2(uint32 Freq,uint32 Duty_Cycle){
	 GFreq=Freq;
	
	 GDuty=Duty_Cycle;
	 
	 Periodic_Time = 1000000/Freq;
	 Time_On=(Periodic_Time*GDuty)/100.00;
	 
 }
 
 
 void TIMER0A_Handler(){
	 
	  if (Counter0>=80){
		 Counter1++;
		 if (Counter1<=Time_On)
			 GPIOF->DATA |=(1<<2); //Time when PF2 IS ON
		 else if (Counter1>=Time_On && Counter1<Periodic_Time)
			 GPIOF->DATA &= ~(1<<2); //Time when PF2 IS OFF
		 else if (Counter1>=Periodic_Time)
			 Counter1=0;
		 
		 Counter0=0;
		 
	 }
	 

	 Counter0++;
	 
	 GPTMICR |= (1<<0); //Clear Interrupt Flag
	 
 }
 
 
 