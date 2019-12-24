#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <time.h>

/*
使用数组实现栈
*/


#define MAXSIZE 1024 * 1024 * 100  /*栈能达到的最大容量*/

typedef int DataType;  // 使用 DataType 来代替 int

// 顺序栈存储结构
typedef struct                  // 用typedef创建新类型，现在可以用 SeqStack 作为类型声明新的结构体变量
{
	DataType data[MAXSIZE];     // 这边为什么就不受制于 栈的 1M 的大小了，是不是这边只是定义，而定没有真正的分配空间？
	int top;
}SeqStack;


// 初始化栈
SeqStack * initSeqStack()  // 这边返回值是一个栈指针
{
	SeqStack *s;
	s = (SeqStack *)malloc(sizeof(SeqStack));  	// 指针类型的强制转换 ，malloc 开辟足够大的空间，不受制于局部变量的空间限制
	s->top = -1;
	printf("%f M \n", (float)(sizeof(SeqStack)/(1024.0*1024.0)));
	return s;
}

// 判断栈是否为空
int isEmpty(SeqStack *s)
{
	if(s->top == -1)
		return 1;
	else
		return 0;
}

// 入栈操作
int push(SeqStack * s, DataType x)
{
	if(s->top == MAXSIZE-1)
	{
		printf("stack overflow");
		return 0;
	}
	s->top++;
	s->data[s->top] = x;
	return 1;
}

// 出栈操作
int pop(SeqStack * s)
{
	if(isEmpty(s)){
		printf("stack empty!");
		return 0;
	}
	s->top--;
	return 1;
}

// 读栈顶元素
DataType getTop(SeqStack *s)
{
	if(isEmpty(s)){
		printf("stack empty!");
		return 0;
	}
	return (s->data[s->top]);
}

// -------------------------------------- 栈的使用 -----------------------------------------------------

int main()
{
    // 对输入的点文件进行合并

    SeqStack *a;
    a = initSeqStack();  // 初始
    FILE *fp;
    char buff[10];
    fp = fopen("C://Users//Administrator//Desktop//test.txt", "w");

    printf("%d\n", isEmpty(a));

    for(int i=0; i<(1024*1024);i++)
    {
        push(a, i);
        itoa(getTop(a), buff, 10);
        fputs(strcat(buff, "\n"), fp);
    }
    fclose(fp);
}
