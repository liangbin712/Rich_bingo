#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main()
{
  string list,zha,copy;
  while (getline(cin, list))
  {
    vector<string> v;
    string mid = "";
    getline(cin, zha);
    list += ",";
    size_t dou = 0, num = 0;
    for (size_t i = 0; i < list.size(); i++)
    {
      if (list[i] == '"' && dou == 0)
        dou = 1;
      else if (list[i] == '"' && dou == 1)
      {
        dou = 0;
      }
      else if (list[i] == ',' && dou == 0){
        num++;
        v.push_back(mid);
        mid.clear();
      }
      copy = mid;
      if (list[i] != '"')
        mid += list[i];
      if (list[i] == ',' && dou == 0)
        mid = copy;
    }
    size_t i, flag = 0;
    for (i = 0; i < num; i++)
    {
      if (v[i] == zha)
        flag = 1;
    }
    if (flag != 1)
      cout << "Important!" << endl;
    else cout << "Ignore" << endl;
    mid.clear();
    list.clear();
    zha.clear();
    copy.clear();
  }
}
