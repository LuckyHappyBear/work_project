/*************************************************************************
 Copyright (C), 2005-2020, TP-LINK TECHNOLOGIES CO., LTD.

 File Name:    main.c

 Description:  Test all function is normal or not

 Author:       HeXiong

 History:

 -----------------------------------------------
 v0.1,2015-8-2,hexiong create the file and complete the function
 ************************************************************************/

#include <stdio.h>
#include "Error_Code_Gen.h"

#define MAX_LEN 20

int main()
{
    /* the string user will input */
    char str[MAX_LEN];

    /* continue test or not */
    int IsContinue;

    do
    {
        printf("Please input a word(not over 20 bits):");
        fgets(str, MAX_LEN, stdin);

        /* test this string */
        Test(str);

        /* test continue or not */
        printf("Continue test(0 for No,1 for Yes)?");
        scanf("%d",&IsContinue);

    } while (IsContinue);

    return 0;
}
