/*************************************************************************
 Copyright (C), 2015, TP-LINK TECHNOLOGIES CO., LTD.

 File Name:    Str_N_Str.c

 Description:  search str1 first appear pos in first n characters of str2

 Author:       HeXiong

 Email:        hexiong@tp-link.net

 History:

 -----------------------------------------------
 v0.1,2015-8-3,hexiong create the file and complete the function
 ************************************************************************/

#include <stdio.h>
#include <assert.h>
#include <string.h>

/*****************************************************************
 Function:     strnstr
 Description:  find str1 first appear position in first n
               characters of str2
 Input:        haystack: search in this string
               needle: search needle in haystack
               n: we just search in first n characters of str2
 Output:       None
 Return:       the pointer of the first appear position
 others:       None
 ****************************************************************/
char *strnstr(const char* haystack, const char* needle, size_t n)
{
    /* loop variable */
    int i;

    /* the pointer uesd to be find first position */
    char *p = haystack;

    /* the length of haystack */
    int hay_length = strlen(haystack);

    /* the length of needle */
    int nee_length = strlen(needle);

    /* the length of haystack should be larger than n */
    assert(hay_length >= n);

    /* n should larger than 0 */
    assert(n > 0);

    /* find from 0 to n- nee_length */
    for (i = 0; i <= (int)(n - nee_length); i++)
    {
        if (strncmp(p, needle, nee_length) == 0)
        {
            return p;
        }
        else
        {
            p++;
        }
    }

    return NULL;
}
