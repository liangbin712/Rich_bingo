#include<stdio.h>
#include<stdlib.h>
//дһ���ݹ麯��DigitSum(n)������һ���Ǹ����������������������֮�ͣ�
//���磬����DigitSum(1729)����Ӧ�÷���1 + 7 + 2 + 9�����ĺ���19
/*
int Digitsum(int n)
{
if (n < 10) //�ݹ����������
{
return n;//����ʱ����Ϊ
}
else										//ģʽһ
{										//��Ϊ�����������
return n % 10 + Digitsum(n / 10);	//��ʣ�µ����⽻���ݹ������ڵ�ȥ�Ĺ����н�����⣩
}
}
//return 1729%10 + Digitsum(1729 /10);			//ģʽ��
//return 1729%10 + 172%10 + Digitsum(172 / 10);//�Ȳ�������⣬�ݹ鴦������
//return 1729%10 + 172%10 + 17%10 +1;==19//�ڹ���ʱ������Ϊ���𲽽������
int main()
{
//int num;
//scanf("%d", &num);
printf("%d\n", Digitsum(1729));
system("pause");
}*/
/*//�õݹ�ʵ�ֶ��ַ�����
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
/*��дһ������ reverse_string(char * string)���ݹ�ʵ�֣�
ʵ�֣��������ַ����е��ַ��������С�
Ҫ�󣺲���ʹ��C�������е��ַ�������������*/
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
