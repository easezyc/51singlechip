#include<head.h>
void error1() //����1������Խ��,ÿ���ַ���������15���ַ�
{
	strncpy(errorresult,"col over range",16);
	showmark=3;
	DisplayFlag=1;
	addmark=0;
	sound=1;
}
void error2() //����2������Խ�磬�ܹ�ֻ����20���ַ���
{
	sprintf(errorresult,"raw over range");
	showmark=3;
	DisplayFlag=1;
	addmark=0;
	sound=1;
}
void error3() //����3����û���������־ͽ�������
{
	sprintf(errorresult,"please input num");
	showmark=3;
	DisplayFlag=1;
	addmark=0;
	sound=1;
}