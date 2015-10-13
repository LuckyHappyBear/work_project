/*************************************************************************
 Copyright (C), 2015, TP-LINK TECHNOLOGIES CO., LTD.

 File Name:    main.c

 Description:  user can test

 Author:       HeXiong

 Email:        hexiong@tp-link.net

 History:

 -----------------------------------------------
 v0.1,2015-8-2,hexiong create the file and complete the function
 ************************************************************************/

#include <stdio.h>
#include <string.h>
#include "Average_Len.h"

#define MAX_LEN 512

int main()
{
    /* the sentence user will input */
    char sentence[MAX_LEN];

    printf("Please input the sentence(not over 512):");

    fgets(sentence, MAX_LEN, stdin);
    int length = strlen(sentence);

    /* overwrite the \n at the end of sentence */
    sentence[length - 1] = '\0';

    int average = getAverageLen(sentence);
    printf("average is %d\n",average);

    return 0;
}
