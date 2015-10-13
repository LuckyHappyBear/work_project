/*************************************************************************
 Copyright (C), 2015, TP-LINK TECHNOLOGIES CO., LTD.

 File Name:    main.c

 Description:  test here

 Author:       HeXiong

 Email:        hexiong@tp-link.net

 History:

 -----------------------------------------------
 v0.1,2015-8-2,hexiong create the file and complete the function
 ************************************************************************/

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>
#include "Get_Prime_Number.h"

int main()
{
    /* upper bound */
    int n;

    /* the start time of function and the end time of function */
    clock_t start,end;

    /* the total time of function excute */
    double total;

    /* the number of prime */
    int number_of_prime;
    printf("Please input the upper bound n"
           "(we will output the number of prime from 0 to n):");
    scanf("%d",&n);
    int *prime = malloc(sizeof(int) * (n + 1));

    start = clock();
    number_of_prime = getPrimeNumber(n,prime,n);
    end = clock();
    total = ((double)(end - start) / CLOCKS_PER_SEC) * 1000;

    if (number_of_prime == -1)
    {
        printf("input error\n");
    }
    else
    {
        printf("The number of the primes is %d\n",number_of_prime);
        printf("The total time of the function excute is %fms\n",total);
    }

    free(prime);
    return 0;
}
