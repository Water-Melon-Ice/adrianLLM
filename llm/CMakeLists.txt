cmake_minimum_required(VERSION 3.11)
project(llm LANGUAGES CXX)

add_executable(llm adrianLLM.cpp adrianLLM.h)
target_link_libraries(llm PRIVATE common)