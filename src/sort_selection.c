/**
 * @file sort_selection.c
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


void sort_selection(void *arr, uint32_t len)
{
    int32_t *arr_ptr = (int32_t *) arr;
    uint32_t it1 = 0;
    uint32_t it2 = 0;
    int32_t  min = 0;
    int32_t temp = 0 ;
    uint32_t loc = 0;


    for (it1 = 0; it1 < len; it1++)
    {
        min = (*(arr_ptr + it1));

        for ( it2 = it1; it2 < len ; it2++)
        {
            if ( *(arr_ptr + it2 ) < min )
            {
                min = *(arr_ptr + it2 );
                loc = it2;
            }
        }
        
        *(arr_ptr + loc ) = *(arr_ptr + it1);
        *(arr_ptr + it1) = min;                   
    }
    

}

