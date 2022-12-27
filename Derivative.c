/*
**���뿪������Խ�� 
**������ˣ��ļ���
*/
#include <stdio.h>
#include <math.h>
#include "headers.h"
static char GetChar(void);
char* ChangHanShu(double C);
char* Sin(double C);
char* Tan(double C);
char* Log(double C);
char* Sec(double C);
char* Index(double C);
char*ArcSin(double C);
char* ArcTan(double C);
void Derivative(){
    printf("��ѡ������Ҫ�Ĺ��ܣ�\nA�������ı��ʽ��B�������ߵ�����\n");
    char c;
    c = GetChar();
    if (c >= 'a' && c <= 'z') c = c + ('A' - 'a');
    char b;
    double C;//�贫����е�ĺ�����
    switch(c){
    	case '#':
    		break;
        case 'A':
            printf("��ѡ�����ѯ���ʽ����ʽ��\n1.��������\t2.���Һ�����\n3.���к�����\t4.�������\n5.ָ��������\t6.����������\n7.�����Һ�����\t8.�����к���\n");
           // printf("Please select the form of the expression to be queried:1. Constant function; 2. Trigonometric function; 3. Tangent function; 4. Secant function; 5. Exponential function; 6. Logarithmic function; 7. Arcsine function; 8. Arctangent function\n");
            b = GetChar();
            switch(b){
                case'1':{
                    printf("�����볣������yֵΪ��");//printf��"Please enter y value of constant function as:"��;
                    double y;
                    scanf("%lf",&y);
                    printf("��Ӧ�����ĵ������ʽΪ�� y = %lf",y);//printf("The derivative expression of the corresponding function is�� y = %lf",y);
                    printf("\n");
                    break;}
                case'2':
                    printf("��Ӧ�����ĵ������ʽΪ��y = cosx");//printf("The derivative expression of the corresponding function is�� y = cosx");
                    printf("\n");
                    break;
                case'3':
                    printf("��Ӧ�����ĵ������ʽΪ��y = ��secx��^2");//printf("The derivative expression of the corresponding function is�� y = ��secx��^2");
                    printf("\n");
                    break;
                case'4':
                    printf("��Ӧ�����ĵ������ʽΪ��y = secx*tanx");//printf("The derivative expression of the corresponding function is�� y = secx*tanx",y);
                    printf("\n");
                    break;
                case'5':
                    printf("������ָ�������ĵ���a����ֵ: ");//printf("Please enter the value of base a of exponential function:");
                    printf("\n");
                    double a,lna;
                    scanf("%lf",&a);
                    if(a<=0){
                        printf("Error");
                    }else{
                        lna = log(a);
                        printf("��Ӧ�����ĵ������ʽΪ��y = %lf^x*%lf",a,lna);//printf("The derivative expression of the corresponding function is��y = %lf^x*%lf",a,lna);
                        
                    }
                    printf("\n");
                    break;
                case'6':
                    printf("��������������ĵ���a����ֵ: ");//printf("Please enter the value of the base a of the logarithmic function:");
                    double b,lnb,B;
                    scanf("%lf",&b);
                    if(b<=0){
                        printf("Error");
                    }else{
                        lnb = log(b);
                        B = 1 / lnb;
                        printf("��Ӧ�����ĵ������ʽΪ��y=1/x*%lf",B);//printf("The derivative expression of the corresponding function is��y=1/x*%lf",B);
                    }
                    printf("\n");
                    break;
                case'7':
                    printf("��Ӧ�����ĵ������ʽΪ��y=1/sqrt(1-x^2)");//printf("The derivative expression of the corresponding function is��y=1/sqrt(1-x^2)");
                    printf("\n");
                    break;
                case'8':
                    printf("��Ӧ�����ĵ������ʽΪ��y=1/(1+x^2)");//printf("The derivative expression of the corresponding function is��y=1/(1+x^2)");
                    printf("\n");
                    break;
                default:
                    printf("Error\n");
                    break;
            }
            break;
        case'B':
            printf("��ѡ�����ѯ��ֵ����ʽ��1.��������2.���Ǻ�����3.���к�����4.�������5.ָ��������6.����������7.�����Һ�����8.�����к���\n");
            //printf("Please select the form of the value to be queried:1. Constant function; 2. Trigonometric function; 3. Tangent function; 4. Secant function; 5. Exponential function; 6. Logarithmic function; 7. Arcsine function; 8. Arctangent function\n");
            b = GetChar();
            printf("�������е㴦�ĺ�����: x = ");//printf("Please enter the abscissa at the tangent point: x = ");
            scanf("%lf",&C);//�ڴ˴�����
            switch(b)
            {
                case '1':
                {
                    char *pStr = ChangHanShu(C);
                    printf("�õ㴦���߷���Ϊ��%s",pStr);//printf("The tangent equation at this point is: %s",pStr);
                    break;
                    
                }
                case '2':
                {
                    char *pStr = Sin(C);
                    printf("�õ㴦���߷���Ϊ��%s",pStr);//printf("The tangent equation at this point is: %s",pStr);
                    break;
                    
                }
                case '3':
                {
                    char *pStr = Tan(C);
                    printf("�õ㴦���߷���Ϊ��%s",pStr);//printf("The tangent equation at this point is: %s",pStr);
                    break;
                    
                }
                case'4':
                {
                    char *pStr = Sec(C);
                    printf("�õ㴦���߷���Ϊ��%s",pStr);//printf("The tangent equation at this point is: %s",pStr);
                    break;
                    
                }
                case'5':
                {
                    char *pStr = Index(C);
                    printf("�õ㴦���߷���Ϊ��%s",pStr);//printf("The tangent equation at this point is: %s",pStr);
                    break;
                    
                }
                case'6':
                {
                    char *pStr = Log(C);
                    printf("�õ㴦���߷���Ϊ��%s",pStr);//printf("The tangent equation at this point is: %s",pStr);
                    break;
                    
                }
                case'7':
                {
                    char *pStr = ArcSin(C);
                    printf("�õ㴦���߷���Ϊ��%s",pStr);//printf("The tangent equation at this point is: %s",pStr);
                    break;
                    
                }
                case'8':ArcTan(C);
                {
                    char *pStr = ArcTan(C);
                    printf("�õ㴦���߷���Ϊ��%s",pStr);//printf("The tangent equation at this point is: %s",pStr);
                    break;
                
                }
                default:
                {
                    printf("Error\n");
                    break;
                    
                }
                    
            }
            break;
        default :
        {
            printf("Error\n");
            break;
            
        }
    }
}

