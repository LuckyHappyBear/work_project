/*************************************************************************
 Copyright (C), 2015, TP-LINK TECHNOLOGIES CO., LTD.

 File Name:    main.c

 Description:  we test here

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
 Function:     create
 Description:  create n link list
 Input:        head[]: the head list
               n: the number of the link list you want to create
 Output:       None
 Return:       None
 Others:       None
 ***************************************************************/
void create(STU_NODE *head[], int n)
{
    /* loop variable */
    int i;

    /* stu number change from w8200 to w8209 */
    char base_num[20] = "w8200";

    /* student name change from 0HeXiong to 9HeXiong */
    char base_name[20] = "Hexiong0";

    /* head pointer */
    //STU_NODE *head[2] = {NULL,NULL};

    /* create node list */
    for (i = 0; i < 10  ; i++)
    {
        STU_NODE *new_node = (STU_NODE *)malloc(sizeof(STU_NODE));
        base_num[4] = (char)((int)base_num[4] + i);
        base_name[7] = (char)((int)base_name[7] + i);
        strncpy(new_node->student.stu_num, base_num, 20);
        strncpy(new_node->student.stu_name, base_name, 20);
        base_num[4] = '0';
        base_name[7] = '0';
        new_node->student.stu_sex = i % 2;
        new_node->student.stu_age = 18 + i;

        /* add to head */
        new_node->next = head[i % 2];
        head[i % 2] = new_node;
    }
}

int main()
{
    STU_NODE *head[2] = {NULL,NULL};
    /* create the link list */
    create(head, 2);

    printf("=====================Initial link list====================\n");
    /* print all node information */
    print_all_info(head[1]);

    printf("\n\n\n");

    /* sort the link list */
    head[1] = sort(head[1]);

    printf("=========================After sort=======================\n");
    /* print all node information */
    print_all_info(head[1]);

    printf("\n\n\n");

    printf("======================Delete node info====================\n");
    head[1] = del(head[1], "w8203");
    head[1] = del(head[1], "w8205");
    head[1] = del(head[1], "w8210");

    printf("\n\n\n");

    printf("========================After delete======================\n");
    print_all_info(head[1]);

    STU_NODE *new_node = (STU_NODE *)malloc(sizeof(STU_NODE));
    strcpy(new_node->student.stu_num, "w8203");
    strcpy(new_node->student.stu_name, "HeXiong");
    new_node->student.stu_sex = 1;
    new_node->student.stu_age = 35;
    head[1] = add(head[1], new_node);

    printf("\n\n\n");

    printf("=========================After add========================\n");
    print_all_info(head[1]);

    printf("=======================Before merge=======================\n");
    printf("#######################list1##########################\n");
    print_all_info(head[1]);

    printf("#######################list2##########################\n");
    print_all_info(head[0]);

    printf("========================After merge=======================\n");
    head[1] = merge(head[1], head[0]);
    print_all_info(head[1]);
    return 0;
}
