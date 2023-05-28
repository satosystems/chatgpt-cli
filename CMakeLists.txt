cmake_minimum_required(VERSION 3.26)
project(chatgpt_cli)

set(CMAKE_CXX_STANDARD 23)

add_subdirectory(lib/satosystems/libchatgpt)
include_directories(lib/satosystems/libchatgpt)

add_executable(chatgpt_cli main.cpp)
