
/**
 * @file sort_insertion.c
 * @author ihsangokhun (onel.gokhun@gmail.com)
 * @brief it is used in order to sort a given array according to the Insertion Sort algorithm 
 * @version 0.1
 * @date 2021-01-10
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "stdlib.h"
#include "stdio.h"
#include "stdint.h"

/**
 * @brief sort the array by using the Insertion Sort algorithm 
 * 
 * @param arr array to be sorted
 * @param len  the number of the element in the array 
 */
void sort_insertion(void *arr, uint32_t len)
{
    int32_t *arr_ptr = (int32_t *) arr;
    int32_t iterator1 = 0;
    int32_t iterator2 = 0;
    int32_t temp=0;

    for (iterator1 = 1; iterator1 < len ; iterator1++)
    {
        for (iterator2 = iterator1 ; iterator2 > 0; iterator2--)
        {
                if (*(arr_ptr + iterator2) < *(arr_ptr + iterator2  - 1 ))
                {
                    temp = *(arr_ptr + iterator2 - 1);
                    *(arr_ptr + iterator2 - 1) = *(arr_ptr + iterator2);
                    *(arr_ptr + iterator2) = temp;
                }
        }       
    }
 }

