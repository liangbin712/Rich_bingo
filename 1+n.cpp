#include<iostream>
class sum{
  public:
  sum()
  {
    x++;
    num = x+ num;
  }
  static void Reset()
  {
    num = 0;
    x = 0;
  }
  static int GetSum()
  {
    return num;
  }
  private:
  static int x;
  static int num;
};
int sum::x = 0; 
int sum::num = 0;
int main()
{
  sum::Reset();
  int n = 100;
  sum *a = new sum[n];
  int s = sum::GetSum();
  std::cout<<s<<std::endl;
}
