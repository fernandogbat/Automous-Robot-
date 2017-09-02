;Author : Israel N. Gbati
;head.s
;Function to initialize trigger pin of ultrasonic
;(head) sensor
	
	
GPIO_PORTA_DIR_R   EQU 0x40004400
GPIO_PORTA_DEN_R   EQU 0x4000451C
SYSCTL_RCGCGPIO_R  EQU 0x400FE608	
	
    	AREA |.text|, CODE, READONLY, ALIGN=2
		THUMB
		EXPORT HEAD_Init

HEAD_Init
		LDR R1,=SYSCTL_RCGCGPIO_R
		LDR R0,[R1]
		ORR R0,R0,#0x01
		STR R0,[R1]
		
		LDR R1,=GPIO_PORTA_DIR_R
		LDR R0,[R1]
		ORR R0,R0,#0x10
		;MOV R0,#0x10 ; 0B 0001 0000
		STR R0,[R1]
		
		LDR R1,=GPIO_PORTA_DEN_R
		LDR R0,[R1]
		ORR R0,R0,#0x10;
		;MOV R0,#0x10
		STR R0,[R1]
		BX  LR
		
		ALIGN
		END
