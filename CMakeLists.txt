cmake_minimum_required(VERSION 3.12)

project(KeyValueStorage LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB_RECURSE source_list "src/*.cpp" "src/*.hpp")
include_directories(${PROJECT_NAME} PUBLIC src)
add_executable(${PROJECT_NAME} ${source_list})
