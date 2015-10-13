/*************************************************************************
 Copyright (C), 2015, TP-LINK TECHNOLOGIES CO., LTD.

 File Name:    Str_N_Str.h

 Description:  search str1 first appear pos in first n characters of str2

 Author:       HeXiong

 Email:        hexiong@tp-link.net

 History:

 -----------------------------------------------
 v0.1,2015-8-3,hexiong create the file and complete the function
 ************************************************************************/

#ifndef _STR_N_STR_H
#define _STR_N_STR_H

#ifdef __cplusplus
extern "C" {
#endif
/*****************************************************************
 Function:     strnstr
 Description:  find str1 first appear position in first n
               characters of str2
 Input:        haystack: search in this string
               needle: search needle in haystack
               n: we just search in first n characters of str2
 Output:       None
 Return:       the pointer of the first appear position
 others:       None
*****************************************************************/
char* strnstr(const char* haystack, const char* needle, size_t n);
#ifdef __cplusplus
}
#endif

#endif
