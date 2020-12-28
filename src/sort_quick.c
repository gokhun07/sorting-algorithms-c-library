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

//int32_t arr_t[] = {2,1,4,8,6,28,10,0,-10};

int32_t arr_t[] = {1,4,8,0,6,2,13,5,7,78,778,41,2365};

int main(int argc, char const *argv[])
{

   for (int32_t i = 0; i < sizeof(arr_t) / sizeof (int32_t); i++)
    {
        printf("%d, ", * (arr_t + i ));
    }
    
    quick_sort(arr_t,   sizeof(arr_t) / sizeof (int32_t) - 1 ,0 );
    
    printf ("\n\n");

   for (int32_t i = 0; i < sizeof(arr_t) / sizeof (int32_t); i++)
    {
        printf("%d, ", * (arr_t + i ));
    }

        printf ("\n\n");

    return 0;
}
