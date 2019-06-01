/*
Write a function that takes a string as input and reverse only the vowels of a string.

Example 1:

Input: "hello"
Output: "holle"
Example 2:

Input: "leetcode"
Output: "leotcede"
Note:
The vowels does not include the letter "y".
*/

char * reverseVowels(char * s)
{
    char *ptr = s;

    int len = strlen(s);
    int mid = (len/2) - 1;

    int itr1 = 0;
    int itr2 = len - 1;
    int itr = 0;
    int flg1 = 0, flg2 = 0;

    while(itr1 < itr2)
    {
        while(itr1 < itr2)
        {

            if(ptr[itr1] == 'a' || ptr[itr1] == 'e' || ptr[itr1] == 'o' || ptr[itr1] == 'i' || ptr[itr1] == 'u')
            {
                flg1 = 1;
                break;
            }
            else if(ptr[itr1] == 'A' || ptr[itr1] == 'E' || ptr[itr1] == 'O' || ptr[itr1] == 'I' || ptr[itr1] == 'U')
            {
                flg1 = 1;
                break;
            }
            else
            {
                flg1 = 0;
            }

            ++itr1;
        }

        while(itr2 > itr1)
        {
            if(ptr[itr2] == 'a' || ptr[itr2] == 'e' || ptr[itr2] == 'o' || ptr[itr2] == 'i' || ptr[itr2] == 'u')
            {
                flg2 = 1;
                break;
            }
            else if(ptr[itr2] == 'A' || ptr[itr2] == 'E' || ptr[itr2] == 'O' || ptr[itr2] == 'I' || ptr[itr2] == 'U')
            {
                flg2 = 1;
                break;
            }
            else
            {
                flg2 = 0;
            }
            --itr2;
        }


        if(flg1 == 1 && flg2 == 1)
        {
            char *ptr1 = s+itr1;
            char *ptr2 = s+itr2;


            *ptr1 = *ptr1 ^ *ptr2;
            *ptr2 = *ptr2 ^ *ptr1;
            *ptr1 = *ptr1 ^ *ptr2;
        }

        flg1 = 0;
        flg2 = 0;

        ++itr1;
        --itr2;

        ++itr;
    }

    return s;
}
