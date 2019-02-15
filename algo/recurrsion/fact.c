#include <stdio.h>
#include <stdlib.h>

int fact(int num)
{
  // base condition
  if(num <= 1)
  {
    return 1;
  }
  else // bigger problem expressed in smaller problems
  {
    return num*fact(num -1);
  }
}

int main(void)
{
  int num, fact_val;
  scanf("%d",&num);
  fact_val = fact(num);
  printf("fact of %d:%d\n",num,fact_val);
  return EXIT_SUCCESS;
}
