#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<ctype.h>
#include <sys/types.h>
#include <sys/wait.h>
#include<fcntl.h>
char buf[1024] = {0};
char *argv[32]= {NULL};
int a = 0;
char *file = NULL;
/*void do_face(){
  printf("[liang@localhost]$");
  fflush(stdout);
  memset(buf,0x00,1024);
  if(scanf("%[^\n]%*c",buf) != 1)
  {
  getchar();
  }
  return;
  }
  void do_parse()
  {
  char *ptr = buf;
  argc = 0;
  while(*ptr != '\0')
  {
  if(!isspace(*ptr))
  {
  argv[argc++] = ptr; 
  while(!isspace(*ptr)&& *ptr != '\0') // ( ls  li)    
  {
  ptr++;
  }
  }else{
 *ptr = '\0';
 ptr++;
 }
 }
 return;
 }*/
int main()
{
  while(1)
  {
     bzero(buf,1024);
     bzero(argv,32);
     a = 0;
    file = NULL;
    int i = 0;
    char pwd[100] = {0};
    //do_face();
    int redirect = 0;
    getcwd(pwd,100);                                                                                            
    printf("[liang@%s:]",pwd);    
    fgets(buf,1024,stdin);    
    buf[strlen(buf)-1] = '\0';    
    char *buf1 = (char *)malloc(sizeof(char*)*1024);    
    while(buf[i] != '\0')
    {
      buf1[i] = buf[i];
      i++;
    }
    *(buf1+i) = '\0';
    while(*(buf+a) != '>' && *(buf+a) != '\0')
    {
      if(a == 0)
      {
        argv[a] = strtok(buf," ");
        a++;
      }
      if(strcmp(argv[0],"cd") == 0)
      {
        argv[a] = strtok(NULL," ");
        chdir(argv[a]);
        break;
      }
      if(strcmp(argv[0],"cat") == 0)
      {
        argv[a] = strtok(NULL," ");
        a++;  
        break;
      }
      argv[a] = strtok(NULL," ");
      a++;
    }
    argv[i] = NULL;
    /*while(*ptr != '\0')
      {
      if(*ptr == '>')
      {
      redirect = 1; // clear chongdingxiang
     *ptr++ ='\0';
     if(*ptr == '>')
     {
     redirect = 2;   //add chongdingxiangi
     *ptr++ ='\0';
     }
     while(isspace(*ptr) && *ptr != '\0')
     {
     ptr++;
     }
     file = ptr;
     while(isspace(*ptr) && *ptr != '\0')
     {
     ptr++;
     }
     *ptr = '\0';
     }
     ptr++;
     }*/
    char *ptr = buf1;
    while(*ptr!='\0')
    {
      if(*ptr == '>')
      {
        redirect = 1;
        *ptr = '\0';
        ptr++;
        if(*ptr == '>')
        {
          redirect = 2;
          *ptr = '\0';
          ptr++;
        }
        while(isspace(*ptr)&& *ptr != '\0')
        {
          ptr++;
        }
        file = ptr;
        while(!isspace(*ptr)&& *ptr != '\0')
        {
          ptr++;
        }
        *ptr = '\0';
      }
      ptr++;
    }
    // do_parse();
    //argv[argc] = NULL;
    int pid = fork();
    if(pid < 0){
      exit(-1);
    }else if(pid == 0)
    {                     // chongdingxiang must be do in childpid;
      if(redirect == 1)
      {
        int  fd = open(file, O_CREAT|O_WRONLY|O_TRUNC,0666);
        dup2(fd,1);
      }else if(redirect == 2)
      {
        int fd = open(file, O_CREAT|O_WRONLY|O_APPEND,0666);
        dup2(fd,1);
      }
      execvp(argv[0],argv);
      exit(0);  
    }
    wait(NULL);
  } 
  return 0;
}
