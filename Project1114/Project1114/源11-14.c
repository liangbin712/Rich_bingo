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
	printf("请玩家落子！\n");
	while (1)
	{
		printf("请玩家输入坐标(row col):");
		int row, col;
		scanf("%d %d", &row, &col);
		if (row < 0 || row >= Row || col < 0 || col >= Row)
		{
			printf("输入的非法坐标，请重新输入！\n");
			continue;
		}
		if (g_board[row][col] == ' ')
		{
			printf("当前位置已经有其他子，请重新输入");
			continue;
		}
		g_board[row][col] = 'x';
		break;
	}
}
void ComputerMove(char g_board[Row][Col], int row, int col)
{
	printf("请电脑落子\n");
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
	//检查行，列，斜线是否连成三个
	//先检查所以行
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
	//再检查所有列
	for (int col = 0; col < col; ++col)
	{
		if (g_board[0][col] == g_board[1][col]
			&& g_board[0][col] == g_board[2][col]
			&& g_board[0][col] != ' ')
		{
			return g_board[0][col];
		}
	}//检查对角线
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
	//1.先对棋盘进行初始化
	qipan(g_board, Row, Col);
	char winner;
	while (1)
	{//2.先打印出棋盘
		print(g_board, Row, Col);
		//3.玩家落子，判游戏是否结束
		PlayerMove(g_board, Row, Col);
		//玩家的子为x，电脑的子为o
		//winner -> x玩家胜
		//winner -> o电脑胜
		//winner -> ‘ ’胜负未分
		//winner -> q 和棋
		winner = CheckWinner(g_board, Row, Col);
		if (winner == 'x' || winner == 'o')
		{
			break;
		}
		//4.电脑落子，判定游戏是否结束
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
		printf("玩家胜\n");
	}
	else if (winner == 'o')
	{
		printf("电脑胜\n");
	}
	else
	{
		printf("和棋\n");
	}
	system("pause");
	return 0;
}
