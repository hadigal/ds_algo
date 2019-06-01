/*
Given two binary strings, return their sum (also a binary string).

The input strings are both non-empty and contains only characters 1 or 0.

Example 1:

Input: a = "11", b = "1"
Output: "100"
Example 2:

Input: a = "1010", b = "1011"
Output: "10101
*/


void *rev(char *str)
{
    int strLen = strlen(str);
    int mid = strLen/2;

    int itr = 0, len = mid -1;

    char *ptr1 = str;
    char *ptr2 = str + strLen-1;


    while(itr <= mid-1)
    {
        *ptr1 = *ptr1 ^ *ptr2;
        *ptr2 = *ptr2 ^ *ptr1;
        *ptr1 = *ptr1 ^ *ptr2;

        ++ptr1;
        --ptr2;

        ++itr;
    }

    return;
}


char * addBinary(char * a, char * b)
{
    char sum;
    char carry = '0';


    int len = 0;

    int itr1 = strlen(a);
    int itr2 = strlen(b);

    int retLen = (itr1 > itr2)?itr1:itr2;
    char *ret = (char *)calloc((retLen+2),sizeof(*ret));

    char *final;
    int itr;

    itr1 -= 1;
    itr2 -= 1;

    while(itr1 >= 0 && itr2 >= 0)
    {
        if(carry == '1' && a[itr1] == '1')
        {
            sum = '0';
        }
        else if(carry == '1' && a[itr1] == '0')
        {
            sum = '1';
            carry = '0';
        }
        else
        {
            sum = a[itr1];
        }

        if(sum == '1' && b[itr2] == '1')
        {
            ret[len++] = '0';
            carry = '1';
        }
        else if(sum == '1' && b[itr2] == '0')
        {
            ret[len++] = '1';
        }
        else
        {
            ret[len++] = b[itr2];
        }

        --itr2;
        --itr1;
    }



    if(itr1 == -1)
    {
        itr = itr2;
        final = b;
    }
    else
    {
        itr = itr1;
        final = a;
    }

    while(itr >= 0)
    {

        if(carry == '1' && final[itr] == '1')
        {
            ret[len++] = '0';
            carry = '1';
        }
        else if(carry == '1' && final[itr] == '0')
        {
            ret[len++] = '1';
            carry = '0';
        }
        else
        {
            ret[len++] = final[itr];
        }

        --itr;
    }

    if(carry == '1')
    {
        ret[len++] = carry;
    }
    ret[len] = '\0';
    rev(ret);
    return ret;
}
