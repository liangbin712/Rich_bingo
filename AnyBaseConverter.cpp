#include<iostream>
#include<string>
#include<stack>
using namespace std;
stack<char>a;
int main()
{
  int  m,n,i = 0;
  char sum;
  cin >> m;
  cin >> n;
  sum = m;
  if(m == 0)
  {
    return 0;
  } 
  if(m == n)
  {
    cout <<"10";
    cout<<endl;
    return 0;
  }
  if(m < n)
  {
    char u = m - 10;
    sum = u + 'A';
    a.push(sum);
    char v;
    while(!a.empty())
    {
      v = a.top();
      a.pop();
      cout << v;
    }
    cout<<endl;
    return 0;
  }
  while(sum != 1)
  {
    if(n <= 10)
    {
      if(sum != 1)
      {
        m = sum;
        sum = m/n;
        i = m%n;
        a.push(i);
      }
    }
    else{
      if(sum != 1)
      {
        m = sum;
        sum = m/n;
        i = m%n;
        if(i >= 10)
        {
          char u = i -10;
          i = 'A'+ u;
        }
        a.push(i);
      }
    }
  }
  a.push(sum);
  int v;
  while(!a.empty())
  {
    v = a.top();
    a.pop();
    cout << v;
  }
  cout<<endl;
}
