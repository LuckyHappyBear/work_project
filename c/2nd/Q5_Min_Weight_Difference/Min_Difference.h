/*************************************************************************
 Copyright (C), 2015, TP-LINK TECHNOLOGIES CO., LTD.

 File Name:    Min_Difference.h

 Description:  merge n stones to two piles,get min weight difference

 Author:       HeXiong

 Email:        hexiong@tp-link.net

 History:

 -----------------------------------------------
 v0.1,2015-8-6,hexiong create the file and complete the function
 ************************************************************************/

#ifndef _MIN_DIFFERENCE_H
#define _MIN_DIFFERENCE_H

#ifdef __cplusplus
extern "C" {
#endif
/*****************************************************************
 Function:     get_min_difference
 Description:  merge n stones to two piles,get min weight difference
 Input:        n:the number of stones
	       weights[]: store every stone's weight
 Output:       None
 Return:       the difference of the two piles weight
 Others:       None
*****************************************************************/
int get_min_difference(int weights[], int n);
#ifdef __cplusplus
}
#endif

#endif
