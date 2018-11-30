#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
// 写一个函数返回参数二进制中 1 的个数
// 比如： 15 0000 1111 4 个 1
// 程序原型：
// int count_one_bits(unsigned int value)
// {
// 	int i = 0;
// 	while (1)
// 	{
// 		if (value % 2 == 0 && value / 2 == 1)
// 		{
// 			return i;
// 		}
// 		if (value % 2 == 1 && value / 2 == 1)
// 		{
// 			i=i+2;
// 			return i;
// 		}
// 		if (value == 1)
// 		{
// 			return 1;
// 		}
// 		if (value == 0)
// 		{
// 			return 0;
// 		}
// 		i++;
// 		value = value / 2;
// 	}
// }
// int main()
// {
// 	printf("%d", count_one_bits(10));
// 	system("pause");
// 
// 	   2.获取一个数二进制序列中所有的偶数位和奇数位，
// 	   分别输出二进制序列。
/*void Get(unsigned int value)
 {
	int oxl[4] = { 0 };
	int jxl[4] = { 0 };
	int arr[8] = { 0 }, i = 0;
	while (1)
	{
		if (value == 2)
		{
			arr[7-i] = 0;
			i++;
			value = value / 2;
		}
		if (value == 1)
		{
			arr[7-i] = 1;
			break;
		}
		if (value == 0)
		{
			arr[i] = 0;
		}
		if (value % 2 == 0)
		{
			arr[7-i] = 0;
			i++;
			value = value / 2;
		}
		if (value % 2 == 1)
		{
			arr[7-i] = 1;
			i++;
			value = value / 2;
		}
	}
	int l = 0, b = 0;
	for (int k = 0; k < 8;k++)
	{
		if (k == 0)
		{
			jxl[4-l] = arr[7-k];
			l++;
		}
		if (k == 1)
		{
			oxl[4-b] = arr[7-k];
			b++;
		}
		if (k % 2 == 0 && k > 1)
		{
			jxl[4-l] = arr[7-k];
			l++;
		}
		if (k % 2 == 1 && k >1)
		{
			oxl[4-b] = arr[7-k];
			b++;
		}
	}
	printf("偶序列为：");
	for (int j = 0; j < 4; j++)
	{
		printf("%d", oxl[j]);
	}
	printf("\n奇序列为：");
	for (int j = 0; j < 4; j++)
	{
		printf("%d", jxl[j]);
	}
}
int main()
{
	Get(10);
	system("pause");
}*/
// 3. 输出一个整数的每一位。
// void Zsum(int n)
// {
// 	if (n > 9)
// 	{
// 		Zsum(n / 10);
// 	}
// 	printf("%d ", n % 10);
// }
// int main()
// {
// 	int i, j, k;
// 	scanf("%d", &k);
// 	Zsum(k);
// }// 
// 4.编程实现：
// 两个int（32位）整数m和n的二进制表达中，有多少个位(bit)不同？
// 输入例子 :
// 1999 2299
// 输出例子 : 7
// // 
/*int arr[8] = { 0 };
int arrm[32] = { 0 };
int arrn[32] = { 0 };
void Double(int m)
{
	int i = 0;
	while (1)
	{
		if (m == 2)
		{
			arrm[31 - i] = 0;
			i++;
			m = m / 2;
		}
		if (m == 1)
		{
			arrm[31 - i] = 1;
			break;
		}
		if (m == 0)
		{
			arrm[i] = 0;
		}
		if (m % 2 == 0)
		{
			arrm[31 - i] = 0;
			i++;
			m = m / 2;
		}
		if (m % 2 == 1)
		{
			arrm[31 - i] = 1;
			i++;
			m = m / 2;
		}
	}
}
void Doublel(int n)
{
	int i = 0;
	while (1)
	{
		if (n == 2)
		{
			arrn[31 - i] = 0;
			i++;
			n = n / 2;
		}
		if (n == 1)
		{
			arrn[31 - i] = 1;
			break;
		}
		if (n == 0)
		{
			arrn[i] = 0;
		}
		if (n % 2 == 0)
		{
			arrn[31 - i] = 0;
			i++;
			n = n / 2;
		}
		if (n % 2 == 1)
		{
			arrn[31 - i] = 1;
			i++;
			n = n / 2;
		}
	}
}
int main()
{
 	Double(2299);
	Doublel(1999);
	int num = 0;
	int len = 0;
	for (int i = 0; i < 32;i++)
	{
		if (arrm[i] == 1)
		{
			break;
		}
		len++;
	}
	int lenmax = 32 - len;
	for (int i = 0; i < lenmax; i++)
	{
		if (arrm[31-i] != arrn[31-i])
		{
			num++;
		}
	}
	printf("   %d", num);
	system("pause");
}*/

