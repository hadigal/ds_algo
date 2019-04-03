
// int compare(void *aptr1, void *aptr2)
// {
//     char c1 = *((char *)aptr1);
//     char c2 = *((char *)aptr2);

//     return (c1-c2);
// }


// since the xor has the ability to a^b = b^a &&  a^a = 0; the str with extra
// object will be returned successlly after iterating the two string chars by
// xoring the a ret char at each step with current index char!!

// Aside, another method is to sort the 2 list and since the all the other chars
// except one are same anding & each char from two list with each other will give
// the extra character!!
char findTheDifference(char* s, char* t)
{
//     char *ptr1 = s;
//     char *ptr2 = t;

//     qsort(ptr1,strlen(s),sizeof(s[0]),compare);
//     qsort(ptr2,strlen(t),sizeof(t[0]),compare);


//     while(*ptr1 && *ptr2)
//     {
//         if((*ptr1 ^ *ptr2) != 0)
//         {
//             return *ptr2;
//         }
//         ++ptr1;
//         ++ptr2;
//     }

//     return *ptr2;

    char ret = 0x00;

    while(*s)
    {
        ret ^= *s++;
    }

    while(*t)
    {
        ret ^= *t++;
    }

    return ret;
}
