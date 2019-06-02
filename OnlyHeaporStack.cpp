#include<iostream>
#include<stdlib.h>
using namespace std;
class StackOnly
{
  public:
    static StackOnly Create()
    {
      return StackOnly();
    }
  private:
    StackOnly()
    {

    }
};
class StackOnly2{
  public:
    StackOnly2()
    {
    }
  private:
    void * operator new(size_t size);
    void operator delete(void *p);
};
class HeapOnly
{
  public:
    static HeapOnly* Create()
    {
      return new HeapOnly;
    }
    int op;
  private:
    HeapOnly()
    {
    }
};
int main()
{
  StackOnly::Create();
  HeapOnly * p = HeapOnly::Create();
  HeapOnly * q = HeapOnly::Create();
  p->op = 6;
  cout << p->op<< endl;
}
