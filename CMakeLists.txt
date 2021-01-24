cmake_minimum_required(VERSION 3.13)

set(This SortingAlgorithms)

project(${This} C CXX)

set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)
set(OPTIMIZATION_RELEASE "-O2")
set(CMAKE_C_FLAGS_RELEASE " ${OPTIMIZATION_RELEASE}  ")
set(CMAKE_CXX_FLAGS_RELEASE " ${OPTIMIZATION_RELEASE} ")
enable_testing()

#/home/ihsangokhun/SoftSkills/software-testing/googletest

add_subdirectory (../../../software-testing/googletest/ build)

# set(Hearders src/test.h )

set(Sources 
     src/sort_buble.c
     src/sort_heap.c
     src/sort_insertion.c 
     src/sort_merge.c 
     src/sort_quick.c 
     src/sort_selection.c 

     )


add_library(${This} STATIC ${Sources} ${Headers})

add_subdirectory(test)