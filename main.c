//Author: Israel N. Gbati
/*
#define ECHO (1U<<6) //PB6 
#define TRIGGER		(1U<<4) //PA4(OUTPUT)
#define BLUE_LED (1U<<2)//PF2 onboard Blue LED 
#define RED_LED  (1U<<3)//PF3 
#define IR_PIN   (1U<<5)//PA5 (INPUT)
#define MOTOR1   (1U<<2)//PE2
#define MOTOR2	 (1U<<3)//PE3
#define SERVO		 (1U<<4)//PE4
*/


#include "TM4C123GH6PM.h"                    // Device header

void TAIL_Init(void);
void HEAD_Init(void);
void LIGHTS_Init(void);
void MOTOR_Init(void);
void TURN_Left(void);
void TURN_Right(void);
void FORWARD(void);
void STOP(void);
void servo_init(void);
void neck_turn(uint32_t);
void look_left();
void echoAndTimer0_Init(void);
uint32_t headSensor_detect(void);
uint32_t TAIL_sense(void);
void delayMs(int n);
void WALK_away(uint16_t distance);
void TURN_away();
uint32_t light;
uint32_t dis;

#define RED  (1U<<1) //PF1
#define BLUE (1U<<2) //PF2
#define GREEN (1U<<3) //PF3
#define IR_PIN   (1U<<5)//PA5 (INPUT)
#define LOOK_LEFT	    319999
#define LOOK_FORWARD 160000
#define	LOOK_RIGHT    10000

int main()
{
  	 TAIL_Init();
	   HEAD_Init();
	   LIGHTS_Init();
	   MOTOR_Init();
	   servo_init();
	// GPIOF->DATA |=RED;
	while(1)
	{
		look_left();
//		
//		  echoAndTimer0_Init();
//	  	dis=headSensor_detect();
//	  
//	// if(dis<=7 &&(TAIL_sense() ==IR_PIN))
//	  if(dis<=7 && dis >=2)
//		{
//		 GPIOF->DATA |=BLUE;
//		 //FORWARD();
//			WALK_away(2000);
//		//delayMs(4000);
//	 }
//	 else
//	 {
//		 GPIOF->DATA &=~BLUE;
//		 
//		  STOP();
//	 }
//	 // if(TAIL_sense()!=IR_PIN &&(dis > 7))
//	   if(TAIL_sense()!=IR_PIN)
//		{
//		
//		
//			 GPIOF->DATA |=RED;
//			
//			  TURN_away();
//	
//			
//		}
//		 else
//		 {
//			 	
//			GPIOF->DATA &=~RED;
//		 STOP();
//		
//		 }
//	 }
}
}
/* delay n milliseconds (16 MHz CPU clock) */
 void WALK_away(uint16_t distance)
 {
	 TURN_Left();
	 delayMs(6000);
	 FORWARD();
	 delayMs(10000+distance);
	 
 }
 void TURN_away(void)
 {
	 TURN_Right();
	 delayMs(6000);
 }
