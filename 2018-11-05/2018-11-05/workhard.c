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
//��#define�У���׼ֻ������#��##���ֲ�����#�����Ѳ���ת�����ַ�����##��������������ǰ�����������������Ǳ��һ���ַ�����
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
/*#undef ��ʶ��

������ǰ�涨��ĺ��ʶ��ȡ�����塣

���������¼��ֳ����÷�������Ժ�������������ӽ�����

1����һ�������������궨���Ϊ��ֹ�����ʶ����ͻ��Ҫȡ����궨�壺
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
	 strlen(str + 1) + 1;   //�ݹ�˼�룬��str + 1��������str��ַ�Ƶ���һ��Ԫ��
	 printf("%s", str);   //��Ȼ�ݹ黹��Ҫ�����г���
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
	return n * factor(n - 1);   // 5*2*3*4  ������ȥ 4 3 2 �³��� 2 3 4��
}
int main()
{
	printf("%d\n", factor(5));
	system("pause");
}*/
1.�ݹ�ͷǵݹ�ֱ�ʵ�����n��쳲���������
