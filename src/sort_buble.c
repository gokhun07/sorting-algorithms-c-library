#include "stdio.h"
#include "stdlib.h"
#include "stdint.h"

void swap(int32_t *val1, int32_t *val2)
{
 int32_t temp = *val1;
 *val1 = *val2;
 *val2 = temp;
}

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


int main(int argc, char const *argv[])
{
    
    int32_t  arr[] = {49,1,2,4,8,6,28,-13,-48,11,5};

    for (int i = 0; i < sizeof (arr) / sizeof(uint32_t); i++)
    {
        printf("%d", arr[i]);
        printf(",");
    }
   
    printf("\n\n\n");
    sort_bubble(arr, sizeof (arr) / sizeof(uint32_t));  

    for (int i = 0; i < sizeof (arr) / sizeof(uint32_t); i++)
    {
        printf("%d", arr[i]);
        printf(",");

    }
    printf("\n\n\n");
    return 0;
}
