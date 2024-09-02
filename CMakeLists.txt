cmake_minimum_required(VERSION 3.29)
project(CSES)

set(CMAKE_CXX_STANDARD 20)

file(GLOB problems problems/*.cpp)
foreach (problem ${problems})
    get_filename_component(problem_name ${problem} NAME_WE)
    add_executable(${problem_name} ${problem})
endforeach ()