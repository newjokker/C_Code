#include<stdio.h>
#include<stdlib.h>    /*���� malloc ���������ӻ��о��浫������*/
#include<string.h>    /*���� strlen ���������ӻ��о��浫������*/
#define MAXSIZE 1024  /*ջ�ܴﵽ���������*/


typedef int DataType;
/*˳��ջ�洢�ṹ*/
typedef struct
{
	DataType data[MAXSIZE];
	int top;
}SeqStack;

/*��ʼ��ջ*/
SeqStack * initSeqStack()
{
	SeqStack *s;
	s = (SeqStack *)malloc(sizeof(SeqStack));
	s->top = -1;
	return s;
}

// �ж�ջ�Ƿ�Ϊ��
int isEmpty(SeqStack *s)
{
	if(s->top == -1)
		return 1;
	else
		return 0;
}

// ��ջ����
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

// ��ջ����
int pop(SeqStack * s)
{
	if(isEmpty(s)){
		printf("stack empty!");
		return 0;
	}
	s->top--;
	return 1;
}

// ��ջ��Ԫ��
DataType getTop(SeqStack *s)
{
	if(isEmpty(s)){
		printf("stack empty!");
		return 0;
	}
	return (s->data[s->top]);
}

// �������תʮ����
int HexAnyToTen(char * num,int hex_begin){
	int i = 0,j = 0,k = 1;
	int counter = 0;
	int prior = 0;
	int length = strlen(num);
	printf("%d",length);
	for(i=0;i < length; i++)
	{
		k = 1;
		for(j=0;j<length-1-i;j++)
		{
			k *= hex_begin;
		}
		if(num[i] >= 48&&num[i] <= 57)
		{
			counter += (num[i] - '0')*k;
			prior = num[i] - '0';
		}
		else if(num[i] >= 65&&num[i] <= 90){
			counter += (num[i] - 55)*k;
			prior = num[i] - 55;
		}
		else if(num[i] >= 97&&num[i] <= 122){
			counter += (num[i] - 87)*k;
			prior = num[i] - 87;
		}
		else{
			if(i==0){
				continue;
			}
			else{
				counter = counter - prior*k*(hex_begin -1);
			}
		}
	}
	printf("%d\n",counter);
	return counter;
}

// ʮ����ת�������
void    HexToTenToAny(int num_hex_ten,int hex_after)
{
	SeqStack * s;
	int x;
	s = initSeqStack();
	while( num_hex_ten )
	{
		push(s, num_hex_ten % hex_after);
		num_hex_ten /= hex_after;
	}

	printf("ת����Ŀ�Ľ��ƺ�:");

	while(!isEmpty(s))
	{
		x = getTop(s);
		pop(s);
		if(x > 9){
			printf("%c",x+87);
		}
		else{
			printf("%d",x);
		}
	}

	printf("\n");
}

int main()
{
	char num [10] = {'0'};
	int hex_begin = 10;
	int hex_after = 10;
	int num_hex_ten = 0;
	scanf("%s",num);
	scanf("%d %d",&hex_begin,&hex_after);
	//printf("%d",hex_begin);
	num_hex_ten = HexAnyToTen(num,hex_begin);
	HexToTenToAny(num_hex_ten,hex_after);
	return 0;
}
