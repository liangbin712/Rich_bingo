#include<iostream>
#include<unistd.h>
#include<pthread.h>
#include<queue>
#include<stdlib.h>
#include<stdio.h>
using namespace std;
typedef bool (*task_callback)(int data);
bool deal_data(int data)
{
  srand(time(NULL));
  int n = rand()%5;
  cout << "thread"<<pthread_self()<<":-----deal_data"<<data<<"-----sleep"<<n<<"sec"<<endl;
  sleep(n);
  return true;
}
class Task{
  public:
    Task()
    {

    }
    ~Task()
    {

    }
  void SetTask(int data,task_callback handle)
  {
    _data = data;
    _handle = handle;
  }
  bool Run()
  {
    return _handle(_data);
  }
  private:
    int _data;  //任务处理要处理的数据
    task_callback   _handle;  //任务的处理方法
};
#define Max_THR 5
#define Max_QUE 10
class ThreadPool
{
  public:
    ThreadPool(){

    }
    ~ThreadPool()
    {
      pthread_mutex_destroy(&_mutex);
      pthread_cond_destroy(&_cond_con);
      pthread_cond_destroy(&_cond_pro);
    }
    bool ThreadInit(int max_thr = Max_THR,int max_que = Max_QUE)
    {
      //实现变量初始化和线程创建
      _quit_flag = false;
      _max_thr = max_thr;
      _cur_thr = max_thr;
      _capacity = max_que;
      pthread_mutex_init(&_mutex,NULL);
      pthread_cond_init(&_cond_con,NULL);
      pthread_cond_init(&_cond_pro,NULL);
      int ret;
      pthread_t tid;
      for(int i = 0; i < _max_thr;i++)
      {
        ret = pthread_create(&tid,NULL,thr_start,NULL);
        if(ret != 0)
        {
          cout << "thread create error" <<endl;
          return false;
        }
        pthread_detach(tid);
      }
       return true;
    }
    bool PushTask(Task &task)
    {
      //向任务队列中添加任务
      if(_quit_flag == true)
      {
        return false;
      }
      QueueLock();
      while(QueueIsFull())
      {
        ProWait();
      }
      _queue.push(task);
      ConWakeUp();
      QueueUnLock();
      return true;
    }
    void ThreadQuit()
    {
      //线程池退出
      if(_quit_flag != true)
      {
        _quit_flag = true;
      }
      while(_cur_thr > 0)
      {
        ConWakeUpAll();
        sleep(1);
      }
      return ;
    }
  private:
    void QueueLock()
    {
      pthread_mutex_lock(&_mutex);
    }
    void QueueUnLock()
    {
      pthread_mutex_unlock(&_mutex);
    }
    void ConWait()
    {//进入ConWait表示消费者这时候没有数据待处理，则解锁退出
      if(_quit_flag == true)
      {
        pthread_mutex_unlock(&_mutex);
        _cur_thr--;
        pthread_exit(NULL);
      }
      pthread_cond_wait(&_cond_con,&_mutex);
    }
    void ConWakeUp()
    {
      pthread_cond_signal(&_cond_con);
    }
    void ConWakeUpAll()
    {
      pthread_cond_broadcast(&_cond_con);
    }
    void ProWait()
    {
      pthread_cond_wait(&_cond_pro,&_mutex);
    }
    void ProWakeUp()
    {
      pthread_cond_signal(&_cond_pro);
    }
    bool QueueIsFull()
    {
      return (_capacity == _queue.size());
    }
    bool QueueIsEmpty()
    {
      return _queue.empty();
    }
    void PopTask(Task *task)
    {
      *task =_queue.front();
      _queue.pop();
    }
   static void *thr_start(void *arg)
    {
      ThreadPool *pool = (ThreadPool*)arg;
      while(1)
      {
        pool->QueueLock();
        while(pool->QueueIsEmpty())
        {
          pool->ConWait();
        }
        Task task;
        pool->PopTask(&task);
        pool->ProWakeUp();
        pool->QueueUnLock();
        //任务处理要放到解锁之外，否则任务处理时间过程导致其他线程阻塞
        task.Run();
      }
      return NULL;
    }
  private:
    int _max_thr;  //线程池中最大线程数量
    int _cur_thr;   //线程池当前线程数量
    int _quit_flag;   //线程退出标志
    int _capacity;    //队列中最大节点数目
    std::queue<Task> _queue;//创建任务队列
    pthread_mutex_t _mutex;  //互斥锁
    pthread_cond_t _cond_pro;//生产者
    pthread_cond_t _cond_con;//消费者
};
int main()
{
  ThreadPool p;
  return 0;
}
