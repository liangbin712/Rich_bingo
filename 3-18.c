#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
typedef int Datetype;
typedef struct sql{
  Datetype* array;
  int capacity;
  int size;
}sql;
static void CheckCapacity(sql *mobi)//检查容量是否够用
{
  if(mobi->size < mobi->capacity)
  {
    return;
  }
  int Newcapacity = 2 * mobi->capacity;
  Datetype * NewArray = (Datetype*)malloc(sizeof(Datetype) * Newcapacity); 
  for(int i = 0;i <mobi->size;i++)
  {
    NewArray[i] = mobi->array[i];
  }
  free(mobi->array);
  mobi->array = NewArray;
  mobi->capacity = Newcapacity;
}
void MobiInit(sql *mobi,int capacity)//初始化大小
{
  assert(mobi != NULL);
  mobi->array =(Datetype*)malloc(sizeof(Datetype)*capacity);
  mobi->size = 0;
  mobi->capacity = capacity;
}
void DestoryMobi(sql * mobi)//销毁数据
{
  assert(mobi != NULL);
  assert(mobi->array != NULL);
  free(mobi->array);
  mobi->array = NULL;
  mobi->size = mobi->capacity = 0;
}
void MobiPushback(sql *mobi,int value)//入栈
{
  CheckCapacity(mobi); 
  mobi->array[mobi->size] = value;
  mobi->size++;
}
void MobiInsertfront(sql *mobi,int value) //头插
{
  CheckCapacity(mobi);
  for(int i = mobi->size;i > 0;i--)
  {
    mobi->array[i] = mobi->array[i-1];
  }
  mobi->array[0] = value;
  mobi->size++;
}
void MobiInserttail(sql *mobi,int value) //尾插
{
  CheckCapacity(mobi);
  mobi->array[mobi->size] = value;
  mobi->size++;
}
void MobiInsertcent(sql * mobi,int value,int pos) //中间插
{
  CheckCapacity(mobi);
  for(int i = mobi->size;i > pos;i--)
  {
    mobi->array[i] = mobi->array[i-1];  
  }
  mobi->array[pos] = value;
  mobi->size++;
}
void MobiDelfront(sql * mobi)//头部删除
{
  CheckCapacity(mobi);
  for(int i = 0;i < mobi->size-2;i++)
  {
    mobi->array[i] = mobi->array[i+1];  
  }
  mobi->size--;
}
void MobiDeltail(sql * mobi)//末尾删除
{
  mobi->array[mobi->size-2] = 0;
  mobi->size--;
}
void MobiDelcent(sql *mobi,int pos)//中间删除
{
  CheckCapacity(mobi);
  for(int i = pos;i < mobi->size-2;i++)
  {
    mobi->array[i] = mobi->array[i+1];  
  } 
  mobi->size--;
}
