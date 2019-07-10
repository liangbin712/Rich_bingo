#include<iostream>
#include<vector>
using namespace std;
bool JudgeRun(int year)
{
  if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
    return true;
  return false;
}
int Getsu(int mon)
{
  int arr[6] = { 0, 2, 3, 5, 7, 11  };
  int a[7] = { 1, 3, 5, 7, 8, 10, 12  }, flag = 0;
  for (int j = 0; j < 7; j++)
  {
    if (mon == a[j])
      flag = 1;
  }
  for (int i = 0; i < 6; i++)
  {
    if (mon == arr[i] && flag == 1)  // 是*1+1
      return 1;
    else if (mon == arr[i] && flag == 0)  //是*1
      return 2;
  }
  if (flag == 1) // 是*2 + 1
    return 3;
  else return 4;//是 *2
}
int getno(int mon)
{
  int arr[6] = { 0, 2, 3, 5, 7, 11  };
  for (int i = 0; i < 6; i++)
  {
    if (mon == arr[i])
      return 0;
  }
  return 1;
}
int main()
{
  int year1, year2, mon1, mon2, day1, day2;
  while (cin >> year1 >> mon1 >> day1
      >> year2 >> mon2 >> day2)
  {
    int money = 0;
    int num = -1, lin, sum = -1, inyear = year2 - year1, haverun = 0, zonday = 0;
    for (int j = mon1; j <= mon2 + (year2 - year1) * 12; j++)
    {
      sum++;
      lin = j;
      if (j > 12)
        lin = j - 12;
      if (Getsu(lin) == 1)
      {
        num = 0;
        money++;
      }
      if (Getsu(lin) == 3)
      {
        money += 2;
        num++;
      }
      if (Getsu(lin) == 4)
        num++;
      if (Getsu(lin) == 2)
        num = 0;
    }
    int tian = 0;
    if (mon1 == mon2 && (getno(mon1)))
    {
      tian = (day2 - day1 + 1) * 2;
    }
    else tian = (day2 - day1) + 1;
    zonday = sum * 30 + tian;
    money = zonday + num * 30;
    for (int i = year1; i <= year2; i++)
    {
      if (JudgeRun(i) == true)
        haverun++;
    }
    if (JudgeRun(year1) == true)
    {
      if (mon1 == mon2)
        money += (inyear + 1 - haverun)*(-2);
      else money += (haverun)*(-1) + (inyear + 1 - haverun)*(-2);
    }
    else{
      if (mon1 == mon2)
        money += (inyear + 1 - haverun-1)*(-2);
      else money += (haverun)*(-1) + (inyear + 1 - haverun)*(-2);
    }
    cout<<money<<endl;
  }
}
