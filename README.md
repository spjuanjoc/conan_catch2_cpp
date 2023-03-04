# Test Suites with Conan

Use the `Catch2` and `gtest` test frameworks with conan package manager.

[cmake-conan](https://github.com/conan-io/cmake-conan) is not yet compatible
with conan 2.0 so before loading the cmake project (to e.g. `./build`) run:

    conan profile show
    conan install . --output-folder=build --build=missing
