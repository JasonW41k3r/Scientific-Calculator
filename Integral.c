/*
**���뿪����Τ��ǿ
**���뿪��������� 
**������ˣ��ļ���
*/
#include<stdio.h>
#include<math.h>
    char Low2Up(char c);
	char iGetChar();
void Integral()
{
	void PrintScreen();//�������Ļ
	void PowerFunction();//�ݺ���
    void Circularfunctions();//���Ǻ���
	void logarithmicfunction();//��������
	void inversetrigonometricfunctions();//�����Ǻ���
	char input;
	while(1){
		PrintScreen();//�������Ļ
		input = iGetChar();//����һ���ַ����ǿո񡢷ǻس���ASCII������㣩
		input = Low2Up(input);//ת��Ϊ��д��ĸ
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
			default:printf("�������\n\n");//���������������ַ������������
		}
	}
}

void PrintScreen()//�������Ļ
{
	printf("********************************\n");
	printf("* ��ӭʹ�ö����ּ����� *\n");
	printf("********************************\n");
	printf("A �ݺ��� B ��������\n");
	printf("C ָ������ D ���Ǻ���\n");
	printf("E �����Ǻ���\n");
	printf("Z �˳�\n");
	printf("���������蹦�ܣ�");
}


char Low2Up(char c)//���������Сд��ĸ����ת��Ϊ��д��ĸ�������ù�
{
	if(c >= 'a' && c <= 'z')
		c=c-32;
	return c;
}

