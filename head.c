#include "TM4C123.h"                    // Device header
#include <stdint.h>

void delay_Microsecond(uint32_t time);
uint32_t headSensor_detect(void);
void triggerPort_Init(void);
void echoAndTimer0_Init(void);
void headSensor_Init(void);
uint32_t headSensor_run(uint32_t distance);

const double _16MHZ_1clock = 62.5e-9; /*valur of 1clock cycle in nanoseconds*/
const uint32_t MULTIPLIER = 5882; /*Constant derived from the speed of sound*/

#define ECHO (1U<<6)//PB6  0000 0000
#define TRIGGER (1U<<4)//PA4(OUTPUT)

uint32_t highEdge,lowEdge;
uint32_t ddistance;
uint32_t counter=0;



void echoAndTimer0_Init(void){
	SYSCTL->RCGCTIMER |=(1U<<0);
	SYSCTL->RCGCGPIO |=(1U<<1); //PortB Clock
	GPIOB->DIR &=~ECHO;
	GPIOB->DEN |=ECHO;
	GPIOB->AFSEL |=ECHO;
	GPIOB->PCTL &=~0x0F000000;
	GPIOB->PCTL |= 0x07000000;
	
	TIMER0->CTL &=~1;
	TIMER0->CFG =4;
	TIMER0->TAMR =0x17;
	TIMER0->CTL |=0x0C;
	TIMER0->CTL |=1;
}

void delay_Microsecond(uint32_t time)
{
	int i;
	SYSCTL->RCGCTIMER |=(1U<<1);
	TIMER1->CTL =0;
	TIMER1->CFG =0x04;
	TIMER1->TAMR = 0x02;
	TIMER1->TAILR = 16-1;
	TIMER1->ICR = 0x1;
	TIMER1->CTL |=0x01;
	
	for(i=0;i<time;i++){
	  while((TIMER1->RIS&0x1)== 0){
		TIMER1->ICR = 0x1;
		}
   }
	}
uint32_t headSensor_detect(void){
		GPIOA->DATA &=~TRIGGER;
	  delay_Microsecond(12);
	  GPIOA->DATA |= TRIGGER;
	  delay_Microsecond(12);
		GPIOA->DATA &=~TRIGGER;
		/*Capture firstEdge i.e rising edge*/
	  TIMER0->ICR =4;
		while((TIMER0->RIS & 4)== 0){};
			highEdge = TIMER0->TAR;
		/*Capture secondEdge i.e falling edge*/
		TIMER0->ICR =4; //Clear timer capture flag
		while((TIMER0->RIS &4)==0){};
			lowEdge =TIMER0->TAR;
		ddistance = lowEdge -highEdge; 
			  ddistance = _16MHZ_1clock*(double) MULTIPLIER *(double)ddistance;
			  
			return ddistance;	
}

