#include<iostream>
#include<string>
using namespace std;
string &Doit(string & ya)
{
  int nums = 0;
  for(size_t i = 0;i < ya.size();i++)
  {
    if(ya[i] == ' ')
      nums++;
  }
  int p1 = ya.size();
  int p2 = p1 + nums*2;
  ya.resize(nums*2+p1+1);
  ya[p2] = '\0';
  //while(p1 >= 0 && p2 > p1)
  while(p1 >= 0)
  {
    if(ya[p1] == ' ')
    {
      ya[p2--] = '0';
      ya[p2--] = '2';
      ya[p2--] = '%';
    }else{
      ya[p2--] = ya[p1];
    }
    p1--;
  }
  return ya;
}
int main()
{
  string ya = "we are would like to party";
  string book;
  book = Doit(ya);
  cout<<book<<endl;
}
