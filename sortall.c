#include<stdio.h>
#include<stdlib.h>
int InsertSort(int arr[],int size)   //时间复杂度：O(n^2)空间复杂度：O(1)稳定
{
  for(int i = 0;i < size;i++)
  {
    int key = arr[i];
    int j;
    for( j = i - 1;j >= 0;j--)
    {
      if(arr[j] <= key)
      {
        break;
      }
      arr[j+1] = arr[j];
    }
    arr[j+1] = key;
}
void selectSort(int arr[],int size)//时间复杂度：O(n^2)空间复杂度：O(1)稳定
{
  for(int i = 0;i < size;i++)
  {
     int max = 0;
     int j;
     for(j = 0;j < size-i;j++)
     {
       if(arr[j] > arr[max])
       {
         max = j;
       }
     }
    swap(arr,size-i-1,max);
  }
}
void shellSortPart(int arr[],int size,int gap)
{
  for(int i = 0;i < size;i++)
  {
    key = arr[i];
    int j ;
    for(int j = i - gap;j >= 0;j= j-gap)
    {
      if(arr[j] <= key)
      {
        break;
      }
     arr[j+gap] = arr[j];
    }
    arr[j+gap] = key;
  }
}
void shellSort(int arr[],int size)  //时间复杂度：O(nlogn)O(n^2)空间复杂度：O(1) 稳定
{
  int gap = size;
  while(1)
  {
    gap = size/3 +1;
    
    shellSortPart(arr,size,gap);
    if(gap == 1)
    {
      return;
    }
  }
}
void heapify(int array[],int size,int rootIdx)
{
  while(1)
  {
    if(size == 0)
    {
      return ;
    }
    int leftIdx = rootIdx*2+1;
    int rightIdx = rootIdx*2+2;
    if(leftIdx > size)
    {
      return ;
    }
    int max;
    if(rightIdx > size)
    {
      max = leftIdx;
    }else if(array[leftIdx] > array[rightIdx])
    {
      max = leftIdx;
    }else{
      max = rightIdx;
    }
    if(array[rootIdx] > array[max] )
    {
      return ;
    }
    else{
      swap(arr,array[rootIdx],array[max]);
      rootIdx = max;
    }
  }
}
void creatHeap(int array[],int size)
{
  for(int i = (size-2)/2;i >= 0;i--)
  {
    heapify(array,size,i);
  }
}
void heapSort(int array[],int size)//时间复杂度：O(nlogn)空间复杂度O(1)：稳定
{
  creatHeap(array,size);
  for(int i = 0;i<size;i++)
  {
    swap(array,0,size-1-i);
    heapify(array,size-i-i,0);
  }
}
int partition1(int array[],int low,int high)//挖坑法  
{
  int begin = low;
  int end = high;
  int provite = array[low];
  while(begin < end)
  {
    while(begin <  end && array[end] >= provite)
    {
      end--;
    }
     array[begin] = array[end];
    while(begin < end && array[begin] <= provite)
    {
      begin++;
    }
   array[end] = array[begin];
  }
  array[begin]= provite;
  return begin;
}
int partition2(int array[],int low, int high)   //hover法
{
  int begin = low;
  int end = high;
  int provite = array[low]; 
  while(begin < end)
  {
    while(begin < end && array[end] >= provite)
    {
      end--;
    }
    while(begin > end && array[begin] <= provite)
    {
      begin++;
    }
    swap(array,begin,end);
  }
  swap(array,low,begin);                    
  return begin;
}
int partiton3(int array[],int low,int high)  // 前后下标法   
{
  int provite = array[low];
  int i = low+1;
  int d = low+1;
  while(i <= high)
  {
    if(array[i] <  provite)
    {
      swap(array,i,d);
      d++;
    }
    i++;
  }
  swap(array,d-1,provite);
  return d-1;
}
void QuickSort(int array[],int low,int high)   //时间复杂度：最好是O(n)*O(logn) 最坏是O(n^2)  空间复杂度：O(logn)O(n) 不稳定
{
  if(high == low)
  {
    return;
  }
  if(low > high)
  {
    return;
  }
  int provite = partition(array,low,high);
  QuickSort(low,provite-1);
  QuickSort(provite+1,high);
}
void fix(int array[],int left,int mid,int right,int extra[])
{
  int i = left;
  int j = mid;
  while(i < mid && mid < right )
  {
  if(array[i] > array[j])
  {
     extra[k] = array[j];
     k++;
     j++;
  }
  else{
    extra[k] = array[i];
    k++;
    i++;
  }
 }
 while(i < mid)
 {
   extra[k++] = array[i++];
 }
 while(j < right)
 {
   extra[k++] = array[j++];
 }
 for(int w = 0;w < right,w++)
 {
   array[w] = extra[w];
 }
}
void MergeSort(int array[],int left,int right,int extra[])    //时间复杂度：O(n*logn) 空间复杂度 O(n) 稳定;
{
  if(right - left == 1)
  {
    return;
  }
  if(left == right)
  {
    return;
  }
  int mid = left + (right - left)/2 +1;
  MergeSort(array,left,mid,extra);
  MergeSort(array,mid,right,extra);
  fix(array,left,mid,right,extra);
}
void bubbleSort(int array[],int size)   //时间复杂度：O(n^2)空间复杂度：O(1)稳定
{
  for(int i = 0;i < size;i++)
  {
    for(int j = 0;j < size-i;i++)
    {
      if(array[j] > array[j+1])
      {
        swap(array,j,j+1);
      }
    }
  }
}
