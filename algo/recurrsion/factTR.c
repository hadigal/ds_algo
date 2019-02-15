#include <stdio.h>

int factTR(int num, int a)
{
  if(num == 0)
  {
    return a;
  }
  else
  {
    return factTR(num-1,num*a);
  }
}

int main(void)
{
  int val;
  scanf("%d",&val);
  int fact = factTR(val,1);
  printf("FACT:%d\n",fact);
}
