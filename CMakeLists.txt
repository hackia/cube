cmake_minimum_required(VERSION 3.10)

project(cube LANGUAGES CXX)

# Enable strict compile rules
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
add_compile_options(-Wall -Wextra -Werror -pedantic)

add_library(cube Cube.cpp Cube.hpp)
add_library(sandbox Sandbox.cpp Sandbox.hpp )
add_library(fs FileSystem.cpp FileSystem.hpp)
add_library(net Net.cpp Net.hpp)
target_link_libraries(sandbox PRIVATE cube)
install(TARGETS cube sandbox fs net DESTINATION lib)
install(FILES Cube.hpp Sandbox.hpp Policy.hpp FileSystem.hpp Net.hpp DESTINATION include)
# Enable testing
enable_testing()

# Download and link GoogleTest
include(FetchContent)
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/refs/heads/main.zip
)
FetchContent_MakeAvailable(googletest)
add_executable(cube_test test.cpp)
target_link_libraries(cube_test gtest_main)
target_compile_options(cube_test PRIVATE -Wall -Wextra -Werror -pedantic)

add_test(NAME cube_test COMMAND cube_test)