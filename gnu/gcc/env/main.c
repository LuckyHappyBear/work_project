/*************************************************************************
 Copyright (C), 2015, TP-LINK TECHNOLOGIES CO., LTD.

 File Name:    main.c

 Description:  we test here

 Author:       HeXiong

 Email:        hexiong@tp-link.net

 History:

 ----------------------------------------------------------------
 v0.1,2015-8-11,hexiong create the file and complete the function
 ************************************************************************/

#include <stdio.h>
#include "env.h"

/* Anwser the question:
   this modified environment variable is only effective in this program,
   because this variable's value will not transfer from subprocess(this
   program) to parent process(shell).Therefore,in this program,we can see
   the change,but in the shell,the change missed.*/

int main()
{
    /* give a variable name */
    char var_name[] = "HOME";

    char path[] = "/bin/bash";

    /* print the variable */
    print_env_var(var_name);

    /* get the value of the variable */
    char *var_value = get_env_value(var_name);

    /* add a path */
    add_env_path(var_name, path);

    /* print the variable again */
    print_env_var(var_name);

    return 0;
}
