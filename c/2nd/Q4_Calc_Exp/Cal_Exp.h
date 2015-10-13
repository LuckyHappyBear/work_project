/*************************************************************************
 Copyright (C), 2015, TP-LINK TECHNOLOGIES CO., LTD.

 File Name:    Cal_Exp.h

 Description:  transfer nifix expression to suffix expression and count

 Author:       HeXiong

 Email:        hexiong@tp-link.net

 History:

 -----------------------------------------------
 v0.1,2015-8-4,hexiong create the file and complete the function
 ************************************************************************/

#ifndef _CAL_EXP_H
#define _CAL_EXP_H

/* we use this to store char operator */
static char g_char_element[100][10];

/* number of elements in g_char_element */
static int g_count = 0;

#ifdef __cplusplus
extern "C" {
#endif
/*****************************************************************
 Function:     get_isp
 Description:  return the operator priority in stack
 Input:        op: the operator you want to konw priority
 Output:       None
 Return:       the priority
 Others:       None
*****************************************************************/
int get_isp(char *op);

/*****************************************************************
 Function:     get_icp
 Description:  return the operator priority incoming stack
 Input:        op: the operator you want to konw priority
 Output:       None
 Return:       the priority
 Others:       None
*****************************************************************/
int get_icp(char *op);

/*****************************************************************
 Function:     is_num_ele
 Description:  judge the string stand for number or not
 Input:        the expression you want to judge
 Output:       None
 Return:       return 0 or 1
 Others:       None
*****************************************************************/
int is_num_ele(char *exp);

/*****************************************************************
 Function:     exchange_exp
 Description:  exchange nifix expression to suffix expression
 Input:        the expression you want to transfrom
 Output:       None
 Return:       suffix expression
 Others:       Noneo
*****************************************************************/
void exchange_exp(char *exp[], int n);

/*****************************************************************
 Function:     calculate
 Description:  calculate the value of the expression
 Input:        None
 Output:       None
 Return:       the result
 Others:       None
*****************************************************************/
float calculate();

/*****************************************************************
 Function:     do_operator
 Description:  accoring to operator,get two element to g_count
 Input:        ele_op: operator
 Output:       None
 Return:       void
 Others:       None
*****************************************************************/
void do_operator(char *ele_op);

/*****************************************************************
 Function:     print_suffix_exp
 Description:  print the suffix expression
 Input:        None
 Output:       None
 Return:       void
 Others:       None
*****************************************************************/
void print_suffix_exp();
#ifdef __cplusplus
}
#endif

#endif
