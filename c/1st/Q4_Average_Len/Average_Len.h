/*************************************************************************
 Copyright (C), 2015, TP-LINK TECHNOLOGIES CO., LTD.

 File Name:    Average_Len.h

 Description:  extract words from a sentence and count the average length

 Author:       HeXiong

 Email:        hexiong@tp-link.net

 History:

 -----------------------------------------------
 v0.1,2015-7-30,hexiong create file and complete the function
 ************************************************************************/

#ifndef _AVERAGE_LEN_H
#define _AVERAGE_LEN_H

#ifdef __cplusplus
extern "C" {
#endif

int Find_First(const char* sentence);
int Find_Last(const char* sentence);
int isValid(const char* sentence, int start, int end);
int getAverageLen(const char* sentence);

#ifdef __cplusplus
}
#endif

#endif
