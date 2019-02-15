#include <stdio.h>
#include <stdlib.h>

int *arr;

void swap(int *aptr1,int *aptr2)
{
  int temp = *aptr1;
  *aptr1 = *aptr2;
  *aptr2 = temp;
}

int part(int *arr, int low, int high)
{
  int piv = high;
  int itr1 = low - 1; //selecting the smallest val
  for(int itr2 = low; itr2 <= high -1; ++itr2)
  {
    if(arr[itr2] <= arr[piv])
    {
      ++itr1;
      swap(arr+itr2,arr+itr1);
    }
  }
  ++itr1;
  swap(arr+itr1,arr+high);
  return itr1;
}

void quickSort(int *arr, int low, int high)
{
  int piv;
  if(low < high)
  {
    piv = part(arr,low,high);
    quickSort(arr,low,piv-1);//before; as last pivot idx was brought to its appropriate place
    quickSort(arr,piv+1,high);//after; right side pivot
  }
}

int main(void)
{
  int len;
  scanf("%d",&len);
  arr = (int *)calloc(len,sizeof(*arr));
  printf("ENter arr elements\n");
  for(int itr = 0; itr < len; ++itr)
  {
    scanf("%d",arr+itr);
  }
  quickSort(arr,0,len-1);

  //display
  for(int itr = 0; itr < len; ++itr)
  {
    printf("arr[%d]:%d\n",itr,*(arr+itr));
  }
  return EXIT_SUCCESS;
}
