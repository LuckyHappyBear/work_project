/*************************************************************************
 Copyright (C), 2015, TP-LINK TECHNOLOGIES CO., LTD.

 File Name:    main.c

 Description:  we test here

 Author:       HeXiong

 Email:        hexiong@tp-link.net

 History:

 -----------------------------------------------
 v0.1,2015-8-6,hexiong create the file and complete the function
 ************************************************************************/

#include <stdio.h>
#include "Min_Difference.h"

int main()
{
    printf("We test three group(stone number is smaller than 32)\n");

    int weights_test_A[5] = {1,2,3,4,5};
    int weights_test_B[8] = {1,2,3,4,5,6,7,8};
    int weights_test_C[10] = {1,2,3,4,5,6,7,8,9,10};

    int result_A = get_min_difference(weights_test_A, 5);
    int result_B = get_min_difference(weights_test_B, 8);
    int result_C = get_min_difference(weights_test_C, 10);

    printf("The result of first group(1,2,3,4,5) is %d\n", result_A);
    printf("The result of second group(1,2,3,4,5,6,7,8) is %d\n", result_B);
    printf("The result of third group(1,2,3,4,5,6,7,8,9,10) is %d\n",result_C);

    return 0;

}
