#include<stdio.h>
#include<stdlib.h>
 int(*pp)(int ,int ) = NULL;
int back(int a ,int b)
{
   int c =a + b;
   return c;
}
int plus(int a,int b,int(*abc)(int,int))
{
  int c = a + b + abc(1,2);
  return c; 
}
int main()
{
  int a = 1,b = 2;
  pp = back;
  int c = plus(a,b,pp);
  printf("%d\n",c);
}
