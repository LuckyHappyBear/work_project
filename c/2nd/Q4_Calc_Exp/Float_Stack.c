/*************************************************************************
 Copyright (C), 2015, TP-LINK TECHNOLOGIES CO., LTD.

 File Name:    FLoat_Stack.c

 Description:  The stack store the float number

 Author:       HeXiong

 Email:        hexiong@tp-link.net

 History:

 -----------------------------------------------
 v0.1,2015-8-5,hexiong create the file and complete the function
 ************************************************************************/

#include <stdio.h>
#include <assert.h>
#include "Float_Stack.h"

/*****************************************************************
 Function:     stk_float_is_empty
 Description:  judge the stack is empty or not
 Input:        None
 Output:       None
 Return:       if the stack is empty,return 1,else return 0
 Others:       None
*****************************************************************/
int stk_float_is_empty()
{
    if (float_top == -1)
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

/*****************************************************************
 Function:     stk_float_is_full
 Description:  judge the stack is full or not
 Input:        None
 Output:       None
 Return:       if the stack is full,return 1,else return 0
 Others:       None
*****************************************************************/
int stk_float_is_full()
{
    if (float_top == STK_FLOAT_SIZE - 1)
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

/*****************************************************************
 Function:     stk_float_push
 Description:  push a element into stack
 Input:        value: the operate number you want to push
 Output:       None
 Return:       void
 Others:       None
*****************************************************************/
void stk_float_push(float value)
{
    /* the stack is not full */
    assert(!stk_float_is_full());
    float_top++;
    stk_float[float_top] = value;
    return;
}

/*****************************************************************
 Function:     stk_float_pop
 Description:  pop a element from stack
 Input:        None
 Output:       None
 Return:       void
 Others:       None
*****************************************************************/
void stk_float_pop()
{
    assert(!stk_float_is_empty());
    float_top--;
    return;
}

/*****************************************************************
 Function:     stk_float_top
 Description:  the top of stack
 Input:        None
 Output:       None
 Return:       the top element of the stack
 Others:       None
*****************************************************************/
float stk_float_top()
{
    assert(!stk_float_is_empty());
    return stk_float[float_top];
}

