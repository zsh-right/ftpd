cmake_minimum_required(VERSION 3.0)
PROJECT(FTP_CLIENT)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -pthread")
set(CMAKE_BUILD_TYPE "Debug")


add_executable(client main.cpp)

target_link_libraries(client -lACE)
