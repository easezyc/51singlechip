#include<head.h>
void addnum() //���һ�����ֵ����
{
	if(mark1==20)error2();
	else{
		if(list[mark1][0]=='-'&&(list[mark1][1]<'0'|list[mark1][1]>'9'))
		{
		 	list[mark1][0]='0';
		}
		if(list[mark1][mark2-1]=='.')
		{
		 	list[mark1][mark2-1]=' ';
			mark2--;
		}
		mem[mark1]=atof(list[mark1]);
		mark1++;
		mark2=0;
		showmark=0;
		sound=0;
	}
	addmark=0;
	DisplayFlag=1;
}
void backspace() //�˸�
{
	if(mark2>0)
	{
		mark2--;
		list[mark1][mark2]=' ';
	}
    addmark=0;
	sound=0;
	showmark=0;
	DisplayFlag=1;
}
void sum()	  //���
{
	if(mark1==0)error3();
	else
	{
		double tsum=0;
		int i;
		for(i=0;i<mark1;i++)
		{
		 	tsum+=mem[i];
		}
		for(i=0;i<16;i++)
		{
		 	result[i]=' ';
		}
		sprintf(result,"%f",tsum);
		showmark=2;
		addmark=0;
		sound=0;
		DisplayFlag=1;
	}
}
void powsum()	  //ƽ����
{
	if(mark1==0)error3();
	else
	{
		double tsum=0;
		int i;
		for(i=0;i<mark1;i++)
		{
		 	tsum=tsum+mem[i]*mem[i];
		}
		for(i=0;i<16;i++)
		{
		 	result[i]=' ';
		}
		sprintf(result,"%f",tsum);
		showmark=2;
		addmark=0;
		sound=0;
		DisplayFlag=1;
	}
}
void average1()	   //ƽ����
{
	if(mark1==0)error3();
	else
	{
	 	double tsum=0;
		int i;
		for(i=0;i<mark1;i++)
		{
		 	tsum+=mem[i];
		}
		for(i=0;i<16;i++)
		{
		 	result[i]=' ';
		}
		tsum=tsum/mark1;
		sprintf(result,"%f",tsum);
		showmark=2;
		addmark=0;
		sound=0;
		DisplayFlag=1;
	}
}
void average2()		//ƽ��ƽ����
{
	if(mark1==0)error3();
	else
	{
	 	double tsum=0;
		int i;
		for(i=0;i<mark1;i++)
		{
		 	tsum=tsum+mem[i]*mem[i];
		}
		for(i=0;i<16;i++)
		{
		 	result[i]=' ';
		}
		tsum=tsum/mark1;
		sprintf(result,"%f",tsum);
		showmark=2;
		addmark=0;
		sound=0;
		DisplayFlag=1;
	}
}
void standarddeviation()	//��׼��
{
	if(mark1==0)error3();
	else
	{
		double avg=0;
		double tsum=0;
		int i;
		for(i=0;i<mark1;i++)
		{
		 	avg+=mem[i];
		}
		avg=avg/mark1;
		for(i=0;i<mark1;i++)
		{
		 	tsum=tsum+(mem[i]-avg)*(mem[i]-avg);
		}
		for(i=0;i<16;i++)
		{
		 	result[i]=' ';
		}
		tsum=tsum/mark1;
		tsum=sqrt(tsum);
		sprintf(result,"%f",tsum);
		showmark=2;
		addmark=0;
		sound=0;
		DisplayFlag=1;
	}	
}
void variance()		 //����
{
	if(mark1==0)error3();
	else
	{
		double avg=0;
		double tsum=0;
		int i;
		for(i=0;i<mark1;i++)
		{
		 	avg+=mem[i];
		}
		avg=avg/mark1;
		for(i=0;i<mark1;i++)
		{
		 	tsum=tsum+(mem[i]-avg)*(mem[i]-avg);
		}
		for(i=0;i<16;i++)
		{
		 	result[i]=' ';
		}
		tsum=tsum/mark1;
		sprintf(result,"%f",tsum);
		showmark=2;
		addmark=0;
		sound=0;
		DisplayFlag=1;
	}	
}
void change()	//�޸�������
{
	uchar i;
	if(list[mark1][0]=='-')
	{
		for(i=0;i<15;i++)
		{
			list[mark1][i]=list[mark1][i+1];
		}
		list[mark1][15]='\0';
		mark2--;
	}
	else{
		for(i=15;i>0;i--)
		{
			list[mark1][i]=list[mark1][i-1];
		}
		list[mark1][0]='-';	
		mark2++;
	}
	showmark=0;
	addmark=0;
	sound=0;
	DisplayFlag=1;
}