/*************************************************************************
 Copyright (C), 2015, TP-LINK TECHNOLOGIES CO., LTD.

 File Name:    Search_Dup.c

 Description:  find reduplicate element from an array

 Author:       HeXiong

 Email:        hexiong@tp-link.net

 History:

 -----------------------------------------------
 v0.1,2015-8-3,hexiong create the file and complete the function
 ************************************************************************/

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

/*****************************************************************
 Function:     searchDup
 Description:  find a reduplicate element from an array
 Input:        a[]: the array we will handle
               n:   the length of the array
 Output:       None
 Return:       the reduplicate number
 others:       None
 ****************************************************************/
int searchDup(int a[], int n)
{
    /* loop variable */
    int i = 0;

    /* set a flag array */
    int *flag = malloc(sizeof(int) * n);

    /* set all elements as 0 */
    for (i = 0; i < n; i++)
    {
        flag[i] = 0;
    }

    /* according to arrayy element mark flag array */
    for (i = 0; i < n; i++)
    {
        if (flag[a[i]] == 0)
        {
            flag[a[i]] = 1;
        }
        else
        {
            free(flag);
            return a[i];
        }
    }
    /* no reduplicate element */
    free(flag);
    return 0;
}

/*****************************************************************
 Function:     searchDupImprove
 Description:  find a reduplicate element from an array(better idea)
 Input:        a[]: the array we will handle
               n:   the length of the array
 Output:       None
 Return:       the reduplicate number
 others:       None
 ****************************************************************/
int searchDupImprove(int a[], int n)
{
    /* loop variable */
    int i;

    /* new index */
    int new_index;

    for (i = 0; i < n; i++)
    {
        /*  get new_index */
        if (a[i] >= n)
        {
            /* has marked,recover it */
            new_index = a[i] - n;
        }
        else
        {
            /* hasn't marked */
            new_index = a[i];
        }

        if (a[new_index] < n)
        {
            /* mark this*/
            a[new_index] += n;
        }
        else
        {
            /* find reduplicate element */
            if (a[i] > n)
            {
                /* if this element has been marked, recover it */
                a[i] -= n;
            }
            return a[i];
        }
    }

    /* can't find reduplicate element */
    return 0;
}
