cmake_minimum_required(VERSION 2.8 FATAL_ERROR)

project(aod)
add_definitions(-std=gnu++0x)
include_directories(common)
add_subdirectory(linked_list)
add_subdirectory(vector)
add_subdirectory(tree)
add_subdirectory(dp)
add_subdirectory(common)
add_subdirectory(graph)
add_subdirectory(containers)

