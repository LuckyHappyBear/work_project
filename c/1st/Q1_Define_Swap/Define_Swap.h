/*************************************************************************
 Copyright (C), 2015, TP-LINK TECHNOLOGIES CO., LTD.

 File Name:    Define_Swap.h

 Description:  use macro defination to accomplish swap(x,y),
               x and y are the same type

 Author:       HeXiong

 Email:        hexiong@tp-link.net

 History:

 -----------------------------------------------

 v0.1, 2015-7-29, hexiong create file and complete the function
 ************************************************************************/

#ifndef _DEFINE_SWAP_H
#define _DEFINE_SWAP_H

#include <stdio.h>
#include <assert.h>
#include <memory.h>
#include <stdlib.h>

/*****************************************************************
 MacroName:    swap
 Description:  Swap two variables
 Input:        x, y: variables waited to be swaped
 Output:       None
 Others:       x, y should have the same type
 ****************************************************************/
#define swap(x, y)                                             \
do                                                             \
{                                                              \
    size_t x_size = sizeof(x);                                 \
    size_t y_size = sizeof(y);                                 \
    assert(sizeof(x) == sizeof(y));                            \
                                                               \
    void *tempBuf = (void*)malloc(sizeof(x));                  \
    assert(tempBuf != NULL);                                   \
                                                               \
    memcpy(tempBuf, &x, sizeof(x));                            \
    memcpy(&x, &y, sizeof(y));                                 \
    memcpy(&y, tempBuf, sizeof(y));                            \
                                                               \
    free(tempBuf);                                             \
} while(0)

#endif
