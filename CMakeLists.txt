cmake_minimum_required(VERSION 3.30)
project(untitled5)

set(CMAKE_CXX_STANDARD 20)

add_executable(untitled5
        main.cpp
        src/sort/SequentialMergeSort.cpp
        src/sort/ParallelMergeSort.cpp
)