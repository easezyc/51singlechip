#include<head.h>
char KeyBuffer;
uchar mark1;	//���list���к�
uchar mark2;	//���list������
uchar mark3;	//���ڼ����ƽ�仯
uchar addmark;	//���ڱ��һ�����Ƿ��������
uchar DisplayFlag;	 //����Ƿ���Ҫ������ʾ
uchar list[21][16];	 //������ַ���
double mem[20];		 //�ַ���ת��Ϊ��ֵ
uchar null[16]="                ";	   //���
uchar result[16];	 //�洢������
uchar errorresult[16];  //��ʾ������Ϣ
uchar showmark;		 //��¼��ǰ��ʾ�����ĸ�����
uchar sound;      //��Ƿ������Ƿ���Ҫ����