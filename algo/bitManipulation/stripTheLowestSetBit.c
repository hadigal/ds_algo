#include <stdio.h>

int stripLowestSetBit(int num)
{
  // num - 1 gives the value before last bit change;
  // anding that to existing value will strip off the last set bit
  int ret = num & (num -1);

  return ret;
}

int main(void)
{
  int val = 0xF;

  printf("%x\n",stripLowestSetBit(val));

  return 0;
}
