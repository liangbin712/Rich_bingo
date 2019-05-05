#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<signal.h>
#include<pthread.h>
pthread_mutex_t mutex;
int ticket = 100;
void *(yellowcow)(void *i)
{
  while(1)
  {
    int *p = (int *)i;
    pthread_mutex_lock(&mutex);
    if(ticket > 0)
    {
    usleep(100000);
    printf("[%d]yellow cow take [%d]# ticket\n",p,ticket);
    ticket--;
    }
    else{
      pthread_mutex_unlock(&mutex);
      pthread_exit(NULL);
    }
    pthread_mutex_unlock(&mutex);
  }
}
int main()
{
  int ret;
  long int i =0;
  pthread_t tid[4];
  pthread_mutex_init(&mutex,NULL);
  while(i < 4)
  {
    ret = pthread_create(&tid[i],NULL,yellowcow,(void*)i);
    i++;
    if(ret != 0)
    {
      printf("yelow cow no exist\n");
      return -1;
    }
  }
  for(i = 3;i >= 0;i--)
  {
    pthread_join(tid[i],NULL);
  }
  pthread_mutex_destroy(&mutex);
  return 0;
}
