#include<iostream>
#include<string.h>
#include<assert.h>
using namespace std;
class String
{
  public:
    String():_str(new char(1)),_size(strlen(_str))
  {
    _str[0] = '\0'; 
  }
    /* String(char *str):_str(new char[strlen(str)+1])
       {
       strcpy(str,_str);
       }*/
    String(char *str = "")
    {
      _size = _capacity = strlen(str);
      _str = new char[_size+1];
      strcpy(str,_str);
    }
    String &operator=(const String &str)
    {
      if(&str != this)   
      {
        _str = new char[strlen(str._str)+1]; 
        delete [] str._str;
        strcpy(_str,str._str);
      }
      return *this;
    }
   ~String()
   {
     if(_str == NULL)
     {
       delete [] _str;
       _str = nullptr;
     }
   }
   char operator[](size_t size)
   {
     return _str[size];
   }
   char *c_str()
   {
     return _str;
   }
   typedef char *iterator;
   iterator begain()
   {
     return _str;
   }
   iterator end()
   {
     return _str+_size;
   }
   void Reserve(size_t n)
   {
     if(n == 0 && n > _capacity)
     {
       int newsize;
       if(n % 8 == 0)
       newsize = (n/8 + 1)*8;
       else
         newsize = 8 + n;
       char* newstr = new char(newsize);
       if(_str)
       strcpy(newstr,_str);
       _str = newstr;
       _capacity = newsize-1;
     }
   }
   void Resize(size_t n,char a = '\0')
   {
     if(n <= _size)
     {
       _size = n;
       _str[_size] = '\0'; 
     }else{
       Reserve(n);
       for(size_t i = _size;i < n;i++)
       {
         _str[i] = a;
         _size++;
       }
       _str[_size] = '\0';  
     }
   }
   void Insert(size_t pos,char ch)
   {
     assert(pos <= _size);
     if(pos == _size)
     {
       Reserve(2*_capacity);
     }
     for(size_t i = _size;i >pos;i--)
     {
        _str[i+1] = _str[i];
     }
     _str[pos] = ch;
     _size++;
   }
   void Push_back(char ch)
   {
     //Insert(_size,ch);
     if(_size == _capacity)
       Reserve(_capacity*2);
     _str[_size] = ch;
     _size++;
     _str[_size+1] = '\0';
   }
   void Append(char *s)
   {
     size_t len = strlen(s);
    // while(_size+len > _capacity)
    //   Reserve(_capacity*2);
       if(_size +len > _capacity)
         Reserve(_size+len);
      //strstr(_str,s);
      strcpy(_str+_size,s);
      _str[len+_size] = '\0';
   }
  private:
    char * _str;
    size_t  _size;
    size_t _capacity;
};
int main()
{
}
