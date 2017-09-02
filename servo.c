#include "TM4C123GH6PM.h"
void delayMs(int n);
void servo_init()
{

   // int x = 319999;
	  int i=0;
    
    /* Enable Peripheral Clocks */
    SYSCTL->RCGCPWM |= 2;       /* enable clock to PWM1 */
    SYSCTL->RCGCGPIO |= 0x10;   /* enable clock to PORTE */
    SYSCTL->RCC &= ~0x00100000; /* no pre-divide for PWM clock */
      while(i<40){
				i++;
			}
			GPIOE->AFSEL = (1U<<4);           /* PE4 uses alternate function */
    GPIOE->PCTL &= ~0x000F0000; /* make PE4 PWM output pin */
    GPIOE->PCTL |= 0x00050000;
		GPIOE->DIR |=(1U<<4);
    GPIOE->DEN |=(1U<<4);            /* pin digital */
		
			PWM1->_1_CTL = 0;           /* stop counter */
    PWM1->_1_GENA = 0x0000008C; /* M1PWM2 output set when reload, */
                                /* clear when match PWMCMPA */
    PWM1->_1_LOAD = 320000;      /* set load value for 50Hz (16MHz/50) */
    PWM1->_1_CMPA = 319999;      /* set duty cycle to min */
    PWM1->_1_CTL = 1;           /* start timer */
    PWM1->ENABLE = 0x04;        /* start PWM1 ch2 */
}
void neck_turn(uint32_t amount)
{
	PWM1->_1_CMPA = amount;
}

void look_left()
{
			PWM1->_1_CMPA = 240000;
        delayMs(1000);
			PWM1->_1_CMPA = 160000;
        delayMs(1000);
			PWM1->_1_CMPA = 80000;
        delayMs(1000);
			PWM1->_1_CMPA = 40000;
        delayMs(1000);
			PWM1->_1_CMPA = 30000;
        delayMs(1000);
			PWM1->_1_CMPA = 20000;
        delayMs(1000);
			PWM1->_1_CMPA = 10000;
        delayMs(1000);
}
void delayMs(int n)
{
    int i, j;
    for(i = 0 ; i < n; i++)
        for(j = 0; j < 3180; j++)
            {}  /* do nothing for 1 ms */
}
void PE5_PWM_init()
{    
	   uint8_t i;
	  SYSCTL->RCGCPWM |= 2 ; // Enable clock for pwm1
	  SYSCTL->RCGCGPIO |=0x10; //Enable clokc for PORT E
	  SYSCTL->RCC &= ~0x00100000; /* no pre-divide for PWM clock */
      while(i<40){
				i++;
			}
			GPIOE->AFSEL =(1U<<5);  //PE5 enabel alternate func
			GPIOE->PCTL &= ~0x00F00000;
			GPIOE->PCTL |= 0x00500000;
			GPIOE->DIR |=(1U<<5);
      GPIOE->DEN |=(1U<<5);
			
			PWM1->_2_CTL =0;   /* disable module 2*/
			PWM1->_2_GENA = 0x0000008C; /* M1PWM2 output set when reload, */
                                /* clear when match PWMCMPA */
      PWM1->_2_LOAD = 320000;      /* set load value for 50Hz (16MHz/50) */
      PWM1->_2_CMPA = 319999;      /* set duty cycle to min */
      PWM1->_2_CTL = 1;           /* start timer */
      PWM1->ENABLE = 0x04;
}
void PE4_PWM_init()
{
	
}