#include<reg51.h>
#define uchar unsigned char
sbit speaker=P1^0;
sbit sw1=P1^2;
sbit sw2=P1^3;
sbit sw3=P1^4;
sbit sw4=P1^5;
uchar T_Mod=0x11;
uchar T10msL=0xD8;
uchar T10msH=0xEF;
uchar index;
uchar tint_c;
uchar note_l;
uchar note_h;
uchar ic_tmp=0;
uchar temp=0;
code uchar musicfreqh[]={
	0xF2,0xF3,0xF5,0xF5,0xF6,0xF7,0xF8,
	0xF9,0xF9,0xFA,0xFA,0xFB,0xFB,0xFC,0xFC,
	0xFC,0xFD,0xFD,0xFD,0xFD,0xFE,
	0xFE,0xFE,0xFE,0xFE,0xFE,0xFE,0xFE
	};
code uchar musicfreql[]={
	0x42,0xC1,0x17,0xB6,0xD0,0xD1,0xB6,
	0x21,0xE1,0x8C,0xD8,0x68,0xE9,0x5B,0x8F,
	0xEE,0x44,0x6B,0xB4,0xF4,0x2D,
	0x47,0x77,0xA2,0xB6,0xDA,0xFA,0x16};
code uchar musicn_del1[]={50,50,50,50,50,50,50,50,50,50,100,50,50,
100,50,50,50,50,100,100,50,50,50,50,100,100,100,100,100,100,100,100};
code uchar musicnotet1[]={7,8,9,7,7,8,9,7,9,10,11,9,10,11,11,12,
11,10,9,7,11,12,11,10,9,7,8,4,7,8,4,7,00}; //¡Ω÷ª¿œª¢
code uchar musicn_del2[]={50,50,100,50,50,100,50,50,50,25,25,50,50,100,50,50,50,25,25,
50,50,100,50,50,100,50,50,100,100,50,50,50,50,100,50,50,50,50,
100,50,50,50,50,50,50,50,50,50,50,50,50,100};
code uchar musicnotet2[]={11,11,11,11,11,11,9,11,12,11,9,8,9,11,11,9,11,9,8,
7,9,8,9,9,8,12,7,8,12,12,11,9,12,11,11,9,8,9,
11,11,9,8,9,11,9,8,9,5,7,8,9,7,00};	  //¬Ù±®∏Ë
code uchar musicn_del3[]={50,50,50,50,50,50,100,50,50,50,50,100,50,50,50,50,50,50,100,
50,50,50,50,100,50,50,50,50,50,50,100,50,50,50,50,100,
50,50,50,50,50,50,100,50,50,50,50,100};
code uchar musicnotet3[]={11,9,11,9,11,9,7,8,10,9,8,11,11,9,11,9,11,9,7,
8,10,9,8,7,8,8,10,10,9,7,11,8,10,9,8,11,
11,9,11,9,11,9,7,8,10,9,8,7,00}; 	 //∑€À¢Ω≥
code uchar musicn_del4[]={50,50,50,50,50,50,100,50,50,50,50,100,100,
50,50,50,50,50,50,100,50,50,50,50,100,100,100,
50,50,50,50,50,50,100};
code uchar musicnotet4[]={11,12,11,12,11,12,11,11,14,13,12,11,9,
11,11,9,10,11,11,9,11,11,9,10,11,11,9,
7,10,9,8,7,8,7,00};	  //’“≈Û”—
void timer_initial(void){
	TMOD=T_Mod;
	TL1=T10msL;
	TH1=T10msH;
	ET0=1;
	ET1=1;
}
void Time0(void) interrupt 1 using 1{
	TR0=0;
	TL0=note_l;
	TH0=note_h;
	speaker=~speaker;
	TR0=1;
}
void Time1(void) interrupt 3 using 2{
	TR1=0;
	TL1=T10msL;
	TH1=T10msH;
	ic_tmp++;
	TR1=1;
}
void main()
{
	int mark=1;
	int keep=1;
	int t=0;
	while(1){
		index=0;
		timer_initial();
		if(mark==1){keep=1;t=musicnotet1[index];}
		else if(mark==2){keep=2;t=musicnotet2[index];}
		else if(mark==3){keep=3;t=musicnotet3[index];}
		else if(mark==4){keep=4;t=musicnotet4[index];}
		for(index=0;musicnotet3[index]!=0;index++){
			if(!sw1){
			   mark=1;
			}
			if(!sw2){
			   mark=2;
			}
			if(!sw3){
			   mark=3;
			}
			if(!sw4){
			   mark=4;
			}
			EA=0;
			TR0=0;
			TR1=0;
			ic_tmp=0;
			if(keep==1){
				tint_c=musicn_del1[index];
				temp=musicnotet1[index];
				t=musicnotet1[index];
			}
			else if(keep==2){
				tint_c=musicn_del2[index];
				temp=musicnotet2[index];
				t=musicnotet2[index];
			}
			else if(keep==3){
				tint_c=musicn_del3[index];
				temp=musicnotet3[index];
				t=musicnotet3[index];
			}
			else if(keep==4){
				tint_c=musicn_del4[index];
				temp=musicnotet4[index];
				t=musicnotet4[index];
			}
			note_l=musicfreql[temp];
			note_h=musicfreqh[temp];
			TR0=1;
			TR1=1;
			EA=1;
			while(tint_c!=ic_tmp);
		}
	}
}