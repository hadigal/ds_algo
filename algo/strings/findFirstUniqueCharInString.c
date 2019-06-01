

int firstUniqChar(char * s)
{
    int *let = (int *)calloc(26,sizeof(*let));
    int itr = 0, flg = 0;
    // int let[26] = {0};
    //int *tmp = (int *)calloc(strlen(s),sizeof(*let));

    while(s[itr] != '\0')
    {
        let[s[itr] - 'a'] += 1;
        ++itr;
    }

    itr = 0;

    while(s[itr] != '\0')
    {
        if(let[s[itr] - 'a'] == 1)
        {
            flg = 1;
            break;
            // return itr;
        }

        ++itr;
    }

    //return -1;
    free(let);
    if(flg == 1)
    {
        return itr;
    }
    else
    {
        return -1;
    }
}
