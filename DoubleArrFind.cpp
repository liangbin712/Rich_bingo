#include<iostream>
#include<vector>
using namespace std;
bool ArrayFind(vector<vector<int> >v,int num)
{
  size_t row = v[0].size();
  size_t col = v.size();
  if(row < 1 && col < 1)
    return false;
  for(size_t i = 0,j = col-1;i < row&&j < col;)
  {
     if(v[i][j] > num)
     {
       i++;
     }else if(v[i][j] < num)
     {
       j++;
     }else{
       return true;
     }
  }
  return false;
}
int main()
{
  int m,n,num,fin;
  vector<vector<int> >v;
  vector<int>mid;
  cin >> m>>n>>fin;
  for(int i = 0;i < m;i++)
  {
    for(int j = 0;j < n;j++)
    {
      cin >> num;
      mid.push_back(num);
    }
    v.push_back(mid);
    mid.clear();
  }
  bool T = ArrayFind(v,fin);
  cout<<T<<endl;
}
