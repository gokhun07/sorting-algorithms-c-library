# "C" Libraries for Sorting Algorithms 

This repository contains optimized "C" libraries for the well known sorting algorithms. In addition to the 
sorting algrithms, unit tests which are created with CMake can also be found under the *test* directory. 
The sorting algorithms are explained below. 


## Heap Sort

Heap sort is a comparison based sorting technique based on Binary Heap data structure. It is a popular and efficient sorting algorithm in computer 
programming. 

**Binary Heap** 
 
 A complete binary tree is a binary tree in which every level, except possibly the last, is completely filled, and all nodes are as far left as possible. 

 A Binary Heap is a Complete Binary Tree where items are stored in a special order such that value in a parent node is greater(or smaller) than the values in its two children nodes. The former is called as max heap and the latter is called min-heap. The heap can be represented by a binary tree or array.

Since a Binary Heap is a Complete Binary Tree, it can be easily represented as an array and the array-based representation is space-efficient. If the parent node is stored at index I, the left child can be calculated by 2 * I + 1 and right child by 2 * I + 2 (assuming the indexing starts at 0).

Heap Sort Algorithm for sorting in increasing order: 

1. Build a max heap from the input data. 
2. At this point, the largest item is stored at the root of the heap. Replace it with the last item of the heap followed by reducing the size of heap by Finally, heapify the root of the tree. 
3. Repeat step 2 while size of heap is greater than 1.


## Buble Sort 

Bubble Sort is the simplest sorting algorithm that works by repeatedly swapping the adjacent elements if they are in wrong order.

## Selection Sort 

The selection sort algorithm sorts an array by repeatedly finding the minimum element (considering ascending order) from unsorted part and putting it at the beginning. The algorithm maintains two subarrays in a given array.

1) The subarray which is already sorted.
2) Remaining subarray which is unsorted.

In every iteration of selection sort, the minimum element (considering ascending order) from the unsorted subarray is picked and moved to the sorted subarray.

## Tests

Unit tests are adapted to CMake automatic build system. All tests case are defined in the "example_test.cpp" source file. In order to produce random arrays for testing a python script that is *number_list_generator.py* is used. Each run of this script creates a random sized an array that contains random numbers. This array is defined in the *"test_array.h"* header file that is also produced by the same python script. 