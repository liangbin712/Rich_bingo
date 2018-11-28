#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
// 1.编写函数：
// unsigned int reverse_bit(unsigned int value);
// 这个函数的返回值value的二进制位模式从左到右翻转后的值。
// 
// 如：
// 在32位机器上25这个值包含下列各位：
// 00000000000000000000000000011001
// 翻转后：（2550136832）
// 10011000000000000000000000000000
// 程序结果返回：
// 2550136832
// int arrm[32] = { 0 };
// unsigned int Double(unsigned int m)
// {
// 	int i = 0;
// 	while (1)
// 	{
// 		if (m == 2)
// 		{
// 			arrm[i] = 0;
// 			i++;
// 			m = m / 2;
// 		}
// 		if (m == 1)
// 		{
// 			arrm[i] = 1;
// 			break;
// 		}
// 		if (m == 0)
// 		{
// 			arrm[i] = 0;
// 		}
// 		if (m % 2 == 0)
// 		{
// 			arrm[i] = 0;
// 			i++;
// 			m = m / 2;
// 		}
// 		if (m % 2 == 1)
// 		{
// 			arrm[i] = 1;
// 			i++;
// 			m = m / 2;
// 		}
// 	}
// 	return 0;
// }
// unsigned long long reverse_bit(unsigned int value)
// {
// 	Double(value);
// 	long long sum = 0, a = 0;
// 	for (int i = 0; i < 32;i++)
// 	{
// 		if (arrm[i] == 1)
// 		{
// 			a = pow(2,32 - i);
// 			sum = sum + a;
// 		}
// 	}
// 	return sum;
// }
// int main()
// {
// 	printf("%d", reverse_bit(25));
// 	system("pause");
// }

// 2.不使用（a + b） / 2这种方式，求两个数的平均值。
// int main()
// {
// 	int a = 5, b = 7,num;
// 	if (a > b)
// 	{
// 		num = (a - b) / 2 + b;
// 	}
// 	else
// 	{
// 		num = (a - b) / 2 + b;
// 	}
// 	printf("%d", num);
// 	system("pause");
// }
// 
// 3.编程实现：
// 一组数据中只有一个数字出现了一次。其他所有数字都是成对出现的。
// 请找出这个数字。（使用位运算）
// 3.int main()
// {
// 	int a[7] = { 1, 2, 2, 1, 3, 4, 3 };
// 	int ans = 0;
// 	for (int i = 0; i < 7; i++)
// 	{
// 		ans ^= a[i];
// 	}
// 	printf("%d\n", ans);
// 	system("pause");
// }
// 4.
// 有一个字符数组的内容为:"student a am i",
// 			请你将数组的内容改为"i am a student".
// 			要求：
// 			不能使用库函数。
// 			只能开辟有限个空间（空间个数和字符串的长度无关）。
// 
// 			student a am i
// 			i ma a tneduts
// 			i am a student
/*
int my_strlen(const char *str)
{
	int count = 0;
	assert(str);
	while (*str != '\0')
	{

		count++;
		str++;
	}
	return count;


}
void reverse(char a[], int left, int right)
{
	while (left < right)
	{
		char tmp = a[left];
		a[left] = a[right];
		a[right] = tmp;
		left++;
		right--;
	}

}
char* reverse_string(char a[])
{
	int i = 0;
	int left = 0;
	int right = my_strlen(a) - 1;
	reverse(a, left, right);

	while (a[i] != '\0')
	{
		left = i;
		while ((a[i] != '\0') && (a[i] != ' '))
		{
			i++;

		}
		right = i - 1;
		reverse(a, left, right);
		if (a[i] != '\0')
			i++;
	}
	return a;
}

int main()
{
	char a[] = "student a am i";
	reverse_string(a);
	printf("%s\n", a);
	return 0;
}*/
/*1.调整数组使奇数全部都位于偶数前面。 
题目： 
输入一个整数数组，实现一个函数， 
来调整该数组中数字的顺序使得数组中所有的奇数位于数组的前半部分， 
所有偶数位于数组的后半部分。 */
// void Adjust(int arr[])
// {
// 	for (int i = 0,j = 0 ; i < 6;i++)
// 	{
// 		if (arr[i] % 2 !=0)
// 		{
// 			int temp;
// 			temp = arr[j];
// 			arr[j] = arr[i];
// 			arr[i] = temp;
// 			j++;
// 		}
// 	}
// 	for (int i = 0; i < 6; i++)
// 	{
// 		printf("%d", arr[i]);
// 	}
// }
// int main()
// {
// 	int arr[6] = {5,2,1,6,4,3};
// 	Adjust(arr);
// 	system("pause");
// }
/*2. 
//杨氏矩阵 
有一个二维数组. 
数组的每行从左到右是递增的，每列从上到下是递增的. 
在这样的数组中查找一个数字是否存在。 
时间复杂度小于O(N); 

数组： 
1 2 3 
2 3 4 
3 4 5 


1 3 4 
2 4 5 
4 5 6 

1 2 3 
4 5 6 
7 8 9*/
int find(int arr[3][3],int a)
{
	if (a <= *(arr+2))
	{
		printf("存在的兄弟");
	}
	else
	{
		printf("不存在的兄弟");
	}
}
int main()
{
	int a;
	scanf("%d", &a);
	int arr[3][3] = {{ 1, 2, 3 },{ 4, 5, 6 },{ 7, 8, 9 }};
	find(arr,a);
	system("pause");
}