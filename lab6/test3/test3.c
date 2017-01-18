#include<reg51.h>
#define uchar unsigned char
sbit speaker=P1^0;
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
code uchar musicn_del[]={100,100,100,100,100,100,100,100};
code uchar musicnotet[]={7,8,9,10,11,12,13,14,00};
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
	while(1){
		index=0;
		timer_initial();
		for(index=0;musicnotet[index]!=0;index++){
			EA=0;
			TR0=0;
			TR1=0;
			ic_tmp=0;
			tint_c=musicn_del[index];
			temp=musicnotet[index];
			note_l=musicfreql[temp];
			note_h=musicfreqh[temp];
			TR0=1;
			TR1=1;
			EA=1;
			while(tint_c!=ic_tmp);
		}
	}
}