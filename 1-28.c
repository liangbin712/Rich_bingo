#include <stdio.h>
int Add(int x, int y)
{
  return x + y;
}
int Sub(int x, int y)
{
  return x - y;
}
int Mul(int x, int y)
{
  return x * y;
}
int Div(int x,int y)
{
  return x / y; 
}
int Menu()
{
  printf("1,add\n");
  printf("2,sub\n");
  printf("3,mul\n");
  printf("4,div\n");
  int choice = 0;
  scanf("%d",&choice);
  return choice;
}
int main()
{
  int num;
  int choice = Menu();
// 这是一个通常的写法，这样的圈复杂度比较高
//  if(choice == 1)
//  {
//    Add(10,20);
//  }else if (choice == 2)
//  {
//    Sub(10,20);
//  }else if(choice == 3)
//  {
//    Mul(10,20);
//  }else if(choice == 4)
//  {
//    Div(10,20);
//  }
//  可以使用表驱动的方法解决这个问题,即转移表
  typedef int (* T)(int , int );
    T  arr[4]= {
      Add,
      Sub,
      Mul,
      Div
    };
    num = arr[choice - 1](10,20);
    printf("%d",num);
}
