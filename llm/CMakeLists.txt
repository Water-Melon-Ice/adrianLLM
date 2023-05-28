cmake_minimum_required(VERSION 3.11)
project(llm LANGUAGES CXX)
include(FetchContent)

FetchContent_Declare(json URL https://github.com/nlohmann/json/releases/download/v3.11.2/json.tar.xz)
FetchContent_MakeAvailable(json)


add_executable(llm adrianLLM.cpp adrianLLM.h)
target_link_libraries(llm PRIVATE nlohmann_json::nlohmann_json)
target_link_libraries(llm PRIVATE common)