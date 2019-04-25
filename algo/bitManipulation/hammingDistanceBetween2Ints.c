/********************** leetcode prob 461 *****************************
The Hamming distance between two integers is the number of positions at which the corresponding bits are different.

Given two integers x and y, calculate the Hamming distance.

Note:
0 ≤ x, y < 231.
************************************************************************/

// O(n) time and o(1) spacce solution
#define MASK ((int32_t)(0x1))

int hammingDistance(int x, int y)
{
    int32_t count = 0;

    while(x != 0 || y != 0)
    {
        count += (((x & MASK) ^ (y & MASK)) == 1)?1:0;
        x >>= 1;
        y >>= 1;
    }

    return count;
}
