#include <stdio.h>

int fib(int n)
{
  if(n == 0)
    return 0;
  else if(n == 1)
    return 1;
  else
    return fib(n-1)+fib(n-2);
}

int main(void)
{
  int val;
  scanf("%d",&val);
  printf("fib:%d\n",fib(val));
  return 0;
}
