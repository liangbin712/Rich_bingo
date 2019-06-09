#include<iostream>
#include<string.h>
#include<assert.h>
#include<string>
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
       strcpy(_str,str);
       }*/
    String(char *str)
    {
      _size = _capacity = strlen(str);
      _str = new char[_size+1];
      strcpy(_str,str);
    }
    String &operator=(const String &str)
    {
      if(&str != this)   
      {
        delete [] _str;
        _str = new char[strlen(str._str)+1]; 
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
   iterator begin()
   {
     return _str;
   }
   iterator end()
   {
     return _str+_size;
   }
   void Reserve(size_t n)
   {
     if(n == 0 || n > _capacity)
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
   void Erase(size_t pos,size_t npos = 1)
   {
     if(pos+npos > _capacity)
     {
       Reserve(2*_capacity);
     }
     char *newstr = new char[_size-npos+1];
     for(size_t i= 0;i < pos;i++)
     {
      newstr[i] = _str[i]; 
     }
     for(size_t i = npos,j = 0;i < _size-1;i++,j++)
     {
       newstr[pos+j] = _str[pos+i];
       _size--;
     }
     newstr[_size+1] = '\0';
     delete[] _str;
     _str = newstr;
     _size-=npos;
     _capacity = _size +1;
   }
  size_t Find(char s,size_t pos)
  {
    if(pos > _size)
    {
      return -1;
    }
    for(size_t i = pos;i < _size;i++)
    {
      if(s == _str[i])
      {
        return i;
      }
    }
      return -1;
  }
  size_t Find(char *str,size_t pos,size_t n)
  {
    assert(str != NULL);
    if(pos >_size || n > _size)
    {
      return -1;
    }
    size_t i = pos,j = 0,flag = 0,t = 0;
    for(;i < pos+n;i++)
    {
      if(str[j] == _str[i])
      {
         j++;
         flag = 1;
      }
      else if(flag != 1)
      {
        t++;
      }
    }
    if(j == strlen(str))
    {
      return (pos+t);
    }
    return -1;
  }
  private:
    char * _str;
    size_t  _size;
    size_t _capacity;
    size_t _npos;
};
