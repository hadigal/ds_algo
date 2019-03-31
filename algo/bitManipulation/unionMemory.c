#include <stdio.h>
#include <stdint.h>


int main()
{
  union
  {
    struct
    {
      char c[4];
      char ch[4];
    }s1;

    struct
    {
      int i;
      int j;
    }s2;

  }u = {{{(uint8_t)12,(uint8_t)1}, {(uint8_t)15,(uint8_t)1}}};

  // struct
  // {
  //   char c[2];
  //   char ch[2];
  // }temp = {{(uint8_t)12,(uint8_t)1}, {(uint8_t)15,(uint8_t)1}};

  char c[2] = {12,1};
  printf("sizeof(s1):%lu\n",sizeof(u.s1));
  printf("sizeof(u):%lu\n",sizeof(u));

  printf("------%d\t%d\t%d\n",u.s1.ch[0],u.s2.i, u.s2.j);

  return 0;
}
