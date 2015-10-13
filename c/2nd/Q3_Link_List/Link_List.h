/*************************************************************************
 Copyright (C), 2015, TP-LINK TECHNOLOGIES CO., LTD.

 File Name:    Link_List.h

 Description:  operation in link list

 Author:       HeXiong

 Email:        hexiong@tp-link.net

 History:

 -----------------------------------------------
 v0.1,2015-8-4,hexiong create the file and complete the function
 ************************************************************************/

#ifndef _LINK_LIST_H
#define _LINK_LIST_H

#define MAX_STU_NUM_LEN 20
#define MAX_STU_NAME_LEN 20

struct STUDENT
{
    char stu_num[MAX_STU_NUM_LEN];          /* student number */
    char stu_name[MAX_STU_NAME_LEN];        /* student name */
    int stu_sex;                            /* student sex */
    int stu_age;                            /* student age */
};

/* rename struct STUDENT */
typedef struct STUDENT STU;

/* list node defination */
struct LIST_NODE
{
    struct LIST_NODE *next;
    STU student;
};

/* rename list node */
typedef struct LIST_NODE STU_NODE;

#ifdef __cplusplus
extern "C" {
#endif
/*****************************************************************
 Function:     print_info
 Description:  print the information of the node
 Input:        stu: the node you want to print
 Output:       no
 Return:       void
 others:       no
*****************************************************************/
void print_info(STU_NODE *stu);

/*****************************************************************
 Function:     print_all_info
 Description:  print the information of the node list
 Input:        head: the head of node list you want to print
 Output:       no
 Return:       void
 others:       no
*****************************************************************/
void print_all_info(STU_NODE *head);

/*****************************************************************
 Function:     add
 Description:  add the new node to the node list
 Input:        head: the head of the node list
               stu : the node you want to add
 Output:       no
 Return:       void
 others:       no
*****************************************************************/
STU_NODE *add(STU_NODE *head, STU_NODE *stu);

/*****************************************************************
 Function:     del
 Description:  input a student number,delete node has same number
 Input:        head: the head of the node
               student_number:the student number you want to delete
 Output:       no
 Return:       void
 others:       no
*****************************************************************/
STU_NODE *del(STU_NODE *head, char *student_number);

/*****************************************************************
 Function:     sort
 Description:  sort the node list with ascending order in
               student_number
 Input:        head: the head of the node list
 Output:       no
 Return:       void
 others:       no
*****************************************************************/
STU_NODE *sort(STU_NODE *head);

/*****************************************************************
 Function:     merge
 Description:  merge two list to one and in accending order
 Input:        head_one: the head of first node list
               head_two: the head of second node list
 Output:       no
 Return:       head
 others:       no
*****************************************************************/
STU_NODE *merge(STU_NODE *head_one, STU_NODE *head_two);
#ifdef __cplusplus
}
#endif
#endif
