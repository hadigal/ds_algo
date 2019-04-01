#include <stdio.h>
#include <limits.h>
#include <stdbool.h>
// the iterative logic using << operator on 1 till we hit val >= num
// this function also determines what 2 power is num
bool numPowOfTwo(int num)
{
  long val = 0;
  int pow = 0;

  while(val <= num)
  {
    val = 1 << pow;

    // handling in overflow
    if(val > INT_MAX)
    {
      return false;
    }

    if(val == num)
    {
      return true;
    }
    ++pow;
  }

  return false;
}


// the 1 line solution;
// if num pow of 2 then & with (num -1) will be zero
int numPowOfTwoWithoutLoop(int num)
{
  if((num & (num-1)) == 0)
  {
    return true;
  }
  return false;
}

int main()
{
  int num;
  scanf("%d",&num);
  bool val1 = numPowOfTwo(num);
  bool val2 = numPowOfTwoWithoutLoop(num);
  printf("val1:%d\tval2:%d\n",val1,val2);
  return 0;
}
