#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/*#define paster( n ) printf( "token " #n" + %s\n ", token##n)*/
/*int main()
{
	int token9 = 10;
	paster(9);
	system("pause");
}
//在#define中，标准只定义了#和##两种操作。#用来把参数转换成字符串，##则用来连接两个前后两个参数，把它们变成一个字符串。
*/
/*
#define M (a+b)
main(){
	int a = 3;
	int b;
	printf("input a number: ");
	scanf("%d", &b);
	a = M*M;
	printf("s=%d\n", a);
	system("pause");
}
/*#undef 标识符

用来将前面定义的宏标识符取消定义。

整理了如下几种常见用法，如果以后发现其他的再添加进来。

1、在一个程序块中用完宏定义后，为防止后面标识符冲突需要取消其宏定义：
*//*
#include <stdio.h>
int main()
{
#define MAX 200
	printf("MAX = %d\n", MAX);
#undef MAX
	{
		int MAX = 10;
		printf("MAX = %d\n", MAX);
	}
	return 0;
}
*/
/*int main()
{
	int a = 6;
	const int* n = &a;
	
	printf("%p",&n);
	system("pause");
}*/
/*int strlen(char str[])
{
	if (str[0] == '\0')
	{
		return 0;
	}
	 strlen(str + 1) + 1;   //递归思想，（str + 1）是数组str地址推到下一个元素
	 printf("%s", str);   //果然递归还是要从梦中出来
}
int main()
{
	char str[] = "abcd";
	int ret = strlen(str);
	printf("%d\t", ret);
	system("pause");
}*/
//1*2*3*.....*n-1*n;
/*int factor(int n)
{
	if (n == 1)
	{
		return 1;
	}
	return n * factor(n - 1);   // 5*2*3*4  先吸进去 4 3 2 吐出来 2 3 4；
}
int main()
{
	printf("%d\n", factor(5));
	system("pause");
}*/
1.递归和非递归分别实现求第n个斐波那契数。
