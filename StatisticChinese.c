#include<stdio.h>
#include<math.h>
#include "headers.h"

double Max( double numbers[], int length );
double Min( double numbers[], int length );
double Aver( double numbers[], int length );
double Vari( double numbers[], int length );
double Disc( double numbers[], int length );
double Rang( double numbers[], int length );
double Mid(double numbers[], int length);
double Most(double numbers[], int length);
double Evolve(double numbers[], int length);
double Standard(double numbers[], int length);

char Up(char c);
char GetChar();
typedef struct {
	double num;
	int count;
} data;

void StatisticChinese()
{
    int i, count = 0;
    char input;
    double numbers[200];

    printf("************************************\n");
    printf("请依次导入数组数据\n");
    printf("数据上限为200\n");
    printf("以“0”结束导入\n");
    printf("************************************\n");
    for(i = 0; i < 200; i++)
    {
        printf( "请输入第%d个数据：\n", i + 1 );
        scanf("%lf", &numbers[i]);
        
        printf("\n");
        if(numbers[i] == 0.0) break;
        count++;
    }


	while(1)
	{
		printf("****************************\n");
		printf("A 计算最大值     B 计算最小值\n");
        printf("C 计算平均值     D 计算方差\n");
	    printf("E 计算离散系数   F 计算极差\n");
	    printf("G 计算中位数     H 计算标准差\n");
	    printf("I 计算变异系数   Z 退出\n");
        printf("请选择功能：\n");

        input = GetChar();
        input = Up(input);

		if(input == 'Z') break;
		else if (input == '#') break;

		switch(input)
        {
        case 'A':printf("结果为：%f\n",Max( numbers, count ));break;
        case 'B':printf("结果为：%f\n",Min( numbers, count ));break;
        case 'C':printf("结果为：%f\n",Aver( numbers, count ));break;
        case 'D':printf("结果为：%f\n",Vari( numbers, count ));break;
		case 'E':printf("结果为：%f\n",Disc( numbers, count ));break;
		case 'F':printf("结果为：%f\n",Rang( numbers, count ));break;
		case 'G':printf("结果为：%f\n",Mid( numbers, count ));break;
		case 'H':printf("结果为：%f\n",Standard( numbers, count ));break;
		case 'I':printf("结果为：%f\n",Evolve( numbers, count ));break;
		/*case 'H':
			if (Most( numbers, count ) != 0) printf("结果为：%f\n",Most( numbers, count ));
			else printf("众数不存在");break;*/
        default:printf("输入错误\n\n");
        }
	}
}

double Standard(double numbers[], int length)
{
	double ret = 0;
	ret = sqrt(Vari( numbers, length ));
	return ret;
}

char Up(char c)
{
    if( c >= 'a' && c <= 'z' )
        c = c - 32 ;
    return c;
}

char GetChar()
{
    char c;
    do
    {
        c = getchar();
    }
    while( c == '\n' || c == ' ' || c < 0 );
    return c;
}

/*double Most(double numbers[], int length)
{
	int cnt = 0, sign = 0;
	int k = 0;
	data Numbers[200];
	for (cnt = 0; cnt < length; cnt++) {
		Numbers[cnt].num = numbers[cnt];
		Numbers[cnt].count = 1;
	}
	for (cnt = 0; cnt < length; cnt++) {
		for (k = 0; k < cnt; k++) {
			if (Numbers[k].num == Numbers[cnt].num) Numbers[cnt].count++;
		}
	}
	double max = Numbers[0].count; 
	for (cnt = 0; cnt < length; cnt++) {
		if (Numbers[cnt].count > max) {
			max = Numbers[cnt].count;
			sign = 1;
		}
	}
	if (sign == 0) return 0;
	else return max;
}*/

double Evolve(double numbers[], int length)
{
	double ret = 0;
	ret = Standard(numbers, length) / Aver(numbers, length);
	return ret;
}

double Max( double numbers[], int length )
{
    int i;
    double max = numbers[0];
    for( i = 0; i < length; i++ )
    {
        if( numbers[i] > max )
            max = numbers[i];
    }
    return max;
}

double Mid(double numbers[], int length)
{
	double ret = 0;
	if (length / 2 == 0) {
		ret = (numbers[length / 2 - 1] + numbers[length / 2]) / 2;
	}
	else ret = numbers[(length + 1) / 2 - 1];
	return ret;
}

double Min(double numbers[], int length)
{
    int i;
    double min = numbers[0];
    for(i = 0; i < length; i++)
    {
        if(numbers[i] < min)
            min = numbers[i];
    }
    return min;
}

double Aver(double numbers[], int length)
{
    int i;
    double aver, sum=0;
    for(i = 0; i < length; i++)
        sum = sum + numbers[i];
    aver = sum / length;
    return aver;
}

double Vari(double numbers[], int length)
{
    int i;
    double aver, vari, Numbers[200], sum = 0, Sum = 0;

    for(i = 0; i < length; i++)
        sum = sum + numbers[i];
    aver = sum / length;
    for(i = 0; i < length; i++)
        Numbers[i] = (numbers[i] - aver) * (numbers[i] - aver);
    for(i = 0; i < length; i++)
        Sum = Sum + Numbers[i];
    vari = Sum / length;
    return vari;
}

/*
**代码开发：刘佳鑫 
**代码审核：饶鉴晟
*/
double Disc(double numbers[], int length)
{
	int i;
    double disc, aver, Numbers[200], sum = 0, Sum = 0;

    for(i = 0; i < length; i++)
        sum = sum + numbers[i];
    aver = sum / length;
    for(i = 0; i < length; i++)
        Numbers[i] = (numbers[i] - aver) * (numbers[i] - aver);
    for(i = 0; i < length; i++)
        Sum = Sum + Numbers[i];
    disc = sqrt(Sum / length);
	return disc;
}

double Rang(double numbers[], int length)
{
	int i;
    double rang, max = numbers[0], min = numbers[0];
    for(i = 0; i < length; i++)
    {
        if(numbers[i] > max)
            max = numbers[i];
    }
    for(i = 0; i < length; i++)
    {
        if(numbers[i] < min)
            min = numbers[i];
    }
	rang = max - min;
	return rang;
}
