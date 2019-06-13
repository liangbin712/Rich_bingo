#include<iostream>
#include<string>
using namespace std;
int main(){
  int n;
  while(cin>>n){
    string str;
    int now=1,top,button;
    cin>>str;
    if(n<=4){
      top=1,button=n;
      for(int i=0;i<str.size();i++){
        if(str[i]=='U'){
          if(now==1) now=button;
          else now--;
        }
        else{
          if(now==button) now=1;
          else now++;
        }
      }
    }
    else{
      top=1,button=4;
      for(int i=0;i<str.size();i++){
        if(str[i]=='U'){
          if(now==1){
            now=n;
            button=n;
            top=n-3;
          }
          else if(now==top){
            now--;
            top--;
            button--;
          }
          else now--;
        }
        else{
          if(now==n){
            top=1;
            button=4;
            now=1;
          }
          else if(now==button){
            now++;
            button++;
            top++;
          }
          else now++;
        }
      }
    }
    for(int i=top;i<button;i++)
      cout<<i<<' ';
    cout<<button<<endl;
    cout<<now<<endl;
  }
  return 0;
}
