cmake_minimum_required(VERSION 3.11)
project(preparer LANGUAGES CXX)
include(FetchContent)

FetchContent_Declare(json URL https://github.com/nlohmann/json/releases/download/v3.11.2/json.tar.xz)
FetchContent_MakeAvailable(json)


add_executable(preparer src/preparer.cpp src/preparer.h)
target_link_libraries(preparer PRIVATE nlohmann_json::nlohmann_json)
target_link_libraries(preparer PRIVATE common)