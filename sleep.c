#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<signal.h>
void sigcb2(int signo)
{
  sleep(10);
}
void zhen(int num)
{

}
void diysleep(unsigned int seconds)
{
  signal(SIGALRM,zhen);
  sigset_t set,old;
  sigemptyset(&set);
  sigprocmask(SIG_BLOCK,&set,&old);
  alarm(seconds);
  sigprocmask(SIG_UNBLOCK,&set,&old);
  sigset_t mask;
  sigemptyset(&mask);
  sigfillset(&mask);
  sigdelset(&mask,SIGALRM);
  sigsuspend(&mask);
  sigprocmask(SIG_SETMASK,&old,NULL);
  signal(SIGALRM,SIG_DFL);
}
int main()
{
  signal(SIGINT,sigcb2);
  int seconds = 3;
  printf("i buy a new car!\n");
  //diysleep(seconds);
  printf("invate you sit on copilot  ");
  diysleep(seconds);
  printf("B is full of you");
}
