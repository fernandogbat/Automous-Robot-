;motors.s 
;Function to initialize motor pins

	
GPIO_PORTE_DATA_R 	EQU 	0x400243FC
GPIO_PORTE_DIR_R  	EQU 	0x40024400
GPIO_PORTE_DEN_R  	EQU 	0x4002451C


SYSCTL_RCGCGPIO_R  EQU  0x400FE608
	
			AREA |.text|, CODE, READONLY, ALIGN=2
			THUMB
			EXPORT MOTOR_Init
			EXPORT TURN_Left
			EXPORT TURN_Right
			EXPORT FORWARD
			EXPORT STOP
MOTOR_Init
			LDR R1,=SYSCTL_RCGCGPIO_R
			LDR R0,[R1]
			ORR R0,R0,#0x10  ; 0B 0000 0000
			STR R0,[R1]
			
			LDR R1,=GPIO_PORTE_DIR_R
			LDR R0,[R1]
			ORR R0,R0,#0x0C  ;PE2,PE3 0000 1100
            STR R0,[R1]
			
			LDR R1,=GPIO_PORTE_DEN_R
			LDR R0,[R1]
			ORR R0,R0,#0x0C
			STR R0,[R1]
			BX  LR
			
TURN_Left
			LDR R1,=GPIO_PORTE_DATA_R
			MOV R0,#0x04     ;PE2, 0000 0100
			STR R0,[R1]
			BX  LR

TURN_Right 
            LDR R1,=GPIO_PORTE_DATA_R
			MOV R0,#0x08  ;PE3 0000 1000
			STR R0,[R1]
			BX  LR
FORWARD 
			LDR R1,=GPIO_PORTE_DATA_R
			MOV R0,#0x0C
			STR R0,[R1]
			BX  LR

STOP
			LDR R1,=GPIO_PORTE_DATA_R
			MOV R0,#0x00
			STR R0,[R1]
			BX  LR
			
			ALIGN
			END