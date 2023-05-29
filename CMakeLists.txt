cmake_minimum_required(VERSION 3.26)
project(chatgpt_cli)

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
endif()

if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    add_compile_options(-O0 -g)
elseif(CMAKE_BUILD_TYPE STREQUAL "Release")
    add_compile_options(-O3)
endif()

set(CMAKE_CXX_STANDARD 23)

add_subdirectory(lib/satosystems/libchatgpt)
include_directories(lib/satosystems/libchatgpt)

add_executable(chatgpt_cli main.cpp)
target_link_libraries(chatgpt_cli chatgpt)
set_target_properties(chatgpt_cli PROPERTIES OUTPUT_NAME chatgpt)

install(FILES ${CMAKE_CURRENT_BINARY_DIR}/chatgpt DESTINATION ~/.local/bin)
