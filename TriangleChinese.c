/*
**���뿪������־ΰ
**������ˣ��ļ���
*/
#include <stdio.h>
#include <math.h>
#define pi 3.1415926535897932384626
#include "headers.h"
char Input;
void EPrintfScreen();
char ELow2Up(char );
char EGetChar();
double ESin();
double ECos();
double ETan();
double EArcSin();
double EArcTan();
double EArcCos();
void TriangleChinese()
{
	
	while (Input != '#')
	{
	    EPrintfScreen();//�������Ļ
    	Input = EGetChar();//����һ���ַ����ǿո񡢷ǻس���ASCII������㣩
    	Input = ELow2Up(Input);//ת��Ϊ��д��ĸ
        if (Input == '#') break;
    	switch (Input)//���ܷ�֧
	    {
        	case 'A': printf("���Ϊ��%lf\n\n",ESin()); break;
        	case 'B': printf("���Ϊ��%lf\n\n",ECos()); break;
        	case 'C': printf("���Ϊ��%lf\n\n",ETan()); break;
        	case 'D': printf("���Ϊ��%lf\n\n",EArcSin()); break;
        	case 'E': printf("���Ϊ��%lf\n\n",EArcCos()); break;
        	case 'F': printf("���Ϊ��%lf\n\n",EArcTan()); break;
        	default: printf("�������\n\n");//���������������ַ������������
        }
	}
}
void EPrintfScreen()//�������Ļ
{
	printf("*****************************\n");
	printf("*  ��ӭʹ�����Ǻ���������!  *\n");
	printf("*****************************\n");
	printf("\n");
	printf("�ҿ��԰�����������º����ĺ���ֵ��\n");
	printf("A.sin      B.cos      C.tan\n");
	printf("D.arcsin   E.arccos   F.arctan\n");
	printf("\n");
	printf("�����������蹦��ǰ����ĸ(��Сд����)��");
}
char ELow2Up(char c)//���������Сд��ĸ����ת��Ϊ��д��ĸ�������ù�
{
	if(c >= 'a' && c <= 'z')
		c = c - 32;
	return c;
}
char EGetChar()//����һ���ַ����ǿո񡢷ǻس���ASCII������㣩
{
	char c;
	do
	{
		c = getchar();
	}
	while(c == '\n' || c ==' ' || c < 0);
	return c;
}
double ESin()//����Sin��ֵ
{
	char Input;//����ѡ��Ƕ��ƻ��ǻ�����
	double a , f , x , mul = 1 , sum = 0 ;//a�������Ҫ�����ֵ��c�ǿ⺯���Ľ����f��������ּ���ÿһ��Ľ����mul�Ǽ���׳ˣ�sum��������ּ�������һ��Ľ��
	int i = 0, j = 1, k, l, m, num = 1;//i��j��k��l��m���ڼ��������źͽ׳�
	printf("\n");
	printf("��ѡ������Ƕ���ֵ�����ͣ�\n");
	printf("A.�Ƕ���  B.������\n");
	printf("��ѡ��");
	Input = EGetChar();
	Input = ELow2Up(Input);
	printf("\n");
	switch(Input)
	{
	case 'A':
		{
			printf("������Ƕȴ�С��");
			scanf("%lf" , &x);
			a = x * 2 * pi / 360;
			break;
		}
	case 'B':
		{
			printf("�����뻡�ȴ�С��");
			scanf("%lf", &a);
			break;
		}
	default: printf("�������\n\n");//���������������ַ������������
	}
	if(a > 0)//��������ת�����涨�ķ�Χ����
	{
		while(a > 2 * pi)
		{
			a = a - 2 * pi;
			i++;
		}
	}
	else
	{
		while(a < -2 * pi)
		{
			a = a + 2 * pi;
			i++;
		}
	}
	f = a;
		while(fabs(f) >= 1e-10)
		{
	        j = j + 2;//�����ĸ�׳����⣨��ʼ��
			k = (j + 2) %4;//����������⣨��ʼ��
			if(k == 1)
			{
				l = -1;
			}
			else l = 1;//����������⣨������
			m = j ;
			while(j > 1)
	       {
		    mul = j * mul;
			j--;
	       }//�����ĸ�׳����⣨������
			j = m;
			f = l * pow(a, j) / mul;//ÿһ��Ĵ�С
			if(fabs(f) >= 1e-10)//������ּ�������ľ���
				;
			else break;
			mul = 1 ;
			sum = sum + f ;
		}
	printf("\n");
	return sum+a;
}

