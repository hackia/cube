cmake_minimum_required(VERSION 3.10)

project(capsule LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 26)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
add_compile_options(-Wall -Wextra -Werror -pedantic)

add_library(capsule Capsule.cpp Capsule.hpp)
enable_testing()

# Download and link GoogleTest
include(FetchContent)
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/refs/heads/main.zip
    DOWNLOAD_EXTRACT_TIMESTAMP true
)
FetchContent_MakeAvailable(googletest)

install(FILES Capsule.hpp DESTINATION include)
install(TARGETS capsule DESTINATION lib)
