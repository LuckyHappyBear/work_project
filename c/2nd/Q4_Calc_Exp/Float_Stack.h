/*************************************************************************
 Copyright (C), 2015, TP-LINK TECHNOLOGIES CO., LTD.

 File Name:    Float_Stack.h

 Description:  the stack store float operate number

 Author:       HeXiong

 Email:        hexiong@tp-link.net

 History:

 -----------------------------------------------
 v0.1,2015-8-5,hexiong create the file and complete the function
 ************************************************************************/

#ifndef _FLOAT_STACK_H
#define _FLOAT_STACK_H

#define TRUE 1
#define FALSE 0

#define STK_FLOAT_SIZE 100

/* the stack with type float */
float stk_float[STK_FLOAT_SIZE];

/* top pointer */
static int float_top = -1;

#ifdef __cplusplus
extern "C" {
#endif
/*****************************************************************
 Function:     stk_float_push
 Description:  push a element into stack
 Input:        value: the operate number you want to push
 Output:       None
 Return:       void
 Others:       None
*****************************************************************/
void stk_float_push(float value);

/*****************************************************************
 Function:     stk_float_pop
 Description:  pop a element from stack
 Input:        None
 Output:       None
 Return:       void
 Others:       None
*****************************************************************/
void stk_float_pop();

/*****************************************************************
 Function:     stk_float_top
 Description:  the top of stack
 Input:        None
 Output:       None
 Return:       the top element of the stack
 Others:       None
*****************************************************************/
float stk_float_top();

/*****************************************************************
 Function:     stk_float_is_empty
 Description:  judge the stack is empty or not
 Input:        None
 Output:       None
 Return:       if the stack is empty,return 1,else return 0
 Others:       None
*****************************************************************/
int stk_float_is_empty();

/*****************************************************************
 Function:     stk_float_is_full
 Description:  judge the stack is full or not
 Input:        None
 Output:       None
 Return:       if the stack is full,return 1,else return 0
 Others:       None
*****************************************************************/
int stk_float_is_full();

#ifdef __cplusplus
}
#endif

#endif
