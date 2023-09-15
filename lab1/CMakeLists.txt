cmake_minimum_required(VERSION 3.10)
project(lab1)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

add_executable(main main.cpp task.cpp)
add_executable(gtests tests.cpp task.cpp)

target_link_libraries(gtests ${GTEST_LIBRARIES})

enable_testing()
add_test(gtests gtests)