#include<head.h>
void error1() //错误1，数组越界,每个字符串不超过15个字符
{
	strncpy(errorresult,"col over range",16);
	showmark=3;
	DisplayFlag=1;
	addmark=0;
	sound=1;
}
void error2() //错误2，数组越界，总共只能有20个字符串
{
	sprintf(errorresult,"raw over range");
	showmark=3;
	DisplayFlag=1;
	addmark=0;
	sound=1;
}
void error3() //错误3，还没有输入数字就进行运算
{
	sprintf(errorresult,"please input num");
	showmark=3;
	DisplayFlag=1;
	addmark=0;
	sound=1;
}