void reverse(char *str, int len)
{
    int mid = (len/2) - 1;
    int itr = 0;
    char *ptr1 = str;
    char *ptr2 = str + len - 1;

    while(itr <= mid)
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

char * addStrings(char * num1, char * num2)
{
    int len1 = strlen(num1);
    int len2 = strlen(num2);

    int retLen = (len1 > len2)?len1:len2;
    char *ret = (char *)calloc((retLen+2),sizeof(*ret));
    char *final = NULL;
    int itr;

    int itr1 = len1 -1;
    int itr2 = len2 -1;
    int sum, len = 0;
    int carry = 0;
    int n1,n2;

    while(itr1 >= 0 && itr2 >= 0)
    {
        n1 = num1[itr1] -  48;
        n2 = num2[itr2] - 48;

        sum = n1+n2;

        sum += carry;
        carry = (sum/10);
        ret[len++] = 48 + (sum%10);

        --itr1;
        --itr2;
    }

    if(itr1 == -1)
    {
        final = num2;
        itr = itr2;
    }
    else
    {
        itr = itr1;
        final = num1;
    }

    while(itr >= 0)
    {
        n1 = final[itr] - 48;
        sum = n1 + carry;

        carry = (sum/10);
        ret[len++] = 48+(sum%10);

        --itr;
    }

    if(carry == 1)
    {
        ret[len++] = 48+carry;
    }

    ret[len] = '\0';

    reverse(ret,len);
    return ret;
}
