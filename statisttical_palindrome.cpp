#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
bool Judge(string &a)
{
  int u = a.size();
  for(int i = 0;i < u;i++)
  {
    if(a[i] != a[u-i-1])
    {
      cout<<a[i]<<endl;
      cout<<a[u-1-i]<<endl;
      cout<<"sss"<<endl;
      return false;
    }
  }
  return true;
}
int main()
{
  string a,b,c;
  cin>>a;
  cin>>b;
  unsigned int s = a.size(),l = a.size(),count = 0;
  c = a.substr(0,l);
  for(unsigned int i = 0;i <= s;i++)
  {
    a.insert(i,b);
    cout<<a<<endl;
    if(Judge(a))
    {
      count++;
    }
    a.clear();
    a = c.substr(0.l);
  }
  cout<<count<<endl;
}
