/*************************************************************************
 Copyright (C), 2015, TP-LINK TECHNOLOGIES CO., LTD.

 File Name:    main.c

 Description:  we test here

 Author:       HeXiong

 Email:        hexiong@tp-link.net

 History:

 -----------------------------------------------
 v0.1,2015-8-12,hexiong create the file and complete the function
 ************************************************************************/

#include <stdio.h>
#include "../staticLib/static_test.h"
#include "../sharedLib/shared_test.h"

void main()
{
    printf("Here is in main!\n");
    static_test();
    shared_test();
}

