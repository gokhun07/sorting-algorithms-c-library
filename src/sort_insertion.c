#include "stdlib.h"
#include "stdio.h"
#include "stdint.h"


int32_t sort_insertion(void *arr, uint32_t len)
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
                    *(arr_ptr + iterator2 - 1) = *(arr_ptr + iterator2 );
                    *(arr_ptr + iterator2) = temp;
                }
                else if (*(arr_ptr + iterator2) == *(arr_ptr + iterator2  - 1 ))
                {
                    return (*(arr_ptr + iterator2));
                }
        }       
    }
    return 0;
}

int main(int argc, char const *argv[])
{
    int32_t  arr[] = {1,2,4,-13,8,6,28,-13,-48,11,5};

    for (int i = 0; i < sizeof (arr) / sizeof(uint32_t); i++)
    {
        printf("%d", arr[i]);
        printf(",");
    }
   
    printf("\n\n\n");
   
    int32_t ret = sort_insertion(arr, sizeof (arr) / sizeof(uint32_t));
   
    if ( (ret) != 0)
    {
        printf (" Equal number has been found !!!\n");
        printf (" %d\n", ret);
        printf("\n\n\n");

        return 0;
    }

    for (int i = 0; i < sizeof (arr) / sizeof(uint32_t); i++)
    {
        printf("%d", arr[i]);
        printf(",");

    }
    
    printf("\n\n\n");

    return 0;
}
