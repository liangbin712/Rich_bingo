#include<iostream>
#include<vector>
#include<pthread.h>
#include <semaphore.h>
class RingQueue
{
  public:
    RingQueue(int cap = 10):_queue(10),_capacity(cap),
             _write_step(0),_read_step(0){
        sem_init(&_sem_data,0,0);
        sem_init(&_sem_idle,0,cap);
        sem_init(&_sem_lock,0,1);
    }
    ~RingQueue(){
        sem_destroy(&_sem_data);
        sem_destroy(&_sem_idle);
        sem_destroy(&_sem_lock);

    }
    bool QueuePush(int data){
      ProductorWait();
      QueueLock();
      _queue[_write_step] = data;
      _write_step = (_write_step + 1)%_capacity;
      QueueUnlock();
      ConsumerWakeup();
      return true;
    }
    bool QueuePop(int *data)
    {
      ConsumerWait();
      QueueLock();
      *data = _queue[_read_step];
      _read_step = (_write_step + 1)%_capacity;
      QueueUnlock();
      ProductorWakeup();
      return true;
    }
  private:
    void QueueLock()
    {
      sem_wait(&_sem_lock);   //通过计数判断是否有资源可操作（计数-1+等待）
    }
    void QueueUnlock()
    {
      sem_post(&_sem_lock);   //计数+1，并唤醒等待
    }
    void ProductorWait()
    {
      sem_wait(&_sem_idle);
    }
    void ProductorWakeup()
    {
      sem_post(&_sem_idle);
    }
    void ConsumerWait()
    {
      sem_wait(&_sem_data);
    }
    void ConsumerWakeup()
    {
      sem_post(&_sem_data);
    }
  private:
    std::vector<int>_queue;
    int _capacity;
    int _write_step;
    int _read_step;
    sem_t _sem_data;//数据资源计数
    sem_t _sem_idle;//空闲空间计数
    sem_t _sem_lock;//实现互斥
};
void *thr_consumer(void *arg)
{
  RingQueue*q = (RingQueue*)arg;
  while(1)
  {
    int data;
    q->QueuePop(&data);
    std::cout<<"Consumer thread get data :"<<data<<std::endl;
  }
  return NULL;
}
void *thr_product(void *arg)
{
  RingQueue*q = (RingQueue*)arg;
  int i = 0;
  while(1)
  {
    q->QueuePush(i);
    std::cout<<"Consumer thread get data :"<<i<<std::endl;
    i++;
  }
  return NULL;
}
int main()
{
  pthread_t ctid[4],ptid[4];
  int ret,i;
  RingQueue q;
  for(i = 0; i < 4;i++)
  {
    ret = pthread_create(&ctid[i],NULL,thr_consumer,(void*)&q);
    if(ret != 0)
    {
      std::cout<<"thread create error"<<std::endl;
      return -1;
    }
  }
  for(i = 0; i < 4;i++)
  {
    ret = pthread_create(&ctid[i],NULL,thr_product,(void*)&q);
    if(ret != 0)
    {
      std::cout<<"thread create error"<<std::endl;
      return -1;
    }
  }
  for(i = 0;i < 4;i++)
  {
    pthread_join(ctid[i],NULL);
  }
  for(i = 0;i < 4; i++)
  {
    pthread_join(ptid[i],NULL);
  }
  return 0;
}
