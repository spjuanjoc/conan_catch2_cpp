cmake_minimum_required(VERSION 3.28)

project(test_suites_cpp
  VERSION "1.0.0"
  DESCRIPTION "Test suites in cpp: gtest and catch2"
  LANGUAGES CXX
)

# Options
option(ENABLE_COVERAGE  "Enable gcov coverage"  False)
option(ENABLE_TESTS     "Enable tests"          False)


add_executable(${PROJECT_NAME} main.cpp)

## Compiler options
include(cmake/CompilerOptions.cmake)
set_compiler_options(${PROJECT_NAME})

target_compile_options(${PROJECT_NAME} INTERFACE ${PROJECT_OPTIONS})

if (ENABLE_TESTS)
  message(STATUS "Tests enabled")
  enable_testing() # Must be placed before add_subdirectory
  add_subdirectory(test)
endif ()
