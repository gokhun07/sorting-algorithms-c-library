cmake_minimum_required(VERSION 3.13)


set(This SortingAlgorithmsTest)

set(OPTIMIZATION_RELEASE "-O2")
set(CMAKE_C_FLAGS_RELEASE " ${OPTIMIZATION_RELEASE}  ")
set(CMAKE_CXX_FLAGS_RELEASE " ${OPTIMIZATION_RELEASE} ")

set(Sources
    example_test.cpp
    array_checker.cpp
)

add_executable(${This} ${Sources})

target_link_libraries(${This} PUBLIC 
    gtest_main
    SortingAlgorithms
)

add_test(
    NAME ${This}
    COMMAND ${This}


)

 