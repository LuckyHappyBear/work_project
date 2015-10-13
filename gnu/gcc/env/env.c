/*************************************************************************
 Copyright (C), 2015, TP-LINK TECHNOLOGIES CO., LTD.

 File Name:    env.c

 Description:  print a environment variable and modify it

 Author:       HeXiong

 Email:        hexiong@tp-link.net

 History:

 -----------------------------------------------
 v0.1,2015-8-11,hexiong create the file and complete the function
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
extern char **environ;

/*****************************************************************
 Function:     print a environment variable
 Description:  print a specified environment variable
 Input:        var_nane: the name of the environment variable
 Output:       the value of the environment variable
 Return:       None
 Others:       None
*****************************************************************/
void print_env_var(char* var_name)
{
    /* record the value of the variable */
    char *value;

    /* get the value */
    value = getenv(var_name);

    if (value)
    {
        printf("**********The environment variable*********\n");
        printf("%s=%s\n", var_name, value);
    }
    else
    {
        printf("This environment variable doesn't exist\n");
    }

}

/*****************************************************************
 Function:     get a environment variable's value
 Description:  get a specified environment variable's value
 Input:        var_nane: the name of the environment variable
 Output:       None
 Return:       the value of the environment variable
 Others:       None
*****************************************************************/
char* get_env_value(char *var_name)
{
    /* record the value of the variable */
    char *value;

    /* get the value */
    value = getenv(var_name);

    if (value)
    {
        return value;
    }
    else
    {
        printf("This environment variable doesn't exist\n");
        return NULL;
    }
}

/*****************************************************************
 Function:     add a path of the environment variable
 Description:  add a path to a specified environment variable
 Input:        var_nane: the name of the environment variable
               path :  the path you want to add
 Output:       None
 Return:       None
 Others:       None
*****************************************************************/
void add_env_path(char *var_name, char* path)
{
    /* record the value of the variable */
    char *value;

    /* get the value */
    value = getenv(var_name);

    /* if this variable exist */
    if (value)
    {
        char* modify_var = malloc(sizeof(char)*(strlen(path) +
                         strlen(var_name) + strlen(value) + 3));
        memset(modify_var, 0, strlen(modify_var));

        strcat(modify_var, var_name);
        strcat(modify_var, "=");
        strcat(modify_var, value);
        strcat(modify_var, ";");
        strcat(modify_var, path);

        if (putenv(modify_var) == 0)
        {
            printf("Add successful\n");
        }
        else
        {
            printf("Add unsuccessfully\n");
            exit(1);
        }
    }
    /* if this variable doesn't exist we create it */
    else
    {
        char *new_var = malloc(sizeof(char)*(strlen(var_name)+
                                             strlen(path) + 2));
        strcat(new_var, var_name);
        strcat(new_var, "=");
        strcat(new_var, path);

        if (putenv(new_var) == 0)
        {
            printf("Add new environment variable successfully\n");
        }
        else
        {
            printf("Add new environment variable unsuccessfully\n");
            exit(2);
        }
    }
}
