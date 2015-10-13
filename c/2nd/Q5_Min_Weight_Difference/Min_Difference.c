/*************************************************************************
 Copyright (C), 2015, TP-LINK TECHNOLOGIES CO., LTD.

 File Name:    Min_Difference.c

 Description:  merge n stones to two piles,get min weight difference

 Author:       HeXiong

 Email:        hexiong@tp-link.net

 History:

 -----------------------------------------------
 v0.1,2015-8-6,hexiong create the file and complete the function
 ************************************************************************/

#include <stdio.h>
#include <assert.h>

/*****************************************************************
 Function:     get_min_difference
 Description:  merge n stones to two piles,get min weight difference
 Input:        n:the number of stones
	       weights[]: store every stone's weight
 Output:       None
 Return:       the difference of the two piles weight
 Others:       None
*****************************************************************/
int get_min_difference(int weights[], int n)
{

    /* n cannot larger than 32 */
    assert(n < 32);
    /* min diferenec result,initial with a big number */
    int result = 65536;

    /* store every difference of weight */
    int temp_result;

    /* store two piles stone weight */
    int piles[2];

    /* loop variable */
    int i, j;

    for (i = (1 << n) - 1; i >= 0; i--)
    {
        piles[0] = 0;
        piles[1] = 0;

        for (j = n - 1; j >= 0; j--)
        {
            piles[(((i >> j) & 1) == 0) ? 1 : 0] += weights[j];
        }

        if (piles[0] > piles[1])
        {
            temp_result = piles[0] - piles[1];
        }
        else
        {
            temp_result = piles[1] - piles[0];
        }

        if (result > temp_result)
        {
            result = temp_result;
        }
    }
    return result;
}
