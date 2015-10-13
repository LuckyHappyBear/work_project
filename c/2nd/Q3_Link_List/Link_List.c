/*************************************************************************
 Copyright (C), 2015, TP-LINK TECHNOLOGIES CO., LTD.

 File Name:    Link_List.c

 Description:  operation in link list

 Author:       HeXiong

 Email:        hexiong@tp-link.net

 History:

 -----------------------------------------------
 v0.1,2015-8-4,hexiong create the file and complete the function
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Link_List.h"

/*****************************************************************
 Function:     print_info
 Description:  print the information of the node
 Input:        stu: the node you want to print
 Output:       no
 Return:       void
 others:       no
*****************************************************************/
void print_info(STU_NODE *stu)
{
    /*print information of the student*/
    printf("***************************************************\n");
    printf("The information of the student\n");
    printf("student number:%s\n", stu->student.stu_num);
    printf("student name  :%s\n", stu->student.stu_name);
    printf("student age   :%d\n", stu->student.stu_age);
    printf("student sex(0 means female,1 means male):%d\n",
           stu->student.stu_sex);
    printf("***************************************************\n");

    return;
}

/*****************************************************************
 Function:     print_all_info
 Description:  print the information of the node list
 Input:        head: the head of node list you want to print
 Output:       no
 Return:       void
 others:       no
*****************************************************************/
void print_all_info(STU_NODE *head)
{
    STU_NODE *p = head;
    while (p != NULL)
    {
        print_info(p);
        p = p->next;
    }
    return;
}

/*****************************************************************
 Function:     add
 Description:  add the new node to the node list
 Input:        head: the head of the node list
               stu : the node you want to add
 Output:       no
 Return:       void
 others:       no
*****************************************************************/
STU_NODE *add(STU_NODE *head, STU_NODE *stu)
{
    if (head == NULL)
    {
        head = stu;
        return head;
    }
    else
    {
        STU_NODE *p = head;
        if (strcmp(p->student.stu_num, stu->student.stu_num) > 0 )
        {
            stu->next = head;
            head = stu;
            return head;
        }
        else
        {
            /* loop to find place */
            while (p->next != NULL)
            {
                if (strcmp(p->student.stu_num, stu->student.stu_num) < 0 &&
                    strcmp(p->next->student.stu_num, stu->student.stu_num) > 0)
                {
                    stu->next = p->next;
                    p->next = stu;
                    return head;
                }
                else
                {
                    p = p->next;
                }
            }

            /* p->next is NULL*/
            stu = p->next;
            p->next = stu;
            return head;
        }
    }
}

/*****************************************************************
 Function:     del
 Description:  input a student number,delete node has same number
 Input:        head: the head of the node
               student_number:the student number you want to delete
 Output:       no
 Return:       void
 others:       no
*****************************************************************/
STU_NODE *del(STU_NODE *head, char* student_number)
{
    /* delete the first node */
    if (strcmp(head->student.stu_num, student_number) == 0)
    {
        STU_NODE *p = head;
        head = head->next;

        print_info(p);
        free(p);
        return head;
    }
    else
    {
        STU_NODE *q = head;
        STU_NODE *p = q->next;

        while (p != NULL)
        {
            if (strcmp(p->student.stu_num, student_number) == 0)
            {
                print_info(p);
                q->next = p->next;
                free(p);
                return head;
            }
            else
            {
                q = q->next;
                p = q->next;
            }
        }
        /* we can't find the student */
        printf("This student doesn't exist\n");
        return head;
    }
}

/*****************************************************************
 Function:     sort
 Description:  sort the node list with ascending order in
               student_number
 Input:        head: the head of the node list
 Output:       no
 Return:       void
 others:       no
*****************************************************************/
STU_NODE *sort(STU_NODE *head)
{
    STU_NODE *temp_head = head;

    /* loop variable */
    STU_NODE *p = temp_head;

    head = NULL;
    while (p != NULL)
    {
        /* use function add to reorder the list */
        STU_NODE *new_node = (STU_NODE *)malloc(sizeof(STU_NODE));
        strncpy(new_node->student.stu_num, p->student.stu_num, 20);
        strncpy(new_node->student.stu_name, p->student.stu_name, 20);
        new_node->student.stu_sex = p->student.stu_sex;
        new_node->student.stu_age = p->student.stu_age;

        head = add(head, new_node);
        STU_NODE *freeNode = p;
        p = p->next;
        free(freeNode);
    }
    return head;
}

/*****************************************************************
 Function:     merge
 Description:  merge two list to one and in accending order
 Input:        head_one: the head of first node list
               head_two: the head of second node list
 Output:       no
 Return:       head
 others:       no
 ***************************************************************/
 STU_NODE *merge(STU_NODE *head_one, STU_NODE *head_two)
 {
    STU_NODE *p = head_two;
    while (p != NULL)
    {
        STU_NODE *new_node = (STU_NODE *)malloc(sizeof(STU_NODE));
        strncpy(new_node->student.stu_num, p->student.stu_num, 20);
        strncpy(new_node->student.stu_name, p->student.stu_name, 20);
        new_node->student.stu_sex = p->student.stu_sex;
        new_node->student.stu_age = p->student.stu_age;

        head_one = add(head_one, new_node);
        STU_NODE *freeNode = p;
        p = p->next;
        free(freeNode);
    }
    return head_one;
 }
