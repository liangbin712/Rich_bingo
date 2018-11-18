#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#define Row 10
#define Col 10
int win = 1;
void P_Boom();
char RoundMove(int row, int col);
char g_board[Row + 2][Col + 2];
int d_map[Row + 2][Col + 2];
void Print()
{
	printf("   ");
	for (int i = 1; i < Col + 1; i++)
	{
		printf("%d ",i);
	}
	printf("\n");
	printf("   _____________________\n");
	for (int row = 1; row < Row + 1; row++)
	{
		printf("%02d|",row);
		for (int col = 1; col < Col + 1; col++)
		{
			printf("%c ",g_board[row][col]);
		}
		printf("\n");
	}
} 
void PrintMine()
{
	printf("   ");
	for (int i = 1; i < Col + 1; i++)
	{
		printf("%d ", i);
	}
	printf("\n");
	printf("   _____________________\n");
	for (int row = 1; row < Row + 1; row++)
	{
		printf("%02d|", row);
		for (int col = 1; col < Col + 1; col++)
		{
			printf("%d ", d_map[row][col]);
		}
		printf("\n");
	}
}
void P_YT()
{
	P_Boom();
	for (int row = 1; row < Row + 1; ++row)
	{
		for (int col = 1; col < Col + 1; ++col)
		{
			g_board[row][col] = '*';
		}
	}
}
void F_blank()
{
	int row;
	int col;
	while (1)
	{
		scanf("%d %d", &row, &col);
		if (row < 1 || row > Row || col < 1 || col > Col)
		{
			printf("输入坐标错误，请重新输入\n");
			continue;
		}
		if (g_board[row][col] != '*')
		{
			printf("当前这个位置已翻开，请重新输入\n");
			continue;
		}
		if (d_map[row][col] == 1)
		{
			win = 0;
			break;
		}
		RoundMove(row, col);
		g_board[row][col - 1] = RoundMove(row, col - 1);
		if (g_board[row][col - 1] == '0')
		{
			int rows = row;
			int cols = col;
			g_board[rows][cols - 1] = RoundMove(rows, cols - 1);
			g_board[rows - 1][cols - 1] = RoundMove(rows - 1, cols - 1);
			g_board[rows - 1][cols] = RoundMove(rows - 1, cols);
			g_board[rows - 1][cols + 1] = RoundMove(rows - 1, cols + 1);
			g_board[rows][cols + 1] = RoundMove(rows, cols + 1);
			g_board[rows + 1][cols] = RoundMove(rows + 1, cols);
			g_board[rows + 1][cols - 1] = RoundMove(rows + 1, cols - 1);
			g_board[rows + 1][cols + 1] = RoundMove(rows + 1, cols + 1);
		}
		g_board[row - 1][col - 1] = RoundMove(row - 1, col - 1);
		if (g_board[row - 1][col - 1] == '0')
		{
			int rows = row;
			int cols = col;
			g_board[rows][cols - 1] = RoundMove(rows, cols - 1);
			g_board[rows - 1][cols - 1] = RoundMove(rows - 1, cols - 1);
			g_board[rows - 1][cols] = RoundMove(rows - 1, cols);
			g_board[rows - 1][cols + 1] = RoundMove(rows - 1, cols + 1);
			g_board[rows][cols + 1] = RoundMove(rows, cols + 1);
			g_board[rows + 1][cols] = RoundMove(rows + 1, cols);
			g_board[rows + 1][cols - 1] = RoundMove(rows + 1, cols - 1);
			g_board[rows + 1][cols + 1] = RoundMove(rows + 1, cols + 1);
		}
		g_board[row - 1][col] = RoundMove(row - 1, col);
		if (g_board[row - 1][col] == '0')
		{
			int rows = row;
			int cols = col;
			g_board[rows][cols - 1] = RoundMove(rows, cols - 1);
			g_board[rows - 1][cols - 1] = RoundMove(rows - 1, cols - 1);
			g_board[rows - 1][cols] = RoundMove(rows - 1, cols);
			g_board[rows - 1][cols + 1] = RoundMove(rows - 1, cols + 1);
			g_board[rows][cols + 1] = RoundMove(rows, cols + 1);
			g_board[rows + 1][cols] = RoundMove(rows + 1, cols);
			g_board[rows + 1][cols - 1] = RoundMove(rows + 1, cols - 1);
			g_board[rows + 1][cols + 1] = RoundMove(rows + 1, cols + 1);
		}
		g_board[row - 1][col + 1] = RoundMove(row - 1, col + 1);
		if (g_board[row - 1][col + 1] == '0')
		{
			int rows = row;
			int cols = col;
			g_board[rows][cols - 1] = RoundMove(rows, cols - 1);
			g_board[rows - 1][cols - 1] = RoundMove(rows - 1, cols - 1);
			g_board[rows - 1][cols] = RoundMove(rows - 1, cols);
			g_board[rows - 1][cols + 1] = RoundMove(rows - 1, cols + 1);
			g_board[rows][cols + 1] = RoundMove(rows, cols + 1);
			g_board[rows + 1][cols] = RoundMove(rows + 1, cols);
			g_board[rows + 1][cols - 1] = RoundMove(rows + 1, cols - 1);
			g_board[rows + 1][cols + 1] = RoundMove(rows + 1, cols + 1);
		}
		g_board[row][col + 1] = RoundMove(row, col + 1);
		if (g_board[row][col + 1] == '0')
		{
			int rows = row;
			int cols = col;
			g_board[rows][cols - 1] = RoundMove(rows, cols - 1);
			g_board[rows - 1][cols - 1] = RoundMove(rows - 1, cols - 1);
			g_board[rows - 1][cols] = RoundMove(rows - 1, cols);
			g_board[rows - 1][cols + 1] = RoundMove(rows - 1, cols + 1);
			g_board[rows][cols + 1] = RoundMove(rows, cols + 1);
			g_board[rows + 1][cols] = RoundMove(rows + 1, cols);
			g_board[rows + 1][cols - 1] = RoundMove(rows + 1, cols - 1);
			g_board[rows + 1][cols + 1] = RoundMove(rows + 1, cols + 1);
		}
		g_board[row + 1][col] = RoundMove(row + 1, col);
		if (g_board[row + 1][col] == '0')
		{
			int rows = row;
			int cols = col;
			g_board[rows][cols - 1] = RoundMove(rows, cols - 1);
			g_board[rows - 1][cols - 1] = RoundMove(rows - 1, cols - 1);
			g_board[rows - 1][cols] = RoundMove(rows - 1, cols);
			g_board[rows - 1][cols + 1] = RoundMove(rows - 1, cols + 1);
			g_board[rows][cols + 1] = RoundMove(rows, cols + 1);
			g_board[rows + 1][cols] = RoundMove(rows + 1, cols);
			g_board[rows + 1][cols - 1] = RoundMove(rows + 1, cols - 1);
			g_board[rows + 1][cols + 1] = RoundMove(rows + 1, cols + 1);
		}
		g_board[row + 1][col - 1] = RoundMove(row + 1, col - 1);
		if (g_board[row + 1][col - 1] == '0')
		{
			int rows = row;
			int cols = col;
			g_board[rows][cols - 1] = RoundMove(rows, cols - 1);
			g_board[rows - 1][cols - 1] = RoundMove(rows - 1, cols - 1);
			g_board[rows - 1][cols] = RoundMove(rows - 1, cols);
			g_board[rows - 1][cols + 1] = RoundMove(rows - 1, cols + 1);
			g_board[rows][cols + 1] = RoundMove(rows, cols + 1);
			g_board[rows + 1][cols] = RoundMove(rows + 1, cols);
			g_board[rows + 1][cols - 1] = RoundMove(rows + 1, cols - 1);
			g_board[rows + 1][cols + 1] = RoundMove(rows + 1, cols + 1);
		}
		g_board[row + 1][col + 1] = RoundMove(row + 1, col + 1);
		if (g_board[row + 1][col + 1] == '0')
		{
			int rows = row;
			int cols = col;
			g_board[rows][cols - 1] = RoundMove(rows, cols - 1);
			g_board[rows - 1][cols - 1] = RoundMove(rows - 1, cols - 1);
			g_board[rows - 1][cols] = RoundMove(rows - 1, cols);
			g_board[rows - 1][cols + 1] = RoundMove(rows - 1, cols + 1);
			g_board[rows][cols + 1] = RoundMove(rows, cols + 1);
			g_board[rows + 1][cols] = RoundMove(rows + 1, cols);
			g_board[rows + 1][cols - 1] = RoundMove(rows + 1, cols - 1);
			g_board[rows + 1][cols + 1] = RoundMove(rows + 1, cols + 1);
		}
		break;
	}
}
void P_Boom()
{
	int row, col;
	int i = 0;
	while (i < 10)
	{
		row = rand() % 10 + 1;
		col = rand() % 10 + 1;
		if (d_map[row][col] == 1)
		{
			continue;
		}
		d_map[row][col] = 1;
		i++;
	}
}
/*void Round()
{
	int row, col;
	g_board[row][col - 1] = RoundMove(row, col - 1);
	if (g_board[row][col - 1] == '0')
	{
		int rows = row;
		int cols = col;
		g_board[rows][cols - 1] = RoundMove(rows, cols - 1);
		g_board[rows - 1][cols - 1] = RoundMove(rows - 1, cols - 1);
		g_board[rows - 1][cols] = RoundMove(rows - 1, cols);
		g_board[rows - 1][cols + 1] = RoundMove(rows - 1, cols + 1);
		g_board[rows][cols + 1] = RoundMove(rows, cols + 1);
		g_board[rows + 1][cols] = RoundMove(rows + 1, cols);
		g_board[rows + 1][cols - 1] = RoundMove(rows + 1, cols - 1);
		g_board[rows + 1][cols + 1] = RoundMove(rows + 1, cols + 1);
	}
	g_board[row - 1][col - 1] = RoundMove(row - 1, col - 1);
	if (g_board[row - 1][col - 1] == '0')
	{
		int rows = row;
		int cols = col;
		g_board[rows][cols - 1] = RoundMove(rows, cols - 1);
		g_board[rows - 1][cols - 1] = RoundMove(rows - 1, cols - 1);
		g_board[rows - 1][cols] = RoundMove(rows - 1, cols);
		g_board[rows - 1][cols + 1] = RoundMove(rows - 1, cols + 1);
		g_board[rows][cols + 1] = RoundMove(rows, cols + 1);
		g_board[rows + 1][cols] = RoundMove(rows + 1, cols);
		g_board[rows + 1][cols - 1] = RoundMove(rows + 1, cols - 1);
		g_board[rows + 1][cols + 1] = RoundMove(rows + 1, cols + 1);
	}
	g_board[row - 1][col] = RoundMove(row - 1, col);
	if (g_board[row - 1][col] == '0')
	{
		int rows = row;
		int cols = col;
		g_board[rows][cols - 1] = RoundMove(rows, cols - 1);
		g_board[rows - 1][cols - 1] = RoundMove(rows - 1, cols - 1);
		g_board[rows - 1][cols] = RoundMove(rows - 1, cols);
		g_board[rows - 1][cols + 1] = RoundMove(rows - 1, cols + 1);
		g_board[rows][cols + 1] = RoundMove(rows, cols + 1);
		g_board[rows + 1][cols] = RoundMove(rows + 1, cols);
		g_board[rows + 1][cols - 1] = RoundMove(rows + 1, cols - 1);
		g_board[rows + 1][cols + 1] = RoundMove(rows + 1, cols + 1);
	}
	g_board[row - 1][col + 1] = RoundMove(row - 1, col + 1);
	if (g_board[row - 1][col + 1] == '0')
	{
		int rows = row;
		int cols = col;
		g_board[rows][cols - 1] = RoundMove(rows, cols - 1);
		g_board[rows - 1][cols - 1] = RoundMove(rows - 1, cols - 1);
		g_board[rows - 1][cols] = RoundMove(rows - 1, cols);
		g_board[rows - 1][cols + 1] = RoundMove(rows - 1, cols + 1);
		g_board[rows][cols + 1] = RoundMove(rows, cols + 1);
		g_board[rows + 1][cols] = RoundMove(rows + 1, cols);
		g_board[rows + 1][cols - 1] = RoundMove(rows + 1, cols - 1);
		g_board[rows + 1][cols + 1] = RoundMove(rows + 1, cols + 1);
	}
	g_board[row][col + 1] = RoundMove(row, col + 1);
	if (g_board[row][col + 1] == '0')
	{
		int rows = row;
		int cols = col;
		g_board[rows][cols - 1] = RoundMove(rows, cols - 1);
		g_board[rows - 1][cols - 1] = RoundMove(rows - 1, cols - 1);
		g_board[rows - 1][cols] = RoundMove(rows - 1, cols);
		g_board[rows - 1][cols + 1] = RoundMove(rows - 1, cols + 1);
		g_board[rows][cols + 1] = RoundMove(rows, cols + 1);
		g_board[rows + 1][cols] = RoundMove(rows + 1, cols);
		g_board[rows + 1][cols - 1] = RoundMove(rows + 1, cols - 1);
		g_board[rows + 1][cols + 1] = RoundMove(rows + 1, cols + 1);
	}
	g_board[row + 1][col] = RoundMove(row + 1, col);
	if (g_board[row + 1][col] == '0')
	{
		int rows = row;
		int cols = col;
		g_board[rows][cols - 1] = RoundMove(rows, cols - 1);
		g_board[rows - 1][cols - 1] = RoundMove(rows - 1, cols - 1);
		g_board[rows - 1][cols] = RoundMove(rows - 1, cols);
		g_board[rows - 1][cols + 1] = RoundMove(rows - 1, cols + 1);
		g_board[rows][cols + 1] = RoundMove(rows, cols + 1);
		g_board[rows + 1][cols] = RoundMove(rows + 1, cols);
		g_board[rows + 1][cols - 1] = RoundMove(rows + 1, cols - 1);
		g_board[rows + 1][cols + 1] = RoundMove(rows + 1, cols + 1);
	}
	g_board[row + 1][col - 1] = RoundMove(row + 1, col - 1);
	if (g_board[row + 1][col - 1] == '0')
	{
		int rows = row;
		int cols = col;
		g_board[rows][cols - 1] = RoundMove(rows, cols - 1);
		g_board[rows - 1][cols - 1] = RoundMove(rows - 1, cols - 1);
		g_board[rows - 1][cols] = RoundMove(rows - 1, cols);
		g_board[rows - 1][cols + 1] = RoundMove(rows - 1, cols + 1);
		g_board[rows][cols + 1] = RoundMove(rows, cols + 1);
		g_board[rows + 1][cols] = RoundMove(rows + 1, cols);
		g_board[rows + 1][cols - 1] = RoundMove(rows + 1, cols - 1);
		g_board[rows + 1][cols + 1] = RoundMove(rows + 1, cols + 1);
	}
	g_board[row + 1][col + 1] = RoundMove(row + 1, col + 1);
	if (g_board[row + 1][col + 1] == '0')
	{
		int rows = row;
		int cols = col;
		g_board[rows][cols - 1] = RoundMove(rows, cols - 1);
		g_board[rows - 1][cols - 1] = RoundMove(rows - 1, cols - 1);
		g_board[rows - 1][cols] = RoundMove(rows - 1, cols);
		g_board[rows - 1][cols + 1] = RoundMove(rows - 1, cols + 1);
		g_board[rows][cols + 1] = RoundMove(rows, cols + 1);
		g_board[rows + 1][cols] = RoundMove(rows + 1, cols);
		g_board[rows + 1][cols - 1] = RoundMove(rows + 1, cols - 1);
		g_board[rows + 1][cols + 1] = RoundMove(rows + 1, cols + 1);
	}
}*/
char RoundMove(int row,int col)
{

	int leinum = (d_map[row][col - 1] - 0) + (d_map[row - 1][col - 1] - 0) + (d_map[row - 1][col] - 0) +
			(d_map[row - 1][col + 1] - 0) + (d_map[row][col + 1] - 0) + (d_map[row + 1][col] - 0) +
			(d_map[row + 1][col - 1] - 0) +(d_map[row + 1][col + 1] - 0);
	if (leinum > 0)
	{
		g_board[row][col] = leinum + '0';
		return leinum + '0';
	}
	if (leinum == 0)
	{
		g_board[row][col] = '0';
		return '0';
	}
}
int Fullblank()
{
	int num = 0;
	for (int row = 0; row < Row; row++)
	{
		for (int col = 0; col < Col; col++)
		{
			if (g_board[row][col] == '*')
			{
				num++;
			}
		}
	}
	if (num == 10)
	{
		return 1;
	}
	return 0;
}
int main()
{
	srand((unsigned int)time(NULL));
	int a;
	//1.游戏开始选项
	printf("======================================================\n");
	printf("============名副其实绕雷游戏，欢迎你的到来！==========\n");
	printf("======================================================\n");
	printf("============1.选择游戏开始。 0.选择关闭游戏。=========\n");
	printf("======================================================\n");
	scanf("%d",&a);
	if (a != 1)
	{
		return 0;
	}
	P_YT();
	Print();
	while (1)
	{
		//2.打印雷盘   
		//P_YT();  //雷盘初始化
		//print();
		//P_Boom( Row, Col);
		//3.玩家翻开格子
		F_blank();
		//4.打印move盘，显示周围雷数
		//5.判断是否踩雷, 若踩到雷，跳出循环
		Print();
		if (win == 1 && Fullblank() == 1)
		{ 
			printf("恭喜你，赢啦！\n");
			Print();
			break;
		}
		if (win == 0 && Fullblank() == 0)
		{
			printf("恭喜你，踩到雷，输啦！\n");
			Print();
			break;
		}
		//6.若没有踩到雷，判断格子是否已经满了，若满了，也得跳出循环
	}
	printf("游戏结束!");

	system("pause");
	return 0;
}