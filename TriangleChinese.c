/*
**代码开发：高志伟
**代码审核：饶鉴晟
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
	    EPrintfScreen();//输出主屏幕
    	Input = EGetChar();//输入一个字符（非空格、非回车、ASCII码大于零）
    	Input = ELow2Up(Input);//转化为大写字母
        if (Input == '#') break;
    	switch (Input)//功能分支
	    {
        	case 'A': printf("结果为：%lf\n\n",ESin()); break;
        	case 'B': printf("结果为：%lf\n\n",ECos()); break;
        	case 'C': printf("结果为：%lf\n\n",ETan()); break;
        	case 'D': printf("结果为：%lf\n\n",EArcSin()); break;
        	case 'E': printf("结果为：%lf\n\n",EArcCos()); break;
        	case 'F': printf("结果为：%lf\n\n",EArcTan()); break;
        	default: printf("输入错误\n\n");//如果输入的是其它字符，则输入错误
        }
	}
}
void EPrintfScreen()//输出主屏幕
{
	printf("*****************************\n");
	printf("*  欢迎使用三角函数计算器!  *\n");
	printf("*****************************\n");
	printf("\n");
	printf("我可以帮助你计算以下函数的函数值：\n");
	printf("A.sin      B.cos      C.tan\n");
	printf("D.arcsin   E.arccos   F.arctan\n");
	printf("\n");
	printf("请输入你所需功能前的字母(大小写均可)：");
}
char ELow2Up(char c)//如果输入是小写字母，就转化为大写字母，否则不用管
{
	if(c >= 'a' && c <= 'z')
		c = c - 32;
	return c;
}
char EGetChar()//输入一个字符（非空格、非回车、ASCII码大于零）
{
	char c;
	do
	{
		c = getchar();
	}
	while(c == '\n' || c ==' ' || c < 0);
	return c;
}
double ESin()//计算Sin的值
{
	char Input;//用于选择角度制还是弧度制
	double a , f , x , mul = 1 , sum = 0 ;//a是输入的要计算的值，c是库函数的结果，f是麦克劳林级数每一项的结果，mul是计算阶乘，sum是麦克劳林级数除第一项的结果
	int i = 0, j = 1, k, l, m, num = 1;//i，j，k，l，m用于计算正负号和阶乘
	printf("\n");
	printf("请选择输入角度数值的类型：\n");
	printf("A.角度制  B.弧度制\n");
	printf("请选择：");
	Input = EGetChar();
	Input = ELow2Up(Input);
	printf("\n");
	switch(Input)
	{
	case 'A':
		{
			printf("请输入角度大小：");
			scanf("%lf" , &x);
			a = x * 2 * pi / 360;
			break;
		}
	case 'B':
		{
			printf("请输入弧度大小：");
			scanf("%lf", &a);
			break;
		}
	default: printf("输入错误\n\n");//如果输入的是其它字符，则输入错误
	}
	if(a > 0)//将弧度制转换到规定的范围以内
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
	        j = j + 2;//解决分母阶乘问题（开始）
			k = (j + 2) %4;//解决符号问题（开始）
			if(k == 1)
			{
				l = -1;
			}
			else l = 1;//解决符号问题（结束）
			m = j ;
			while(j > 1)
	       {
		    mul = j * mul;
			j--;
	       }//解决分母阶乘问题（结束）
			j = m;
			f = l * pow(a, j) / mul;//每一项的大小
			if(fabs(f) >= 1e-10)//麦克劳林级数计算的精度
				;
			else break;
			mul = 1 ;
			sum = sum + f ;
		}
	printf("\n");
	return sum+a;
}

double ECos()//该部分注释参考Sin部分的注释
{
	char Input;
	double a, f, x, mul = 1, sum = 0;
	int i = 0, j = 0, k, l, m;
	printf("\n");
	printf("请选择输入角度数值的类型：\n");
	printf("A.角度制  B.弧度制\n");
	printf("请选择：");
	Input = EGetChar();
	Input = ELow2Up(Input);
	printf("\n");
	switch(Input)
	{
	case 'A':
		{
			printf("请输入角度大小：");
			scanf("%lf", &x);
			a = x * 2 * pi / 360;
			break;
		}
	case 'B':
		{
			printf("请输入弧度大小：");
			scanf("%lf", &a);
			break;
		}
	default: printf("输入错误\n\n");//如果输入的是其它字符，则输入错误
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
	        j = j + 2 ;//解决分母阶乘问题（开始）
			k = (j + 3) % 4;//解决符号问题（开始）
			if(k == 1)
			{
				l = -1 ;
			}
			else l = 1 ;//解决符号问题（结束）
			m = j ;
			while( j > 1)
	       {
		    mul = j * mul ;
			j--;
	       }//解决分母阶乘问题（结束）
			j = m;
			f = l * pow(a, j) / mul ;//每一项的大小
			if(fabs(f) >= 1e-10)
				;
			else break;
			mul = 1;
			sum = sum + f;
		}
	printf("\n");
    return sum + 1.0;
}
double ETan()//该部分的注释参考Sin部分的注释
{
	char Input;
	double a , f , x , mul = 1 , sum = 0 , summ = 0 ;
	int i = 0, j = 1, k, l, m, num = 1;
	printf("\n");
	printf("请选择输入角度数值的类型：\n");
	printf("A.角度制  B.弧度制\n");
	printf("请选择：");
	Input=EGetChar();
	Input=ELow2Up(Input);
	printf("\n");
	switch(Input)
	{
	case 'A':
		{
			printf("请输入角度大小：");
			scanf("%lf", &x);
			a = x * 2 * pi / 360;
			break;
		}
	case 'B':
		{
			printf("请输入弧度大小：");
			scanf("%lf", &a);
			break;
		}
	default: printf("输入错误\n\n");//如果输入的是其它字符，则输入错误
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
double EArcSin()//计算ArcSin的值
{
	double a ;//库函数
	double f , sum = 0;//f是mac的通项
	int i = 1, j = 0, Mul1 = 1, Mul2 = 1, m;//用于计算阶乘，Mul1是n的阶乘，Mul2是2n的阶乘
	printf("\n");
	printf("请输入数值：");
	scanf("%lf", &a);
	if(a < -1 || a > 1)//根据定义域检验输入数值的正确性
		printf("输入错误\n");
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
double EArcCos()//参考ArcSin的注释
{
	double a;//库函数
	double f, sum = 0;//f是mac的通项
	int  i = 1, j = 0, Mul1 = 1, Mul2 = 1, m;
	printf("\n");
	printf("请输入数值：");
	scanf("%lf", &a);
	if(a < -1 || a > 1)
		printf("输入错误\n");
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
	printf("请输入数值：");
	scanf("%lf", &a);
	f = a; 
		while(fabs(f) >= 1e-7)
		{
	        j = j + 2;
			k = (j+3) % 4;//解决符号问题（开始）
			if(k == 1)
			{
				l = -1;
			}
			else l = 1;//解决符号问题（结束）
			f = l * pow(a, j+1) / (j+1);//每一项的大小
			sum = sum + f;
		}
	return sum + a;
	printf("\n");
}
