// This is good for max to be a value greater than 0
int maxSubArray(int* nums, int numsSize)
{
    int len = numsSize - 1;
    int max = 0;
    int max_end = 0;
    for(int itr = 0; itr <= len; ++itr)
    {
        max_end  = max_end + nums[itr];
        if(max_end < 0)
        {
            max_end  = 0;
        }
        else if(max < max_end)
        {
            max = max_end;
        }
    }
    return max;
}
