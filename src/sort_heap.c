/**
 * @file sort_heap.c
 * @author ihsangokhun (onel.gokhun@gmail.com)
 * @brief it is used in order to sort a given array according to heap sort algorithm 
 * @version 0.1
 * @date 2021-01-10
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "stdlib.h"
#include "stdint.h"
#include "stdio.h"
#include "string.h"

#define NODE_EXIST 1U 
#define NODE_NOT_EXIST 0U 

/**
 * @brief a single node in the heap 
 * 
 */
typedef struct{

    int32_t node_data; // value of the node 
    uint8_t exist; // check whether node exists 

}node; 

/**
 * @brief data structure of the binary heap 
 * 
 */
typedef struct 
{
    node  *data_arr; // array that holds nodes and values 
    uint32_t arr_cursor; // where it points in the heap 
    uint32_t arr_size;  // size of the heap

}heap_data;


//this will be used globally in this source code 
static heap_data data;


/**
 * @brief swap the values of the two nodes 
 * 
 * @param index1 first node 
 * @param index2 second node 
 */
static void swap(uint32_t index1, uint32_t index2)
{
    int32_t temp = data.data_arr[index1].node_data;
    data.data_arr[index1].node_data = data.data_arr[index2].node_data ;
    data.data_arr[index2].node_data = temp;
}


/**
 * @brief Get the value of the node from given index 
 * 
 * @param index index of the node 
 * @return int32_t value of the node 
 */
int32_t get_index_val(uint32_t index)
{
    return ( (data.data_arr + index)->node_data);
}

/**
 * @brief Calculate the index of the parent 
 * 
 * @param index node index which is searching its parent 
 * @return uint32_t index of the parent 
 */
uint32_t get_parent_index(uint32_t index)
{
    return (index - 1 ) / 2 ;
}

/**
 * @brief Calculate the index of the left child 
 * 
 * @param index node index which is searching its left child 
 * @return uint32_t index of the left child 
 */
uint32_t get_left_chld_index(uint32_t index)
{
    return ((index*2 ) + 1);
}

/**
 * @brief Calculate the index of the right child 
 * 
 * @param index node index which is searching its right child 
 * @return uint32_t index of the right child 
 */
uint32_t get_right_chld_index(uint32_t index)
{
    return ((index*2 ) + 2);
}

/**
 * @brief it checks whether the node that is given over index has left child 
 * 
 * @param index index of the node 
 * @return uint8_t if the left child exists return 1 otherwise returns 0 
 */
uint8_t has_left_child(uint32_t index)
{
    return ( data.data_arr[get_left_chld_index(index)].exist == NODE_EXIST ? NODE_EXIST : NODE_NOT_EXIST);
}

/**
 * @brief  it checks whether the node that is given over index has right child 
 * 
 * @param index index of the node 
 * @return uint8_t if the right child exists return 1 otherwise returns 0 
 */
uint8_t has_right_child(uint32_t index)
{
    return ( data.data_arr[get_right_chld_index(index)].exist ==  NODE_EXIST ? NODE_EXIST : NODE_NOT_EXIST);
}

/**
 * @brief it checks whether the node that is given over index has parent 
 * 
 * @param index index of the node 
 * @return uint8_t if the parent exists return 1 otherwise returns 0 
 */
uint8_t has_parent(uint32_t index )
{
    return ((index > 1) && data.data_arr[(get_parent_index(index))].exist ==  NODE_EXIST ? NODE_EXIST : NODE_NOT_EXIST);
}

/**
 * @brief heapfiy up the binary heap 
 * 
 */

void heapfiyUp(void)
{
   uint32_t temp_cursor = data.arr_cursor;
    
   while (has_parent(temp_cursor) && get_index_val(temp_cursor) > get_index_val(get_parent_index(temp_cursor)))
    {
        swap(temp_cursor,get_parent_index(temp_cursor));
        temp_cursor = get_parent_index(temp_cursor);
    }
}

/**
 * @brief heapify the binary heap 
 * 
 * @return uint8_t 
 */
void heapfiy(void)
{
    
   uint32_t temp_cursor = 0;
   uint32_t compare_cursor = data.arr_cursor; 

 

   while (has_left_child(temp_cursor))
    {
      
        if ( data.data_arr[compare_cursor].node_data > get_index_val(temp_cursor))
            {
               swap(compare_cursor, temp_cursor);
            }    
            
        if (data.data_arr[compare_cursor].node_data > get_index_val(get_left_chld_index(temp_cursor)))
            {
                swap(compare_cursor, get_left_chld_index(temp_cursor));
            }
            
        if (has_right_child(temp_cursor) && data.data_arr[compare_cursor].node_data > get_index_val(get_right_chld_index(temp_cursor)))
            {
                swap(compare_cursor, get_right_chld_index(temp_cursor));
            }
            
            temp_cursor++;     
   }

}

/**
 * @brief  It checks each nodes in the binary heap and sorts the heap to down 
 *  
 */
void heapfiyDown(void)
{
    
   uint32_t temp_cursor = 0;
   
   while (has_left_child(temp_cursor))
    {
       if (data.data_arr[temp_cursor].node_data < get_index_val(get_left_chld_index(temp_cursor)) && get_index_val(get_left_chld_index(temp_cursor)) > get_index_val(get_right_chld_index(temp_cursor)))
            {
                swap(temp_cursor, get_left_chld_index(temp_cursor));
                temp_cursor = get_left_chld_index(temp_cursor);
            }
            
       else if (has_right_child(temp_cursor) && data.data_arr[temp_cursor].node_data < get_index_val(get_right_chld_index(temp_cursor)))
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

/**
 * @brief it adds item inside the heap as min heap format 
 * 
 * @param item item to be added 
 */
void add_item_to_min_heap(int32_t item)
{
    data.data_arr[data.arr_cursor].node_data = item;
    data.data_arr[data.arr_cursor].exist = NODE_EXIST;
    heapfiyUp();
    data.arr_cursor++;
}

/**
 * @brief it adds item inside the array as max heap format 
 * 
 * @param item item to be added 
 */
void add_item_to_max_heap(int32_t item)
{
    data.data_arr[data.arr_cursor].node_data = item;
    data.data_arr[data.arr_cursor].exist = NODE_EXIST;
    
    heapfiy();

    data.arr_cursor++;
}

/**
 * @brief creates a max heap from the given array 
 * 
 * @param ptr array to be used in order to create a max heap 
 * @param len the number of element in the array  
 */
void max_heap(int32_t *ptr, uint32_t len)
{
    for (int i = 0; i < len; i++)
      {
         add_item_to_max_heap(*(ptr + i));
      }  
}

/**
* @brief it sorts the given array by using HEAP SORT algorithm
* 
* @param ptr array to be sorted 
* @param len the number of element in the array 
* 
* @return does not return anything 
*
**/
void heap_sort(int32_t *ptr,uint32_t len)
{   
    memset(&data, 0, sizeof(heap_data));

    data.data_arr = (node *) malloc(sizeof(node) * len);
    data.arr_size = len;
    
    memset(data.data_arr, 0, len * sizeof(node));

    max_heap(ptr, len);
    
    data.arr_cursor--; // arr_cursor is following the size of the array 
    
    for (int i = 0; i < len; i++)
        {
            *(ptr + len - i - 1) = data.data_arr[0].node_data;
            swap(0, data.arr_cursor);
            data.data_arr[data.arr_cursor].node_data = 0;
            data.data_arr[data.arr_cursor].exist = NODE_NOT_EXIST;
            data.arr_cursor--;
            heapfiyDown();
        }
     
    free(data.data_arr);
}