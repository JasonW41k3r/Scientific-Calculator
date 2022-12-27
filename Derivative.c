/*
**代码开发：庞越飞 
**代码审核：饶鉴晟
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
    printf("请选择所需要的功能：\nA：求导数的表达式；B：求曲线的切线\n");
    char c;
    c = GetChar();
    if (c >= 'a' && c <= 'z') c = c + ('A' - 'a');
    char b;
    double C;//需传入该切点的横坐标
    switch(c){
    	case '#':
    		break;
        case 'A':
            printf("请选择需查询表达式的形式：\n1.常函数；\t2.正弦函数；\n3.正切函数；\t4.正割函数；\n5.指数函数；\t6.对数函数；\n7.反正弦函数；\t8.反正切函数\n");
           // printf("Please select the form of the expression to be queried:1. Constant function; 2. Trigonometric function; 3. Tangent function; 4. Secant function; 5. Exponential function; 6. Logarithmic function; 7. Arcsine function; 8. Arctangent function\n");
            b = GetChar();
            switch(b){
                case'1':{
                    printf("请输入常函数的y值为：");//printf（"Please enter y value of constant function as:"）;
                    double y;
                    scanf("%lf",&y);
                    printf("对应函数的导数表达式为： y = %lf",y);//printf("The derivative expression of the corresponding function is： y = %lf",y);
                    printf("\n");
                    break;}
                case'2':
                    printf("对应函数的导数表达式为：y = cosx");//printf("The derivative expression of the corresponding function is： y = cosx");
                    printf("\n");
                    break;
                case'3':
                    printf("对应函数的导数表达式为：y = （secx）^2");//printf("The derivative expression of the corresponding function is： y = （secx）^2");
                    printf("\n");
                    break;
                case'4':
                    printf("对应函数的导数表达式为：y = secx*tanx");//printf("The derivative expression of the corresponding function is： y = secx*tanx",y);
                    printf("\n");
                    break;
                case'5':
                    printf("请输入指数函数的底数a的数值: ");//printf("Please enter the value of base a of exponential function:");
                    printf("\n");
                    double a,lna;
                    scanf("%lf",&a);
                    if(a<=0){
                        printf("Error");
                    }else{
                        lna = log(a);
                        printf("对应函数的导数表达式为：y = %lf^x*%lf",a,lna);//printf("The derivative expression of the corresponding function is：y = %lf^x*%lf",a,lna);
                        
                    }
                    printf("\n");
                    break;
                case'6':
                    printf("请输入对数函数的底数a的数值: ");//printf("Please enter the value of the base a of the logarithmic function:");
                    double b,lnb,B;
                    scanf("%lf",&b);
                    if(b<=0){
                        printf("Error");
                    }else{
                        lnb = log(b);
                        B = 1 / lnb;
                        printf("对应函数的导数表达式为：y=1/x*%lf",B);//printf("The derivative expression of the corresponding function is：y=1/x*%lf",B);
                    }
                    printf("\n");
                    break;
                case'7':
                    printf("对应函数的导数表达式为：y=1/sqrt(1-x^2)");//printf("The derivative expression of the corresponding function is：y=1/sqrt(1-x^2)");
                    printf("\n");
                    break;
                case'8':
                    printf("对应函数的导数表达式为：y=1/(1+x^2)");//printf("The derivative expression of the corresponding function is：y=1/(1+x^2)");
                    printf("\n");
                    break;
                default:
                    printf("Error\n");
                    break;
            }
            break;
        case'B':
            printf("请选择需查询数值的形式：1.常函数；2.三角函数；3.正切函数；4.正割函数；5.指数函数；6.对数函数；7.反正弦函数；8.反正切函数\n");
            //printf("Please select the form of the value to be queried:1. Constant function; 2. Trigonometric function; 3. Tangent function; 4. Secant function; 5. Exponential function; 6. Logarithmic function; 7. Arcsine function; 8. Arctangent function\n");
            b = GetChar();
            printf("请输入切点处的横坐标: x = ");//printf("Please enter the abscissa at the tangent point: x = ");
            scanf("%lf",&C);//在此处传入
            switch(b)
            {
                case '1':
                {
                    char *pStr = ChangHanShu(C);
                    printf("该点处切线方程为：%s",pStr);//printf("The tangent equation at this point is: %s",pStr);
                    break;
                    
                }
                case '2':
                {
                    char *pStr = Sin(C);
                    printf("该点处切线方程为：%s",pStr);//printf("The tangent equation at this point is: %s",pStr);
                    break;
                    
                }
                case '3':
                {
                    char *pStr = Tan(C);
                    printf("该点处切线方程为：%s",pStr);//printf("The tangent equation at this point is: %s",pStr);
                    break;
                    
                }
                case'4':
                {
                    char *pStr = Sec(C);
                    printf("该点处切线方程为：%s",pStr);//printf("The tangent equation at this point is: %s",pStr);
                    break;
                    
                }
                case'5':
                {
                    char *pStr = Index(C);
                    printf("该点处切线方程为：%s",pStr);//printf("The tangent equation at this point is: %s",pStr);
                    break;
                    
                }
                case'6':
                {
                    char *pStr = Log(C);
                    printf("该点处切线方程为：%s",pStr);//printf("The tangent equation at this point is: %s",pStr);
                    break;
                    
                }
                case'7':
                {
                    char *pStr = ArcSin(C);
                    printf("该点处切线方程为：%s",pStr);//printf("The tangent equation at this point is: %s",pStr);
                    break;
                    
                }
                case'8':ArcTan(C);
                {
                    char *pStr = ArcTan(C);
                    printf("该点处切线方程为：%s",pStr);//printf("The tangent equation at this point is: %s",pStr);
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
        printf("请输入对数函数的底数：");//printf("printf("Please enter the value of the base of the logarithmic function: ");
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
    printf("请输入指数函数的底数:");//printf("Please enter the value of base of exponential function:");
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
