A_LAMP	EQU		P2
EW_G	EQU		01100110B
A_RED	EQU		11111111B
A_Y		BIT		P1.1
LEN_GR	EQU		28H
LEN_SP	EQU		8H
		ORG		0000H
		LJMP	START
		ORG		0003H
		LJMP	INT0_S
		ORG		0013H
		LJMP	INT1_S
		ORG		0030H
START:	MOV		SP,#60H
		LCALL	INIT
MLOOP:	MOV		R5,#LEN_GR
		LCALL	DELAY
		XRL		A_LAMP,#0FFH
		SJMP	MLOOP
INIT:	MOV		A_LAMP,#EW_G
		SETB	A_Y
		SETB	IT0
		SETB	PX1
		SETB	EX1
		SETB	EX0
		SETB	EA
		RET
DELAY:	MOV		R7,#00H
		MOV		R6,#00H
LOOP:	DJNZ	R7,LOOP
		DJNZ	R6,LOOP
		DJNZ	R5,LOOP
		RET
INT0_S:	CLR		EA
		PUSH	PSW
		MOV		A,A_LAMP
		PUSH	ACC
		CLR		RS1
		SETB	RS0
		SETB	EA
		MOV		A_LAMP,#A_RED
		MOV		R1,#0AH
T:		MOV		R5,#LEN_SP
		LCALL	DELAY
		XRL		A_LAMP,#0FFH
		DJNZ	R1,T
		CLR		EA
		POP		ACC
		MOV		A_LAMP,A
		POP		PSW
		SETB	EA
		RETI
INT1_S:	CLR		EA
		PUSH	PSW
		SETB	RS1
		CLR		RS0
		SETB	EA
		MOV		A,A_LAMP
		PUSH	ACC
		MOV		A_LAMP,#A_RED
		MOV		R1,#05H		
K:		CLR		A_Y
		MOV		R5,#LEN_SP
		LCALL	DELAY
		SETB	A_Y
		MOV		R5,#LEN_SP
		LCALL	DELAY
		DJNZ	R1,K
		POP		ACC
		MOV		A_LAMP,A
		CLR		EA
		POP		PSW
		SETB	EA
		RETI
		END