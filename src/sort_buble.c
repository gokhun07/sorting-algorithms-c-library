/**
 * @file sort_buble.c
 * @author ihsangokhun (onel.gokhun@gmail.com)
 * @brief  it sort a given array according to the Buble sorting algorithm 
 * @version 0.1
 * @date 2021-01-10
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "stdio.h"
#include "stdlib.h"
#include "stdint.h"

/**
 * @brief swaps the given values 
 * 
 * @param val1 
 * @param val2 
 */
void swap(int32_t *val1, int32_t *val2)
{
    int32_t temp = *val1;
    *val1 = *val2;
    *val2 = temp;
}
/**
 * @brief sorts the given array according to bubble sorting algorithm 
 * 
 * @param arr the array to be sorted 
 * @param len  length of the array 
 */
void sort_bubble(void *arr, uint32_t len)
{
    uint16_t it1 = 0;
    uint16_t it2 = 0;
    int32_t *arr_p = (int32_t *) arr;

    for (it1 = 0; it1 < len; it1++)
    {
        for (it2 = 0; it2 < len - 1; it2++)
        {
            if (*(arr_p + it2) > *(arr_p + it2 + 1))
            {
                swap((arr_p + it2), (arr_p + it2+1));
            }
        }        
    }   
}
