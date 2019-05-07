/*题目描述
 * 六一儿童节，老师带了很多好吃的巧克力到幼儿园。每块巧克力j的重量为w[j]，对于每个小朋友i，当他分到的巧克力大小达到h[i] (即w[j]>=h[i])，他才会上去表演节目。老师的目标是将巧克力分发给孩子们，使得最多的小孩上台表演。可以保证每个w[i]> 0且不能将多块巧克力分给一个孩子或将一块分给多个孩子。
 * 输入描述:
 * 第一行：n，表示h数组元素个数
 *  第二行：n个h数组元素
 *   第三行：m，表示w数组元素个数
 *    第四行：m个w数组元素*/
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int i,j;
void sort(char p[],int c)
{
  for(int a = 0;a < c;a++)
  {
    for(int b = 0;b <c-a-1;b++)
    {
      if(p[b] > p[b+1])
      {
        int temp = p[b];
        p[b] = p[b+1];
        p[b+1] = temp;

      }

    }

  }

}
int main()
{
  char *h = (char*)malloc(sizeof(char)*10000);
  char *w = (char*)malloc(sizeof(char)*10000);
  scanf("%d",&i);
  h[i] = '\0';
  for(int a = 0;a < i;a++)
  {
    scanf("%d",&h[a]);

  }
  scanf("%d",&j);
  w[j] = '\0';
  for(int a = 0;a < j;a++)
  {
    scanf("%d",&w[a]);

  }
  sort(w,j);
  sort(h,i);
  int num = 0;
  for(int a=0,b=0;a<i&&b<=j;b++){
    if(w[b]>=h[a]){
      num++;
      a++;
    }
  }
  printf("%d",num);
}
