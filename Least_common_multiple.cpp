#include<iostream>
#include<vector>
#include<string>
using namespace std;
int main()
{
  int a,x = 0,lflag = 1,zflag = 1;
  cin>>a;
  vector<string>v(a);
  while(x < a)
  {
    cin>>v[x];
    x++;
  }
  for(x = 1;x < a;x++)
  {
    for(unsigned int j = 0;j < ((v[x].size() < v[x-1].size())?v[x].size():v[x-1].size());j++)
    {
      if(v[x-1][j] > v[x][j])
      {
        zflag = 0;
      }
    }
    if(v[x-1].size() > v[x].size())
    {
      lflag = 0;
    }
  }
  if(zflag == 0 && lflag == 0)
  {
    cout <<"none"<<endl;
  }
  if(zflag != 0 && lflag == 0)
  {
    cout <<"lexicographically"<<endl;
  }
  if(zflag == 0 && lflag != 0)
  {
    cout <<"lengths"<<endl;
  }
  if(zflag != 0 && lflag != 0)
  {
    cout <<"both"<<endl;
  }
}
