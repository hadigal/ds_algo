#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

bool numPowOf4Iter(int num)
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
    pow += 2;
  }

  return false;
}


bool numPowOf4(int num)
{
  // check if it divisible by 2
  // then check if the odd digit is 1 and rest are 0;
  if(((num & (num-1)) == 0) && ((num & (0x55555555)) == num))
  {
    return true;
  }

  return false;
}

// iterative method

int main(void)
{
  int val;
  scanf("%d",&val);

  bool ret = numPowOf4(val);

  printf("val:%d\n",ret);

  return 0;
}
