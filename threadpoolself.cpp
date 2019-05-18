#include<iostream>
#include<unistd.h>
#include<pthread.h>
#include<queue>
#include<time.h>
#include<stdlib.h>
#define MAX_THR  5
#define MAX_QUE  10
typedef bool(*task_callback)(int data);
bool deal_data(int data)
{
  srand(time(NULL)); 
  int n = rand()%5;
  std::cout << "thread:"<<pthread_self()<<"-----"<<"deal_data:"<<data<<"-----"<<"sleep"<<n<<"sec"<<std::endl;
  sleep(n);
  return true;
}
class Task{
   public:
     void SetTask(int data, task_callback handle)
     {
       _data =data;
       _handle = handle;
     }
     bool Run()
     {
       return _handle(_data);
     }
   private:
     int _data;
     task_callback _handle;
};
class ThreadPool
{
  public:
  ThreadPool()
  {}
  ~ThreadPool()
  {
    pthread_mutex_destroy(&_mutex);
    pthread_cond_destroy(&_cond_con);
    pthread_cond_destroy(&_cond_pro);
  }
  bool Threadinit(int max_thr=MAX_THR ,int max_que = MAX_QUE)
  {
    _quit_flag = false;
    _max_thr = max_thr;
    _capacity = max_que;
    _cur_thr = max_thr;
    pthread_t tid;
    pthread_mutex_init(&_mutex,NULL);
    pthread_cond_init(&_cond_con,NULL);
    pthread_cond_init(&_cond_pro,NULL);
    for(int i = 0; i <_max_thr;i++)
    {
      int ret = pthread_create(&tid,NULL,thr_start,(void *)this);
      if(ret != 0)
      {
        std::cout<<"thread create error"<<std::endl;
        return false;
      }
      pthread_detach(tid);
    }
    return true;
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
      pool->QueueUnlock();
      //任务处理要放到解锁之外，否则任务处理时间过程导致其他线程阻塞
      task.Run();
    }
    return NULL;
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
    QueueUnlock();
    return true;
  }
  void ThreadQuit()
  {
    if(_quit_flag != true)
    {
      _quit_flag = true;
    }
    while(_cur_thr > 0)
    {
      ConWakeUpAll();
      sleep(1);
    }
    return;
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
  void ConWait()
  {
    //进入ConWait表示消费者这时候没有数据待处理
    if(_quit_flag == true)
    {
      pthread_mutex_unlock(&_mutex);
      std::cout << "thread:"<<pthread_self()<<std::endl;
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
    std::cout<<"wakeup all"<<std::endl;
    pthread_cond_broadcast(&_cond_con);
  }
  void ProWait(){
    pthread_cond_wait(&_cond_pro, &_mutex);
  }
  void ProWakeUp(){
    pthread_cond_signal(&_cond_pro);
  }
  bool QueueIsFull(){
    return (_capacity == _queue.size());
  }
  bool QueueIsEmpty(){
    return _queue.empty();        
  }
  void PopTask(Task *task){
    *task = _queue.front();
    _queue.pop();            
  }
  private:
  int _max_thr;   //最大线程数量
  int _cur_thr;       //当前线程数量
  int _capacity;          //线程队列最大节点数目
  int _quit_flag;            //线程池中线程退出标志
  std::queue<Task> _queue;   
  pthread_mutex_t _mutex;
  pthread_cond_t _cond_pro;
  pthread_cond_t _cond_con;
};
int main()
{
  ThreadPool pool;
  pool.Threadinit();
  Task task[10];
  for(int i = 0;i < 10;i++)
  {
    task[i].SetTask(i,deal_data);
    pool.PushTask(task[i]);
  }
  pool.ThreadQuit();
  return 0;
}
