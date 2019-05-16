#include<stdio.h>
#include<unistd.h>
#include<pthread.h>
void *threat(void *arg)
{
  printf("aaaaaaaaaaaaaaa\n");
  sleep(2);
  return NULL;
}
void *threat0(void *arg)
{
  while(1)
  {
    printf("zuse\n");
    sleep(1);
  }
  return NULL;
}
int main()
{
  pthread_t tid[4];
  int t = 0;
  while(t < 3)
  {
    pthread_create(&tid[t],NULL,threat,NULL);
    t++;
  }
    pthread_create(&tid[3],NULL,threat0,NULL);
  t = 0;
  while(t < 4)
  {
    pthread_join(tid[t],NULL);
    t++;
  }
}
