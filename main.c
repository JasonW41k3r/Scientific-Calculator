/*
**代码开发：饶鉴晟 
**代码审核：饶鉴晟
*/
#include "headers.h"
#include <stdio.h>

int main(int argc, char *argv[]) {
    int choose = 0;
    printf("请选择软件语言：\n[1] 简体中文\n");
    scanf("%d", &choose);
    getchar();
    switch(choose) {
        case 1:
            PrintScreenChinese();
            CalculateChinese();
            printf("再见！\n");
            break;
        default:
            printf("再见！\nGoodBye!");
            break;
    }
    return 0;
} 
