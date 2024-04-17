set(TEST_NAME ${PROJECT_NAME}_catch2tests)

file(GLOB_RECURSE TEST_SOURCES LIST_DIRECTORIES false test.*.cpp)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_BINARY_DIR})
set(CMAKE_PREFIX_PATH ${CMAKE_PREFIX_PATH} ${CMAKE_BINARY_DIR})

find_package(Catch2 REQUIRED)

add_executable(${TEST_NAME} ${TEST_SOURCES})

add_test(
  NAME ${TEST_NAME}
  WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
  COMMAND ${TEST_NAME} --verbosity quiet --success --durations no --order decl # -? for catch2 help
)

## Compiler options
include(../../cmake/CompilerOptions.cmake)
set_compiler_options(${TEST_NAME})

## Target
target_link_libraries(${TEST_NAME} pthread ${catch2_LIBRARIES})
target_compile_options(${TEST_NAME} INTERFACE ${PROJECT_OPTIONS})

target_include_directories(${TEST_NAME}
  PRIVATE
  ../include
  PRIVATE SYSTEM
  ${catch2_INCLUDE_DIRS}
)
