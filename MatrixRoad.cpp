#include<iostream>
#include<string.h>
#include<string>
using namespace std;
bool hasPath(string matrix,int rows,int cols,string s)
{
  if(matrix.c_str() == NULL || rows < 1|| cols < 1 || s.c_str() == NULL)
  {
    return false;
  }
  int l = 0;
  bool *visited = new bool[rows * cols];
  memset(visited,0,rows*cols);
  for(int row = 0;row < rows;row++)
  {
    for(int col = 0;col < cols;col++)
    {
      if(hasPathRoad(matrix,row,col,rows,cols,s,l,visited) == true)
      {
        return true;
      }
    }
  }
}
bool hasPathRoad(string matrix,int row,int col,int rows,int cols,string s,int l,bool* visited)
{
   if(s[0] == '\0')
     return false;
   bool hasPath = false;
   if(row>0 && col>0 && matrix[row*cols+col] == s[l] && visited[row*cols+col] == false)
   {
     visited[row*cols +col] = true;
     hasPath = hasPathRoad(matrix,row,col,rows,cols-1,s,l,visited) 
             || hasPathRoad(matrix,row,col,rows-1,cols,s,l,visited) 
             || hasPathRoad(matrix,row,col,rows,cols+1,s,l,visited) 
             || hasPathRoad(matrix,row,col,rows+1,cols,s,l,visited); 
     if(!hasPath)
     {
       --l;
       visited[row*cols+col] = false;
     }
     return hasPath;
   }
}
int main()
{
  string s = "bfce";
  string matrix = "abtgcfcsjdeh";
  int rows = 3,cols = 4;
  bool IF = hasPath(matrix,rows,cols,s);
  if(IF) cout<<"true"<<endl;
  else cout<<"false"<<endl;
}