static char GetChar(void){
    char c;
    do
    {
        c=getchar();
    }
    while(c=='\n'||c==' ');
    return c;

}
char* ChangHanShu(double C){
    static char str[256] = {0};
    sprintf(str,"y=%lf",C);
    return str;
}
char* Sin(double C){
    double SinC,CosC;
    static char str[256] = {0};
    SinC = sin(C);
    CosC = cos(C);
    sprintf(str,"y=%lf(x-%lf)+%lf\n",CosC,C,SinC);
    return str;
}
char* Tan(double C){
    double TanC,dTanC;
    static char str[256] = {0};
    TanC = tan(C);
    dTanC = 1 / pow(cos(C),2);
    sprintf(str,"y=%lf(x-%lf)+%lf\n",dTanC,C,TanC);
    return str;
}
char* Sec(double C){
    double SecC,dSecC;
    static char str[256]={0};
    SecC = 1 / cos(C);
    dSecC = SecC * tan(C);
    sprintf(str,"y=%lf(x-%lf)+%lf\n",dSecC,C,SecC);
    return str;
}
char* Log(double C){
    double A,LogC,dLogC;
    static char str[256] = {0};
    if(C>0){
        printf("��������������ĵ�����");//printf("printf("Please enter the value of the base of the logarithmic function: ");
        scanf("%lf",&A);
        LogC=log(C) / log(A);
        dLogC = 1/( C * log(A) );
        sprintf(str,"y=%lf(x-%lf)+%lf\n",dLogC,C,LogC);
    }else{
        sprintf(str,"Error\n");
    }
    return str;
}
char* Index(double C){
    double A,AX,dAX;
    static char str[256] = {0};
    printf("������ָ�������ĵ���:");//printf("Please enter the value of base of exponential function:");
    scanf("%lf",&A);
    AX = pow(A,C);
    dAX = AX*log(A);
    sprintf(str,"y=%lf(x-%lf)+%lf\n",dAX,C,AX);
    return str;
}
char* ArcSin(double C){
    double arcsinC,darcsinC;
    static char str[256] = {0};
    arcsinC = asin(C);
    darcsinC=1/sqrt(1-pow(C,2));
    sprintf(str,"y=%lf(x-%lf)+%lf\n",darcsinC,C,arcsinC);
    return str;
}
char* ArcTan(double C){
    double arctanC,darctanC;
    static char str[256]={0};
    arctanC = atan(C);
    darctanC = 1/(1+pow(C,2));
    sprintf(str,"y=%lf(x-%lf)+%lf",darctanC,C,arctanC);
    return str;
}
