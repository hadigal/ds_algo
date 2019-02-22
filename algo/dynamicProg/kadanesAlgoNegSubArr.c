// This is good for max to be a value greater than 0
int maxVal(int num1, int num2)
{
    return ((num1 < num2)?num2:num1);
}

int maxSubArray(int* nums, int numsSize)
{
    int len = numsSize - 1;
    int max = nums[0];
    int max_end = nums[0];
    int itr = 1;

    while(itr <= len)
    {
        max_end = maxVal(nums[itr],(max_end+nums[itr]));
        max = maxVal(max,max_end);
        ++itr;
    }
    return max;
}
