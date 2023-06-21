cmake_minimum_required(VERSION 3.25)
project(rush01 C)

set(CMAKE_C_STANDARD 99)

include_directories(.)

add_executable(permute
        ex00/include_sys.h
        ex00/lib.c
        ex00/lib.h
        ex00/main.c
        )
add_executable(rush-01
        ex00/include_sys.h
        ex00/lib.c
        ex00/lib.h
        ex00/main.c
        ex00/lib_aux.c ex00/lib_aux.h)
