#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <time.h>

/*
使用数组实现栈
*/


#define MAXSIZE 102 /*栈能达到的最大容量*/

typedef int DataType;  // 使用 DataType 来代替 int


typedef struct
{
    DataType data[MAXSIZE];
    int top;
}SeqStack;

SeqStack * StackInit()
{
    SeqStack *s;
    s = (SeqStack *)malloc(sizeof(SeqStack));
    s->top = -1;
    return s;
}

int isEmpty(SeqStack *s)
{
    if((s->top)==-1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void push(SeqStack *s, DataType v)
{
    if(s->top < MAXSIZE)
    {
        s->data[s->top] = v;
        s->top++;
    }
    else
    {
        printf("%s", "over flow");
    }
}

void pop(SeqStack *s)
{
    if(s->top != -1)
    {
        s->top--;
    }
    else
    {
        printf("%s", "no data left");
    }
}

int GetTopValue(SeqStack *s)
{
    if(s->top != -1)
    {
        return s->data[s->top];
    }
    else
    {
        printf("%s", "no value");
        return 0;
    }
}

int main()
{
    printf("ok");
}