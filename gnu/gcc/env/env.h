/*************************************************************************
 Copyright (C), 2015, TP-LINK TECHNOLOGIES CO., LTD.

 File Name:    env.h

 Description:  print a environment variable and modify it

 Author:       HeXiong

 Email:        hexiong@tp-link.net

 History:

 -----------------------------------------------
 v0.1,2015-8-11,hexiong create the file and complete the function
 ************************************************************************/

#ifndef _ENV_H
#define _ENV_H

#ifdef __cpluscplus
extern "C" {
#endif
/*****************************************************************
 Function:     print a environment variable
 Description:  print a specified environment variable
 Input:        var_nane: the name of the environment variable
 Output:       the value of the environment variable
 Return:       None
 Others:       None
*****************************************************************/
void print_env_var(char* var_name);

/*****************************************************************
 Function:     get a environment variable's value
 Description:  get a specified environment variable's value
 Input:        var_nane: the name of the environment variable
 Output:       None
 Return:       the value of the environment variable
 Others:       None
*****************************************************************/
char* get_env_value(char *var_name);

/*****************************************************************
 Function:     add a path of the environment variable
 Description:  add a path to a specified environment variable
 Input:        var_nane: the name of the environment variable
               path :  the path you want to add
 Output:       None
 Return:       None
 Others:       None
*****************************************************************/
void add_env_path(char *var_name, char* path);
#ifdef __cpluscplus
}
#endif

#endif
