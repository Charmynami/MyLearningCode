cmake_minimum_required(VERSION 4.2)
project(untitled)

set(CMAKE_CXX_STANDARD 20)

add_executable(untitled main.cpp
        MyInclude/Mystring.h
        src/Mystring.cpp
        MyInclude/MyStack.h
        src/MyStack.cpp
        MyInclude/MyStruct.h
        src/MyStruct.cpp
        MyInclude/Union_And_Enum.h
        src/Union_And_Enum.cpp
        MyInclude/mypoint_using.h
        src/mypoint_using.cpp
        MyInclude/Function.h
        src/MyFunction.cpp
        MyInclude/MyReference.h
        src/MyReference.cpp)
