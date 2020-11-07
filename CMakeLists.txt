cmake_minimum_required(VERSION 2.8)
project(HolaMundo CXX)

add_executable(${PROJECT_NAME} main.cpp)

add_subdirectory(test)

set_target_properties(${PROJECT_NAME} PROPERTIES CXX_STANDARD 17)
