#include <stdio.h>

int main()
{
  char str[] = "hello";
  unsigned int len = (sizeof(str)/sizeof(str[0]));

  for(int i = 0; i < len; ++i)
  {
    printf("i:%d\t%c\n",i,str[i]);
  }
  return 0;
}
