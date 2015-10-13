/*************************************************************************
 Copyright (C), 2015, TP-LINK TECHNOLOGIES CO., LTD.

 File Name:    Stack.c

 Description:  create stack to store list node

 Author:       HeXiong

 Email:        hexiong@tp-link.net

 History:

 -----------------------------------------------
 v0.1,2015-8-4,hexiong create the file and complete the function
 ************************************************************************/

#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "Element_Stack.h"

/*****************************************************************
 Function:     stk_ele_push
 Description:  push a element into stack
 Input:        value: the character you want to push
 Output:       None
 Return:       void
 Others:       None
*****************************************************************/
void stk_ele_push(char *value)
{
    /* the stack is not full */
    assert(!stk_ele_is_full());
    top_pos ++;
    strncpy(Stack[top_pos].exp,value,10);

    return;
}

/*****************************************************************
 Function:     stk_ele_pop
 Description:  pop a element from stack
 Input:        None
 Output:       None
 Return:       void
 Others:       None
*****************************************************************/
void stk_ele_pop()
{
    assert(!stk_ele_is_empty());
    top_pos --;

    return;
}

/*****************************************************************
 Function:     stk_ele_top
 Description:  the top of stack
 Input:        None
 Output:       None
 Return:       the top element of the stack
 Others:       None
*****************************************************************/
char* stk_ele_top()
{
    assert(!stk_ele_is_empty());

    return Stack[top_pos].exp;
}

/*****************************************************************
 Function:     stk_ele_is_empty
 Description:  judge the stack is empty or not
 Input:        None
 Output:       None
 Return:       if the stack is empty,return 1,else return 0
 Others:       None
*****************************************************************/
int stk_ele_is_empty()
{
    if (top_pos == -1)
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

/*****************************************************************
 Function:     stk_ele_is_full
 Description:  judge the stack is full or not
 Input:        None
 Output:       None
 Return:       if the stack is full,return 1,else return 0
 Others:       None
*****************************************************************/
int stk_ele_is_full()
{
    if (top_pos == STACK_SIZE - 1)
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}
