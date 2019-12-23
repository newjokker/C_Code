#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*
尝试自己实现数字和字符串之间的转换


*/


int main()
{
	int number1 = 123456;
	int number2;
	char string[16] = {0};
	char string_2[16] = "11223344.2356";
	// 数字转为字符串
	itoa(number1,string,10);
	printf("number %d --> %s\n",number1,string);
	// 字符串转为数字
	number2 = atoi(string_2);
	printf("string %s --> %d\n",string_2, number2);
}
