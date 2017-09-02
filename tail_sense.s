; tail_sense.s
; Function to trigger tail sensor (IR_Sensor)
GPIO_PORTA_DATA_R  EQU 0x400043FC
		AREA |.text|, CODE, READONLY, ALIGN=2
		THUMB
		EXPORT TAIL_sense

TAIL_sense
		LDR R1,=GPIO_PORTA_DATA_R
		LDR R0,[R1]
		AND R0,R0,#0x20
		BX LR
		ALIGN
		END