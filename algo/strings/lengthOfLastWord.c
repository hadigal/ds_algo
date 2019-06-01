/*
Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word in the string.

If the last word does not exist, return 0.

Note: A word is defined as a character sequence consists of non-space characters only.

Example:

Input: "Hello World"
Output: 5
*/

int lengthOfLastWord(char * s)
{
    char *tk  = strtok(s," ");
    char *prev = s;
    int len = 0;
    while(tk != NULL)
    {
        prev = tk;
        tk = strtok(NULL," ");
    }

    while(*prev != NULL)
    {
        if(*prev != ' ')
        {
            ++len;
        }
        ++prev;
    }


    return len;
}
