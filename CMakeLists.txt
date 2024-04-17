cmake_minimum_required(VERSION 3.19)

project(test_suites_cpp
  VERSION     "1.0.0"
  DESCRIPTION "Test suites in cpp: gtest and catch2"
  LANGUAGES   CXX
)

# Options
option(ENABLE_COVERAGE  "Enable gcov coverage"  False)
  option(ENABLE_TESTS     "Enable tests"          False)


  add_executable(${PROJECT_NAME} main.cpp)

## Compiler options
include(cmake/CompilerOptions.cmake)
set_compiler_options(${PROJECT_NAME})



## Setup Conan < 2.0
if (NOT EXISTS "${CMAKE_BINARY_DIR}/conan.cmake")
  message(STATUS "Downloading conan.cmake from https://github.com/conan-io/cmake-conan")
  file(DOWNLOAD
    "https://raw.githubusercontent.com/conan-io/cmake-conan/master/conan.cmake"
    "${CMAKE_BINARY_DIR}/conan.cmake"
  )
endif ()


include(${CMAKE_BINARY_DIR}/conan.cmake)
conan_cmake_autodetect(settings)
conan_check(REQUIRED)
conan_cmake_run(CONANFILE conanfile.txt
  BASIC_SETUP NO_OUTPUT_DIRS
  BUILD missing
  SETTINGS ${settings}
  )

## Find third-party packages
  set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_BINARY_DIR})
set(CMAKE_PREFIX_PATH ${CMAKE_PREFIX_PATH} ${CMAKE_BINARY_DIR})

  target_compile_options(${PROJECT_NAME} INTERFACE ${PROJECT_OPTIONS})

  if (ENABLE_TESTS)
    message(STATUS "Tests enabled")
    enable_testing() # Must be placed before add_subdirectory
    add_subdirectory(test)
  endif ()
