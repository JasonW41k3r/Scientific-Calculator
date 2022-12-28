/*
**代码开发：韦百强
**代码开发：费庆辉 
**代码审核：饶鉴晟
*/
#include<stdio.h>
#include<math.h>
    char Low2Up(char c);
	char iGetChar();
void Integral()
{
	void PrintScreen();//输出主屏幕
	void PowerFunction();//幂函数
    void Circularfunctions();//三角函数
	void logarithmicfunction();//对数函数
	void inversetrigonometricfunctions();//反三角函数
	char input;
	while(1){
		PrintScreen();//输出主屏幕
		input = iGetChar();//输入一个字符（非空格、非回车、ASCII码大于零）
		input = Low2Up(input);//转化为大写字母
		if(input == 'Z')
			break;
		if (input == '#')
			break;
		switch(input)
		{
			case 'A':PowerFunction();break;
			case 'B':logarithmicfunction();break;
			case 'C':;break;
			case 'D':Circularfunctions();break;
			case 'E':inversetrigonometricfunctions();break;
			case 'F':;break;
			default:printf("输入错误\n\n");//如果输入的是其它字符，则输入错误
		}
	}
}

void PrintScreen()//输出主屏幕
{
	printf("********************************\n");
	printf("* 欢迎使用定积分计算器 *\n");
	printf("********************************\n");
	printf("A 幂函数 B 对数函数\n");
	printf("C 指数函数 D 三角函数\n");
	printf("E 反三角函数\n");
	printf("Z 退出\n");
	printf("请输入所需功能：");
}


char Low2Up(char c)//如果输入是小写字母，就转化为大写字母，否则不用管
{
	if(c >= 'a' && c <= 'z')
		c=c-32;
	return c;
}

