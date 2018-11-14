#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> 
#include <stdlib.h>
#include <math.h>
#include <time.h>
#define Row 3
#define Col 3
int g_board[Row][Col];
void qipan(char g_board[Row][Col], int row, int col)
{
	for (int row = 0; row < Row; ++row)
	{
		for (int col = 0; col < col; ++col)
		{
			g_board[row][col] = ' ';
		}
	}
}
void print(char g_board[Row][Col], int row, int col)
{
	for (int row = 0; row < Row; ++row)
	{
		printf("| %c | %c | %c |\n", g_board[row][0], g_board[row][1], g_board[row][2]);
		if (row != Row - 1)
		{
			printf(" ---|---|----\n");
		}
	}
}
void PlayerMove(char g_board[Row][Col], int row, int col)
{
	printf("��������ӣ�\n");
	while (1)
	{
		printf("�������������(row col):");
		int row, col;
		scanf("%d %d", &row, &col);
		if (row < 0 || row >= Row || col < 0 || col >= Row)
		{
			printf("����ķǷ����꣬���������룡\n");
			continue;
		}
		if (g_board[row][col] == ' ')
		{
			printf("��ǰλ���Ѿ��������ӣ�����������");
			continue;
		}
		g_board[row][col] = 'x';
		break;
	}
}
void ComputerMove(char g_board[Row][Col], int row, int col)
{
	printf("���������\n");
	while (1)
	{
		int row = rand() % Row;
		int col = rand() % Col;
		if (g_board[row][col] == 'x' || g_board[row][col] == 'o')
		{
			continue;
		}
		g_board[row][col] = 'o';
		break;
	}
}
char CheckWinner(char g_board[Row][Col], int row, int col)
{
	//����У��У�б���Ƿ���������
	//�ȼ��������
	for (int row = 0; row < Row; ++row)
	{
		if (g_board[row][0] == g_board[row][1]
			&& g_board[row][0] == g_board[row][2]
			&& g_board[row][0] != ' ')
		{
			return g_board[row][0];
		}
	}
	//return ' ';
	//�ټ��������
	for (int col = 0; col < col; ++col)
	{
		if (g_board[0][col] == g_board[1][col]
			&& g_board[0][col] == g_board[2][col]
			&& g_board[0][col] != ' ')
		{
			return g_board[0][col];
		}
	}//���Խ���
	if (g_board[0][0] == g_board[1][1]
		&& g_board[0][0] == g_board[2][2]
		&& g_board[0][0] != ' ')
	{
		return g_board[0][0];
	}
	if (g_board[2][0] == g_board[1][1]
		&& g_board[2][0] == g_board[0][2]
		&& g_board[2][0] != ' ')
	{
		return g_board[2][0];
	}
	else if (check_full(g_board, row, col))
	{
		return 'q';
	}
	return 0;
}
int check_full(char g_board[Row][Col], int row, int col)
{
	for (row = 0; row < Row; row++)
	{
		for (col = 0; col < Col; col++)
		{
			if (g_board[row][col] == ' ')
			{
				return 0;
			}
		}
	}
	return 1;
}
int main()
{
	srand((unsigned int)time(NULL));
	//1.�ȶ����̽��г�ʼ��
	qipan(g_board, Row, Col);
	char winner;
	while (1)
	{//2.�ȴ�ӡ������
		print(g_board, Row, Col);
		//3.������ӣ�����Ϸ�Ƿ����
		PlayerMove(g_board, Row, Col);
		//��ҵ���Ϊx�����Ե���Ϊo
		//winner -> x���ʤ
		//winner -> o����ʤ
		//winner -> �� ��ʤ��δ��
		//winner -> q ����
		winner = CheckWinner(g_board, Row, Col);
		if (winner == 'x' || winner == 'o')
		{
			break;
		}
		//4.�������ӣ��ж���Ϸ�Ƿ����
		print(g_board, Row, Col);
		ComputerMove(g_board, Row, Col);
		winner = CheckWinner(g_board, Row, Col);
		if (winner == 'x' || winner == 'o')
		{
			break;
		}
	}
	if (winner == 'x')
	{
		printf("���ʤ\n");
	}
	else if (winner == 'o')
	{
		printf("����ʤ\n");
	}
	else
	{
		printf("����\n");
	}
	system("pause");
	return 0;
}
