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
        
    }
    

}

int32_t  arr_G[] = {2,1,4,-49,8,6,28,-13,-48,11};

int main(int argc, char const *argv[])
{
    

    for (int i = 0; i < sizeof (arr_G) / sizeof(uint32_t); i++)
    {
        printf("%d", arr_G[i]);
        printf(",");
    }
   
    printf("\n\n\n");
   
    sort_merge(arr_G, sizeof (arr_G) / sizeof(uint32_t));  

    for (int i = 0; i < sizeof (arr_G) / sizeof(uint32_t); i++)
    {
        printf("%d", arr_G[i]);
        printf(",");

    }
    
    printf("\n\n\n");

    return 0;
}
