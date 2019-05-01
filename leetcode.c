#include<stdio.h>
#include<stdlib.h>
int* twoSum(int* nums, int numsSize, int target) {
  int *arr = (int *)malloc(sizeof(int*)*2);
  for(int i = 0; i < numsSize;i++)
  {
    int differ = target - nums[i];
    for(int j = i + 1;j < numsSize;j++)
    {
      if(differ == nums[j])
      {
        arr[0]= i;
        arr[1] = j;
        return arr;

      }

    }

  }
  return NULL;
}
