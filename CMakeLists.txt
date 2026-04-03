cmake_minimum_required(VERSION 4.2)
project(untitled)

set(CMAKE_CXX_STANDARD 20)

add_executable(untitled main.cpp
        Mystring.h
        Mystring.cpp
        MyStack.h
        MyStack.cpp
        MyStruct.h
        MyStruct.cpp
        Union_And_Enum.h
        Union_And_Enum.cpp
        mypoint_using.h
        mypoint_using.cpp)
