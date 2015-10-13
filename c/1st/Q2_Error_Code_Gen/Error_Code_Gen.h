/*************************************************************************
 Copyright (C), 2015, TP-LINK TECHNOLOGIES CO., LTD.

 File Name:    Error_Code_Gen.h

 Description:  this program used to know the user's input is valid or not

 Author:       HeXiong

 Email:        hexiong@tp-link.net

 History:

 -----------------------------------------------

 v0.1，2015-7-29，hexiong create file and complete the function
 ************************************************************************/

#ifndef _ERROR_CODE_GEN_H
#define _ERROR_CODE_GEN_H

/* enum error code */
enum error_code
{
    RIGHT,                  /* ERROR: input is right */
    OVER_LENGTH,            /* ERROR: input is over length */
    INITIAL_LOWER,          /* ERROR: initial is not upper case*/
    CONTAIN_OTHER,          /* ERROR: input contains other character except letter*/
    NOT_ALL_LOWER           /* ERROR: Except initial,some letter is not lower case*/
};

#ifdef __cplusplus
extern "C" {
#endif

enum error_code Is_Over_Length(char *str);
enum error_code Is_Initial_Upper(char *str);
enum error_code Is_Contain_Other(char *str);
enum error_code Is_Other_Lower(char *str);
int Print_Result(int error_code);
void Test(char *str);

#ifdef __cplusplus
}
#endif

#endif
