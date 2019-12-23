#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <time.h>

#define MAXSIZE 10000000  /*栈能达到的最大容量*/

typedef int DataType;  // 使用 DataType 来代替 int

/*顺序栈存储结构*/
typedef struct
{
	DataType data[MAXSIZE];
	int top;
}SeqStack;


/*初始化栈*/
SeqStack * initSeqStack()  // 这边返回值是一个栈指针
{
	SeqStack *s;
	s = (SeqStack *)malloc(sizeof(SeqStack));  	// 指针类型的强制转换 ，malloc 开辟足够大的空间
	s->top = -1;                        		// 这边是不是重复开辟了空间？之前 SeqStack 不就分配过一次空间了吗？
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
// 自己写的对栈的使用函数，可以输入一个 txt 里面是各个点的坐标，将这些点进行斑块合并，使用栈结构

int main()
{
    // 对输入的点文件进行合并

    SeqStack *a;
    a = initSeqStack();  // 初始
    FILE *fp;
    char buff[10];
    fp = fopen("C://Users//Administrator//Desktop//test.txt", "w");

    for(int i=0; i<2000000;i++)
    {
        push(a, i);
        itoa(getTop(a), buff, 10);
        fputs(strcat(buff, "\n"), fp);
    }

    fclose(fp);

}