double ECos()//�ò���ע�Ͳο�Sin���ֵ�ע��
{
	char Input;
	double a, f, x, mul = 1, sum = 0;
	int i = 0, j = 0, k, l, m;
	printf("\n");
	printf("��ѡ������Ƕ���ֵ�����ͣ�\n");
	printf("A.�Ƕ���  B.������\n");
	printf("��ѡ��");
	Input = EGetChar();
	Input = ELow2Up(Input);
	printf("\n");
	switch(Input)
	{
	case 'A':
		{
			printf("������Ƕȴ�С��");
			scanf("%lf", &x);
			a = x * 2 * pi / 360;
			break;
		}
	case 'B':
		{
			printf("�����뻡�ȴ�С��");
			scanf("%lf", &a);
			break;
		}
	default: printf("�������\n\n");//���������������ַ������������
	}
	if(a > 0)
	{
		while(a > 2 * pi)
		{
			a = a - 2* pi;
			i++;
		}
	}
	else
	{
		while(a < -2 * pi)
		{
			a = a + 2 * pi;
			i++;
		}
	}
	f = a;
		while(fabs(f) >= 1e-10)
		{
	        j = j + 2 ;//�����ĸ�׳����⣨��ʼ��
			k = (j + 3) % 4;//����������⣨��ʼ��
			if(k == 1)
			{
				l = -1 ;
			}
			else l = 1 ;//����������⣨������
			m = j ;
			while( j > 1)
	       {
		    mul = j * mul ;
			j--;
	       }//�����ĸ�׳����⣨������
			j = m;
			f = l * pow(a, j) / mul ;//ÿһ��Ĵ�С
			if(fabs(f) >= 1e-10)
				;
			else break;
			mul = 1;
			sum = sum + f;
		}
	printf("\n");
    return sum + 1.0;
}
double ETan()//�ò��ֵ�ע�Ͳο�Sin���ֵ�ע��
{
	char Input;
	double a , f , x , mul = 1 , sum = 0 , summ = 0 ;
	int i = 0, j = 1, k, l, m, num = 1;
	printf("\n");
	printf("��ѡ������Ƕ���ֵ�����ͣ�\n");
	printf("A.�Ƕ���  B.������\n");
	printf("��ѡ��");
	Input=EGetChar();
	Input=ELow2Up(Input);
	printf("\n");
	switch(Input)
	{
	case 'A':
		{
			printf("������Ƕȴ�С��");
			scanf("%lf", &x);
			a = x * 2 * pi / 360;
			break;
		}
	case 'B':
		{
			printf("�����뻡�ȴ�С��");
			scanf("%lf", &a);
			break;
		}
	default: printf("�������\n\n");//���������������ַ������������
	}
	if(a > 0)
	{
		while(a > pi)
		{
			a = a - pi;
			i++;
		}
	}
	else
	{
		while(a < -pi)
		{
			a = a + pi;
			i++;
		}
	}
	sum=a+pow(a,3)/3+2*pow(a,5)/15+17*pow(a,7)/315+62*pow(a,9)/2835+1382*pow(a,11)/155925+21844*pow(a,13)/6081075+929569*pow(a,15)/638512875;
	return sum;
	printf("\n");
}
double EArcSin()//����ArcSin��ֵ
{
	double a ;//�⺯��
	double f , sum = 0;//f��mac��ͨ��
	int i = 1, j = 0, Mul1 = 1, Mul2 = 1, m;//���ڼ���׳ˣ�Mul1��n�Ľ׳ˣ�Mul2��2n�Ľ׳�
	printf("\n");
	printf("��������ֵ��");
	scanf("%lf", &a);
	if(a < -1 || a > 1)//���ݶ��������������ֵ����ȷ��
		printf("�������\n");
	f=a;
	while(fabs(f) >= 1e-200)
		{
			m = i;
			j = 2 * i;
			while(i > 1)
			{
				Mul1 = i * Mul1 ;
				i--;
			}
			while(j > 1)
			{
				Mul2 = j * Mul2 ;
				j--;
			}
			j = 2 * m;
			i = m ;
			f = Mul2 * pow(a,j+1) / pow(4.0,i) / Mul1 / Mul1 / (j + 1) ;
			Mul1 = 1;
			Mul2 = 1;
			i = m + 1;
			sum = sum + f;
		}
	return sum + a; 
	printf("\n");
}
double EArcCos()//�ο�ArcSin��ע��
{
	double a;//�⺯��
	double f, sum = 0;//f��mac��ͨ��
	int  i = 1, j = 0, Mul1 = 1, Mul2 = 1, m;
	printf("\n");
	printf("��������ֵ��");
	scanf("%lf", &a);
	if(a < -1 || a > 1)
		printf("�������\n");
	f = a;
	while(fabs(f) >= 1e-200)
		{
			m = i;
			j = 2 * i;
			while(i > 1)
			{
				Mul1 = i * Mul1; 
				i--;
			}
			while(j > 1)
			{
				Mul2 = j * Mul2;
				j--;
			}
			j = 2 * m;
			i = m;
			f = Mul2 * pow(a, j+1) / pow(4.0, i) / Mul1 / Mul1 / (j + 1);
			Mul1 = 1;
			Mul2 = 1;
			i = m + 1;
			sum = sum + f;
		}
	return 0.5 * pi - sum - a;
	printf("\n");
}
double EArcTan()
{
	double a, f, x, sum = 0;
	int j = 0, l, k;
	printf("\n");
	printf("��������ֵ��");
	scanf("%lf", &a);
	f = a; 
		while(fabs(f) >= 1e-7)
		{
	        j = j + 2;
			k = (j+3) % 4;//����������⣨��ʼ��
			if(k == 1)
			{
				l = -1;
			}
			else l = 1;//����������⣨������
			f = l * pow(a, j+1) / (j+1);//ÿһ��Ĵ�С
			sum = sum + f;
		}
	return sum + a;
	printf("\n");
}
