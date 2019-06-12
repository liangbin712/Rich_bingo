#include<iostream>
#include<string>
using namespace std;
int main()
{
  string a;
  getline(cin,a);
  int _size = a.size();
  int sum = _size/2;
  char hashtable[256] = {0};
  cout <<a[1]<<endl;

  for(int t = 0;t < _size;t++)
  {
    hashtable[a[t]]++;
  }
  for(int t = 0; t < _size;t++)
  {
    if(hashtable[a[t]] >= sum)
    {
      if(flag == 1){
      cout << a[t] <<endl;
      }
    }
  }
}
