#include <stdio.h>
//setting  31st bit to 0 if negative;
#define SIGNEDBIT1 0x00000001
#define SIGNEDBIT2 0x00000002
#define NEGMASK 0xfffffffe


int main(void)
{
  int foo = -2;

  // this prints value 0xffffffff which is 2's complement form of representing the -ve value
  // THus have to use the following MASK to clear the 2's complement bit to comvert the value to +ve
  printf("before:%x\n",foo);
  printf("signed bit:%x\n",SIGNEDBIT2);

  foo &= SIGNEDBIT2;
  printf("after:%x\n",foo);

  //foo = 5;
  foo |= NEGMASK;
  printf("Convert back to -ve:%d\n",foo);

  foo *= -1;
  printf("after mul:%d\n",foo);

  return 0;
}
