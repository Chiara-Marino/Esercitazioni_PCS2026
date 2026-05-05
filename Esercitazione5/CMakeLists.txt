cmake_minimum_required(VERSION 3.20)

project(esercitazione5) 

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wshadow -Werror=vla")
set(CMAKE_CXX_FLAGS_RELEASE "-O3")

set(SRC_MEASURE timecounter.cpp measure_sorts.cpp randfiller.cpp)
add_executable(measure_sorts ${SRC_MEASURE})


add_executable(test_bubblesort test_bubblesort.cpp randfiller.cpp)
add_test(NAME bubblesort COMMAND test_bubblesort)

add_executable(test_insertionsort test_insertionsort.cpp randfiller.cpp)
add_test(NAME insertionsort COMMAND test_insertionsort)

add_executable(test_selectionsort test_selectionsort.cpp randfiller.cpp)
add_test(NAME selectionsort COMMAND test_selectionsort)

add_executable(test_mergesort test_mergesort.cpp randfiller.cpp)
add_test(NAME mergesort COMMAND test_mergesort)

add_executable(test_quicksort test_quicksort.cpp randfiller.cpp)
add_test(NAME quicksort COMMAND test_quicksort)

enable_testing()