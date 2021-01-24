/**
 * @file sort_merge.c
 * @author ihsangokhun (onel.gokhun@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2021-01-23
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "stdlib.h"
#include "stdint.h"
#include "stdio.h"


void swap(int32_t *val1, int32_t *val2)
{
 int32_t temp = *val1;
 *val1 = *val2;
 *val2 = temp;
}

void partition_sort(int32_t * arr1, uint32_t len1, int32_t *arr2, uint32_t len2 )
{
    int32_t *p_arr1 = (int32_t * ) arr1;
    int32_t *p_arr2 = (int32_t * ) arr2;
    int32_t  tmp = 0;
    uint32_t pos1 = 0;
    uint32_t pos2 = 0;
    
    
    for (uint32_t i = 0; i < len1; i++)
    {   
        for (uint32_t k = 0; k < len2; k++)
            {       
               if (*(p_arr1 + i) > *(p_arr2 + k))
                    {
                        swap(p_arr1, p_arr2);
                        break;
                   }
            }        
    }   
}

void sort_merge(void *arr, uint32_t len )
{
    uint32_t n = 2 ;
    uint32_t step = 1 ;

    if ( len%2 == 0 )
    {
      while ( (uint32_t)(len / n) > 1 )
      {
         for (int i = 0; i < len / n ; i++)
        {
            partition_sort((int32_t*) arr, (n / 2), (int32_t*)(arr + (n / 2 )* (sizeof(int32_t))) , (n / 2));
            step++;
        }
        n *=2;     
        step = 0;
      }  
    }
    else
    {   
        return; // ToDo 
    }

}
