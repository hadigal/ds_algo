/********************************************************************
Write a program to find the sum of bit differences in all pairs that
can be formed from array elements n. Bit difference of a pair (x, y) is
a count of different bits at same positions in binary representations
of x and y. For example, bit difference for 2 and 7 is 2.
Binary representation of 2 is 010 and 7 is 111 ( first and last bits differ in two numbers).

Input: The first line of input contains an integer T denoting the
number of test cases. First line of the test case will contain an array of elements n.

Output: The sum of bit differences of all pairs that can be formed by given array.

Constraints:

1 <=T<= 100

1 <=N<= 10

1 <=a[i]<= 10
Example:

Input:

2
2
1 2
3
1 3 5

Output:
4
8
*************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int countSetBits(int val)
{
    int mask = 1;
    int count = 0;
    while(val > 0)
    {
        if((val & mask) == 1)
        {
            ++count;
        }
        val >>= 1;
    }

    return count;
}

int main() {
	//code
	int tc;
	scanf("%d",&tc);
	int xorVal, count = 0;
	int *arr, n;
	for(size_t itr = 0; itr < tc; ++itr)
	{
	    scanf("%d",&n);
	    arr = (int *)malloc(n*sizeof(*arr));
	    for(size_t itr2 = 0; itr2 < n; ++itr2)
	    {
	        scanf("%d",arr+itr2);
	    }

	    size_t itr2;
	    for(itr2 = 0; itr2 < n; ++itr2)
	    {
	        for(size_t itr3 = 0; itr3 < n; ++itr3)
	        {
	            if(itr3 ==  itr2)
	            {
	                continue;
	            }
	            //printf("arr[%d]:%d\tarr[%d]:%d\n",itr2,arr[itr2],itr3,arr[itr3]);
	            xorVal = arr[itr3] ^ arr[itr2];
        	    count += countSetBits(xorVal);
	        }
	    }
	    printf("%d\n",count);
	    free(arr);
	    count = 0;
	}

	return 0;
}
