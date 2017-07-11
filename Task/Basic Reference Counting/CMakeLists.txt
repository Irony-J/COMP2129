cmake_minimum_required(VERSION 3.7)
project(Basic_Reference_Counting)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        mem_ref.c
        mem_ref.h
        run.c)

add_executable(Basic_Reference_Counting ${SOURCE_FILES})