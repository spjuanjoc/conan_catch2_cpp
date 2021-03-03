enable_testing()

add_executable(foo_test main.cpp test.foo.cpp)

target_compile_features(foo_test PUBLIC cxx_std_17)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()
#conan_basic_setup(TARGETS)
#conan_target_link_libraries(foo_test)
#target_link_libraries(foo_test CONAN_PKG::gtest CONAN_PKG::catch2)

add_test(foo_test foo_test)
