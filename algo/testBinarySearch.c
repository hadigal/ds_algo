#include "binarySearch.h"

static int compre(const void *arr1,const void *arr2)
{
  int val1 = *((int *)arr1);
  int val2 = *((int *)arr2);

  return val1 - val2;
}

int main(void)
{
  int arr[10] = {1,3,2,10,8,4,5,9,7,6};

  qsort(arr,10,sizeof(arr[0]),compre);

  for(int i = 0; i < 10; ++i)
  {
    printf("arr[%d]:%d\n",i,arr[i]);
  }

  // int idx = binarySearchRecurrsive(arr,11,0,9);

  int idx = binarySearchIterative(arr,1,0,9);

  printf("idx:%d\n",idx);

  return 0;
}
