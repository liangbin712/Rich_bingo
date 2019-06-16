#include<iostream>
#include<vector>
using namespace std;
int Maxyue(int a,int b)
{
  int temp;
  while(b){
    temp = b; b = a%b; a = temp;
  }
  return (a);
}
int Engry(int s,int init,vector<int> &v)
{
  for(int i = 0;i < s;i++)
  {
    if(v[i] <= init)
      init+=v[i];
    else{

      init+=Maxyue(init,v[i]);
      cout<<init<<endl;
    }
  }
  return init;
}
int main()
{
  int s,init,n;
  while(cin >> s >>init)
  {
    vector<int> v;
    for(int i = 0;i < s;i++)
    {
      cin >> n;
      v.push_back(n);
    }
    cout<<Engry(s,init,v)<<endl;
  }
}
