// flip on the the bits which represent number i.e for num = 5 flip last 3 bits only

// solution use mask
// create a mask of 0xFFFFFFFF if the size of num is 32 bits
// shift the mask to left till (mask&num) != 0
// this creates a mask only for the bits representing the number!!
// now perform ~mask&~num to get the flipped bit number

int findComplement(int num)
{
    //printf("%x",~(num));

    uint32_t mask = 0xFFFFFFFF;

    while(mask & num)
    {
        mask = mask << 1;
    }

    int ret = ~mask & ~num;
    return ret;
}
