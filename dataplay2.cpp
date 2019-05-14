#include<iostream>
using namespace std;
class Date
{
  public:
    Date(int year = 1900,int month = 1,int day = 1)
    {
      if(year >= 1900 && month > 0 && month < 13 && (day == Getmonth(year,month)))
      {
        _year = year;
        _month = month;
        _day = day;
      }else{
        cout <<"日期错误"<<endl;
      }
    }
    inline int Getmonth(int year,int month)
    {
      int array[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
      if((month == 2) && (((year % 4 == 0)&&(year % 100 != 0))||(year % 400 == 0)))
      {
        return 29;
      }
      return array[month];
    }
    bool operator>(const Date&d)const
    {
      if(_year == d._year)
      {
        if(_month == d._month)
        {
          if(_day > d._day)
          {
            return true;
          }else{
            return false;
          } 
        }else if(_month > d._month)
        {
          return true;
        }else{
          return false;
        }
      }else if(_year > d._year){
              return true;
      }else{
          return false;
      }
    }
    bool operator<(const Date&d)const 
    {
      if((operator>(d))||
          (operator==(d)))
      {
        return false;
      }else{
        return true;
      }
    }
    bool operator>=(const Date&d)const 
    {
      if((operator<(d)))
      {
        return false;
      }else{
        return true;
      }
    }
    bool operator<=(const Date&d)const 
    {
      if(operator>(d))
      {
        return false;
      }else{
        return true;
      }
    }
    bool operator==(const Date&d)const 
    {
      if(_year == d._year)
      {
        if(_month == d._month)
        {
          if(_day == d._day)
          {
            return true;
          }
        }else{
          return false;
        }
      }else{
        return false;
      }
      return false;
    }
    Date& operator++(){
        if(this->_day > Getmonth(this->_year,this->_month))
        {
          if(this->_month == 12)
          {
            this->_year += 1;
            this->_month = 1;
          }
          else
          {
             this->_month += 1;
          }
          this->_day = 1;
        }
        return *this;
    }
    Date &operator--()
    {
      _day = _day-1;
      if(_day < 1)
      {
        _month--;
        _day = Getmonth(_year,_month);
        if(_month < 1)
        {
          _month = 12;
          _year--;
        }
      }
      return *this; 
    }
    Date &operator++(int)
    {
      Date &ret(*this);
      operator++();
      return ret;
    }
    Date & operator--(int)
    {
      Date &ret(*this);
      operator--();
      return ret;
    }
    Date &operator+(int day)
    {
      if(day < 0)
      {
        day = day * (-1);
        *this = operator-(day);
        return *this;
      }
      if(day > Getmonth(_year,_month))
      {
        _month += 1;
        while(day > Getmonth(_year,_month))
        {
             day -= Getmonth(_year,_month);
             _month += 1;
             if(_month > 12)
             {
               _month = 1;
               _year+= 1;
             }
        }
        _day = day;
        return *this;
      }else{
        _day = _day +day;
        if(_day > Getmonth(_year,_month))
        {
          _day = _day - Getmonth(_year,_month); 
          _month+=1;
        return *this;
        }else{
        return *this;
        }
      }
    }
    Date &operator-(int day)
    {
      while(day> 0)
      {
        operator--();
        day--;
      }
      return *this;
    }
    void Print()
    {
      cout<<_year<<"--"<<_month<<"--"<<_day<<endl;
    }
  private:
    int _year;
    int _month;
    int _day;
};
int main()
{
  Date A(1901,5,31);
  A.Print();
  int day = -5000;
  A+day;
  A.Print();
}
