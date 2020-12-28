#include "stdlib.h"
#include "stdint.h"
#include "stdio.h"

#define HEAP_ARR_SIZE 50
#define INITIAL_STATE 1U 

typedef struct 
{
    int32_t heap_arr[50];
    uint32_t arr_cursor;
}heap_data;

static heap_data data;

void swap(uint32_t index1, uint32_t index2)
{
    int32_t temp = data.heap_arr[index1];
    data.heap_arr[index1] = data.heap_arr[index2] ;
    data.heap_arr[index2] = temp;
}

int32_t get_index_val(uint32_t index)
{
    return ( *(data.heap_arr + index));
}

uint32_t get_parent_index(uint32_t index)
{
    return (index - 1 ) / 2 ;
}

uint32_t get_left_chld_index(uint32_t index)
{
    return ((index*2 ) + 1);
}

uint32_t get_right_chld_index(uint32_t index)
{
    return ((index*2 ) + 2);
}

uint8_t has_left_child(uint32_t index)
{
    return ( data.heap_arr[get_left_chld_index(index)] > 0 ? 1 : 0);
}

uint8_t has_right_child(uint32_t index)
{
   return ( data.heap_arr[get_right_chld_index(index)] > 0 ? 1 : 0);  
}

uint8_t has_parent(uint32_t index )
{
    return ((index > 1) && get_index_val(get_parent_index(index)) > 0) ? 1 : 0;
}

uint8_t heapfiyUp(void)
{
   
   uint32_t temp_cursor = data.arr_cursor;
    
   while (has_parent(temp_cursor) && get_index_val(temp_cursor) > get_index_val(get_parent_index(temp_cursor)))
    {
        swap(temp_cursor,get_parent_index(temp_cursor));
        temp_cursor = get_parent_index(temp_cursor);
    }
}

uint8_t heapfiy(void)
{
    
   uint32_t temp_cursor = 0;
   uint32_t compare_cursor = data.arr_cursor; 

   if(data.arr_cursor == (HEAP_ARR_SIZE - 1 ))
        return 0;

   while (has_left_child(temp_cursor))
    {
      
        if ( data.heap_arr[compare_cursor] > get_index_val(temp_cursor))
            {
               swap(compare_cursor, temp_cursor);
            }    
            
        if (data.heap_arr[compare_cursor] > get_index_val(get_left_chld_index(temp_cursor)))
            {
                swap(compare_cursor, get_left_chld_index(temp_cursor));
            }
            
        if (has_right_child(temp_cursor) && data.heap_arr[compare_cursor] > get_index_val(get_right_chld_index(temp_cursor)))
            {
                swap(compare_cursor, get_right_chld_index(temp_cursor));
            }
            
            temp_cursor++;     
   }

}

uint8_t heapfiyDown(void)
{
    
   uint32_t temp_cursor = 0;
   

   if(data.arr_cursor == (HEAP_ARR_SIZE - 1 ))
        return 0;

   while (has_left_child(temp_cursor))
    {
       if (data.heap_arr[temp_cursor] < get_index_val(get_left_chld_index(temp_cursor)) && get_index_val(get_left_chld_index(temp_cursor)) > get_index_val(get_right_chld_index(temp_cursor)))
            {
                swap(temp_cursor, get_left_chld_index(temp_cursor));
                temp_cursor = get_left_chld_index(temp_cursor);
            }
            
       else if (has_right_child(temp_cursor) && data.heap_arr[temp_cursor] < get_index_val(get_right_chld_index(temp_cursor)))
            {
                swap(temp_cursor, get_right_chld_index(temp_cursor));
                temp_cursor = get_right_chld_index(temp_cursor);
            }
        else
        {
            break;
        }
        
            
      
   }

}
uint8_t add_item_to_heap(int32_t item)
{
    if(data.arr_cursor == (HEAP_ARR_SIZE - 1 ))
        return 0;

    data.heap_arr[data.arr_cursor] = item;
    heapfiyUp();
    data.arr_cursor++;
}



uint8_t add_item_to_max_heap(int32_t item)
{
    if(data.arr_cursor == (HEAP_ARR_SIZE - 1 ))
        return 0;

    data.heap_arr[data.arr_cursor] = item;
    
    heapfiy();

    data.arr_cursor++;
}

void max_heap(int32_t *ptr, uint32_t len)
{
    for (int i = 0; i < len; i++)
      {
         add_item_to_max_heap(*(ptr + i));
      }  
}

void heap_sort(int32_t *ptr,uint32_t len)
{
    max_heap(ptr, len);

    data.arr_cursor--; // point to the end of the tree

    for (int i = 0; i < len; i++)
        {
            *(ptr + len - i - 1) = data.heap_arr[0];
            swap(0, data.arr_cursor);
            data.heap_arr[data.arr_cursor] = 0;
            data.arr_cursor--;
            heapfiyDown();
        }
}
/*
int main(int argc, char const *argv[])
{
    int32_t arr[] ={10,5,755,2,8};

    max_heap(arr, sizeof(arr) / sizeof (int32_t));
    
    for (int32_t i = 0; i < data.arr_cursor; i++)
    {
        printf("%d, ", data.heap_arr[i] );
    }
    
    heap_sort(arr, sizeof(arr) / sizeof (int32_t));
    
    printf ("\n\n");

   for (int32_t i = 0; i < sizeof(arr) / sizeof (int32_t); i++)
    {
        printf("%d, ", * (arr + i ));
    }
    return 0;
}
*/