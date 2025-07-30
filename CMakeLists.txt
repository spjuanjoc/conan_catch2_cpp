cmake_minimum_required(VERSION 3.28)

project(test_suites_cpp
  VERSION "1.0.0"
  DESCRIPTION "Test suites in cpp: gtest and catch2"
  LANGUAGES CXX
)

# Options
option(ENABLE_COVERAGE  "Enable gcov coverage"  False)
option(ENABLE_TESTS     "Enable tests"          True)


if (ENABLE_TESTS)
  message(STATUS "Tests enabled")
  enable_testing() # Must be placed before add_subdirectory
  add_subdirectory(test)
endif ()
