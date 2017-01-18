#include<head.h>
char KeyBuffer;
uchar mark1;	//标记list的行号
uchar mark2;	//标记list的列数
uchar mark3;	//用于检验电平变化
uchar addmark;	//用于标记一个数是否输入完成
uchar DisplayFlag;	 //标记是否需要重新显示
uchar list[21][16];	 //输入的字符串
double mem[20];		 //字符串转变为数值
uchar null[16]="                ";	   //清空
uchar result[16];	 //存储计算结果
uchar errorresult[16];  //显示错误信息
uchar showmark;		 //记录当前显示调用哪个函数
uchar sound;      //标记蜂鸣器是否需要发声