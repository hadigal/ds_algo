#include "binarySearch.h"

int binarySearchRecurrsive(int *arr, int val, int lIdx, int rIdx)
{
  if(lIdx > rIdx)
  {
    return INT_MIN;
  }

  //int mid = lIdx+((lIdx+rIdx)/2);

  int mid = ((lIdx+rIdx)/2);

  if(arr[mid] == val)
  {
    return mid;
  }
  else if(arr[mid] < val)
  {
    return binarySearchRecurrsive(arr,val,mid+1,rIdx);
  }
  else
  {
    return binarySearchRecurrsive(arr,val,lIdx,mid-1);
  }
}

int binarySearchIterative(int *arr, int val, int lIdx, int rIdx)
{
  int mid;

  while(lIdx <= rIdx)
  {
    mid = (lIdx + rIdx)/2;
    if(arr[mid] == val)
    {
      return mid;
    }
    else if(arr[mid] < val)
    {
      lIdx = mid+1;
      rIdx = rIdx;
    }
    else
    {
      lIdx = lIdx;
      rIdx = mid-1;
    }
  }
  return INT_MIN;
}
