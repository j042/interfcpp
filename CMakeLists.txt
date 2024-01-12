cmake_minimum_required(VERSION 3.13)
project(fcpy VERSION 0.1 LANGUAGES CXX C Fortran)

set(CMAKE_VERBOSE_MAKEFILE ON)
add_subdirectory(pybind11)

set(C_SRC c_src/caller.cpp)
add_library(clib STATIC ${C_SRC})
target_include_directories(clib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/c_src)
target_link_libraries(clib PUBLIC pybind11::embed)
target_compile_options(clib PUBLIC -fPIC)

set(F_LIB f_src/callm.f90)
add_library(calllib SHARED ${F_LIB})
target_link_libraries(calllib PRIVATE clib)

set(F_SRC f_src/call.f90)
add_executable(f f_src/call.f90)
target_include_directories(clib PUBLIC ${CMAKE_CURRENT_BINARY_DIR})
target_link_libraries(f PUBLIC clib calllib)


