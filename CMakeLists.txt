cmake_minimum_required(VERSION 3.25)
project(rush01 C)

set(CMAKE_C_STANDARD 99)

include_directories(.)

add_executable(permute
        #        count_rr_rl.c
        ex00/includes.h
        ex00/lib.c
        ex00/lib.h
        ex00/main.c
        )
add_executable(rush-01
        ex00/count_rr_rl.c
        ex00/includes.h
        ex00/lib.c
        ex00/lib.h
        ex00/main.c
        )
