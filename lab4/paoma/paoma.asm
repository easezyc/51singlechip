LAMP	EQU		P2
INIT	EQU		0FEH
LEN		EQU		10H
	ORG		0000H
	LJMP	START
	ORG		0030H
START:	MOV		LAMP,#INIT
MLOOP:	MOV		R5,#LEN
		LCALL	DELAY
		MOV		A,LAMP
		RL		A
		MOV		LAMP,A
		SJMP  MLOOP
DELAY:	MOV		R7,#00H
		MOV		R6,#00H
LOOP:	DJNZ	R7,LOOP
		DJNZ	R6,LOOP
		DJNZ	R5,LOOP
		RET
	END