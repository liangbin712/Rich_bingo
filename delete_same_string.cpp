#include<iostream>
#include<string>
using namespace std;
int main()
{
  string a,b;
  cin >> a;
  cin >> b;
  for(unsigned int i = 0;i < a.size();i++)
  {
    for(unsigned int j = 0;j < b.size();j++)
    {
      if(a[i] == b[j])
      {
        string::iterator position;
        position = a.begin()+i;
        a.erase(position); 
      }
    }
  }
  cout<<a<<endl;
  return 0;

}
