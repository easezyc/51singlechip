#include<reg51.h>
#include<intrins.h>
#include<rtx51tny.h>
#include<string.h>
#include<stdlib.h>
#include<stdio.h>
#include<math.h>
#include<string.h>
#define INIT	0
#define TASK1 1	   //����1
#define TASK2 2	   //����2
#define TASK3 3	   //����3
#define uchar unsigned char

//input
#define COLUMN0 0xFE	//��һ�а�ť
#define COLUMN1 0xFD	//�ڶ��а�ť
#define COLUMN2 0xFB	//�����а�ť
#define COLUMN3 0xF7	//�����а�ť
#define COLUMN4 0xEF	//�����а�ť
#define NULLCOLUMN 0x1F	//û�а�ť����ʱP1.0-p1.4�ĵ�ƽ
#define NULLKEY 0x3F	//û�а�ť����ʱP2.0-P2.5�ĵ�ƽ
#define KeyPortCol P1	//����P1�˿�
#define KeyPortRan P2	//����P2�˿�

//dis	 
#define DELAYTIME 10	//������ʱ
#define DISPLAYMODE 0x38
#define CLS 0x01
#define OPENDISPLAY 0x0F
#define CURSORRESET 0x02
#define MOVECURSOR 0x06
#define DOTA 0x40
#define DataPort P0	   //����P0�˿�

extern uchar DisplayFlag;
extern uchar mark1;  //�������
extern uchar mark2;	 //��ǵ�ǰ����
extern char KeyBuffer;//�洢����ĵ����ַ�
extern uchar mark3;	 //���ư���̧����
extern uchar addmark;  //��ǵ�ǰkeybuffer�Ƿ���Ҫ�洢
extern uchar list[21][16];//�ַ������飬���ڴ洢������ַ���
extern double mem[20];	 //�ַ���ת������������
extern uchar null[16];	 //����nullΪ16���ո�
extern uchar showmark;	 //��ʾ����ѡ��
extern uchar result[16]; //���ڼ�����
extern uchar sound;  //��Ƿ������Ƿ���Ҫ��
extern uchar errorresult[16];  //��ʾ������Ϣ

extern void addnum(); //һ������������
extern void backspace();  //�˸�
extern void sum();  //���
extern void powsum();  //��ƽ����
extern void average1();  //��ƽ����
extern void average2();  //��ƽ����ƽ����
extern void standarddeviation(); //���׼��
extern void variance();  //�󷽲�
extern void change();   //�������л�
extern void error1();  //����1��Խ�磬���������λ�����ܳ���15
extern void error2();  //����2��Խ�磬�����������20������
extern void error3();  //����3��û���������־ͽ�������