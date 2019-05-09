/*
Given a 32 bit number x, reverse its binary form and print the answer in decimal.

Input:
The first line of input consists T denoting the number of test cases. T testcases follow. Each test case contains a single 32 bit integer

Output:
For each test case, in a new line, print the reverse of integer.

Constraints:
1 <= T <= 100
0 <= x <= 4294967295

Example:
Input:
2
1
5
Output:
2147483648
2684354560

Explanation:
Testcase1:
00000000000000000000000000000001 =1
10000000000000000000000000000000 =2147483648
*/

#include <stdio.h>
#include <stdint.h>
#define MASK1 0xFFFF0000
#define MASK2 0x0000FFFF

static inline void reverseBits(int *val)
{
    int num = 0;

    for(size_t itr = 0; itr < 32; ++itr)
    {
        int tmp = 0;
        tmp = (*val & 1);
        num |= (tmp << (31 - itr));
        *val >>= 1;
    }
    *val = num;
}

int main()
{
	//code
	int tc;
	scanf("%d",&tc);
	uint32_t *numArr = (uint32_t *)calloc(tc,sizeof(*numArr));

	for(size_t itr = 0; itr < tc; ++itr)
	{
	    scanf("%u",numArr+itr);
	    reverseBits(numArr+itr);
	    printf("%u\n",numArr[itr]);
	}

	return 0;
}
