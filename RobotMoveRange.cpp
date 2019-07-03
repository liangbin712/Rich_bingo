#include<iostream>
#include<vector>
using namespace std;
int Check(int m,int n,int row,int col,int k,int *v);
int Could(int m,int n,int row,int col,int *v,int k)
{
  int count = 0;
  if(Check(m,n,row,col,k,v) == 1)
  {
    v[row*n+col] = 1;
    count = 1+Could(m,n,row-1,col,v,k)+Could(m,n,row,col-1,v,k)+ Could(m,n,row+1,col,v,k)+Could(m,n,row,col+1,v,k);
  }
  return count;
}
int Check(int m,int n,int row,int col,int k,int *v)
{
  if(col < 0 || row < 0 || col > m || row > n || v[row*n+col] == 1)
    return 0;
  int sum1 = 0,sum2 = 0;
  while(row != 0)
  {
    sum1 += row%10;
    row /= 10;
  }
  while(col != 0)
  {
    sum2 += col%10;
    col /= 10;
  }
  if(sum1+sum2 > k)
    return 0;
  else return 1;
}
int Init(int m,int n,int k)
{
  int *v = new int[m*n];
  for(int i = 0;i < m*n;i++)
  {
    v[i] = 0;
  }
  int count = Could(m,n,0,0,v,k);
  delete []v;
  return count;
}
int main()
{
  int m,n,k;
  while(cin>>m>>n>>k)
  {
    cout<<Init(m,n,k)<<endl;
  }
}
