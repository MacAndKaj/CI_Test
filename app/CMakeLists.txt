cmake_minimum_required(VERSION 3.5)

project(app LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory (src)
add_subdirectory (test)

enable_testing ()
add_test (NAME MyTest COMMAND Test)
