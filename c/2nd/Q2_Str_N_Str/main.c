/*************************************************************************
 Copyright (C), 2015, TP-LINK TECHNOLOGIES CO., LTD.

 File Name:    main.c

 Description:  we test here

 Author:       HeXiong

 Email:        hexiong@tp-link.net

 History:

 -----------------------------------------------
 v0.1,2015-8-3,hexiong create the file and complete the function
 ************************************************************************/

#include <stdio.h>
#include <string.h>
#include "Str_N_Str.h"

/*****************************************************************
 Function:     print_result
 Description:  find str1 first appear position in first n
               characters of str2
 Input:        haystack: search in this string
               needle: search needle in haystack
               n: we just search in first n characters of str2
 Output:       None
 Return:       the pointer of the first appear position
 others:       None
 ****************************************************************/
void print_result(char *position, int length)
{
    if (position == NULL)
    {
       printf("We can't search it.\n");
    }
    else
    {
        int pos_length = strlen(position);
        printf("First appear position is %d\n", length - pos_length);
        printf("the pointer position is %s\n", position);
    }
}


int main()
{
    char test_haystack[64] = "helloHeXiongIloveyouverymuch";

    /* the string appear at the end */
    char test_needle1[6] = "much";

    /* the string appear in the middle */
    char test_needle2[8] = "HeXiong";

    /* the string doesn't appear */
    char test_needle3[6] = "sLove";

    /* the length of the test_haystack*/
    int haystack_length = strlen(test_haystack);

    /* test three condition(normal test) */
    char *position1 = strnstr(test_haystack, test_needle1, 28);
    char *position2 = strnstr(test_haystack, test_needle2, 20);
    char *position3 = strnstr(test_haystack, test_needle3, 28);

    /* test board */
    /* let n < needle */
    char *position4 = strnstr(test_haystack, test_needle3, 2);


    /* print result */
    print_result(position1, haystack_length);
    print_result(position2, haystack_length);
    print_result(position3, haystack_length);
    print_result(position4, haystack_length);

    return 0;
}

