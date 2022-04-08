cmake_minimum_required(VERSION 3.21)
project(Prog_Tech C)

set(CMAKE_C_STANDARD 17)

add_executable(num_swap num_swap.c)
add_executable(komachi komachi.c)
target_link_libraries(komachi m)