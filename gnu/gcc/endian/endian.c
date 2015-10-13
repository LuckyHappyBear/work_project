/*************************************************************************
 Copyright (C), 2015, TP-LINK TECHNOLOGIES CO., LTD.

 File Name:    endian.c

 Description:  judge my computer is big-endian or little endian

 Author:       HeXiong

 Email:        hexiong@tp-link.net

 History:

 -----------------------------------------------
 v0.1,2015-8-11,hexiong create the file and complete the function
 ************************************************************************/

#include <stdio.h>

/* a union my_char and my_int share the same memory space */
static union
{
    char my_char[4];
    unsigned int my_int;

}endian_test={{'l', '?', '?', 'b'}};

/********************************************************
MacroName:    ENDIANNESS
Description:  get the low eight bits of my_int
Input:        None
Output:       the low eight bits of my_int
Other:        None
********************************************************/
#define ENDIANNESS ((char)endian_test.my_int)

/*******************************************************
 Function:    test_print
 Description: print the test result
 Input:       None
 Output:      the result of the test
 Other:       None
 ******************************************************/
void test_print()
{
    if (ENDIANNESS == 'l')
    {
        printf("The computer is little-endian\n");
    }
    else
    {
        printf("The computer is big-endian\n");
    }
}
