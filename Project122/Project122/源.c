#include<stdio.h>
#include<stdlib.h>
int main()
{
	int i, j, k, l, num, ge = 0;
	printf("1,2,3,4����ɻ�����ͬ�������ظ����ֵ���λ����");
	for (i = 1; i < 5; i++)
	{
		for (j = 1; j < 5; j++)
		{
			for (k = 1; k < 5; k++)
			{
				for (l = 1; l < 5; l++)
				{
					if (j != i&&j != k&&j != l&&i != k&&i != l&&k != l)
					{
						num = i * 1000 + j * 100 + k * 10 + l;
						printf("%d\t", num);
						ge++;
					}
				}
			}
		}
	}
	printf("������������%d��", ge);
}
2.��ҵ���ŵĽ������������ɡ�����(I)���ڻ����10��Ԫʱ���������10%���������10��Ԫ������20��Ԫʱ������10��Ԫ�Ĳ��ְ�10%��ɣ�����10��Ԫ�Ĳ��֣��ɿ����7.5%��20��40��֮��ʱ������20��Ԫ�Ĳ��֣������5%��40��60��֮��ʱ����40��Ԫ�Ĳ��֣������3%��60��100��֮��ʱ������60��Ԫ�Ĳ��֣������1.5%������100��Ԫʱ������100��Ԫ�Ĳ��ְ�1%��ɣ��Ӽ������뵱������I����Ӧ���Ž���������
main()
{
	long int i;
	int bonus1, bonus2, bonus4, bonus6, bonus10, bonus;
	scanf("%ld", &i);
	bonus1 = 100000 * 0.1; bonus2 = bonus1 + 100000 * 0.75;
	bonus4 = bonus2 + 200000 * 0.5;
	bonus6 = bonus4 + 200000 * 0.3;
	bonus10 = bonus6 + 400000 * 0.15;
	if (i <= 100000)
		bonus = i*0.1;
	else if (i <= 200000)
		bonus = bonus1 + (i - 100000)*0.075;
	else if (i <= 400000)
		bonus = bonus2 + (i - 200000)*0.05;
	else if (i <= 600000)
		bonus = bonus4 + (i - 400000)*0.03;
	else if (i <= 1000000)
		bonus = bonus6 + (i - 600000)*0.015;
	else
		bonus = bonus10 + (i - 1000000)*0.01;
	printf("bonus=%d", bonus);
}
