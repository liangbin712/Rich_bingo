#include<iostream>
#include<queue>
#include<pthread.h>
#include<stdio.h>
#include<unistd.h>
class BlockQueue{
  public:
    BlockQueue(int cap = 10):_capacity(cap){
      pthread_mutex_init(&_mutex,NULL);
      pthread_cond_init(&_cond_product,NULL);
      pthread_cond_init(&_cond_consumer,NULL);
    }
    ~BlockQueue()
    {
      pthread_mutex_destroy(&_mutex);
      pthread_cond_destroy(&_cond_product);
      pthread_cond_destroy(&_cond_consumer);
    }
    bool QueuePush(int data){
      QueueLock();
      while(QueueFull())
      {
        ProductWait();
      }
      _queue.push(data);
      ConsumerWakeup();
      QueueUnlock();
      return true;
    }
    bool QueuePop(int *data)
    {
      QueueLock();
      while(QueueIsempty())
      {
        ConsumerWait();
      }
      *data = _queue.front();
      _queue.pop();
      productWakeup();
      QueueUnlock();
      return true;
    }
  private:
    void QueueLock()
    {
      pthread_mutex_lock(&_mutex);
    }
    void QueueUnlock()
    {
      pthread_mutex_unlock(&_mutex);
    }
    bool  QueueFull()
    {
      return (_queue.size() == _capacity);
    }
    void ProductWait()
    {
      pthread_cond_wait(&_cond_product,&_mutex);
    }
    void ConsumerWakeup()
    {
      pthread_cond_signal(&_cond_consumer);
    }
    bool QueueIsempty()
    {
      return _queue.empty();
    }
    void ConsumerWait()
    {
      pthread_cond_wait(&_cond_consumer,&_mutex);
    }
    void productWakeup()
    {
      pthread_cond_signal(&_cond_product);
    }
  private:
    std::queue<int>_queue;
    int _capacity;
    pthread_mutex_t _mutex;
    pthread_cond_t _cond_product;
    pthread_cond_t _cond_consumer;
};
void *product(void *arg)
{
  int i = 0 ;
  BlockQueue *q = (BlockQueue *)arg;
  while(1)
  {
    printf("product thread coast data:%d----\n",i);
    sleep(1);
    q->QueuePush(i++);
  }
  return NULL;
}
void *consumer(void *arg)
{
  BlockQueue *c = (BlockQueue *)arg;
  while(1)
  {
    int i;
    c->QueuePop(&i);
    printf("consumer thread create data:%d----\n",i);
    sleep(1);
  }
  return NULL;
}
int main()
{
  int i = 0;
  BlockQueue La;
  pthread_t ctid[4],ptid[4];
  while(i < 4)
  {
    pthread_create(&ptid[i],NULL,product,(void *)&La);
    i++;
  }
  i = 0;
  while(i < 4)
  {
    pthread_create(&ctid[i],NULL,consumer,(void *)&La);
    i++;
  }
  i = 0;
  while(i < 4)
  {
    pthread_join(ptid[i],NULL);
    i++;
  }
  i = 0;
  while(i < 4)
  {
    pthread_join(ctid[i],NULL);
  }
}
