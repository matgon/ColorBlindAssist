cmake_minimum_required(VERSION 3.14)
project(ColorBlindAssist LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(OpenCV REQUIRED)

include_directories(include)

add_library(colorblindassist STATIC
    src/simulator.cpp
)

target_link_libraries(colorblindassist ${OpenCV_LIBS})

add_executable(main examples/demo.cpp)

target_link_libraries(main colorblindassist ${OpenCV_LIBS})

target_include_directories(colorblindassist PRIVATE ${OpenCV_INCLUDE_DIRS})
target_include_directories(main PRIVATE ${OpenCV_INCLUDE_DIRS})
