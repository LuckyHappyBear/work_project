/*************************************************************************
 Copyright (C), 2015, TP-LINK TECHNOLOGIES CO., LTD.

 File Name:    Bit_Invert.c

 Description:  invert some bits in a unsigned int number

 Author:       HeXiong

 Email:        hexiong@tp-link.net

 History:

 -----------------------------------------------

 v0.1,2015-7-30,hexiong create file and complete the function
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>

/* the most invert bits */
#define MAX_BIT 32

/********************************************************************
  Function:     invert
  Description:  invert n bits on x from position p
  Input:        x:  number will be handled
                p:  start position
                n:  the length we will revert
  Output:       no
  Return:       x after handled
  others:       no
*********************************************************************/
unsigned int invert(unsigned int x, int p, int n)
{
    /* board check */
    if ((n + p) > MAX_BIT)
    {
        printf("Over board\n");
        return -1;
    }
    else
    {
        /* xor number which will xor with x */
        unsigned int xor_handle = 0;

        /* construct xor_handle */
        unsigned int xor_cons = 1;

        /* loop variable */
        int i;

        /* produce n length 1 */
        xor_handle = (xor_cons<<n) - 1;

        /* shift to position */
        xor_handle = xor_handle << p;

        /* handle x */
        x = x ^ xor_handle;

        return x;
    }
}
