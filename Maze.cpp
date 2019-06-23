#include<iostream>
#include<stack>
#include<vector>
using namespace std;
vector<vector<int> >nice;
vector<vector<int> >cur;
vector<vector<int> >mi;
void GetPath(int m, int n)
{
  int i = 0, j = 0, x = 0,num = 0;
  while (i < n && j < m)
  {
    if (mi[j][i] != 1)
    {
      vector<int>mid;
      mid.push_back(i);
      mid.push_back(j);
      cur.push_back(mid);
      mi[j][i] = 1;
      x++;
    }
    if (i + 1 < n)
    {
      num = mi[j][i + 1];
    }
    if (j + 1<m && mi[j + 1][i] != 1)
      j++;
    else if (i + 1<n && mi[j][i + 1] != 1)
      i++;
    else if (i - 1>0 && mi[j][i - 1] != 1)
      i--;
    else if (j - 1>0 && mi[j - 1][i] != 1)
      j--;
    else{
      if (x < 2)
      {
        continue;
      }
      j = cur[x - 2][1];
      i = cur[x - 2][0];
      cur[x - 1][1] = 0;
      cur[x - 1][0] = 0;
      x--;
    }
    if (i == n - 1 && j == m - 1)
      break;
  }

}
int main()
{
  vector<int>midp;
  int m, n, q;
  while(cin >> m >> n)
  {
    for (int j = 0; j < m; j++)
    {
      for (int i = 0; i < n; i++)
      {
        cin >> q;
        midp.push_back(q);
      }
      mi.push_back(midp);
      midp.clear();
    }
    GetPath(m, n);
    for (size_t i = 0,flag = 0; i < cur.size(); i++)
    {
      if (flag == 1 && cur[i][0] == 0 && cur[i][1] == 0)
      {
        continue;
      }
      cout<<cur[i][1]<<","<< cur[i][0]<< endl;
      flag = 1;
    }
    cout << m-1 << "," << n-1 << endl;
    cur.clear();
    mi.clear();
  }
}
