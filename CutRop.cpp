#include<iostream>
#include<algorithm>
using namespace std;
int GetMax(int len)
{
  if(len == 1)
    return 0;
  if(len == 1)
    return 0;
  if(len == 2)
    return 1;
  if(len == 3)
    return 2;
  int Max = 0;
  int product[len+1];
  product[0] = 0;
  product[1] = 1;
  product[2] = 2;
  product[3] = 3;
  for(int i = 4;i <= len;i++)
  {
    for(int j = 1;j <= len/2;j++)
    {
      Max = max(Max,product[j]*product[i-j]);
    }
    product[i] = Max;
  }
   Max = product[len];
  return Max;
}
int main()
{
  int len;
  cin >>len;
  int product = GetMax(len);
  cout<<product<<endl;
}
