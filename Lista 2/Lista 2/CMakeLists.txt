cmake_minimum_required(VERSION 3.6)
project(Lista_2)

#set(CMAKE_C_STANDARD 99)
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES  main.cpp)
add_executable(Lista_2 ${SOURCE_FILES} ${PYTHON_FILES})
