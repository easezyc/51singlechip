#include<head.h>
uchar KeyEncoded(uchar KeyScanCode1,uchar KeyScanCode2)//检查键盘具体按键
{   
	uchar KeyCode=0;
	switch(KeyScanCode2){
		case 0x1E:
			switch(KeyScanCode1){
				case 0x3E:KeyCode='a';break;
				case 0x3D:KeyCode='f';break;
				case 0x3B:KeyCode='7';break;
				case 0x37:KeyCode='4';break;
				case 0x2F:KeyCode='1';break;
				case 0x1F:KeyCode='0';break;	
			}
			break;
		case 0x1D:
			switch(KeyScanCode1){
				case 0x3E:KeyCode='b';break;
				case 0x3D:KeyCode='g';break;
				case 0x3B:KeyCode='8';break;
				case 0x37:KeyCode='5';break;
				case 0x2F:KeyCode='2';break;
				case 0x1F:KeyCode='0';break;	
			}
			break;
		case 0x1B:
			switch(KeyScanCode1){
				case 0x3E:KeyCode='c';break;
				case 0x3D:KeyCode='h';break;
				case 0x3B:KeyCode='9';break;
				case 0x37:KeyCode='6';break;
				case 0x2F:KeyCode='3';break;
				case 0x1F:KeyCode='.';break;	
			}
			break;
		case 0x17:
			switch(KeyScanCode1){
				case 0x3E:KeyCode='d';break;
				case 0x3D:KeyCode='i';break;
				case 0x3B:KeyCode='k';break;
				case 0x37:KeyCode='m';break;
				case 0x2F:KeyCode='o';break;
				case 0x1F:KeyCode='q';break;	
			}
			break;
		case 0x0F:
			switch(KeyScanCode1){
				case 0x3E:KeyCode='e';break;
				case 0x3D:KeyCode='j';break;
				case 0x3B:KeyCode='l';break;
				case 0x37:KeyCode='n';break;
				case 0x2F:KeyCode='p';break;
				case 0x1F:KeyCode='r';break;	
			}
			break;
	}
	return KeyCode;
}
uchar KeyScan(void)		//扫描键盘
{	 
	uchar ScanValue;
	KeyPortCol=COLUMN0;
	ScanValue=KeyPortRan&NULLKEY;
	if(ScanValue!=NULLKEY){
		return KeyEncoded(ScanValue,(COLUMN0&NULLCOLUMN));
	}
	KeyPortCol=COLUMN1;
	ScanValue=KeyPortRan&NULLKEY;
	if(ScanValue!=NULLKEY){
		return KeyEncoded(ScanValue,(COLUMN1&NULLCOLUMN));
	}
	KeyPortCol=COLUMN2;
	ScanValue=KeyPortRan&NULLKEY;
	if(ScanValue!=NULLKEY){
		return KeyEncoded(ScanValue,(COLUMN2&NULLCOLUMN));
	}
	KeyPortCol=COLUMN3;
	ScanValue=KeyPortRan&NULLKEY;
	if(ScanValue!=NULLKEY){
		return KeyEncoded(ScanValue,(COLUMN3&NULLCOLUMN));
	}
	KeyPortCol=COLUMN4;
	ScanValue=KeyPortRan&NULLKEY;
	if(ScanValue!=NULLKEY){
		return KeyEncoded(ScanValue,(COLUMN4&NULLCOLUMN));
	}
	return 0;
}
void choose(uchar t)	//函数功能调用
{
	switch(t){
		case 'r':addnum();break; //确认添加数字
		case 'h':DisplayFlag=1;showmark=1;break;	//清屏
		case 'f':backspace();break;	 //退格	
		case 'm':sum();break;	//求和
		case 'n':powsum();break;   //求平方和
		case 'k':average1();break;   //求平均数
		case 'l':average2();break;   //求平方平均数
		case 'o':standarddeviation();break;  //求标准差
		case 'p':variance();break;   //求方差
		case 'q':change();break;
	}
}
void Task2_ReadKey(void) _task_ TASK2	  //进程2扫描输入并调用相应函数或者输入到进程1
{		 
	uchar KeyScanValue=NULLKEY|NULLCOLUMN;
	uchar t=NULLKEY|NULLCOLUMN;
	while(1){
		if(mark3==0){
			KeyScanValue=KeyScan();
			choose(KeyScanValue);
			mark3=1;
		}
		else {
		 	t=KeyScan();
			if(t!=KeyScanValue){
				mark3=0;
			}
		}
		if(mark3==0&&((KeyScanValue>='0'&&KeyScanValue<='9')||KeyScanValue=='.')) //如果是数字或者小数点则输入
		{
			KeyBuffer=KeyScanValue;
			addmark=1;
			showmark=0;
			sound=0;
			DisplayFlag=1;
			os_switch_task();
		}
	}
}