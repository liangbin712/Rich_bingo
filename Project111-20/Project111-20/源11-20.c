#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
// 1.
// // 5λ�˶�Ա�μ���10��̨��ˮ����������������Ԥ��������
// // Aѡ��˵��B�ڶ����ҵ�����
// // Bѡ��˵���ҵڶ���E���ģ�
// // Cѡ��˵���ҵ�һ��D�ڶ���
// // Dѡ��˵��C����ҵ�����
// // Eѡ��˵���ҵ��ģ�A��һ��
// // ����������ÿλѡ�ֶ�˵����һ�룬����ȷ�����������Ρ�
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
// �ձ�ĳ�ط�����һ��ıɱ��������ͨ���Ų�ȷ��ɱ�����ֱ�Ϊ4��
// ���ɷ���һ��������Ϊ4�����ɷ��Ĺ��ʡ�
// A˵�������ҡ�
// B˵����C��
// C˵����D��
// D˵��C�ں�˵
// ��֪3����˵���滰��1����˵���Ǽٻ���
// �����������Щ��Ϣ��дһ��������ȷ������˭�����֡�
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
