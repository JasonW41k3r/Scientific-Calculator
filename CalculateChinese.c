#include <stdio.h>
#include <math.h>
#include "headers.h"
int CalculateChinese() {
    while (1) {
        char input[5] = {0};
        gets(input);
        if (strcmp(input, "*") == 0) {
            BrochureChinese();
        }
        else if (strcmp(input, "#0") == 0) {
            break;
        }
        else if(strcmp(input, "#1") == 0) {
        	StatisticChinese();
        	getchar();
        	printf("���ѽ������˵�\n");
			continue; 
		} 
        else if(strcmp(input, "#3") == 0) {
        	Integral();
        	getchar();
        	printf("���ѽ������˵�\n");
			continue; 
		} 		
        else if(strcmp(input, "#2") == 0) {
        	Derivative();
        	getchar();
        	printf("���ѽ������˵�\n");
			continue; 
		} 		
        else if (strcmp(input, "#") == 0) {
            printf("���ѽ��볣��ģʽ�����Խ�����ͨ��������\n");
            Calculate();
            BrochureChinese();
            continue;
        }
        else if (strcmp(input, "#4") == 0) {
            TriangleChinese();
            getchar();
            printf("���ѽ������˵�\n");
            continue;
        }
    } 
}
