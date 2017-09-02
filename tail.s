;#define IR_PIN   (1U<<5)//PA5 (INPUT)
;portA clock
;set PA5 as input
;Enable PA5
;Check PortA data register to see if PA5 is high
GPIO_PORTA_DIR_R   EQU 0x40004400
GPIO_PORTA_DEN_R   EQU 0x4000451C
SYSCTL_RCGCGPIO_R  EQU 0x400FE608

        AREA |.text|, CODE, READONLY, ALIGN=2
		THUMB
		EXPORT TAIL_Init
			
TAIL_Init
		LDR R1, =SYSCTL_RCGCGPIO_R
		LDR R0,[R1]
		ORR R0,R0,#0x01
		STR R0,[R1]
        
        LDR R1,=GPIO_PORTA_DIR_R
		LDR R0,[R1]
		ORR R0,R0,#0x00
        ;MOV R0,#0x00
		STR R0,[R1]
		
		LDR R1,=GPIO_PORTA_DEN_R
		LDR R0,[R1]
		ORR R0,R0,#0x20
		;MOV R0,#0x20
		STR R0,[R1]
		BX  LR


	   ALIGN
	   END
		   