/*************************************************************************
 Copyright (C), 2015, TP-LINK TECHNOLOGIES CO., LTD.

 File Name:    Error_Code_Gen.c

 Description:  this program used to know the user's input is valid or not

 Author:       HeXiong

 Email:        hexiong@tp-link.net

 History:

 -----------------------------------------------

 v0.1, 2015-7-29, hexiong create file and complete the function
 ************************************************************************/

#include <stdio.h>
#include <string.h>
#include "Error_Code_Gen.h"

#define MAX_LEN 8

/*****************************************************************
 Function:     Is_Over_Length
 Description:  judge the string is over length or not
 Input:        str:  the string used to be tested
 Output:       no
 Return:       return OVER_LENGTH or RIGHT
 others:       no
*****************************************************************/
enum error_code Is_Over_Length(char *str)
{
    /* word length */
    int length = strlen(str);

    /* length over MAX_LEN */
    if (length > MAX_LEN)
    {
        return OVER_LENGTH;
    }
    else
    {
        return RIGHT;
    }
}

/*****************************************************************
 Function:     Is_Initial_Upper
 Description:  judge the initial of string is upper case or not
 Input:        str: the string used to be tested
 Output:       no
 Return:       return INITIAL_LOWER or RIGHT
 others:       no
*****************************************************************/
enum error_code Is_Initial_Upper(char *str)
{
    /* initial is upper case */
    if (str[0] >= 'A' && str[0] <= 'Z')
    {
        return RIGHT;
    }
    else
    {
        return INITIAL_LOWER;
    }
}

/*****************************************************************
 Function:     Is_Contain_Other
 Description:  judge string contain other character or not
 Input:        str: the string used to be tested
 Output:       no
 Return:       return CONTAIN_OTHER or RIGHT
 others:       no
*****************************************************************/
enum error_code Is_Contain_Other(char *str)
{
    /* get length of string */
    int length = strlen(str);

    /* loop variable */
    int i;

    /* judge string contains other character or not */
    for (i = 0; i < length; i++)
    {
        if ((str[i] >= 'a' && str[i] <= 'z') ||
            (str[i] >= 'A' && str[i] <= 'Z'))
        {
            /* this character is letter */
        }
        else
        {
            return CONTAIN_OTHER;
        }
    }

    return RIGHT;
}

/*****************************************************************
 Function:     Is_Ohter_Lower
 Description:  judge last bits are lower case or not
 Input:        char *str: the string used to be tested
 Output:       no
 Return:       return NOT_ALL_LOWER or RIGHT,NOT_ALL_LOWER means
               contains not lower case，RIGHT means all lower case
 others:       no
 ****************************************************************/
 enum error_code Is_Other_Lower(char *str)
 {
    /* get length of string */
    int length = strlen(str);

    /* loop variable */
    int i;

    /* judge last bits are lower case or not */
    for (i = 1; i < length; i++)
    {
        if (str[i] < 'a' || str[i] > 'z')
        {
            return NOT_ALL_LOWER;
        }
    }

    return RIGHT;
 }


/*****************************************************************
 Function:     Print_Result
 Description:  print according to error code
 Input:        int error_code: error code
 Output:       no
 Return:       if has errors，return 0，nor return 1
 others:       无
 ****************************************************************/
int Print_Result(int error_code)
{
    /* print according to error code */
    if (error_code == OVER_LENGTH)
    {
        printf("Over length error:word length is over\n");
        return 0;
    }
    else if (error_code == INITIAL_LOWER)
    {
        printf("Initial lower error:initial is not upper case\n");
        return 0;
    }
    else if (error_code == CONTAIN_OTHER)
    {
        printf("Contian other character error:"
               "Word contains other character except letter\n");
        return 0;
    }
    else if (error_code == NOT_ALL_LOWER)
    {
        printf("Not all lower case error:"
               "Except initial,there is other character which is not lower case\n");
        return 0;
    }
    else if (error_code == RIGHT)
    {
        return 1;
    }
    else
    {
        printf("program error\n");
        return 0;
    }
}


/*****************************************************************
 Function:     Test
 Description:  Test all according to string user input
 Input:        char *str: the string user input
 Output:       no
 Return:       void
 others:       no
 ****************************************************************/
 void Test(char *str)
 {
    /* record pass how many tests */
    int count = 0;

    count += Print_Result(Is_Over_Length(str));
    count += Print_Result(Is_Initial_Upper(str));
    count += Print_Result(Is_Contain_Other(str));
    count += Print_Result(Is_Other_Lower(str));

    /* pass all tests */
    if (count == 4)
    {
        printf("Your input is correct\n");
    }
}
