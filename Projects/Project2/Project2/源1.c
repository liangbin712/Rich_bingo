#define _CRT_SECURE_NO_WARNINGS
#include<stdlib.h>
#include<stdio.h>
#include<math.h>
#include<time.h>
#include<string.h>
/*
int main()
{
    int i,t,x = 0,a;
	srand((unsigned int)time(0));
	t = rand() % 100 + 1;
	printf("猜数字游戏，按1选择开始，按0选择退出游戏");
	scanf_s("%d", &a);
	for (i = 0;; i++)
	{
		if (a == 1)
		{
			printf("1-100之间,请输入你所猜的数字");
			scanf("%d", &x);
			if (x > t)
			{
				printf("高了");
			}
			else if (x < t)
			{
				printf("低了");
			}
			else

			{
				printf("恭喜你，答案正确");
				break;
			}
		}
		else
		{
			printf("游戏关闭，按任意键退出");
		}
	}
		system("pause");

}
*/
/*
int main()
{
	int arr[] = { 0, 1, 2, 3, 4, 5, 6, 9, 10, 11 };
	int j = 0,a,index,length,k = 10;
	printf("请输入要查找的数字。");
	scanf("%d", &a);
	length = sizeof(arr) / sizeof(int);
	for (j = length / 2;;)
	{
		if (a == arr[j])
		{
			index = j + 1;
			printf("你找到了下标为%d",index);    //1 2 3 4 5 6 7 8 9 10
			break;
		}
		else if (a > arr[j])
		{
			if (j % 2 == 0)
			{
				j = (j + k - 1) / 2;
			}
			else
			{
				j = (j+k-1) / 2;
			}
		}
		else if (a < arr[j] )
		{
			if (j % 2 == 0)
			{
				j = (j + k - 1) / 2;
			}
			else
			{
				j = j / 2;
			}
		}
		k = j;
	}
	system  ("pause");
}
*/
/*int main()
{
	int i, j;
	char password[] = "123456";
	char input[6];
	printf("请输入密码");
	scanf("%s", &input);
	if (strcmp(password,input) == 0)
	{
		printf("密码正确");
	}
	else
	{
		printf("密码错误");
	}
	system("pause");
}
*/
/*int main()
{
	int num;
	char letter;
	printf("请输入字符");
	scanf("%d", &num);
	scanf("%s", &letter);
	if (letter >= 97 && letter <= 122)
	{
		letter = letter - 32;
		printf("%c", (unsigned char)letter);
	}
	else if (letter >= 65 && letter <= 90)
	{
		letter = letter + 32;
		printf("%c", (unsigned char)letter);
	}
	else 
	{
		printf("");
	}
	system("pause");
}
*/
/*int change(int x,int y);
void main()
{
	int a, b, m;
	printf("input two data:\n");
	scanf("%d%d", &a, &b);
	m = change(a, b);
	printf("main a = %d b =%d\n", a, b);
}
int change(int x, int y)
{
	printf("start sub x = %d y = %d\n", x, y);
	x = 64;
	y = 36;
	printf("End sub x = %d y = %d\n", x, y);
	return x * y; 
}

2.使用函数实现两个数的交换。
3.实现一个函数判断year是不是润年。
4.创建一个数组，
实现函数init（）初始化数组、
实现empty（）清空数组、
实现reverse（）函数完成数组元素的逆置。
要求：自己设计函数的参数，返回值。
5.实现一个函数，判断一个数是不是素数。
*/
/*int main()
{
	int i, j = 1, k, num;
	printf("您需要一个几乘几的乘法表");
	scanf("%d", &k);
	for (i = 1; i < k +1; i++)
	{
		for (j = 1; j < i+1; j++)
		{ 
			num = i * j;
			printf("%d*%d=%d ", j, i,num);
			
		}
		printf("\n");
	}
	system("pause");
}
*/
/*void decide(int * year)
{
	int a;
	if (*year < 100)
	{
		if (*year % 4 == 0)
		{
			printf("%d是闰年", *year);
		}
		else
		{
			printf("%d不是闰年", *year);
		}
	}
	else if (*year > 100)
	{  
		a = *year % 400;
		if (a % 4 == 0)
		{
			printf("%d是闰年", *year);
		}
		else
		{
			printf("%d不是闰年", *year);
		}
	}
	else
	{
		printf("%d不是闰年", *year);
	}
}
int main()
{ 
	int a;
	printf("请输入年份");
	scanf("%d", &a);
	decide(&a);
	system("pause");
}
*/
/*创建一个数组，
实现函数init（）初始化数组、
实现empty（）清空数组、
实现reverse（）函数完成数组元素的逆置。
要求：自己设计函数的参数，返回值。
*/
/*
void init(int a[],int len)
{
	for (int i = 0; i < len; i++)
	{
		a[i] = i * 2 + 1;
		printf("%d\t",a[i]);
	}
	printf("\n");
}
void empty(int a[])
{
	for (int i = 0; i < 5; i++)
	{
		a[i] = 0;
		printf("b[%d] = %d\t",i,a[i]);
	}
	printf("清空数组了");
	printf("\n");
}
void reverse(int a[])
{
	for (int i = 4; i >= 0; i--)
	{
		printf("%d\t", a[i]);
	}
	printf("\n");
}
int main()
{
	int b[5],j,length;
	length = sizeof(b) / sizeof(b[0]);
	init(b,length);
	reverse(b);
	empty(b);
	system("pause");
}*/
void prime(int *num)
{
	int i;
	for (i = 2; i < *num; i++)
	{
		if (*num % i == 0)
		{
			printf("它不是素数");
			break;
		}
		else
		{
			printf("它是素数");
			break;
		}
	}
}
int main()
{
	int sum;
	printf("请输入");
	scanf("%d", &sum);
	prime(&sum);
	system("pause");
}
