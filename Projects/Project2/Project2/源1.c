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
	printf("��������Ϸ����1ѡ��ʼ����0ѡ���˳���Ϸ");
	scanf_s("%d", &a);
	for (i = 0;; i++)
	{
		if (a == 1)
		{
			printf("1-100֮��,�����������µ�����");
			scanf("%d", &x);
			if (x > t)
			{
				printf("����");
			}
			else if (x < t)
			{
				printf("����");
			}
			else

			{
				printf("��ϲ�㣬����ȷ");
				break;
			}
		}
		else
		{
			printf("��Ϸ�رգ���������˳�");
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
	printf("������Ҫ���ҵ����֡�");
	scanf("%d", &a);
	length = sizeof(arr) / sizeof(int);
	for (j = length / 2;;)
	{
		if (a == arr[j])
		{
			index = j + 1;
			printf("���ҵ����±�Ϊ%d",index);    //1 2 3 4 5 6 7 8 9 10
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
	printf("����������");
	scanf("%s", &input);
	if (strcmp(password,input) == 0)
	{
		printf("������ȷ");
	}
	else
	{
		printf("�������");
	}
	system("pause");
}
*/
/*int main()
{
	int num;
	char letter;
	printf("�������ַ�");
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

2.ʹ�ú���ʵ���������Ľ�����
3.ʵ��һ�������ж�year�ǲ������ꡣ
4.����һ�����飬
ʵ�ֺ���init������ʼ�����顢
ʵ��empty����������顢
ʵ��reverse���������������Ԫ�ص����á�
Ҫ���Լ���ƺ����Ĳ���������ֵ��
5.ʵ��һ���������ж�һ�����ǲ���������
*/
/*int main()
{
	int i, j = 1, k, num;
	printf("����Ҫһ�����˼��ĳ˷���");
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
			printf("%d������", *year);
		}
		else
		{
			printf("%d��������", *year);
		}
	}
	else if (*year > 100)
	{  
		a = *year % 400;
		if (a % 4 == 0)
		{
			printf("%d������", *year);
		}
		else
		{
			printf("%d��������", *year);
		}
	}
	else
	{
		printf("%d��������", *year);
	}
}
int main()
{ 
	int a;
	printf("���������");
	scanf("%d", &a);
	decide(&a);
	system("pause");
}
*/
/*����һ�����飬
ʵ�ֺ���init������ʼ�����顢
ʵ��empty����������顢
ʵ��reverse���������������Ԫ�ص����á�
Ҫ���Լ���ƺ����Ĳ���������ֵ��
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
	printf("���������");
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
			printf("����������");
			break;
		}
		else
		{
			printf("��������");
			break;
		}
	}
}
int main()
{
	int sum;
	printf("������");
	scanf("%d", &sum);
	prime(&sum);
	system("pause");
}
