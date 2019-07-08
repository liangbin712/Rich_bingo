#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int getFirstUnFormedNum(vector<int> arr, int len) {
  sort(&arr[0], &arr[len - 1]);
  int Min = arr[0], Max = 0, sum = 0;
  vector<int>mid;
  for (int i = 0; i < len; i++)
  {
    Max += arr[i];
    mid.push_back(arr[i]);
  }
  for (int j = 0; j < len-1; j++)
  {
    for (int x = j; x < len; x++)
    {
      sum = arr[j]+arr[x];
      mid.push_back(sum);
    }
    sum = 0;
  }
  int end = 0,flag = 0;
  for(int i = Min; i <= Max; i++)
  {
    for (size_t j = 0; j < mid.size(); j++)
    {
      if (i == mid[j])
      {
        flag = 1;
      }
    }
    if(flag == 0)
    {
      end = i;
      break;
    }
    flag =0 ;
  }
  if (len == 1)
    end = arr[0] + 1;
  return end;
}
int main()
{
  vector<int> arr;
  arr.push_back(3);
  arr.push_back(2);
  arr.push_back(4);
  cout<<getFirstUnFormedNum(arr, 3)<<endl;
}
