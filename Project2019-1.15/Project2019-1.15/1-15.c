1.#include <stdio.h>


void Turn(char *sum, int k)
{
	int i, j, temp;
	for (i = 0; i < k; i++)
	{
		for (j = 0; j < 3; j++)
		{
			temp = *(sum + j);
			*(sum + j) = *(sum + j + 1);
			*(sum + j + 1) = temp;
		}
	}
}
int main()
{
	char sum[4];
	int k, i, j;
	printf("请输入字符串i");
	for (i = 0; i < 4; i++)
	{
		scanf("%c", &sum[i]);
	}
	printf("请输入旋转K个数");
	scanf("%d", &k);
	printf("旋转K个字符后的字符串为：");
	Turn(sum, k);
	for (j = 0; j < 4; j++)
	{
		printf("%c", sum[j]);
	}
}
2.int  JUDeql(char* A, char* B)

{
	int  i = 0, j = -1, l = 0, k = 0, p = -1;
	for (; i < 5; i++)
	{
		j = p + 1;
		for (k = 0; k < 5; k++)
		{
			if (*(A + i) == *(B + j))
			{
				++l;
				//printf("666");    
				p = j;
				if (j == 4)
				{
					p = -1;
				}
			}
			j++;
		}
	}
	if (l == 5)
	{
		return 110;
	}
	else
	{
		return 120;
	}
}
int main()
{
	char arr_s1[] = "ABCDE";
	char arr_s2[] = "CDEAB";
	if (JUDeql(arr_s1, arr_s2) == 110)
	{
		printf("equall");
	}
	else
	{
		printf("no");
	}
}
1.void Foundit(char *arr)


{
	char brr[13];
	for (int i = 0; i < 13; i++)
	{
		brr[i] = arr[i];
	}
	for (int i = 0; i < 13; i++)
	{
		int j = 0, t = 0;
		int k = 0;
		for (j = 0; k < 13; j++)
		{
			k = i + j + 1;
			t = i - 1;
			if (arr[i] == arr[k] || arr[i] == arr[t])
			{
				brr[i] = 0;
			}
			if (t > 0)
			{
				t--;
			}
		}
	}
	for (int i = 0; i < 13; i++)
	{
		if (brr[i] != 0)
		{
			printf("%c", brr[i]);
		}
	}
}
int main()
{
	char arr[13] = "112233455677";
	Foundit(arr);

}
//2.喝汽水，1瓶汽水1元，2个空瓶可以换一瓶汽水，     
//给20元，可以多少汽水。     
//编程实现。     
void swapb(int a)
{
	int colo = 1, bottle = 0, num = 0;
	for (; a > 0;)
	{
		a = a - colo;
		bottle++;
		num++;
		if (bottle == 2)
		{
			bottle = 0;
			num++;
		}
	}
	printf("%d", num);
}
int main()
{
	int a = 20;
	swapb(a);
}

