cmake_minimum_required(VERSION 3.8)
project(linked_list)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Node.cpp Node.hpp LinkedList.cpp LinkedList.hpp LinkedIterator.cpp LinkedIterator.hpp)
add_executable(linked_list ${SOURCE_FILES})