cmake_minimum_required(VERSION 3.25)
project(rush01 C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(permute
        #        count_box.c
        #        count_rr_rl.c
        ex00/includes.h
        #        inv_tab.c
        ex00/lib.c
        ex00/lib.h
        #        lib2.c
        #        lib_count.c
        ex00/main.c
        #        test.c
        ex00/lib2.h)
add_executable(rush-01
        ex00/count_box.c
        ex00/count_rr_rl.c
        ex00/includes.h
        ex00/inv_tab.c
        ex00/lib.c
        ex00/lib.h
        ex00/lib2.c
        ex00/lib_count.c
        ex00/main.c
        ex00/test.c
        ex00/lib2.h)
