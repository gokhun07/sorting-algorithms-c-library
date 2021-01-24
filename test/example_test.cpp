#include "gtest/gtest.h"
#include <stdint.h>
#include "test_arrays.h"

extern bool arrays_are_eq(int32_t * arr1, int32_t* arr2, uint32_t size1, uint32_t size2);


extern "C"
{
    extern void sort_selection(void *arr, uint32_t len);
    extern int32_t sort_insertion(void *arr, uint32_t len);
    extern void sort_bubble(void *arr, uint32_t len);
    extern void heap_sort(int32_t *ptr,uint32_t len);
 }
 
TEST(SortingAlgorithmsTest, SortInsertion)
{
  int32_t temp_arr[TEST_ARR_ROW_SIZE][TEST_ARR_COLUMN_SIZE];
  
  memcpy((int32_t ** )&temp_arr[0][0],(int32_t ** )&test_arr1[0][0],sizeof(temp_arr));

  for (size_t i = 0; i < TEST_ARR_ROW_SIZE - 1 ; i+=2)
    {
       sort_insertion((int32_t * )&temp_arr[i][0], TEST_ARR_COLUMN_SIZE);
       EXPECT_TRUE((bool)arrays_are_eq((int32_t * )&temp_arr[i][0], (int32_t * )&temp_arr[i+1][0], TEST_ARR_COLUMN_SIZE, TEST_ARR_COLUMN_SIZE ));
     }
    
 }
 


TEST(SortingAlgorithmsTest, SortBuble)
{
  int32_t temp_arr[TEST_ARR_ROW_SIZE][TEST_ARR_COLUMN_SIZE];
  
  memcpy((int32_t ** )&temp_arr[0][0],(int32_t ** )&test_arr1[0][0],sizeof(temp_arr));

  for (size_t i = 0; i < TEST_ARR_ROW_SIZE - 1 ; i+=2)
    {
       sort_bubble((int32_t * )&temp_arr[i][0], TEST_ARR_COLUMN_SIZE);
       EXPECT_TRUE((bool)arrays_are_eq((int32_t * )&temp_arr[i][0], (int32_t * )&temp_arr[i+1][0], TEST_ARR_COLUMN_SIZE, TEST_ARR_COLUMN_SIZE ));
     }
    
 }
 
TEST(SortingAlgorithmsTest, SortHeap)
{
  int32_t temp_arr[TEST_ARR_ROW_SIZE][TEST_ARR_COLUMN_SIZE];
  
  memcpy((int32_t ** )&temp_arr[0][0],(int32_t ** )&test_arr1[0][0],sizeof(temp_arr));

  for (size_t i = 0; i < TEST_ARR_ROW_SIZE; i+=2)
    {
       heap_sort((int32_t * )&temp_arr[i][0], TEST_ARR_COLUMN_SIZE);
       EXPECT_TRUE((bool)arrays_are_eq((int32_t * )&temp_arr[i][0], (int32_t * )&temp_arr[i+1][0], TEST_ARR_COLUMN_SIZE, TEST_ARR_COLUMN_SIZE ));
    }  
 }

