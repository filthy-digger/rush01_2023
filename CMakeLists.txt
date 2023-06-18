cmake_minimum_required(VERSION 3.25)
project(rush01 C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(permute
#        count_box.c
#        count_rr_rl.c
        includes.h
#        inv_tab.c
        lib.c
        lib.h
#        lib2.c
#        lib_count.c
        main.c
#        test.c
        )
