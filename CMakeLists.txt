cmake_minimum_required(VERSION 3.13)
project(fcpy VERSION 0.1 LANGUAGES CXX C Fortran)

add_subdirectory(pybind11)

set(C_SRC c_src/caller.cpp)
add_library(clib STATIC ${C_SRC})
target_include_directories(clib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/c_src)
target_link_libraries(clib PUBLIC pybind11::embed)

set(F_SRC f_src/call.f90)
add_executable(f f_src/call.f90)
target_link_libraries(f PUBLIC clib)
