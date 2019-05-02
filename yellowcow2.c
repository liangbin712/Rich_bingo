#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<signal.h>
#include<pthread.h>
pthread_mutex_t mutex;
int ticket = 100;
void *(yellowcow)(void *i)
{
  int *p = (int *)i;
  while(ticket > 0)
  {
    pthread_mutex_lock(&mutex);
    printf("[%d]yellow cow take [%d]# ticket\n",p,ticket);
    ticket--;
    pthread_mutex_unlock(&mutex);
    usleep(100000);
  }
  pthread_exit(0);
}
int main()
{
  int ret;
  long int i = 4;
  pthread_t tid[4];
  void **o = 0;
  while(i > 0)
  {
    ret = pthread_create(&tid[i],NULL,&yellowcow,(void*)i);
    i--;
    if(ret != 0)
    {
      printf("yelow cow no exist\n");
      return -1;
    }
  }
  pthread_mutex_init(&mutex,NULL);
  i = 0;
  for(i = 0;i < 4;i++)
  {
    pthread_join(tid[i],o);
  }
  pthread_mutex_destroy(&mutex);
  return 0;
}
