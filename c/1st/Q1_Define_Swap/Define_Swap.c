/*************************************************************************
 Copyright (C), 2015, TP-LINK TECHNOLOGIES CO., LTD.

 File Name:    Define_Swap.c

 Description:  use macro definition to accomplish swap(x, y)，
               x and y are the same type

 Author:       HeXiong

 Email:        hexiong@to-link.net

 History:

 -----------------------------------------------

 V0.1, 2015-7-29, hexiong  create file and complete the function
 ************************************************************************/


#include "Define_Swap.h"

/* test part */
int main()
{
    /* Use int variable to test */
    int TEST_INT_A = 2;
    int TEST_INT_B = 4;

    /* use char variable to test */
    char TEST_CHAR_A = 'A';
    char TEST_CHAR_B = 'B';

    /* use double variable to test */
    double TEST_DOUBLE_A = 20.5;
    double TEST_DOUBLE_B = 30.5;

    /* use string variable to test */
    char TEST_STR_A[12] = "test_str_1";
    char TEST_STR_B[12] = "test_str_2";


    /* print test result */
    printf("Before swap TEST_INT_A is %d, TEST_INT_B is %d\n",
           TEST_INT_A, TEST_INT_B);

    swap(TEST_INT_A, TEST_INT_B);

    printf("After swap TEST_INT_A is %d, TEST_INT_B is %d\n",
           TEST_INT_A, TEST_INT_B);

    printf("Before swap TEST_CHAR_A is %c, TEST_CHAR_B is %c\n",
          TEST_CHAR_A, TEST_CHAR_B);

    swap(TEST_CHAR_A, TEST_CHAR_B);

    printf("After swap TEST_CHAR_A is %c, TEST_CHAR_B is %c\n",
          TEST_CHAR_A, TEST_CHAR_B);


    printf("Before swap TEST_DOUBLE_A is %f, TEST_DOUBLE_B is %f\n",
          TEST_DOUBLE_A, TEST_DOUBLE_B);

    swap(TEST_DOUBLE_A, TEST_DOUBLE_B);

    printf("After swap TEST_DOUBLE_A is %f, TEST_DOUBLE_B is %f\n",
          TEST_DOUBLE_A, TEST_DOUBLE_B);

    printf("Before swap TEST_STR_A is %s, TEST_STR_B is %s\n",
          TEST_STR_A, TEST_STR_B);

    swap(TEST_STR_A, TEST_STR_B);

    printf("After swap TEST_STR_A is %s, TEST_STR_B is %s\n",
          TEST_STR_A, TEST_STR_B);

    return 0;
}
