#include <stdio.h>
#include <stdint.h>

int main(void)
{
  //int32_t num = 0xFFFFFFFF, count = 0;
  int32_t num, count = 0;
  scanf("%d",&num);
  printf("Num in hex:%x\n",num);
  uint8_t temp;

  while(num != 0)
  {
    temp = num & 0x01;
    if(temp == 1)
    {
      ++count;
    }
    num = (uint32_t)num >> (uint32_t)1;
  }

  printf("count:%d\n",count);
  return 0;
}
