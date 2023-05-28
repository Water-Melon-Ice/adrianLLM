cmake_minimum_required(VERSION 3.11)
project(common LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)

add_library(common 
	src/basic_write.cpp 
	src/basic_read.cpp)

target_include_directories(common PUBLIC include)