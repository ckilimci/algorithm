cmake_minimum_required(VERSION 3.2.2)
project(Algorithms)


add_subdirectory(data-structures)
add_subdirectory(games)

add_executable(hello hello.cpp)
add_executable(goodbye goodbye.cpp)
add_executable(draw_map draw_map.cpp Map.h Map.cpp)
add_executable(operations operations.cpp)
add_executable(nth-magical-number nth-magical-number.cpp)
add_executable(river_size river-size.cpp)

set_property(TARGET river_size PROPERTY CXX_STANDARD 11)

add_executable(subset_sum subset-sum.cpp)

set_property(TARGET subset_sum PROPERTY CXX_STANDARD 11)

