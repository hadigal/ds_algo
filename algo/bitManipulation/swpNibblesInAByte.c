/********************* Geeks for Geeks practice **********************
Given a byte, swap the two nibbles in it. For example 100 is be
represented as 01100100 in a byte (or 8 bits).
The two nibbles are (0110) and (0100).
If we swap the two nibbles, we get 01000110 which is 70 in decimal.

Input:

The first line contains 'T' denoting the number of testcases. Each testcase contains a single positive integer X.


Output:

In each separate line print the result after swapping the nibbles.


Constraints:

1 ≤ T ≤ 70
1 ≤ X ≤ 255


Example:

Input:

2
100
129

Output:

70
24
************************************************************************/
int swpNibble(int val)
{
    int val1 = 0;

    int n1 = 128;
    int n2 = 8;

    int itr = 0;

    int mask1, mask2;

    int itr1 = 7, itr2 = 3;
    int nib1, nib2;
    while(itr < 4)
    {
        nib1 = n1 >> itr;
        nib2 = n2 >> itr;
        ++itr;

        mask1 = (val & nib1);
        mask2 = (val & nib2);

        val1 |= (mask2 << 4);
        val1 |= (mask1 >> 4);
    }

    return val1;
}

int main() {
	//code

	int tc;
	scanf("%d",&tc);
	int *x = (int *)malloc(tc*sizeof(*x));

	for(size_t itr = 0; itr < tc; ++itr)
	{
	    scanf("%d",(x+itr));
	}

	int ret;
	for(size_t itr = 0; itr < tc; ++itr)
	{
	    ret = swpNibble(x[itr]);
	    printf("%d\n",ret);
	}

	return 0;
}
