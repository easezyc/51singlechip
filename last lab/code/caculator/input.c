#include<head.h>
uchar KeyEncoded(uchar KeyScanCode1,uchar KeyScanCode2)//�����̾��尴��
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
uchar KeyScan(void)		//ɨ�����
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
void choose(uchar t)	//�������ܵ���
{
	switch(t){
		case 'r':addnum();break; //ȷ���������
		case 'h':DisplayFlag=1;showmark=1;break;	//����
		case 'f':backspace();break;	 //�˸�	
		case 'm':sum();break;	//���
		case 'n':powsum();break;   //��ƽ����
		case 'k':average1();break;   //��ƽ����
		case 'l':average2();break;   //��ƽ��ƽ����
		case 'o':standarddeviation();break;  //���׼��
		case 'p':variance();break;   //�󷽲�
		case 'q':change();break;
	}
}
void Task2_ReadKey(void) _task_ TASK2	  //����2ɨ�����벢������Ӧ�����������뵽����1
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
		if(mark3==0&&((KeyScanValue>='0'&&KeyScanValue<='9')||KeyScanValue=='.')) //��������ֻ���С����������
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