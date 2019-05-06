#include <stdio.h>

void clearLSBToIth(int *num, int i)
{
  // the shift operation sets the ith bit to 1 and rest to 0
  // -1 to above statement sets ith bit to 0 and bit numbers less than ith to 1
  // complement to 2 statement as whole gives a num with LSB to ith bit set as 0 and
  // rest set as 1 and &ing this clears LSB to ith bits
  *num = *num & (~((1 << i) -1));
}

// the shift operation sets the ith bit to 1 and rest to 0
// -1 to above statement sets ith bit to 0 and bit numbers less than ith to 1
// and &ing this clears MSB to ith bits from the num
void clearMSBToIth(int *num,int i)
{
  *num = *num & ((1 << i) - 1);
}

int main()
{
  int num = 0xFFFFFFFF;
  clearMSBToIth(&num,16);
  printf("num:%.8x\n",num);

  clearLSBToIth(&num,8);
  printf("num:%16.8x\n",num);
  return 0;
}
