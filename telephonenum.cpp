#include<iostream>
#include<vector>
#include<string>
#include<set>
using namespace std;
vector<string> v;
set<string>chong;
void AllRight()
{
  string mid;
  for (size_t i = 0; i < v.size(); i++)
  {
    v[i].push_back(' ');
    for (size_t j = 0; j <= v[i].size(); j++)
    {
      if (v[i][j] == '-')
        continue;
      if (v[i][j] <= '9' && v[i][j] >= '0')
        mid += v[i][j];
      else if (v[i][j] <= 'Z' && v[i][j] >= 'A')
      {
        if (v[i][j] == 'A' || v[i][j] == 'B' || v[i][j] == 'C')
          mid += '2';
        else if (v[i][j] == 'D' || v[i][j] == 'E' || v[i][j] == 'F')
          mid += '3';
        else if (v[i][j] == 'G' || v[i][j] == 'H' || v[i][j] == 'I')
          mid += '4';
        else if (v[i][j] == 'J' || v[i][j] == 'K' || v[i][j] == 'L')
          mid += '5';
        else if (v[i][j] == 'M' || v[i][j] == 'N' || v[i][j] == 'O')
          mid += '6';
        else if (v[i][j] == 'P' || v[i][j] == 'Q' || v[i][j] == 'R' || v[i][j] == 'S')
          mid += '7';
        else if (v[i][j] == 'T' || v[i][j] == 'U' || v[i][j] == 'V')
          mid += '8';
        else if (v[i][j] == 'X' || v[i][j] == 'Y' || v[i][j] == 'Z' || v[i][j] == 'W')
          mid += '9';
      }
    }
    mid.insert(3,"-");
    chong.insert(mid);
    mid.clear();
  }
  for (auto e : chong)
  {
    cout << e<< endl;
  }
}
int main()
{
  int num;
  while (cin >> num)
  {
    string str;
    while (num > 0)
    {
      cin >> str;
      v.push_back(str);
      num--;
    }
    AllRight();
    v.clear();
  }
}
