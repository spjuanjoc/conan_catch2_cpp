enable_testing()

add_executable(foo_test main.cpp test.foo.cpp)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()
conan_target_link_libraries(foo_test)

add_test(foo_test foo_test)
