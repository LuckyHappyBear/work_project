/*************************************************************************
 Copyright (C), 2015, TP-LINK TECHNOLOGIES CO., LTD.

 File Name:    Cal_Exp.c

 Description:  transfer nifix expression to suffix expression and count

 Author:       HeXiong

 Email:        hexiong@tp-link.net

 History:

 -----------------------------------------------
 v0.1,2015-8-4,hexiong create the file and complete the function
 ************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Element_Stack.h"
#include "Float_Stack.h"
#include "Cal_Exp.h"

/*****************************************************************
 Function:     get_isp
 Description:  return the operator priority in stack
 Input:        op: the operator you want to konw priority
 Output:       None
 Return:       the priority
 Others:       None
*****************************************************************/
int get_isp(char *op)
{
    if (strcmp(op, "#") == 0)
    {
        return 0;
    }
    else if (strcmp(op, "(") == 0)
    {
        return 1;
    }
    else if ((strcmp(op, "*") == 0) || (strcmp(op, "/") == 0))
    {
        return 5;
    }
    else if ((strcmp(op, "+") == 0) || (strcmp(op, "-") == 0))
    {
        return 3;
    }
    else
    {
        return 6;
    }
}

/*****************************************************************
 Function:     get_icp
 Description:  return the operator priority incoming stack
 Input:        op: the operator you want to konw priority
 Output:       None
 Return:       the priority
 Others:       None
*****************************************************************/
int get_icp(char *op)
{
    if (strcmp(op, "#") == 0)
    {
        return 0;
    }
    else if (strcmp(op, "(") == 0)
    {
        return 6;
    }
    else if ((strcmp(op, "*") == 0) || (strcmp(op, "/") == 0))
    {
        return 4;
    }
    else if ((strcmp(op, "+") == 0) || (strcmp(op, "-") == 0))
    {
        return 2;
    }
    else
    {
        return 1;
    }
}

/*****************************************************************
 Function:     is_num_ele
 Description:  judge the string stand for number or not
 Input:        the expression you want to judge
 Output:       None
 Return:       return 0 or 1
 Others:       None
*****************************************************************/
int is_num_ele(char *exp)
{
    int length = strlen(exp);
    int i;

    for (i = 0; i < length; i++)
    {
        if ((exp[i] >= '0' && exp[i] <= '9') || exp[i] == '.')
        {
            /* is number */
        }
        else
        {
            return 0;
        }
    }
    return 1;
}

/*****************************************************************
 Function:     exchange_exp
 Description:  exchange nifix expression to suffix expression
 Input:        the expression you want to transfrom
 Output:       None
 Return:       suffix expression
 Others:       Noneo
*****************************************************************/
void exchange_exp(char *exp[],int n)
{
    /* loop variable */
    int i = 0;

    /* the bottom of the stack */
    stk_ele_push("#");

    /* in stack, judge priority variable */
    char *isp_ch = malloc(sizeof(char) * 4);

    /* transfrom from nifix expression to suffix expression */
    while (!stk_ele_is_empty() && (i < n))
    {
        if (is_num_ele(exp[i]))
        {
            strcpy(g_char_element[g_count], exp[i]);
            g_count++;
            i++;
        }
        else
        {
            strcpy(isp_ch, stk_ele_top());
            if (get_icp(exp[i]) > get_isp(isp_ch))
            {
                stk_ele_push(exp[i]);
                i++;
            }
            else if (get_icp(exp[i]) < get_isp(isp_ch))
            {
                strcpy(g_char_element[g_count], stk_ele_top());
                stk_ele_pop();
                g_count++;
            }
            else
            {
                if (strcmp(stk_ele_top(), "(") == 0)
                {
                    stk_ele_pop();
                    i++;
                }
            }
        }
    }
    /* get the left element in stack */
    if (strcmp(stk_ele_top(), "#") != 0)
    {
        strcpy(g_char_element[g_count], stk_ele_top());
        g_count++;
        stk_ele_pop();
    }

    /* free the memory */
    free(isp_ch);
}


/*****************************************************************
 Function:     calculate
 Description:  calculate the value of the expression
 Input:        None
 Output:       None
 Return:       the result
 Others:       None
*****************************************************************/
float calculate()
{
    /* loop variable */
    int i;

    for (i = 0; i < g_count; i++)
    {
        if ((strcmp(g_char_element[i], "+") == 0) ||
            (strcmp(g_char_element[i], "-") == 0) ||
            (strcmp(g_char_element[i], "*") == 0) ||
            (strcmp(g_char_element[i], "/") == 0))
        {
            /* according to operator to operate */
            do_operator(g_char_element[i]);
            continue;
        }
        else
        {
            if (is_num_ele(g_char_element[i]))
            {
                /* push number into stack */
                stk_float_push(atof(g_char_element[i]));
                continue;
            }
            else
            {
                printf("There are invalid character.\n");
            }
        }
    }

    /* the top of the stack is result*/
    float result = stk_float_top();

    return result;
}

/*****************************************************************
 Function:     do_operator
 Description:  accoring to operator,get two element to g_count
 Input:        ele_op: operator
 Output:       None
 Return:       void
 Others:       None
*****************************************************************/
void do_operator(char *ele_op)
{
    /* two operate number */
    float op1, op2;

    /* result */
    float result;

    if (stk_float_is_empty())
    {
        printf("No right opearte number\n");
        exit(1);
    }

    /* get right operate number */
    op2 = stk_float_top();
    stk_float_pop();

    if (stk_float_is_empty())
    {
        printf("No left operate.\n");
        exit(1);
    }

    /* get left operate number */
    op1 = stk_float_top();
    stk_float_pop();

    if (strcmp(ele_op, "+") == 0)
    {
        result = op1 + op2;
        stk_float_push(result);
    }
    else if (strcmp(ele_op, "-") == 0)
    {
        result = op1 - op2;
        stk_float_push(result);
    }
    else if (strcmp(ele_op, "*") == 0)
    {
        result = op1 * op2;
        stk_float_push(result);
    }
    else if (strcmp(ele_op, "/") == 0)
    {
        if (op2 == 0)
        {
            printf("right operator is 0.\n");
            exit(1);
        }
        else
        {
            result = op1 / op2;
            stk_float_push(result);
        }
    }
}

/*****************************************************************
 Function:     print_suffix_exp
 Description:  print the suffix expression
 Input:        None
 Output:       None
 Return:       void
 Others:       None
*****************************************************************/
void print_suffix_exp()
{
    int i;
    for (i = 0; i < g_count; i++)
    {
        printf("%s ", g_char_element[i]);
    }
    printf("\n");
    return;
}
