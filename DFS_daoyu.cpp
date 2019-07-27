#include<iostream>
#include<vector>
using namespace std;
void DFS(vector<vector<int> >&mid, int row, int col, int i, int j, vector<vector<char> >&grid)
{
  int fang[4][2] = { { 0, 1  }, { 1, 0  }, { 0, -1  }, { -1, 0  }  };
  mid[i][j] = 1;
  for (int k = 0; k < 4; ++k)
  {
    int y = j + fang[k][1];
    int x = i + fang[k][0];
    if (x >= row || x < 0 || y >= col || y < 0)
      continue;
    if (grid[x][y] == '1' && mid[x][y] == 0)
      DFS(mid, row, col, x, y, grid);
  }
}
int numIslands(vector<vector<char>>& grid) {
  if (grid.empty()) return 0;
  int row = grid.size(), num = 0;
  int col = grid[0].size();
  vector<vector<int> >mid(row, vector<int>(col, 0));
  for (int i = 0; i < row; i++)
  {
    for (int j = 0; j < col; j++)
    {
      if (mid[i][j] == 0 && grid[i][j] == '1')
      {
        num++;
        DFS(mid, row, col, i, j, grid);
      }
    }
  }
  return num;
}
int main()
{
  vector<vector<char> > grid;
  vector<char>mid;
  char pp;
  for (int i = 0; i < 4; i++)
  {
    for (int j = 0; j < 5; j++)
    {
      cin>>pp;
      mid.push_back(pp);
    }
    grid.push_back(mid);
    mid.clear();
  }
  cout << numIslands(grid) << endl;
}
