#include<stdio.h>
#include<stdlib.h>
5.int strlen(char* string, int len)
{
	if (*(string + len) != '\0')
	{
		len++;
		strlen(string, len);
	}
	else
	{
		printf("%d ", len);
	}
}
int F_strlen(char *string)
{
	int r = 0;
	for (string; *string; string++)
	{
		++r;
	}
	printf("%d", r);
}
int main()
{
	char *string = "abcdef";
	F_strlen(string);
	int len = 0;
	strlen(string, len);
	system("pause");
}
6.int J_chen(int n)
{
	if (n == 1)
	{
		return 1;
	}
	else
	{
		return J_chen(n - 1) * n;
	}
}
int JF_chen(int n)
{
	int sum = 1;
	for (n; n > 0; n--)
	{
		sum = sum * n;
	}
	printf("%d", sum);
}
int main()
{
	printf("%d  ", J_chen(5));
	JF_chen(5);
	system("pause");
}
7.int Zsum(int n)
{
	if (n > 9)
	{
		Zsum(n / 10);
	}
	printf("%d ", n % 10);
}
int main()
{
	int n = 123456;
	int m = 1;
	Zsum(n);
	system("pause");
}

