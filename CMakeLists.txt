cmake_minimum_required(VERSION 2.8)
project(HolaMundo CXX)

add_executable(${PROJECT_NAME} main.cpp)


set_target_properties(${PROJECT_NAME} PROPERTIES CXX_STANDARD 17)
target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_17)

add_subdirectory(test)
