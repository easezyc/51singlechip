T1MOD_W	EQU	00100000B
			;GATE1=0
			;C/T1=0
			;M1=1,M0=0
BPS_I	EQU	0FDH
		ORG 0000H
		LJMP	START
		ORG	0030H
START:	LCALL	INIT
MLOOP:	CLR	TI
		MOV	R1,#6
		MOV	R3,#00H
LOOP:	MOV	A,R3
		MOV	DPTR,#TABLE
		MOVC	A,@A+DPTR
		MOV	SBUF,A
WAIT:	JNB	TI,WAIT
		CLR	TI
		INC	R3
		DJNZ	R1,LOOP
		SJMP	MLOOP
INIT:	CLR	SM0
		SETB	SM1
		MOV	TMOD,#T1MOD_W
		MOV	TH1,#BPS_I
		MOV	TL1,#BPS_I
		SETB	TR1
		RET
TABLE:
		DB	'H','e','l','l','o',0DH,0AH
		END