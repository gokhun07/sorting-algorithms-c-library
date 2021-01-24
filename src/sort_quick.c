/**
 * @file sort_quick.c
 * @author ihsangokhun (onel.gokhun@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2021-01-23
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include "stdlib.h"
#include "stdio.h"
#include "stdint.h"

void swap(int32_t *arr,uint32_t index1, uint32_t index2)
{
    int32_t temp = *(arr + index1);
    *(arr + index1) = *(arr + index2);
    *(arr + index2) = temp;
}

uint32_t partition(int32_t *arr, uint32_t right, uint32_t left, int32_t pivot)
{

    while (right>left)
    {
        while (*(arr+left) < pivot)
        {
            left++;
        }
        
        while (*(arr+right) > pivot)
        {
            right--;    
        }

        if (right >= left)
            swap(arr, left,right);
       
        if (right > 0 )
        {
            right--;
            left++;

        }
    }
    
    return left;
    

}
static int first_piv = -1;

void _quick_sort(int32_t *arr, uint32_t right, uint32_t left, uint8_t phase)
{

    if (left >= right)
    {
        return;
    }
    
    int32_t pivot = *(arr + (right + left) / 2 );
    uint32_t index = 0; // index of the pivot 

    index = partition(arr, right, left, pivot);
    if (first_piv == -1 )
    {
        first_piv = index;
    }
    
    if (phase == 1)
    _quick_sort(arr, index, left, 1 );
    else
    _quick_sort(arr, right, index,0 );

}

void quick_sort(int32_t *arr, uint32_t right, uint32_t left)
{
    _quick_sort(arr,right,left, 1);
    _quick_sort(arr,right,first_piv,0);
    first_piv = -1;

}
