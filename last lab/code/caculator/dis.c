#include<head.h>
sbit LCD_RS=P3^0;
sbit LCD_RW=P3^6;
sbit LCD_E=P3^1;
uchar LCD_ReadStatus(void)	 //定义显示屏读状态函数
{		 
	DataPort=0xFF;
	LCD_RS=0;
	LCD_RW=1;
	LCD_E=1;
	while(DataPort&0x80);
	return(DataPort);
}
uchar LCD_ReadData(void)   //定义读数据函数
{	  
	LCD_RS=1;
	LCD_RW=1;
	LCD_E=1;
	return(DataPort);
}
void LCD_WriteCommand(uchar CMDW,uchar Busy)   //定义写指令函数
{
	if(Busy)LCD_ReadStatus();
	LCD_RS=0;
	LCD_RW=0;
	LCD_E=1;
	DataPort=CMDW;
	LCD_E=0;
	_nop_();
	_nop_();
	_nop_();
	_nop_();
	LCD_E=1;
}
void LCD_WriteData(uchar WData)	//向LCD写数据
{   
	LCD_RS=1;
	LCD_RW=0;
	LCD_E=1;
	DataPort=WData;
	LCD_E=0;
	_nop_();
	_nop_();
	_nop_();
	_nop_();
	LCD_E=1;
}
void SetPosition(uchar X,uchar Y)	 //设置显示的坐标函数
{   
	if(Y==1)LCD_WriteCommand(X&0x0F|0xC0,0);
	else if(Y==0)LCD_WriteCommand(X&0x0F|0x80,0);
	else if(Y==2)LCD_WriteCommand(X&0x0F|0x90,0);
	else LCD_WriteCommand(X&0x0F|0xD0,0);
}
void DisplayListChar(uchar ListLength,uchar *Data) //显示字符串
{
	uchar i;
	for(i=0;i<ListLength&0x0F;i++)
		LCD_WriteData(* Data++);
}
void initarray() //初始化数组
{	 
	uchar i;
	for(i=0;i<20;i++)
	{
		uchar j;
		for(j=0;j<16;j++)
		{
			list[i][j]=' ';
		}
		mem[i]=0;
	}
	mark1=0;
	mark2=0;
	DisplayFlag=1;
	addmark=0;
	showmark=0;
	sound=0;
}
void empty()   //清空屏幕
{
	uchar i;
	for(i=0;i<20;i++)
	{
		uchar j;
		for(j=0;j<16;j++)
		{
			list[i][j]=0;
		}
		mem[i]=0;
	}
	mark1=0;
	mark2=0;
	sound=0;
	DisplayFlag=1;
	addmark=0;
	showmark=0;
	SetPosition(0,0);
	DisplayListChar(16,null);
	SetPosition(0,1);
	DisplayListChar(16,null);
	SetPosition(0,2);
	DisplayListChar(16,null);
	SetPosition(0,3);
	DisplayListChar(16,null);
}
void Task0(void) _task_ INIT   //定义进程0，做初始化操作
{
	while(1){
		os_reset_interval(DELAYTIME);
		LCD_WriteCommand(DISPLAYMODE,0);
		os_wait(K_IVL,DELAYTIME,0);
		LCD_WriteCommand(OPENDISPLAY,0);
		os_wait(K_IVL,DELAYTIME,0);
		LCD_WriteCommand(MOVECURSOR,0);
		os_wait(K_IVL,DELAYTIME,0);
		LCD_WriteCommand(CLS,0);
		os_wait(K_IVL,DELAYTIME,0);
		LCD_WriteCommand(CURSORRESET,0);
		os_wait(K_IVL,DELAYTIME,0);
		initarray();
		mark3=0;
		KeyBuffer=' ';	
		os_create_task(TASK1);
		os_create_task(TASK2);
		os_create_task(TASK3);
		os_delete_task(INIT);
	}
}
void addword()//添加一个数字
{
	if(mark2==15)error1();
	else {
		if(KeyBuffer=='.')
		{
			if(mark2==0||(list[mark1][mark2-1]<'0'||list[mark1][mark2-1]>'9')){
				list[mark1][mark2]='0';
				mark2++;
			}
		}
		list[mark1][mark2]=KeyBuffer;
		mark2++;
	}
	addmark=0;
}
void normalshow()//正常显示，显示输入的数字
{
	if(mark1>=4)
	{
 		int i;
		for(i=0;i<4;i++)
		{
			SetPosition(0,i);
			DisplayListChar(16,list[mark1-3+i]);
		}
	}
	else{
 		int i;
		for(i=0;i<=mark1;i++)
		{
			SetPosition(0,3-mark1+i);
			DisplayListChar(16,list[i]);
		}
	}
	DisplayFlag=0;
}
void showresult()//显示统计计算后的结果
{
	SetPosition(0,0);
	DisplayListChar(16,null);
	SetPosition(0,1);
	DisplayListChar(16,null);
	SetPosition(0,2);
	DisplayListChar(16,null);
	SetPosition(0,3);
	DisplayListChar(16,result);
	DisplayFlag=0;
}
void showerror()//显示错误的信息
{
	SetPosition(0,0);
	DisplayListChar(16,null);
	SetPosition(0,1);
	DisplayListChar(16,null);
	SetPosition(0,2);
	DisplayListChar(16,null);
	SetPosition(0,3);
	DisplayListChar(16,errorresult);
	DisplayFlag=0;
}
void Task1_DisplayBuffer(void) _task_ TASK1	 //进程1控制LCD的进程
{
	while(1){
		if(addmark==1)addword();
		if(DisplayFlag){
			switch(showmark){
			 	case 1:empty();break;
				case 2:showresult();break;
				case 3:showerror();break;
				case 0:normalshow();break;
			}
		}
		os_switch_task();
		LCD_ReadData();
	}
}