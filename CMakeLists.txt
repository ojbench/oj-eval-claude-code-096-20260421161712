cmake_minimum_required(VERSION 3.10)
project(problem_096 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_BUILD_TYPE Release)

add_executable(code src/main.cpp)
set_target_properties(code PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}"
)

target_compile_options(code PRIVATE -O2 -pipe)
