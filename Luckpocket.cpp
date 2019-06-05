#include <stdio.h>
#include <stdlib.h>
int bag[1001],n;
int comp(const void *a,const void *b){
  return *(int*)a - *(int*)b;
}
int dfs(int pos,long long sum,long long pi){
  int i,c;
  for(i=pos,c=0;i<n;++i){
    sum+=bag[i];
    pi*=bag[i];
    if (sum>pi) c+=1+dfs(i+1,sum,pi);
    else if (bag[i]==1) c+=dfs(i+1,sum,pi);
    else break;
    sum-=bag[i];
    pi/=bag[i];
    for(;i<n-1 && bag[i]==bag[i+1];++i);// duplicate

  }
  return c;

}
int main(){
  int i;
  while(~scanf("%d",&n)){
    for(i=0;i<n;scanf("%d",&bag[i++]));
    qsort(bag,n,sizeof(int),comp);
    printf("%d\n",dfs(0,0,1));

  }
  return 0;
}
