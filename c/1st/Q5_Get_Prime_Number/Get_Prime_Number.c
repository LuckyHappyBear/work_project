/*************************************************************************
 Copyright (C), 2015, TP-LINK TECHNOLOGIES CO., LTD.

 File Name:    Get_Prime_Number.c

 Description:  find all prime numbers between 0~n

 Author:       HeXiong

 Email:        hexiong@tp-link.net

 History:

 -----------------------------------------------
 v0.1,2015-7-31,hexiong create file and complete the function
 ************************************************************************/

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include "Get_Prime_Number.h"

/*****************************************************************
  Function:     getPrimeNumber
  Description:  find all prime number between 0~n
  Input:        n: the upper bound n
                prime[]:  an array prime[] store the result
                arr_size: the array size arr_size
  Output:       no
  Return:       the number of the prime numbers between 0~n
  others:       no
******************************************************************/
int getPrimeNumber(const int n, unsigned int prime[], const int arr_size)
{
    if (n <= 0)
        return -1;

    /* loop variable */
    int i,j;

    /* amount of prime number */
    int num_of_prime = 0;

    /* array elements which index is odd number is 1
       array elements which index is even number is 0 */
    for (i = 1; i <= n; i += 2)
    {
        prime[i] = 1;
    }

    for (i = 0; i <= n; i += 2)
    {
        prime[i] = 0;
    }

    /* 2 is prime number */
    prime[2] = 1;

    /* prime number's multiple isn't prime number */
    for (i = 3; i <= sqrt(n); i++)
    {
        if (prime[i])
        {
            for (j = i + i; j < n;j += i)
            {
                prime[j] = 0;
            }
        }
    }
    /* count the number of prime number */
    for (i = 2; i <= n; i++)
    {
        if (prime[i])
        {
            /*if (num_of_prime != 0 && num_of_prime % 7 == 0)
            {
                printf("\n");
            }
            printf("%d ",i);*/
            num_of_prime++;
        }
    }

    return num_of_prime;
}
