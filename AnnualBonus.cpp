#include<iostream>
#include<vector>
using namespace std;
int getMost(vector<vector<int> > board) {
  int Max = 0;
  for(size_t i = 0;i < board.size();i++ )
  {
    for(size_t j = 0;j < board[0].size();j++)
    {
      if(i == 0 && j == 0)
      {}
      else if(i == 0)
        board[i][j] += board[i][j-1];
      else if(j == 0)
        board[i][j] += board[i-1][j];
      else{
        int case1 = board[i][j]+board[i-1][j];
        int case2 = board[i][j]+board[i][j-1];
        Max = max(case1,case2);
        board[i][j] = Max;
      }
    }
  }
  for(size_t i = 0;i < board[0].size();i++ )
  {
    for(size_t j = 0;j < board.size();j++)
    {
      cout<<board[i][j]<<" ";
    }
    cout<<endl;
  }
  return Max;
}
int main()
{
  vector<vector<int> >v;
  vector<int>mid(6,0);
  for(int i = 0;i < 6;i++)
  {
    for(int j = 0;j < 6;j++)
      cin>>mid[j];
    v.push_back(mid);
  }
  int num = getMost(v);
  cout <<num<<endl;
}
