/*************************************************************************
 Copyright (C), 2015, TP-LINK TECHNOLOGIES CO., LTD.

 File Name:    main.c

 Description:  we test function here

 Author:       HeXiong

 Email:        hexiong@tp-link.net

 History:

 -----------------------------------------------
 v0.1,2015-8-3,hexiong create the file and complete the functionn
 ************************************************************************/

#include <stdio.h>
#include "Search_Dup.h"

int main()
{
    /* the array used to be tested */
    int test_a[5] = {1,2,3,4,2};
    int test_b[10] = {1,2,3,4,5,6,7,8,9,3};
    int test_c[10] = {1,2,3,4,5,6,7,8,9,0};

    /* the test result of function searchDup */
    int result_a = searchDup(test_a, 5);
    int result_b = searchDup(test_b, 10);
    int result_c = searchDup(test_c, 10);


    /* the test result of function searchDupImprove */
    int result_improve_a = searchDupImprove(test_a, 5);
    int result_improve_b = searchDupImprove(test_b, 10);
    int result_improve_c = searchDupImprove(test_c, 10);

    /* print the result of function searchDup*/
    printf("Here are result by function searchDup\n");
    if (result_a == 0)
    {
        printf("There is no reduplicate element in this array\n");
    }
    else
    {
        printf("In this array,the reduplicate element is %d\n",result_a);
    }

    if (result_b == 0)
    {
        printf("There is no reduplicate element in this array\n");
    }
    else
    {
        printf("In this array,the reduplicate element is %d\n",result_b);
    }

    if (result_c == 0)
    {
        printf("There is no reduplicate element in this array\n");
    }
    else
    {
        printf("In this array,the reduplicate element is %d\n",result_c);
    }

    /* print the result of function searchDupImprove */
    printf("Here are result by function searchDupImprove\n");
    if (result_improve_a == 0)
    {
        printf("There is no reduplicate element in this array\n");
    }
    else
    {
        printf("In this array,the reduplicate element is %d\n",result_improve_a);
    }

    if (result_improve_b == 0)
    {
        printf("There is no reduplicate element in this array\n");
    }
    else
    {
        printf("In this array,the reduplicate element is %d\n",result_improve_b);
    }

    if (result_improve_c == 0)
    {
        printf("There is no reduplicate element in this array\n");
    }
    else
    {
        printf("In this array,the reduplicate element is %d\n",result_improve_c);
    }
    return 0;
}
