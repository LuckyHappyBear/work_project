/*************************************************************************
 Copyright (C), 2015, TP-LINK TECHNOLOGIES CO., LTD.

 File Name:    main.c

 Description:  we test here

 Author:       HeXiong

 Email:        hexiong@tp-link.net

 History:

 -----------------------------------------------
 v0.1,2015-8-5,hexiong create the file and complete the function
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Element_Stack.c"
#include "Float_Stack.c"
#include "Cal_Exp.h"

#define MAX_ELE_NUM 100

/*****************************************************************
 Function:     get_exp_list
 Description:  transform expression to a list contain oprator and
               operate number
 Input:        expression: the expression you want to count
               *exp[MAX_ELE_NUM]: list
 Output:       no
 Return:       void
 Others:       no
*****************************************************************/
int get_exp_list(char *expression, char *exp[MAX_ELE_NUM])
{
    /* a string store a number*/
    char num[10];
    memset(num, 0, 10);

    /* list node number */
    int count = 0;

    /* every bit of the number */
    int bit = 0;

    /* loop variable */
    int i;

    /* length of the expression */
    int exp_len = strlen(expression);

    for (i = 0; i < exp_len; i++)
    {
        /* ignore spcae*/
        if (expression[i] == ' ')
        {
            continue;
        }
        /* get number */
        else if ((expression[i] >= '0' && expression[i] <= '9') ||
                 (expression[i]) == '.')
        {
            while (((expression[i] >= '0' && expression[i] <= '9') ||
                    (expression[i] == '.'))&& i < exp_len)
            {
                num[bit] = expression[i];
                i ++;
                bit ++;
            }
            num[bit] = '\0';
            exp[count] = malloc(sizeof(char) * 10);
            strcpy(exp[count], num);
            count++;

            /* reset */
            bit = 0;
            memset(num, 0, 10);
            i --;

            continue;
        }
        /* get operator */
        else
        {
            exp[count] = malloc(sizeof(char) * 10);
            exp[count][0] = expression[i];
            exp[count][1] = '\0';
            count++;
        }
    }

    return count;
}

int main()
{
    /* loop variable */
    int i;

    char expression[] = "32.5 + 3 * (1 + 2)*1.5 - 4";

    /* element list store oprator and operate number */
    char *exp[MAX_ELE_NUM];

    /* get the number of list node */
    int count = 0;
    count = get_exp_list(expression, exp);

    /* print the nifix expression */
    printf("The initial expression is %s\n", expression);

    /* transform nifix expression to suffix expression */
    exchange_exp(exp,count);

    /* print the suffic expression */
    printf("The suffix expression is ");
    print_suffix_exp();

    /* get the result and print it */
    float result = calculate();
    printf("The calculate result is %0.2f.\n",result);

    /* free the memory */
    for (i = 0; i < count; i++)
    {
        free(exp[i]);
    }

    return 0;
}
