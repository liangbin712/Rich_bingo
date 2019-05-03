#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<string.h>
int main(void)
{
  int i = 0;
  pid_t pid = fork();
  if(pid > 0)
  {
    exit(1);   //1.创建孤儿进程
  }
  if(pid == 0)
  {
    setsid();//2.创建会话组长
    chdir("/");//3.修改工作目录
    umask(0);//4.修改权限掩码
   for(i = 0;i<=1024;++i)
   {
     close(i);//5.关闭文件描述符
   }
  }
  while(1)
  {
    char buf[255];
    fgets(buf,255,stdin);
    buf[strlen(buf)-1] = '\0';
    if(strcmp(buf,"quit") == 0)
      printf("zhizhang\n");
  }
}
