#include<iostream>                                                                                                                          
#include<vector>    
using namespace std;    
int main()    
{    
  int a, ci = 20;    
  while(ci)    
  {    
    cin >> a;
    int j = 2,p = a,guo = 0,last = 0,getj = 0,no = 0;
    for(;j <= p/2;j++)    
    {    
      if(a % j==0 && a > j)    
      {    
        a/=j;
        if(getj != j)
          guo++;
        last = a;
        getj = j;
        no = 1;
        j--;
      }    
    }    
    if(last != getj)
      {
        guo++;
      }
   if(no == 0)
     cout<<1<<endl;
   else{
    cout<<guo<<endl;
   }
    ci--;
  }    
}    


