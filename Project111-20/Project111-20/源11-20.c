#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
// 1.
// // 5位运动员参加了10米台跳水比赛，有人让他们预测比赛结果
// // A选手说：B第二，我第三；
// // B选手说：我第二，E第四；
// // C选手说：我第一，D第二；
// // D选手说：C最后，我第三；
// // E选手说：我第四，A第一；
// // 比赛结束后，每位选手都说对了一半，请编程确定比赛的名次。
// int main()
// {
// 	for (int a = 1; a < 6; a++)
// 	{
// 		for (int b = 1; b < 6; b++)
// 		{
// 			for (int c = 1; c < 6; c++)
// 			{
// 				for (int d = 1; d < 6; d++)
// 				{
// 					for (int e = 1; e < 6; e++)
// 					{
// 						if ((b == 2) + (a == 3) == 1 && (b == 2) + (e == 4) == 1 && (c == 1) + (d == 2) == 1 &&
// 							(c == 5) + (d == 3) == 1 && (a == 1) + (e == 4) == 1)
// 						{
// 							if ( 120 == a*b*c*d*e)
// 							{
// 								printf("a=%d,b=%d,c=%d,d=%d,e=%d\n", a, b, c, d, e);
// 								break;
// 							}
// 						}
// 					}
// 				}
// 			}
// 		}
// 	}
// 	system("pause");
// }
// 2.
// 日本某地发生了一件谋杀案，警察通过排查确定杀人凶手必为4个
// 嫌疑犯的一个。以下为4个嫌疑犯的供词。
// A说：不是我。
// B说：是C。
// C说：是D。
// D说：C在胡说
// 已知3个人说了真话，1个人说的是假话。
// 现在请根据这些信息，写一个程序来确定到底谁是凶手。
// int main()
// {
// 	int murderer = 1;
// 	int clean = 0;
// 	// a =0,c =1,d=1,d = 0,
// 	for (int a = 0; a < 2;a++)
// 	{
// 		for (int b = 0; b < 2;b++)
// 		{
// 			for (int c = 0; c < 2; c++)
// 			{
// 				for (int d = 0; d < 2; d++)
// 				{
// 					if ((a == 0)+(c == 1)+(d == 1)+(d == 0)+(b != 3) == 4)
// 					{
// 						if ((a + b + c + d) == 3)
// 						{
// 							printf("a=%d,b=%d,c=%d,d=%d\n", a, b, c, d);
// 						}
// 					}
// 				}
// 			}
// 		}
// 	}
// 	system("pause");
// }
int J_chen(int n)
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
int JF_chen(int n, int m)
{
	int sum = 1;
	for (; n > 0, m > 0;)
	{
		sum = sum * n;
		m = m - 1;
		n = n - 1;
	}
	return sum;
}
int C_chen(int n, int m)
{
	int sum;
	return sum = JF_chen(n,m) / J_chen(m);
}
int main()
{
	printf("1\n");
	printf("1  ");
	for (int i = 1; i < 5; i++)
	{
		printf("1  ");
		for (int j = 1; j < i + 1; j++)
		{
			if (i > 1)
			{
				printf("%d  ", C_chen(i, j));
			}
		}
		printf("\n");
	}
	system("pause");
}
