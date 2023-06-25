cmake_minimum_required(VERSION 3.11)
project(preparer LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)

add_executable(preparer src/preparer.cpp src/preparer.h)
target_link_libraries(preparer PRIVATE common)