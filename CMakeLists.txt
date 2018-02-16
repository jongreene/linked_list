cmake_minimum_required(VERSION 3.8)
project(linked_list)

set(CMAKE_CXX_STANDARD 11)
add_subdirectory(lib/googletest-master)
include_directories(lib/googletest-master/googletest/include)
include_directories(lib/googletest-master/googlemock/include)

set(SOURCE_FILES main.cpp Node.cpp Node.hpp LinkedList.cpp LinkedList.hpp LinkedIterator.cpp LinkedIterator.hpp Tests/ClassName.h Tests/LinkedList_test.cpp)
add_executable(linked_list ${SOURCE_FILES} Tests/ClassName.h Tests/LinkedList_test.cpp)

target_link_libraries(linked_list gtest gtest_main)