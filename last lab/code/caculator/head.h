#include<reg51.h>
#include<intrins.h>
#include<rtx51tny.h>
#include<string.h>
#include<stdlib.h>
#include<stdio.h>
#include<math.h>
#include<string.h>
#define INIT	0
#define TASK1 1	   //进程1
#define TASK2 2	   //进程2
#define TASK3 3	   //进程3
#define uchar unsigned char

//input
#define COLUMN0 0xFE	//第一列按钮
#define COLUMN1 0xFD	//第二列按钮
#define COLUMN2 0xFB	//第三列按钮
#define COLUMN3 0xF7	//第四列按钮
#define COLUMN4 0xEF	//第五列按钮
#define NULLCOLUMN 0x1F	//没有按钮按下时P1.0-p1.4的电平
#define NULLKEY 0x3F	//没有按钮按下时P2.0-P2.5的电平
#define KeyPortCol P1	//定义P1端口
#define KeyPortRan P2	//定义P2端口

//dis	 
#define DELAYTIME 10	//定义延时
#define DISPLAYMODE 0x38
#define CLS 0x01
#define OPENDISPLAY 0x0F
#define CURSORRESET 0x02
#define MOVECURSOR 0x06
#define DOTA 0x40
#define DataPort P0	   //定义P0端口

extern uchar DisplayFlag;
extern uchar mark1;  //标记行数
extern uchar mark2;	 //标记当前列数
extern char KeyBuffer;//存储输入的单个字符
extern uchar mark3;	 //控制按键抬起检查
extern uchar addmark;  //标记当前keybuffer是否需要存储
extern uchar list[21][16];//字符串数组，用于存储输入的字符串
extern double mem[20];	 //字符串转换的数字数组
extern uchar null[16];	 //设置null为16个空格
extern uchar showmark;	 //显示函数选择
extern uchar result[16]; //用于计算结果
extern uchar sound;  //标记蜂鸣器是否需要响
extern uchar errorresult[16];  //显示错误信息

extern void addnum(); //一个数字完成添加
extern void backspace();  //退格
extern void sum();  //求和
extern void powsum();  //求平方和
extern void average1();  //求平均数
extern void average2();  //求平方和平均数
extern void standarddeviation(); //求标准差
extern void variance();  //求方差
extern void change();   //正负号切换
extern void error1();  //错误1，越界，输入的数字位数不能超过15
extern void error2();  //错误2，越界，数组最多输入20个数字
extern void error3();  //错误3，没有输入数字就进行运算