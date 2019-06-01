/*
Write a function that reverses a string. The input string is given as an array of characters char[].

Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.

You may assume all the characters consist of printable ascii characters.



Example 1:

Input: ["h","e","l","l","o"]
Output: ["o","l","l","e","h"]
Example 2:

Input: ["H","a","n","n","a","h"]
Output: ["h","a","n","n","a","H"]

*/

void reverseString(char* s, int strLen)
{
    //int strLen = strlen(s);
    int mid = strLen/2;
    int itr = 0;
    int len = mid-1;

    char *ptr1 = s;
    char *ptr2 = s + strLen - 1;

    while(itr <= len)
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
