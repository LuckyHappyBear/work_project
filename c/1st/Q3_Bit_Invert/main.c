/*************************************************************************
 Copyright (C), 2015, TP-LINK TECHNOLOGIES CO., LTD.

 File Name:    main.c

 Description:  we test here

 Author:       HeXiong

 Email:        hexiong@tp-link.net

 History:

 -----------------------------------------------
 v0.1,2015-8-2,hexiong create the file and complete the function
 ************************************************************************/

#include <stdio.h>
#include "Bit_Invert.h"

int main()
{
    /* arguments we will input */
    unsigned int x;
    int p, n;

    printf("Please input the number,start position,invert length in order:");
    scanf("%d%d%d",&x, &p, &n);

    x = invert(x, p, n);
    if (x == -1)
    {
        return 0;
    }
    else
    {
        printf("After invert, x is %u\n", x);
        return 0;
    }
}

