#include<stdio.h>
#include<stdlib.h>
//写一个递归函数DigitSum(n)，输入一个非负整数，返回组成它的数字之和，
//例如，调用DigitSum(1729)，则应该返回1 + 7 + 2 + 9，它的和是19
/*
int Digitsum(int n)
{
if (n < 10) //递归结束的条件
{
return n;//结束时的行为
}
else										//模式一
{										//行为（解决方法）
return n % 10 + Digitsum(n / 10);	//将剩下的问题交给递归解决（在递去的过程中解决问题）
}
}
//return 1729%10 + Digitsum(1729 /10);			//模式二
//return 1729%10 + 172%10 + Digitsum(172 / 10);//先不解决问题，递归处理问题
//return 1729%10 + 172%10 + 17%10 +1;==19//在归来时描述行为，逐步解决问题
int main()
{
//int num;
//scanf("%d", &num);
printf("%d\n", Digitsum(1729));
system("pause");
}*/
/*//用递归实现二分法查找
int erfen(int a, int b, int c, int d[])
{
int x = (a + b) / 2;
if (d[x] == c)
{
printf("%d", x);
}
else if (d[x] > c)
{
return erfen(a, x - 1, c, d);
}
else if (d[x] < c)
{
return erfen(x + 1, b, c, d);
}
}
int main()
{
int arr[5] = { 5, 4, 3, 2, 1 };
int size = sizeof(arr[5]) / sizeof(arr[0]);
int c = 2;
erfen(0,4,c,arr[5]);
}*/
/*编写一个函数 reverse_string(char * string)（递归实现）
实现：将参数字符串中的字符反向排列。
要求：不能使用C函数库中的字符串操作函数。*/
reverse_string(char * string)
{
	if (*(string) != '\0')
	{
		reverse_string(string++);
	}
	printf("%c", *(string - 1));
}
int main()
{
	char *string = "ab";
	reverse_string(string);
	system("pause");
}

/*void reverse_string(char *string)
{
if (*(++string) != '\0')
reverse_string(string);
printf("%c", *(string - 1));
}
int main()
{
char *a = "abcd\0";
reverse_string(a);
printf("\n");
system("pause");
}*/
