cmake_minimum_required(VERSION 3.10)
project(Product_UT)

set(CMAKE_CXX_STANDARD 17)

add_definitions(-std=c++17)


add_executable(Product_UT main.cpp)

target_link_libraries(Product_UT
    pthread
    gmock
    gtest
)