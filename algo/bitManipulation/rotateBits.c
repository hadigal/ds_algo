#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>

#define INT16 16

void left(int val, int shift)
{
    //int sft = 1;
    uint32_t num = 0;
    num |= ((val << shift)|(val >> (INT16 - shift)));
    printf("%u\n",num);
}

void right(int val, int shift)
{
  uint32_t num = 0;
  num |= ((val >> shift)|(val << (INT16 - shift)));
  printf("%d\n",num);
}

// void right(int val, int shift)
// {
//     uint16_t rt;
//     int sft = shift;
//     uint32_t num = 0;
//
//     while(sft >= 1)
//     {
//         rt = (val & 0x1);
//         num |= (rt << (INT16 - sft));
//         val >>= 1;
//         --sft;
//     }
//
//     printf("%u\n",(num|val));
// }

int main() {
	//code
	int tc;
	scanf("%d",&tc);

	uint16_t *arr = (uint16_t *)malloc(tc*sizeof(*arr));
	uint32_t *shift = (uint32_t *)malloc(tc*sizeof(*shift));
	int itr = 0;

	while(itr < tc)
	{
	    scanf("%hu%u",arr+itr,shift+itr);
	    ++itr;
	}

	itr = 0;

	while(itr < tc)
	{
	    left(arr[itr],shift[itr]);
	    right(arr[itr],shift[itr]);
	    ++itr;
	}


// 	free(arr);
// 	free(shift);
	return 0;
}
