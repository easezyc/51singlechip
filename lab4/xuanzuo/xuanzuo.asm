SW1		BIT		P1.2
SW2		BIT		P1.3
SW3		BIT		P1.4
SW4		BIT		P1.5
A_LAMP	EQU		P2
INITG	EQU		01111111B
INITR	EQU		10111111B
LEN		EQU		3h
	ORG		0000H
	LJMP	START
	ORG		0030H
START:	MOV	R1,#00H
		MOV	R2,#00H
		MOV	A_LAMP,#0FEH
NEXT:	JB	SW1,NEXT1
	MOV	R1,#00H
	SJMP	NEXT
NEXT1:	JB	SW2,NEXT2
	MOV	R1,#01H
	SJMP	NEXT
NEXT2:	JB	SW3,NEXT3
	MOV	R2,#01H
	MOV	A_LAMP,#INITG
	SJMP	NEXT
NEXT3:	JB	SW4,CAL
	MOV	R2,#01H
	MOV	A_LAMP,#INITR
	SJMP	NEXT
CAL:	
	MOV A,R2
	JNZ	PT
	MOV	A,R1
	JZ	T2
T11:	MOV	A,A_LAMP
	RL	A;��
	MOV	A_LAMP,A
	SJMP	O
T2:	MOV	A,A_LAMP
	RR	A;˳
	MOV	A_LAMP,A
	SJMP	O
PT:	MOV	A,R1
	JZ	T4
T3:	MOV	A,A_LAMP
	RL	A;��
	RL	A;��
	MOV	A_LAMP,A
	SJMP	O
T4:	MOV	A,A_LAMP
	RR	A;˳
	RR	A;˳
	MOV	A_LAMP,A
O:	
	MOV	R5,#LEN
	LCALL	DELAY
	SJMP	NEXT
DELAY:	MOV		R7,#00H
		MOV		R6,#00H
LOOP:	DJNZ	R7,LOOP
		DJNZ	R6,LOOP
		DJNZ	R5,LOOP
		RET
	END