char iGetChar()//����һ���ַ����ǿո񡢷ǻس���ASCII������㣩
{
	char c;
	do {
		c = getchar();
	}	
	while(c == '\n' || c== ' ' || c < 0);
	return c;
}



	void PowerFunction()//�ݺ���
	{
		int Parity(int x);//�ж�����ż������������ 1 ��ż������ 0
		void Reduction(double n, int *px, int *py);
		double a, b, n, c, d;
		int x, y;
		int *px, *py;
		px = &x;
		py = &y;
		printf("\n********************************\n");
        printf("����ĸ�������ֵ��������10^3\n");
        printf("********************************\n");
		printf("��������ݣ���λ������С�����Ҿ���ֵ������10^3����\n");
		scanf("%lf", &n);
		printf("������ϵ����\n");
		scanf("%lf", &a);
		printf("�����볣���\n");
		scanf("%lf", &b);
		Reduction(n, px, py);
		printf("������������ޣ�");
	    scanf("%lf", &c);
		printf("������������ޣ�");
		scanf("%lf", &d);
		if(n >= 0)//�жϴ���Ϊ��
		{
			if(Parity(x))//����Ϊ��������1
			{
				if(Parity(y))//��ĸ��������1
					printf("���Ϊ��%lf\n\n",(a * pow(c, (n + 1)) / (n + 1.0)) - (a * pow(d ,(n + 1)) / (n + 1.0)) + b * (c - d));
				else//��ĸ��ż���� 0
				{
					if(c < 0 && d < 0)
						printf("���������޴���\n\n");
					else
						printf("���Ϊ��%lf\n\n",(a * pow(c, (n + 1)) / (n + 1.0)) - (a * pow(d ,(n + 1)) / (n + 1.0)) + b * (c - d));
				}
			}
			else//������ż���� 0
			{
				if(Parity(y))//��ĸ�������� 1
					printf("���Ϊ��%lf\n", (a * pow(c, (n + 1)) / (n + 1.0)) - (a * pow(d ,(n + 1)) / (n + 1.0)) + b * (c - d));
				else//��ĸ��ż���� 0
				{
					if(x >= y)
						printf("���Ϊ��%lf\n\n",(a * pow(c, (n + 1)) / (n + 1.0)) - (a * pow(d ,(n + 1)) / (n + 1.0)) + b * (c - d));
					else
					{
						if(c < 0 && d < 0)
						printf("���������޴���\n\n");
					else
						printf("���Ϊ��%lf\n\n", (a * pow(c, (n + 1)) / (n + 1.0)) - (a * pow(d ,(n + 1)) / (n + 1.0)) + b * (c - d));
					}
				}
			}
		}
		else if(n < 0 && n != -1)//�жϴ���Ϊ��
		{
			if(Parity(x))//������������1
			{
				if(Parity(y))//��ĸ��������1
				{
					if(c * d > 0)
						printf("���Ϊ��%lf\n\n",(a * pow(c, (n + 1)) / (n + 1.0)) - (a * pow(d ,(n + 1)) / (n + 1.0)) + b * (c - d));
					else printf("���������޴���\n");
				}
				else//��ĸ��ż���� 0
				{
					if(c <=0 && d <=0)
						printf("���������޴���\n\n");
					else
						printf("���Ϊ��%lf\n\n",(a * pow(c, (n + 1)) / (n + 1.0)) - (a * pow(d ,(n + 1)) / (n + 1.0)) + b * (c - d));
			}
			}
			else//������ż��
			{
				if(Parity(y))//��ĸ��������1
				{
					if(c * d > 0)
						{printf("���Ϊ��%lf\n\n",(a * pow(c, (n + 1)) / (n + 1.0)) - (a * pow(d ,(n + 1)) / (n + 1.0)) + b * (c - d));
					printf("x=%d  y=%d",x,y);}
					else printf("���������޴���\n\n");
				}
				else//��ĸ��ż���� 0
					if(x > y)
					{
					if(c * d > 0)
						printf("���Ϊ��%lf\n\n",(a * pow(c, (n + 1)) / (n + 1.0)) - (a * pow(d ,(n + 1)) / (n + 1.0)) + b * (c - d));
					else printf("���������޴���\n\n");
					}
					else if(x < y)
					{
						if(c <=0 && d <=0)
						printf("���������޴���\n\n");
					else
						printf("���Ϊ��%lf\n\n",(a * pow(c, (n + 1)) / (n + 1.0)) - (a * pow(d ,(n + 1)) / (n + 1.0)) + b * (c - d));
					}
					else 
					{
						if(c * d > 0)
						printf("���Ϊ��%lf\n\n",(a * log (c)+ b* c)-(a * log (d)+ b * d));
						else printf("���������޴���\n\n");
					}
			}
		}
		else if(n == -1) printf("���Ϊ��%lf\n\n",(a * log (c)+ b* c)-(a * log (d)+ b * d));
		}



						
		void Reduction(double n, int *px, int *py)//��һ�������� n ����������������Ϊ x�� ��ĸΪ y��n ��Χ������
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
		
    

		

		int Parity(int x)//�ж�����ż������������ 1 ��ż������ 0 
		{
			if(x > 0 && x & 2 ==1)
				return 1;
			else return 0;
		}

		void Circularfunctions()//���Ǻ���
		{
		void sinefunction(double a, double b, double c);//���Һ���
		void cosinefunction(double a, double b, double c);//���Һ���
		void  tangentfunction(double a, double b, double c);//���к���
		double a, b, c;
		char n;
		printf("\n������ϵ����\n");
		scanf("%lf", &a);
		printf("������δ֪����ĳ������磺sin��x+a������");
		scanf("%lf", &b);
		printf("�����볣���");
		scanf("%lf", &c);
		printf("��ѡ������\n");
		printf("********************************\n");
        printf("*                              *\n");
        printf("********************************\n");
        printf("A ���Һ��� B ���Һ���\n");
        printf("C ���к���\n");
        printf("Z �˳�\n");
        printf("���������蹦�ܣ�");
		n = iGetChar();
		n = Low2Up(n);
		switch (n)
		{
		case 'A':sinefunction(a, b, c);break;//���Һ���
		case 'B':cosinefunction(a, b, c);break;//���Һ���
		case 'C':tangentfunction(a, b, c);break;//���к���
		case 'Z':;break;//�˳�
		default: printf("��Ǹ����δ�����˹���\n");
		}
		}
		void sinefunction(double a, double b, double c)//���Һ���
		{
			double m = 0.0, n = 0.0;
			double s = 0.0;
			printf("�������������(�����ƣ�:");
			scanf("%lf", &m);
			printf("������������ޣ������ƣ�:");
			scanf("%lf", &n);
			s = (-cos(a * m + b) + cos(a * n + b)) / a + c * (m - n);
			printf("���Ϊ��%lf\n", s);
		}
		void cosinefunction(double a, double b, double c)//���Һ���
		{
			double m = 0.0, n = 0.0;
			double s = 0.0;
			printf("������������ޣ������ƣ�:");
			scanf("%lf", &m);
			printf("������������ޣ������ƣ�:");
			scanf("%lf", &n);
			s=(sin(a * m + b) - sin(a * n + b)) / a + c * (m - n);
			printf("���Ϊ��%lf\n", s);
		}
		void tangentfunction(double a, double b, double c)//���к���
		{
			double m = 0.0,n = 0.0;
			double s = 0.0;
			printf("������������ޣ������ƣ�:");
			scanf("%lf", &m);
			printf("������������ޣ������ƣ�:");
			scanf("%lf", &n);
			s=(-log(cos(a * m + b)) + log(cos(a * n + b))) / a + c * (m - n);
			printf("���Ϊ��%lf\n", s);
		}
		void logarithmicfunction()//��������
	{
		double m = 0.0, n = 0.0, x = 0.0, y = 0.0, a = 0.0, b = 0.0, c = 0.0;
		printf("�����������");
		scanf("%lf", &m);
		printf("�����볣����");
		scanf("%lf", &n);
		printf("������ָ����");
		scanf("%lf", &x);
		printf("�����볣���");
		scanf("%lf", &c);
		printf("������������ޣ�");
		scanf("%lf", &a);
		printf("������������ޣ�");
		scanf("%lf", &b);
		if(m <= 0 || n * pow(a, x) <= 0 || n * pow(b, x) <= 0)
		{
			printf("�����ֵ���ڶ�������\n");
		}
		else 
		{
			if(n * a > 0)
			{
				y = x *((a * log(n * a) -a / n) - (b * log(n * b) - b / n)) / (log (m)) + c * (a - b);
				printf("����ǣ�%lf\n", y);
			}
			if(n * a < 0)
			{
				y = x*(((-a) * log(n * (-a)) - (-a) / n) - ((-b) * log(n * (-b)) - (-b) / n)) / (log (m)) + c * (a - b);
				printf("����ǣ�%lf\n", y);
			}
	}
		}
		void inversetrigonometricfunctions()//�����Ǻ���
	{
		void InversesinelFunction();//�����Һ���
		void InversecosineFunction();//�����Һ���
		void InversetangentFunction();//�����к���
		char n;
		printf("\n��ѡ������\n");
		printf("********************************\n");
        printf("*                              *\n");
        printf("********************************\n");
        printf("A �����Һ��� B �����Һ���\n");
        printf("C �����к���\n");
        printf("Z �˳�\n");
        printf("���������蹦�ܣ�");
		n = iGetChar();
		n = Low2Up(n);
		switch (n)
		{
		case 'A':InversesinelFunction();break;//�����Һ���
		case 'B':InversecosineFunction();break;//�����Һ���
		case 'C':InversetangentFunction();break;//�����к���
		case 'Z':;break;//�˳�
		default: printf("��Ǹ����δ�����˹���\n");
		}
	}
		void InversesinelFunction()//�����Һ���
		{
			double m = 0.0,n = 0.0;
			double s = 0.0;
			double p, q;
			printf("�������������:");
			scanf("%lf", &m);
			printf("�������������:");
			scanf("%lf", &n);
			if(m < -1 || m > 1 ||n < -1 || n > 1)
			{
				printf("�������\n");
			}
			else 
			{
				printf("������ϵ����\n");
				scanf("%lf", &p);
				printf("�����볣���\n");
				scanf("%lf", &q);
				s = (p * (m*  asin(m) + pow((1 - m *m ), 0.5)) + q * m) -(p * (n * asin(n) + pow((1 - n * n), 0.5)) + q * n);
			    printf("���Ϊ��%lf\n", s);
			}
		}
		void InversecosineFunction()//�����Һ���
		{
			double m = 0.0,n = 0.0;
			double s = 0.0;
			double p, q;
			printf("�������������:");
			scanf("%lf", &m);
			printf("�������������:");
			scanf("%lf", &n);
			if(m < -1 || m> 1 || n < -1 || n >1)
			{
				printf("�������\n");
			}
			else 
			{
				printf("������ϵ����\n");
				scanf("%lf", &p);
				printf("�����볣���\n");
				scanf("%lf", &q);
				s = (p * (m * acos(m) - pow((1 - m * m), 0.5)) + q * m)-(p * (n * acos(n) - pow((1 - n * n), 0.5)) + q * n);
			    printf("���Ϊ��%lf\n", s);
			}
		}
		void InversetangentFunction()//�����к���
		{
		    double m = 0.0,n = 0.0;
			double s = 0.0;
			double p, q;
			printf("�������������:");
			scanf("%lf", &m);
			printf("�������������:");
			scanf("%lf", &n);
			printf("������ϵ����\n");
		    scanf("%lf", &p);
			printf("�����볣���\n");
			scanf("%lf", &q);
		    s = (p * (m * atan(m) - 0.5 * log(m * m + 1.0)) + q * m) -(p * (n * atan(n) - 0.5 * log(n * n + 1.0)) + q * n);
			printf("���Ϊ��%lf\n", s);
			
		}
	
