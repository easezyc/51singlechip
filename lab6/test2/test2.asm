TMOD_W	EQU	00010001B
		;GATE1=1
		;C/T1=0
		;M1=0,M0=1
I_TH0	EQU	03CH
I_TL0	EQU	0B0H
I_TH1	EQU	03CH
I_TL1	EQU	0B0H
A_TIME1	EQU	4
A_TIME0	EQU	40
A_LAMP	EQU	P2 
MARK	bit	0h	;0��ʾ��1��ʾ��
LED		EQU	01111111B
	ORG	0000H
	LJMP	START
	ORG	000BH
	LJMP	T0_S
	ORG	001BH
	LJMP	T1_S
	ORG	0030H
START:	LCALL	INIT
MLOOP:
	SJMP	MLOOP
INIT:	MOV	A_LAMP,#LED
	MOV	R0,#0
	MOV	R2,A_LAMP
	MOV	R1,#0
	MOV	TMOD,#TMOD_W
	MOV	TH0,#I_TH0
	MOV	TL0,#I_TL0
	MOV	TH1,#I_TH1
	MOV	TL1,#I_TL1
	SETB	ET0
	SETB	EA
	SETB	TR0
	SETB	MARK
	SETB	ET1
	SETB	TR1
	RET
T0_S:
	INC	R0
	CJNE	R0,#A_TIME0,EXIT0
	MOV	R0,#0
	MOV		A,R2
	RL		A
	MOV		R2,A
EXIT0:	MOV	TH1,#I_TH1
	MOV	TL1,#I_TL1
	RETI
T1_S:
	INC	R1
	CJNE	R1,#A_TIME1,EXIT1
	MOV	R1,#0
	JB	MARK,MIE
	MOV	A_LAMP,R2
	SETB	MARK
	SJMP	EXIT1
MIE:	
	MOV	A_LAMP,#0FFH
	CLR	MARK
EXIT1:	
	MOV	TH1,#I_TH1
	MOV	TL1,#I_TL1
	RETI
	END