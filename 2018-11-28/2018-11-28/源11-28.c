#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
// 1.��д������
// unsigned int reverse_bit(unsigned int value);
// ��������ķ���ֵvalue�Ķ�����λģʽ�����ҷ�ת���ֵ��
// 
// �磺
// ��32λ������25���ֵ�������и�λ��
// 00000000000000000000000000011001
// ��ת�󣺣�2550136832��
// 10011000000000000000000000000000
// ���������أ�
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

// 2.��ʹ�ã�a + b�� / 2���ַ�ʽ������������ƽ��ֵ��
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
// 3.���ʵ�֣�
// һ��������ֻ��һ�����ֳ�����һ�Ρ������������ֶ��ǳɶԳ��ֵġ�
// ���ҳ�������֡���ʹ��λ���㣩
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
// ��һ���ַ����������Ϊ:"student a am i",
// 			���㽫��������ݸ�Ϊ"i am a student".
// 			Ҫ��
// 			����ʹ�ÿ⺯����
// 			ֻ�ܿ������޸��ռ䣨�ռ�������ַ����ĳ����޹أ���
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
/*1.��������ʹ����ȫ����λ��ż��ǰ�档 
��Ŀ�� 
����һ���������飬ʵ��һ�������� 
�����������������ֵ�˳��ʹ�����������е�����λ�������ǰ�벿�֣� 
����ż��λ������ĺ�벿�֡� */
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
//���Ͼ��� 
��һ����ά����. 
�����ÿ�д������ǵ����ģ�ÿ�д��ϵ����ǵ�����. 
�������������в���һ�������Ƿ���ڡ� 
ʱ�临�Ӷ�С��O(N); 

���飺 
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
		printf("���ڵ��ֵ�");
	}
	else
	{
		printf("�����ڵ��ֵ�");
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