/*
**���뿪�����ļ��� 
**������ˣ��ļ���
*/
#include "headers.h"
#include <stdio.h>

int main(int argc, char *argv[]) {
    int choose = 0;
    printf("��ѡ��������ԣ�\n[1] ��������\n");
    scanf("%d", &choose);
    getchar();
    switch(choose) {
        case 1:
            PrintScreenChinese();
            CalculateChinese();
            printf("�ټ���\n");
            break;
        default:
            printf("�ټ���\nGoodBye!");
            break;
    }
    return 0;
} 
