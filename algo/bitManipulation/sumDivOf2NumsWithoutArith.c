#include <stdio.h>
#include <limits.h>
#include <stdbool.h>
// logic is to find carry using & and sum uisng xor just like half-adder
int sumDiff(int a, int b)
{
  unsigned int carry; // taking carry unsigned to handle -ve number left shift
  while(b != 0)
  {
    // carry
    carry = a & b;
    // sum
    a = a ^ b;

    b = (carry&INT_MAX)<<1;
  }

  return a;
}

int main(void)
{
  int a;
  int b;
  scanf("%d%d",&a,&b);
  
  int val = sumDiff(a,b);

  printf("val:%d\n",val);

  return 0;
}
