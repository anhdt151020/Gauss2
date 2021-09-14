cmake_minimum_required(VERSION 3.20)
project(GaussC2 C)

set(CMAKE_C_STANDARD 99)

add_executable(GaussC2 main.c gauss.h matrix.h)
