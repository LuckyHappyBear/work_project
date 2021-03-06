/******************************************************************************
  Copyright (C), 1996-2011, TP_LINK TECHNOLOGIES CO., LTD.

  File name:   cgic_local.h

  Description: Teamwork, CGI model. local function.

  Author:      Chenjiaxin

  History:
  ----------------------------------------------------------------------------

	V1.0, 2015-09-29, Chen Jiaxin		Create file.
*****************************************************************************/
#include "cgic_local.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>

#define CGIC_LOCAL_TEST 0

#define MAX_FILE       100
#define MAX_COMMAND    100

/* buffer length */
#define MAX_IMSI       20
#define MAX_PRODUCT_ID 20
#define MAX_SERVER_IP  20
/* Constraint length */
#define LEN_IMSI       15 /* must less than MAX_IMSI */
#define LEN_PRODUCT_ID 8  /* must less than MAX_PRODUCT_ID */

#define SERVER_IP_DEFAULT "192.168.0.100"
#define SERVER_IP_FILE    "/app/config/backup.conf"

static char imsi[MAX_IMSI] = {0};
static char product_id[MAX_PRODUCT_ID] = {0};
static char server_ip[MAX_SERVER_IP] = {0};

/******************************************************************************
  Function:    cgi_pack
  Description: pack file or folder.
  Input:
    (1)srcfolder: The absolute path of the source file/folder's folder
    (2)srcname  : The name of the source file/folder name.
    (3)dstfile  : The absolute path of the destination file
  Output:
  Return: 0 for succeed, -1 for fail.
  Others:
*******************************************************************************/
int cgi_pack(const char *srcfolder, const char *srcname, const char *dstfile)
{
    /* Check the input */
    if ( ( NULL == srcfolder ) || ( NULL == srcname ) || ( NULL == dstfile ) )
    {
        return -1;
    }

    /* Check the file existence */
    char srcfile[MAX_FILE];
    memset(srcfile, 0, MAX_FILE);
    strcat(srcfile, srcfolder);
    if ( '/' != srcfile[ strlen(srcfile) - 1 ] )
    {
        srcfile[strlen(srcfile)] = '/';
    }
    strcat(srcfile, srcname);
#if CGIC_LOCAL_TEST
    printf("srcfile: %s\n", srcfile);
#endif
    if ( -1 == access(srcfile, F_OK) )
    {
#if CGIC_LOCAL_TEST
        perror("No file to pack");
#endif
        return -1;
    }

    char command[MAX_COMMAND];
    memset(command, 0, MAX_COMMAND);
#if CGIC_LOCAL_TEST
    strcat(command, "tar -cf");
#else
    strcat(command, "busybox tar -cf ");
#endif
    strcat(command, dstfile);
    strcat(command, " -C ");
    strcat(command, srcfolder);
    strcat(command, " ");
    strcat(command, srcname);

    system(command);
    return 0;
}
/******************************************************************************
  Function:    cgi_unpack
  Description: unpack file
  Input:
    (1)srcfile  : The absolute path of the source file
    (2)dstfolder: The absolute path of the destination file's folder
  Output:
  Return: 0 for succeed, -1 for fail.
  Others:
*******************************************************************************/
int cgi_unpack(const char *srcfile, const char *dstfolder)
{
    /* Check the input */
    if ( ( NULL == srcfile ) || ( NULL == dstfolder ) )
    {
        return -1;
    }

    /* Check the file existence */
    if ( 0 != access(srcfile, F_OK) )
    {
#if CGIC_LOCAL_TEST
        printf("No file to unpack: %s\n", srcfile);
#endif
        return -1;
    }
    if ( 0 != access(dstfolder, F_OK) )
    {
#if CGIC_LOCAL_TEST
        printf("No dstfolder to unpack: %s\n", dstfolder);
#endif
        return -1;
    }

    char command[MAX_COMMAND];
    memset(command, 0, MAX_COMMAND);
#if CGIC_LOCAL_TEST
    strcat(command, "tar -xf");
#else
    strcat(command, "busybox tar -xf ");
#endif
    strcat(command, srcfile);
    strcat(command, " -C ");
    strcat(command, dstfolder);

    system(command);
    return 0;
}
/******************************************************************************
  Function:    cgi_rmfile
  Description: remove file
  Input:
    (1)folder: The absolute path of the source file's folder
    (2)name  : The name of the source file's name.
  Output:
  Return: 0 for succeed, 1 for fail.
  Others:
*******************************************************************************/
int cgi_rmfile(const char *file)
{
    /* Check the input */
    if ( NULL == file )
    {
        return -1;
    }

    /* Check the file existence */
    if ( 0 != access(file, F_OK) )
    {
#if CGIC_LOCAL_TEST
        printf("No file to remove: %s\n", file);
#endif
        return 0;
    }

    struct stat fileinfo;
    stat(file, &fileinfo);
    char command[MAX_COMMAND];
    memset(command, 0, MAX_COMMAND);

    /* If the file is a folder */
    if ( S_ISDIR(fileinfo.st_mode) )
    {
        strcat(command, "rm -rf ");
    }
    else
    {
        strcat(command, "rm -f ");
    }
    strcat(command, file);

    system(command);
    return 0;
}
/******************************************************************************
  Function:    cgi_mvfile
  Description: move file from src to dst
  Input:
    (1)srcfile  : The absolute path of the source file
    (2)dstfolder: The absolute path of the destination file's folder
  Output:
  Return: 0 for succeed, 1 for fail.
  Others:
*******************************************************************************/
int cgi_mvfile(const char *srcfile, const char *dstfolder)
{
    /* Check the input */
    if ( ( NULL == srcfile ) || ( NULL == dstfolder ) )
    {
        return -1;
    }

    /* Check the file existence */
    if ( 0 != access(srcfile, F_OK) )
    {
#if CGIC_LOCAL_TEST
        printf("No file to move: %s\n", srcfile);
#endif
        return -1;
    }
    if ( 0 != access(dstfolder, F_OK) )
    {
#if CGIC_LOCAL_TEST
        printf("No dstfolder for file to move: %s\n", dstfolder);
#endif
        return -1;
    }

    char command[MAX_COMMAND];
    memset(command, 0, MAX_COMMAND);

#if CGIC_LOCAL_TEST
    strcat(command, "mv ");
#else
    strcat(command, "busybox mv ");
#endif
    strcat(command, srcfile);
    strcat(command, " ");
    strcat(command, dstfolder);

    system(command);
    return 0;
}
/******************************************************************************
  Function:    cgi_get_imsi
  Description: return the ISMI buffer, if the buffer store nothing, return NULL.
  Input:
  Output:
  Return: The string storing the imsi.
  Others:
*******************************************************************************/
char *cgi_get_imsi(void)
{
    memset(imsi, 0, MAX_IMSI);

    /* Get the imsi */
#if CGIC_LOCAL_TEST
    memset(imsi, 65, 8);
#else
    FILE *fp = NULL;
    fp = popen("uci get sim.common_state.imsi", "r");
    if ( NULL == fp )
    {
        return NULL;
    }
    memset(imsi, 0, MAX_IMSI);
    fread(imsi, sizeof(char), MAX_IMSI - 1, fp);
    pclose(fp);

    /* Replace the newline character */
    char *pnewline = strchr(imsi, '\n');
    if ( pnewline )
    {
        *pnewline = '\0';
    }

    /* Constrain the length of imsi */
    imsi[LEN_IMSI] = '\0';
#endif

    if ( 0 == strlen(imsi) )
    {
        return NULL;
    }
    else
    {
        return imsi;
    }
}
/******************************************************************************
  Function:    cgi_get_product_id
  Description: return the product id, if the buffer store nothing, return NULL.
  Input:
  Output:
  Return: The string storing the product id.
  Others:
*******************************************************************************/
char *cgi_get_product_id(void)
{
    memset(product_id, 0, MAX_PRODUCT_ID);

    /* Get the product id */
#if CGIC_LOCAL_TEST
    memset(product_id, 66, 8);
#else
    FILE *fp = NULL;
    fp = popen("uci get product.info.product_id", "r");
    if ( NULL == fp )
    {
        return NULL;
    }
    memset(product_id, 0, MAX_PRODUCT_ID);
    fread(product_id, sizeof(char), MAX_PRODUCT_ID - 1, fp);
    pclose(fp);

    /* Replace the newline character */
    char *pnewline = strchr(product_id, '\n');
    if ( pnewline )
    {
        *pnewline = '\0';
    }

    /* Constrain the length of product id */
    product_id[LEN_PRODUCT_ID] = '\0';
#endif

    if ( 0 == strlen(product_id) )
    {
        return NULL;
    }
    else
    {
        return product_id;
    }
}
/******************************************************************************
  Function:    cgi_setip
  Description: set the server ip
  Input:
    (1)ip: The ip to be set
  Output:
  Return: 0 for succeed, -1 for fail
  Others:
*******************************************************************************/
int cgi_setip(const char *ip)
{
    /* Check the input */
    if ( ( NULL == ip ) || ( 0 == strlen(ip) ) )
    {
        return -1;
    }

    /* open the file */
    FILE *fp = NULL;
    fp = fopen(SERVER_IP_FILE, "w");

    /* if create the file fails */
    if ( NULL == fp )
    {
        return -1;
    }
    else
    {
        fwrite(ip, sizeof(char), strlen(ip), fp);
        fclose(fp);
        return 0;
    }
}
/******************************************************************************
  Function:    cgi_getip
  Description: return the server ip
  Input:
  Output:
  Return: The string storing the server ip
  Others:
*******************************************************************************/
char *cgi_getip(void)
{
    /* If the config file does not exist, create the file and set the default ip*/
    if ( 0 != access(SERVER_IP_FILE, F_OK) )
    {
#if CGIC_LOCAL_TEST
        puts("No file to getip");
#endif
        memset(server_ip, 0, MAX_SERVER_IP);
        strcpy(server_ip, SERVER_IP_DEFAULT);

        /* create the file */
        FILE *fp = NULL;
        fp = fopen(SERVER_IP_FILE, "w");
        /* if create the file fails, just return the default ip */
        if ( NULL == fp )
        {
            return server_ip;
        }
        else
        {
            fwrite(server_ip, sizeof(char), strlen(server_ip), fp);
            fclose(fp);
            return server_ip;
        }
    }
    /* file exists: 0 == access(SERVER_IP_FILE, F_OK) */
    else
    {
#if CGIC_LOCAL_TEST
        puts("File to getip");
#endif
        FILE *fp = NULL;
        fp = fopen(SERVER_IP_FILE, "r");
        /* If config file open fails */
        if ( NULL == fp )
        {
            return NULL;
        }
        else
        {
            memset(server_ip, 0, MAX_SERVER_IP);
            int iplen = fread(server_ip, sizeof(char), MAX_SERVER_IP, fp);
            if ( iplen > 15 )
            {
#if CGIC_LOCAL_TEST
                puts("Server ip length error");
#endif
                return NULL;
            }
            else
            {
                fclose(fp);
                return server_ip;
            }
        }
    }
}
