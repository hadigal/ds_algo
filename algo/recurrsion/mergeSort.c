#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

int *arr;
int *temp;

void copy(int *arr, int *temp, int lIdx, int rIdx)
{
  int itr;
  for(itr = lIdx; itr <= rIdx; ++itr)
  {
    arr[itr] = temp[itr];
  }
  return;
}

void merge(int *arr, int lIdx1, int rIdx1, int lIdx2, int rIdx2)
{
  int itr1 = lIdx1;
  int itr2 = lIdx2;
  int itr3 = lIdx1;

  while((itr1 <= rIdx1) && (itr2 <= rIdx2))
  {
    if(arr[itr1] <= arr[itr2])
    {
      temp[itr3++] = arr[itr1++];
    }
    else
    {
      temp[itr3++] = arr[itr2++];
    }
  }

  while(itr1 <= rIdx1)
  {
    temp[itr3++] = arr[itr1++];
  }

  while(itr2 <= rIdx2)
  {
    temp[itr3++] = arr[itr2++];
  }
  return;
}

void mergeSort(int *arr, int lIdx, int rIdx)
{
  int mid;
  if(lIdx < rIdx)
  {
    mid = (lIdx+rIdx)/2;
    mergeSort(arr,lIdx,mid);
    mergeSort(arr,mid+1,rIdx);
    merge(arr,lIdx,mid,mid+1,rIdx);
    copy(arr,temp,lIdx,rIdx);
  }
  return;
}

void print_arr(int *arr, int len)
{
  for(int itr = 0; itr < len; ++itr)
  {
    printf("arr[%d]:%d\n",itr,arr[itr]);
  }
}

int main(void)
{
  int len;
  struct timeval start, stop;
  scanf("%d",&len);
  arr = (int *)calloc(len,sizeof(*arr));
  temp = (int *)calloc(len,sizeof(*temp));

  for(int itr = 0; itr < len; ++itr)
  {
    scanf("%d",arr+itr);
  }
  gettimeofday(&start,NULL);
  mergeSort(arr,0,len-1);
  gettimeofday(&stop,NULL);
  print_arr(arr,len);
  printf("Total time for sorting:%lf usec\n",(double)(stop.tv_usec - start.tv_usec));
  free(arr);
  free(temp);
  return EXIT_SUCCESS;
}
