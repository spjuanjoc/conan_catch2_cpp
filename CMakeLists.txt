cmake_minimum_required(VERSION 3.19)
project(testing_conan
  VERSION "0.1.1"
  DESCRIPTION "conan with test suites: gtest and catch2"
  LANGUAGES CXX
)

option(ENABLE_TESTS "Enable tests" False)

add_executable(${PROJECT_NAME} main.cpp)

set(PROJECT_OPTIONS
  -Wpedantic
  -Wall
  -Wextra
  -Werror
)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_BINARY_DIR})
set(CMAKE_PREFIX_PATH ${CMAKE_PREFIX_PATH} ${CMAKE_BINARY_DIR})

target_link_libraries(${PROJECT_NAME} pthread)
target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_17)
target_compile_options(${PROJECT_NAME} INTERFACE ${PROJECT_OPTIONS})

if (ENABLE_TESTS)
  message(STATUS "Tests enabled")
  enable_testing() # Must be placed before add_subdirectory
  add_subdirectory(test)
  add_subdirectory(gtest)
endif ()
