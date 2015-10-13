/*************************************************************************
 Copyright (C), 2015, TP-LINK TECHNOLOGIES CO., LTD.

 File Name:    Stack.h

 Description:  create a satck to store list node

 Author:       HeXiong

 Email:        hexiong@tp-link.net

 History:

 -----------------------------------------------
 v0.1,2015-8-5,hexiong create the file and complete the function
 ************************************************************************/

#ifndef _STACK_H
#define _STACK_H

#define FALSE 0
#define TRUE 1
#define STACK_SIZE 100
#define MAX_OP_LEN 10

/* node of the stack */
struct stack
{
    char exp[MAX_OP_LEN];
};

/* stack store list node */
struct stack Stack[STACK_SIZE];

/* top pointer */
static int top_pos = -1;

#ifdef __cplusplus
extern "C" {
#endif
/*****************************************************************
 Function:     stk_ele_push
 Description:  push a element into stack
 Input:        value: the character you want to push
 Output:       None
 Return:       void
 Others:       None
*****************************************************************/
void stk_ele_push(char *value);

/*****************************************************************
 Function:     stk_ele_pop
 Description:  pop a element from stack
 Input:        None
 Output:       None
 Return:       void
 Others:       None
*****************************************************************/
void stk_ele_pop();

/*****************************************************************
 Function:     stk_ele_top
 Description:  the top of stack
 Input:        None
 Output:       None
 Return:       the top element of the stack
 Others:       None
*****************************************************************/
char* stk_ele_top();

/*****************************************************************
 Function:     stk_ele_is_empty
 Description:  judge the stack is empty or not
 Input:        None
 Output:       None
 Return:       if the stack is empty,return 1,else return 0
 Others:       None
*****************************************************************/
int stk_ele_is_empty();

/*****************************************************************
 Function:     stk_ele_is_full
 Description:  judge the stack is full or not
 Input:        None
 Output:       None
 Return:       if the stack is full,return 1,else return 0
 Others:       None
*****************************************************************/
int stk_ele_is_full();
#ifdef __cplusplus
}
#endif

#endif
