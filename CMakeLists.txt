cmake_minimum_required(VERSION 3.12)

project(KeyValueStorage LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


file(GLOB sources "src/*.cpp")
file(GLOB headers "src/*.hpp")

set(testing_sources ${sources})
set(testing_headers ${sources})

list(REMOVE_ITEM testing_sources ${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp)

list(REMOVE_ITEM sources ${CMAKE_CURRENT_SOURCE_DIR}/src/catch_amalgamated.cpp)
list(REMOVE_ITEM sources ${CMAKE_CURRENT_SOURCE_DIR}/src/test.cpp)

list(REMOVE_ITEM headers ${CMAKE_CURRENT_SOURCE_DIR}/src/catch_amalgamated.hpp)

include_directories(${PROJECT_NAME} PUBLIC src)
add_executable(main ${sources} ${headers})
#add_executable(testing ${testing_sources} ${headers})
