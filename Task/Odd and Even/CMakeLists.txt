cmake_minimum_required(VERSION 3.7)
project(Odd_and_Even)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        num.c
        num.h
        num_run.c)

add_executable(Odd_and_Even ${SOURCE_FILES})