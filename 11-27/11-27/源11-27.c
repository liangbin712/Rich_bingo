#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int found(int a)
{
	if (a <= 9)
	{
		return a;
	}
	if (a > 9 && a < 100)
	{
		return a = (a / 10) % 10;
	}
	if (a >99 && a < 1000)
	{
		return a = (a / 100) % 10;
	}
}
int main()
{
	int a =10, b = 11, c = 22;
	int d = 505, e = 9;
	int arr[5] = {a, b, c,d,e };
	int ans[5] = { found(a), found(b), found(c), found(d), found(e)};
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5 - i; j++)
		{
			if (ans[j] < ans[j + 1])
			{
				int temp,all;
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
				all = ans[j];
				ans[j] = ans[j + 1];
				ans[j + 1] = all;
			}
		}
	}
	for (int i = 0; i < 5; i++)
	{
	printf("%d", arr[i]);
	}
	/*char cool[3];
	for (int i = 0; i < 3; i++)
	{
		cool[i] = arr[i];
	}
	for (int i = 0; i < 3; i++)
	{
		printf("%c", cool[i]);
	}*/
	system("pause");
}

