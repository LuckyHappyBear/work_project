/*************************************************************************
 Copyright (C), 2015, TP-LINK TECHNOLOGIES CO., LTD.

 File Name:    Search_Dup.h

 Description:  find reduplicate element from an array

 Author:       HeXiong

 Email:        hexiong@tp-link.net

 History:

 -----------------------------------------------
 v0.1,2015-8-3,hexiong create the file and complete the function
 ************************************************************************/

#ifndef _SEARCH_DUP_H
#define _SEARCH_DUP_H

#ifdef __cplusplus
extern "C" {
#endif
/*****************************************************************
 Function:     searchDup
 Description:  find a reduplicate element from an array
 Input:        a[]: the array we will handle
               n:   the length of the array
 Output:       None
 Return:       the reduplicate number
 others:       None
*****************************************************************/
int searchDup(int a[], int n);

/*****************************************************************
 Function:     searchDupImprove
 Description:  find a reduplicate element from an array(better idea)
 Input:        a[]: the array we will handle
               n:   the length of the array
 Output:       None
 Return:       the reduplicate number
 others:       None
*****************************************************************/
int searchDupImprove(int a[], int n);
#ifdef __cplusplus
}
#endif

#endif
