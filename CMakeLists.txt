cmake_minimum_required(VERSION 3.14)
project(ColorBlindAssist LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)

add_library(colorblindassist STATIC
    src/simulator.cpp
)

add_executable(main examples/demo.cpp)

target_link_libraries(main colorblindassist)

