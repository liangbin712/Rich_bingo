#include<iostream>
#include<vector>
#include<math.h>
using namespace std;
vector<int>  v;
void appnum(int n)
{
  for(int i = 2;i < sqrt(n);i++)
  {
    if(n%i == 0)
    {
      v.push_back(i);
      if(n / i != i)
      {
        v.push_back(n/i);
      }
    }
  }
}
int main()
{
  int n;
  while(cin>>n)
  {
    int count = 0,sum = 0;
    for(int i = 2;i<=n;i++)
    {
      sum = 0;
      appnum(i);
      for(unsigned int j = 0;j < v.size();j++)
      {
        sum+=v[j];
      }
      if(i == (sum+1))
      {
        count++;
      }
      v.clear();
    }
    cout<<count<<endl;
  }
}
