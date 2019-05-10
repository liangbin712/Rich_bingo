#include<stdio.h>       
#include<unistd.h>    
#include<stdlib.h>    
#include<errno.h>    
#include <sys/types.h>    
#include <sys/wait.h>
int main()
{
  int pipfed[2];
  int ret = pipe(pipfed);
  if(ret <  0)
  {
    perror("pipe error");
    return -1;
  }
  int pid1 = fork();
  if(pid1 < 0)
  {
    perror("pid1 error");
    return -1;
  }
  if(pid1 == 0)
  {
    close(pipfed[0]);
    dup2(pipfed[1],1);
    execlp("ps","ps","ef",NULL);
  }
  int pid2 = fork();
  if(pid2 < 0)
  {
    perror("pid2 error");
    return -1;
  }
  if(pid2 == 0)
  {
    close(pipfed[1]);
    dup2(pipfed[0],0);
    execlp("grep","grep","ssh",NULL);
  }
  close(pipfed[0]);
  close(pipfed[1]);
  waitpid(pid1,NULL,0);
  waitpid(pid2,NULL,0);
  return 0;
}
