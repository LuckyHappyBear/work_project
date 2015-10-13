/*************************************************************************
 Copyright (C), 2015, TP-LINK TECHNOLOGIES CO., LTD.

 File Name:    Average_Len.c

 Description:  extract words from a sentence and count the average length

 Author:       HeXiong

 History:

 -----------------------------------------------
 v0.1,2015-7-30,hexiong create the file and complete the function
 ************************************************************************/

#include <stdio.h>
#include <string.h>
#include "Average_Len.h"

/*****************************************************************
  Function:     Find_First
  Description:  find the first character in sentence except space
  Input:        sentence: a string will be checked
  Output:       no
  Return:       return the pos of first no space character
  Others:       no
******************************************************************/

int Find_First(const char* sentence)
{
    /* get the length of sentence */
    int length = strlen(sentence);
    int i = 0;

    while (sentence[i] == ' ' && i < length - 1)
    {
        i++;
    }

    return i;
}

/*****************************************************************
  Function:     Find_Last
  Description:  find the last character in sentence except space
  Input:        sentence: a string will be checked
  Output:       no
  Return:       return the pos of last no space character
  Others:       no
******************************************************************/
int Find_Last(const char* sentence)
{
    /* get the length of sentence */
    int length = strlen(sentence);
    int i = length - 1;

    while (sentence[i] == ' ' && i > 0)
    {
        i--;
    }

    return i;
}

/*****************************************************************
  Function:     isValid
  Description:  juage the string is valid or not
  Input:        sentence: a string will be checked
                int start: start pos
                int end: end pos
  Output:       no
  Return:       return 0 or 1,1 means valid,0 means invalid
  Others:       no
******************************************************************/
int isValid(const char* sentence, int start, int end)
{
    /* loop variable */
    int i;
    for (i = start; i < end; i++)
    {
        if ((sentence[i] >= 'a' && sentence[i] <= 'z') ||
            (sentence[i] >= 'A' && sentence[i] <= 'Z') ||
            (sentence[i] == ' '))
        {
            /* valid letter */
        }
        else
        {
            return 0;
        }
    }

    /* test the last bit is . or letter */
    if ((sentence[end] == '.') ||
        (sentence[end] >= 'a' && sentence[end] <= 'z') ||
        (sentence[end] >= 'A' && sentence[end] <= 'Z'))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}


/*****************************************************************
  Function:     getAverageLen
  Description:  get the average length of words
  Input:        sentence: a const string used to be count
  Output:       no
  Return:       return the average value
  Others:       no
******************************************************************/
int getAverageLen(const char* sentence)
{
    /* get the length of the sentence */
    int length = strlen(sentence);
    /* find first character except space */
    int first_character_pos = Find_First(sentence);

    /* find last character except space */
    int last_character_pos = Find_Last(sentence);

    /* loop variable */
    int i;

    /* number of letter */
    int num_of_letter = 0;

    /* number of words */
    int num_of_word = 1;

    /* sentece valid and then count average */
    if (isValid(sentence,first_character_pos,last_character_pos))
    {
        for (i = first_character_pos; i < last_character_pos; i++)
        {
            if ((sentence[i] >= 'a' && sentence[i] <= 'z') ||
                (sentence[i] >= 'A' && sentence[i] <= 'Z'))
            {
                num_of_letter++;
            }
            else
            {
                while (sentence[i + 1] == ' ' &&
                       (i + 1) < last_character_pos)
                {
                    i++;
                }

                if (sentence[i + 1] != '.' && sentence[i + 1] != ' ')
                {
                    num_of_word++;
                }
            }
        }

        /* if last bit is letter,num_of_letter + 1,else unchange */
        if (sentence[i] == '.')
        {
            return num_of_letter / num_of_word;
        }
        else
        {
            num_of_letter++;
            return (num_of_letter) / num_of_word;
        }
    }
    else
    {
        return 0;
    }
}

