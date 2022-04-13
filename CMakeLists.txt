cmake_minimum_required(VERSION 3.21)
project(Prog_Tech C)

set(CMAKE_C_STANDARD 17)

add_executable(num_swap num_swap.c)
add_executable(komachi komachi.c)
target_link_libraries(komachi m)
add_executable(collatz collatz.c)
add_executable(collatz_bit collatz_bit.c)
add_executable(collatz_re collatz_re.c)
add_executable(collatz_re_bit collatz_re_bit.c)