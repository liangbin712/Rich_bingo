#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<time.h>
#define ROWS 3
#define COLS 3
void menu();
void init_board(char arr[][COLS], int x, int y);//��ʼ������
void print_board(char arr[][COLS], int x, int y);//��ӡ����
void player_move(char arr[][COLS]);//�������
int check_full(char arr[][COLS], int x, int y);//�ж������Ƿ�����
void computer_move(char arr[][COLS]);//��������
char check_win(char arr[][COLS], int x, int y);//�ж�˭Ӯ
#include"three_chess.h"
void menu()
{
	printf("****************\n");
	printf("****1.play******\n");
	printf("****0.exit******\n");
	printf("****************\n");
}

void init_board(char arr[][COLS], int x, int y)//������ʱһ��Ҫ��������±�Ҳ������
{
	int i = 0;
	int j = 0;
	for (i = 0; i < x; i++)
	{
		for (j = 0; j < y; j++)
		{
			arr[i][j] = ' ';//����ά�����ʼ��Ϊ�ո�
		}
	}
}

void print_board(char arr[][COLS], int x, int y)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < x; i++)
	{
		printf("%c |%c |%c\n", arr[i][0], arr[i][1], arr[i][2]);

		if (i < 2)  //һ����ӡ�������̣����ڴ�ӡ������ʱ����ӡ�±ߵĺ���
		{
			printf("--|--|--\n");
		}
	}
}


void player_move(char arr[][COLS])
{
	int x = 0;
	int y = 0;
	while (1)
	{
		printf("��������Ҫ�µ�����>");
		scanf("%d %d", &x, &y);
		x--;//����Ԫ�ص��±��Ǵ�0��ʼ��������Ҫ��һ
		y--;

		if (arr[x][y] == ' ')//�������±��µ�Ԫ��Ϊ�ո���p�������Ԫ��
		{
			arr[x][y] = 'p';
			break;//����ѭ��
		}
		else
		{
			printf("��������±��ѱ�ռ������������\n>");
			continue;//��������ѭ��
		}

	}
}


int check_full(char arr[][COLS], int x, int y)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < x; i++)
	{
		for (j = 0; j < y; j++)
		{
			if (arr[i][j] == ' ')//�ж���������û�пո��������һ�οո񣬾��Ѿ�����֤������û��
			{
				return 0;
			}
		}
	}
	return 1;//����������ִ�е����˵�������Ѿ����ˣ��򷵻�0
}

void computer_move(char arr[][COLS])
{
	srand((unsigned int)time(NULL));//Ϊ��ÿ�β�����ͬ�������
	while (1)
	{
		int x = rand() % 3;//����һ��С��3����
		int y = rand() % 3;
		if (check_full(arr, ROWS, COLS) == 0)//�ж������Ƿ��Ѿ�����
		{
			if (arr[x][y] == ' ')//�ж����Ԫ���Ƿ�Ϊ��
			{
				arr[x][y] = 'c';//���Ϊ�գ���c�����Ԫ��
				break;//�������ѭ��
			}
			else
			{
				continue;//����ִ����һ�ε�ѭ��
			}
		}

	}
}



char check_win(char arr[][COLS], int x, int y)
{
	int i = 0;
	if (check_full(arr, ROWS, COLS) == 1)//����������ˣ��򷵻�q
	{
		return 'q';
	}
	for (i = 0; i < x; i++)
	{
		if ((arr[i][0] == arr[i][1]) && arr[i][1] == arr[i][2])
		{
			return arr[i][0];//��������Ԫ���е���һ��Ԫ��
		}
	}

	for (i = 0; i < y; i++)
	{
		if ((arr[0][i] == arr[1][i]) && arr[1][i] == arr[2][i])
		{
			return arr[1][i];
		}
	}

	if ((arr[0][0] == arr[1][1]) && arr[1][1] == arr[2][2])
	{
		return arr[0][0];
	}

	if ((arr[0][2] == arr[1][1]) && arr[1][1] == arr[2][0])
	{
		return arr[1][1];
	}

	return ' ';//���û���жϳ�˭Ӯ�������̻�û���������������Ϸ
}



#include"three_chess.h"

void game()//��Ϸ��ʼ
{
	char ret = 0;
	char arr[ROWS][COLS];
	init_board(arr, ROWS, COLS);//��ʼ������
	print_board(arr, ROWS, COLS);//��ӡ����
	do
	{
		player_move(arr);//�������
		print_board(arr, ROWS, COLS);//��ӡ������
		if (check_win(arr, ROWS, COLS) != ' ')//������̲�Ϊ�յĻ���������ѭ��
		{
			break;
		}
		printf("�����£�\n");
		computer_move(arr);//�����������
		print_board(arr, ROWS, COLS);//�ѵ����¹�������̴�ӡ����
		ret = check_win(arr, ROWS, COLS);//���ж���Ӯ��ķ���ֵ��������
	} while (ret == ' ');//�������û������ͬʱҲû���жϳ���Ӯ�Ļ�������ִ��ѭ������������ѭ��

	if (check_win(arr, ROWS, COLS) == 'p')//����ж���Ӯ�ķ���ֵΪ����µ��ַ�������жϳ����Ӯ
	{
		printf("���Ӯ\n");
	}
	else if (check_win(arr, ROWS, COLS) == 'c')//����ж���Ӯ�ķ���ֵΪc,������жϵ���Ӯ

	{
		printf("����Ӯ\n");

	}
	else
	{
		if (check_win(arr, ROWS, COLS) == 'q')//������������ˣ������Ƿ���ֵΪq��ʱ��������ж�Ϊƽ��
			printf("ƽ��\n");
	}

}




int main()
{
	int choose = 0;
	do
	{
		menu();
		printf("��ѡ��>");
		scanf("%d", &choose);
		switch (choose)
		{
		case 0:
			exit(1);
		case 1:
			game();
		}

	} while (choose);
}

