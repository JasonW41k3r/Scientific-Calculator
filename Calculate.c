/*
**���뿪���������� 
**������ˣ��ļ���
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "headers.h"

typedef struct node
{
    char val;
    struct node* next;
}pnode;
typedef struct seqstack
{
    int size;
    pnode* top;
}phead;
phead* initstack()//����ջ
{
    phead* istack = (phead*)malloc(sizeof(phead));//Ϊͷ�ڵ����ռ�
    if (istack != NULL)
    {
        istack->top = NULL;
        istack->size = 0;
    }
    return istack;
}
int isempty(phead* istack)//�ж�ջΪ��
{
    if (istack->top == NULL)
    {
        return 1;
    }
    return 0;
}
pnode* seqstack_top(phead* istack)//��ȡջ��Ԫ�ص����ݽڵ�
{
    if (istack->size != 0)
    {
        return istack->top;
    }
    return NULL;
}
pnode* seqstack_pop(phead* istack)//����ջ��Ԫ��
{
    if (isempty(istack) == 0)
    {
        pnode* account = istack->top;
        istack->top = istack->top->next;
        istack->size--;
        return account;
    }
    return NULL;
}
void seqstack_push(phead* istack, char x)//��ջ
{
    pnode* temp;
    temp = (pnode*)malloc(sizeof(pnode));
    temp->val = x;
    temp->next = istack->top;
    istack->top = temp;
    istack->size++;
    return;
}
//��׺���ʽת��׺���ʽ
char buffer[300] = { 0 };

void char_put(char ch)//���ַ������������
{
    static int index = 0;
    buffer[index++] = ch;
}
int priority(char ch)//�Ƚ����ȼ�
{
    int result = 0;
    switch (ch)
    {
    case '+':result = 1; break;
    case '-':result = 1; break;
    case '*':result = 2; break;
    case '/':result = 2; break;
    default:
        break;
    }
    return result;
}
int is_number(char ch)
{
    return(ch >= '0' && ch <= '9');//���ַ���1���������ַ���0
}
int is_op(char ch)
{
    return(ch == '+' || ch == '-' || ch == '*' || ch == '/');
}
int is_left(char ch)
{
    return(ch == '(');
}
int is_right(char ch)
{
    return(ch == ')');
}
int transform(char str[])//��׺���ʽת��׺���ʽ
{
    phead* istack = initstack();
    int i = 0;
    while (str[i] != '\0')
    {
        
        if (is_number(str[i]) == 1)
        {
            if (is_number(str[i + 1]) == 1)
            {
                char_put(str[i]);
            }
            else
            {
                char_put(str[i]);
                char_put(' ');//�м����ո�
            }
        }
        else if (is_op((str[i])) == 1)
        {
            if (str[i + 1] == '0' && str[i] == '/')
            {
                
                return 0;
            }
            if (isempty(istack) == 0)
            {
                while ((isempty(istack) == 0) && (priority(str[i]) <= (priority(seqstack_top(istack)->val))))
                {
                    char_put(seqstack_pop(istack)->val);
                    char_put(' ');//�м����ո�
                }
            }
            seqstack_push(istack, str[i]);
        }
        else if (is_left(str[i]))
        {
            seqstack_push(istack, str[i]);
        }
        else if (is_right(str[i]))
        {
            while (is_left(seqstack_top(istack)->val) != 1)
            {
                char_put(seqstack_pop(istack)->val);
                if (isempty(istack) == 1)
                {
                    return -1;
                }
            }
            seqstack_pop(istack);
        }
        else
        {
            return -1;
        }
        i++;
    }

    if (str[i] == '\0')
    {
        while (isempty(istack) == 0)
        {
            if (seqstack_top(istack)->val == '(')
            {
                return -1;
            }
            char_put(seqstack_pop(istack)->val);
        }
    }
    return 0;
}


//�����׺���ʽ
typedef struct node1
{
    int val;
    struct node1* next;
}pnode1;
typedef struct seqstack1
{
    int size;
    pnode1* top;
}phead1;
phead1* initstack1()
{
    phead1* istack = (phead1*)malloc(sizeof(phead1));
    if (istack != NULL)
    {
        istack->top = NULL;
        istack->size = 0;
    }
    return istack;
}
int isempty1(phead1* istack)
{
    if (istack->top == NULL)
    {
        return 0;
    }
    return 0;
}
int seqstack_top1(phead1* istack)//��ȡջ��Ԫ��
{
    if (istack->size != 0)
    {
        return istack->top->val;
    }
    return 0;
}
int seqstack_pop1(phead1* istack)//ջ��Ԫ�س�ջ
{
    if (isempty1(istack) == 0)
    {
        int account = istack->top->val;
        istack->top = istack->top->next;
        istack->size--;
        return account;
    }
    return 0;
}
void seqstack_push1(phead1* istack, int x)//Ԫ����ջ
{
    pnode1* temp;
    temp = (pnode1*)malloc(sizeof(pnode1));
    temp->val = x;
    temp->next = istack->top;
    istack->top = temp;
    istack->size++;
}
int basecaculate(int a, int b, char op)//��������
{
    switch (op)
    {
    case '+':return a + b; break;
    case '-':return a - b; break;
    case '*':return a * b; break;
    case '/':
        if (b == 0)
        {
            return 0;
        }
        else
        {
            return a / b;
        }
    default:
        break;
    }
    return 0;
}
int getsize(phead1* stack)
{
    return stack->size;
}
int calculate(char str[])//�����׺���ʽ
{
    phead1* istack2 = initstack1();
    int i = 0;
    while (str[i] != '\0')
    {
        char a[6] = { 0 };
        int index = 0;
        if (is_number(str[i]) == 1)
        {
            while (is_number(str[i]) == 1)
            {
                a[index] = str[i];
                index++;
                i++;
            }
            
            seqstack_push1(istack2, atoi(a));
        }
        else if (is_op(str[i]) == 1)
        {
            int right = seqstack_pop1(istack2);
            int left = seqstack_pop1(istack2);
            int ret = basecaculate(left, right, str[i]);
            if (ret == 999)
            {
                printf("�������");
                return 0;
            }
            seqstack_push1(istack2, ret);
        }
        else if (str[i] == ' ')
        {

        }
        else
        {
            printf("error\n");
            break;
        }
        i++;
    }
    if (str[i] == '\0' && getsize(istack2))
    {
        return seqstack_top1(istack2);
    }
    return 0;
}
void Calculate()
{
    char str[1000] = { 0 };
    while (1) {
    printf("********************************\n");
    printf("* ��ӭʹ����ͨ������ *\n");
    printf("********************************\n");
    printf("����������������ʽ:\n");//��������Ҫת����Ӣ��
    scanf("%s", str);
    if (strcmp(str, "*") == 0) break;
    int number = transform(str);
    if (number == -1)
    {
        printf("�������:\n");
    }
    int num = calculate(buffer);
    printf("���Ϊ��%d\n", num);
    }
}
