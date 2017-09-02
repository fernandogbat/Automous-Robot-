#include "TM4C123GH6PM.H"

void PE5_PWM_init
{
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