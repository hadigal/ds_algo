/*O(n) SOLUTION*/
bool canConstruct(char * rNote, char * mag)
{
    int *rN = (int *)calloc(26,sizeof(*rN));
    int *mg = (int *)calloc(26,sizeof(*mg));

    int itr1 = 0;
    int itr2 = 0;
    int itr = 0, flg = 0;

    while(rNote[itr1] != '\0' && mag[itr2] != '\0')
    {
        rN[rNote[itr1] - 'a'] += 1;
        mg[mag[itr2] - 'a'] += 1;

        ++itr1;
        ++itr2;
    }

    if(mag[itr2] == '\0' && rNote[itr1] != '\0')
    {
        free(rN);
        free(mg);
        return false;
    }

    while(mag[itr2] != '\0')
    {
        //printf("mag[itr2] - 'a':%d\n",mag[itr2] - 'a');
        mg[mag[itr2] - 'a'] += 1;
        ++itr2;
    }


    while(itr < 26)
    {
        if(rN[itr] > mg[itr])
        {
            flg  = 1;
        }
        ++itr;
    }

    free(rN);
    free(mag);

    if(flg == 1)
    {
        return false;
    }

    return true;
}

/* O(N^2) SOLUTION */
// int cmp(const void *aptr1, const void *aptr2)
// {
//     char a = *((char *)(aptr1));
//     char b = *((char *)(aptr2));

//     return (a-b);
// }

// bool canConstruct(char * rNote, char * mag)
// {
//     int len1 = strlen(rNote);
//     int len2 = strlen(mag);

//     qsort(rNote,len1,sizeof(*rNote),cmp);
//     qsort(mag,len2,sizeof(*mag),cmp);

//     int itr1 = 0;
//     int itr2 = 0;
//     int flg = 0;

//     while(rNote[itr1] != '\0')
//     {
//         while(mag[itr2] != '\0')
//         {
//             if(mag[itr2] == rNote[itr1])
//             {
//                 flg = 1;
//                 ++itr2;
//                 break;
//             }
//             ++itr2;
//         }

//         if(flg == 0)
//         {
//             return false;
//         }

//         flg = 0;
//         ++itr1;
//     }

//     return true;
// }
