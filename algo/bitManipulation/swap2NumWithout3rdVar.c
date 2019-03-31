#include <stdio.h>

int main(void)
{
  int foo = -5;
  int baz = -10;

  printf("before:\nfoo:%d\tbaz:%d\n",foo,baz);

  foo ^= baz;
  baz ^= foo;
  foo ^= baz;

  printf("After:\nfoo:%d\tbaz:%d\n",foo,baz);
  return 0;
}
