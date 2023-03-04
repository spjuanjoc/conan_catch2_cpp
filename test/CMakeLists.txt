set(TEST_NAME ${PROJECT_NAME}_catch2tests)

file(GLOB_RECURSE TEST_SOURCES LIST_DIRECTORIES false test.*.cpp)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_BINARY_DIR})
set(CMAKE_PREFIX_PATH ${CMAKE_PREFIX_PATH} ${CMAKE_BINARY_DIR})

find_package(Catch2 REQUIRED)

add_executable(${TEST_NAME} ${TEST_SOURCES})
add_test(${TEST_NAME} ${TEST_NAME})

target_link_libraries(${TEST_NAME} pthread ${Catch2_LIBRARIES})
target_compile_features(${TEST_NAME} PUBLIC cxx_std_20)
target_compile_options(${TEST_NAME} INTERFACE ${PROJECT_OPTIONS})
target_include_directories(${TEST_NAME} PRIVATE
  ../include
  ${Catch2_INCLUDE_DIRS}
)