char iGetChar()//输入一个字符（非空格、非回车、ASCII码大于零）
{
	char c;
	do {
		c = getchar();
	}	
	while(c == '\n' || c== ' ' || c < 0);
	return c;
}



	void PowerFunction()//幂函数
	{
		int Parity(int x);//判断奇数偶数，奇数返回 1 ，偶数返回 0
		void Reduction(double n, int *px, int *py);
		double a, b, n, c, d;
		int x, y;
		int *px, *py;
		px = &x;
		py = &y;
		printf("\n********************************\n");
        printf("输入的各数绝对值均不大于10^3\n");
        printf("********************************\n");
		printf("请输入次幂（三位及以内小数，且绝对值不大于10^3）：\n");
		scanf("%lf", &n);
		printf("请输入系数：\n");
		scanf("%lf", &a);
		printf("请输入常数项：\n");
		scanf("%lf", &b);
		Reduction(n, px, py);
		printf("请输入积分上限：");
	    scanf("%lf", &c);
		printf("请输入积分下限：");
		scanf("%lf", &d);
		if(n >= 0)//判断次幂为正
		{
			if(Parity(x))//分子为是奇数，1
			{
				if(Parity(y))//分母是奇数，1
					printf("结果为：%lf\n\n",(a * pow(c, (n + 1)) / (n + 1.0)) - (a * pow(d ,(n + 1)) / (n + 1.0)) + b * (c - d));
				else//分母是偶数， 0
				{
					if(c < 0 && d < 0)
						printf("输入上下限错误！\n\n");
					else
						printf("结果为：%lf\n\n",(a * pow(c, (n + 1)) / (n + 1.0)) - (a * pow(d ,(n + 1)) / (n + 1.0)) + b * (c - d));
				}
			}
			else//分子是偶数， 0
			{
				if(Parity(y))//分母是奇数， 1
					printf("结果为：%lf\n", (a * pow(c, (n + 1)) / (n + 1.0)) - (a * pow(d ,(n + 1)) / (n + 1.0)) + b * (c - d));
				else//分母是偶数， 0
				{
					if(x >= y)
						printf("结果为：%lf\n\n",(a * pow(c, (n + 1)) / (n + 1.0)) - (a * pow(d ,(n + 1)) / (n + 1.0)) + b * (c - d));
					else
					{
						if(c < 0 && d < 0)
						printf("输入上下限错误！\n\n");
					else
						printf("结果为：%lf\n\n", (a * pow(c, (n + 1)) / (n + 1.0)) - (a * pow(d ,(n + 1)) / (n + 1.0)) + b * (c - d));
					}
				}
			}
		}
		else if(n < 0 && n != -1)//判断次幂为负
		{
			if(Parity(x))//分子是奇数，1
			{
				if(Parity(y))//分母是奇数，1
				{
					if(c * d > 0)
						printf("结果为：%lf\n\n",(a * pow(c, (n + 1)) / (n + 1.0)) - (a * pow(d ,(n + 1)) / (n + 1.0)) + b * (c - d));
					else printf("输入上下限错误！\n");
				}
				else//分母是偶数， 0
				{
					if(c <=0 && d <=0)
						printf("输入上下限错误！\n\n");
					else
						printf("结果为：%lf\n\n",(a * pow(c, (n + 1)) / (n + 1.0)) - (a * pow(d ,(n + 1)) / (n + 1.0)) + b * (c - d));
			}
			}
			else//分子是偶数
			{
				if(Parity(y))//分母是奇数，1
				{
					if(c * d > 0)
						{printf("结果为：%lf\n\n",(a * pow(c, (n + 1)) / (n + 1.0)) - (a * pow(d ,(n + 1)) / (n + 1.0)) + b * (c - d));
					printf("x=%d  y=%d",x,y);}
					else printf("输入上下限错误！\n\n");
				}
				else//分母是偶数， 0
					if(x > y)
					{
					if(c * d > 0)
						printf("结果为：%lf\n\n",(a * pow(c, (n + 1)) / (n + 1.0)) - (a * pow(d ,(n + 1)) / (n + 1.0)) + b * (c - d));
					else printf("输入上下限错误！\n\n");
					}
					else if(x < y)
					{
						if(c <=0 && d <=0)
						printf("输入上下限错误！\n\n");
					else
						printf("结果为：%lf\n\n",(a * pow(c, (n + 1)) / (n + 1.0)) - (a * pow(d ,(n + 1)) / (n + 1.0)) + b * (c - d));
					}
					else 
					{
						if(c * d > 0)
						printf("结果为：%lf\n\n",(a * log (c)+ b* c)-(a * log (d)+ b * d));
						else printf("输入上下限错误！\n\n");
					}
			}
		}
		else if(n == -1) printf("结果为：%lf\n\n",(a * log (c)+ b* c)-(a * log (d)+ b * d));
		}



						
		void Reduction(double n, int *px, int *py)//把一个有理数 n 化成最简分数，分子为 x， 分母为 y，n 范围有限制
		{
			int a, b, t, m, p;
			m =  n * 1000;
			p =  1000;
			a = m;
			b = p;
			while(b!=0)
			{
				t = a % b;
				a = b;
				b = t;
			}
			m /= a;
			p /= a;
			*px = m;
			*py = p;
		}
		
    

		

		int Parity(int x)//判断奇数偶数，奇数返回 1 ，偶数返回 0 
		{
			if(x > 0 && x & 2 ==1)
				return 1;
			else return 0;
		}

		void Circularfunctions()//三角函数
		{
		void sinefunction(double a, double b, double c);//正弦函数
		void cosinefunction(double a, double b, double c);//余弦函数
		void  tangentfunction(double a, double b, double c);//正切函数
		double a, b, c;
		char n;
		printf("\n请输入系数：\n");
		scanf("%lf", &a);
		printf("请输入未知数后的常数（如：sin（x+a））：");
		scanf("%lf", &b);
		printf("请输入常数项：");
		scanf("%lf", &c);
		printf("请选择类型\n");
		printf("********************************\n");
        printf("*                              *\n");
        printf("********************************\n");
        printf("A 正弦函数 B 余弦函数\n");
        printf("C 正切函数\n");
        printf("Z 退出\n");
        printf("请输入所需功能：");
		n = iGetChar();
		n = Low2Up(n);
		switch (n)
		{
		case 'A':sinefunction(a, b, c);break;//正弦函数
		case 'B':cosinefunction(a, b, c);break;//余弦函数
		case 'C':tangentfunction(a, b, c);break;//正切函数
		case 'Z':;break;//退出
		default: printf("抱歉，尚未开发此功能\n");
		}
		}
		void sinefunction(double a, double b, double c)//正弦函数
		{
			double m = 0.0, n = 0.0;
			double s = 0.0;
			printf("请输入积分上限(弧度制）:");
			scanf("%lf", &m);
			printf("请输入积分下限（弧度制）:");
			scanf("%lf", &n);
			s = (-cos(a * m + b) + cos(a * n + b)) / a + c * (m - n);
			printf("结果为：%lf\n", s);
		}
		void cosinefunction(double a, double b, double c)//余弦函数
		{
			double m = 0.0, n = 0.0;
			double s = 0.0;
			printf("请输入积分上限（弧度制）:");
			scanf("%lf", &m);
			printf("请输入积分下限（弧度制）:");
			scanf("%lf", &n);
			s=(sin(a * m + b) - sin(a * n + b)) / a + c * (m - n);
			printf("结果为：%lf\n", s);
		}
		void tangentfunction(double a, double b, double c)//正切函数
		{
			double m = 0.0,n = 0.0;
			double s = 0.0;
			printf("请输入积分上限（弧度制）:");
			scanf("%lf", &m);
			printf("请输入积分下限（弧度制）:");
			scanf("%lf", &n);
			s=(-log(cos(a * m + b)) + log(cos(a * n + b))) / a + c * (m - n);
			printf("结果为：%lf\n", s);
		}
		void logarithmicfunction()//对数函数
	{
		double m = 0.0, n = 0.0, x = 0.0, y = 0.0, a = 0.0, b = 0.0, c = 0.0;
		printf("请输入底数：");
		scanf("%lf", &m);
		printf("请输入常数：");
		scanf("%lf", &n);
		printf("请输入指数：");
		scanf("%lf", &x);
		printf("请输入常数项：");
		scanf("%lf", &c);
		printf("请输入积分上限：");
		scanf("%lf", &a);
		printf("请输入积分下限：");
		scanf("%lf", &b);
		if(m <= 0 || n * pow(a, x) <= 0 || n * pow(b, x) <= 0)
		{
			printf("输入的值不在定义域内\n");
		}
		else 
		{
			if(n * a > 0)
			{
				y = x *((a * log(n * a) -a / n) - (b * log(n * b) - b / n)) / (log (m)) + c * (a - b);
				printf("结果是：%lf\n", y);
			}
			if(n * a < 0)
			{
				y = x*(((-a) * log(n * (-a)) - (-a) / n) - ((-b) * log(n * (-b)) - (-b) / n)) / (log (m)) + c * (a - b);
				printf("结果是：%lf\n", y);
			}
	}
		}
		void inversetrigonometricfunctions()//反三角函数
	{
		void InversesinelFunction();//反正弦函数
		void InversecosineFunction();//反余弦函数
		void InversetangentFunction();//反正切函数
		char n;
		printf("\n请选择类型\n");
		printf("********************************\n");
        printf("*                              *\n");
        printf("********************************\n");
        printf("A 反正弦函数 B 反余弦函数\n");
        printf("C 反正切函数\n");
        printf("Z 退出\n");
        printf("请输入所需功能：");
		n = iGetChar();
		n = Low2Up(n);
		switch (n)
		{
		case 'A':InversesinelFunction();break;//反正弦函数
		case 'B':InversecosineFunction();break;//反余弦函数
		case 'C':InversetangentFunction();break;//反正切函数
		case 'Z':;break;//退出
		default: printf("抱歉，尚未开发此功能\n");
		}
	}
		void InversesinelFunction()//反正弦函数
		{
			double m = 0.0,n = 0.0;
			double s = 0.0;
			double p, q;
			printf("请输入积分上限:");
			scanf("%lf", &m);
			printf("请输入积分下限:");
			scanf("%lf", &n);
			if(m < -1 || m > 1 ||n < -1 || n > 1)
			{
				printf("输入错误\n");
			}
			else 
			{
				printf("请输入系数：\n");
				scanf("%lf", &p);
				printf("请输入常数项：\n");
				scanf("%lf", &q);
				s = (p * (m*  asin(m) + pow((1 - m *m ), 0.5)) + q * m) -(p * (n * asin(n) + pow((1 - n * n), 0.5)) + q * n);
			    printf("结果为：%lf\n", s);
			}
		}
		void InversecosineFunction()//反余弦函数
		{
			double m = 0.0,n = 0.0;
			double s = 0.0;
			double p, q;
			printf("请输入积分上限:");
			scanf("%lf", &m);
			printf("请输入积分下限:");
			scanf("%lf", &n);
			if(m < -1 || m> 1 || n < -1 || n >1)
			{
				printf("输入错误\n");
			}
			else 
			{
				printf("请输入系数：\n");
				scanf("%lf", &p);
				printf("请输入常数项：\n");
				scanf("%lf", &q);
				s = (p * (m * acos(m) - pow((1 - m * m), 0.5)) + q * m)-(p * (n * acos(n) - pow((1 - n * n), 0.5)) + q * n);
			    printf("结果为：%lf\n", s);
			}
		}
		void InversetangentFunction()//反正切函数
		{
		    double m = 0.0,n = 0.0;
			double s = 0.0;
			double p, q;
			printf("请输入积分上限:");
			scanf("%lf", &m);
			printf("请输入积分下限:");
			scanf("%lf", &n);
			printf("请输入系数：\n");
		    scanf("%lf", &p);
			printf("请输入常数项：\n");
			scanf("%lf", &q);
		    s = (p * (m * atan(m) - 0.5 * log(m * m + 1.0)) + q * m) -(p * (n * atan(n) - 0.5 * log(n * n + 1.0)) + q * n);
			printf("结果为：%lf\n", s);
			
		}
	
