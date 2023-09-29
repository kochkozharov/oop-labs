cmake_minimum_required(VERSION 3.10)
project(lab1)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

add_executable(lab1 main.cpp task.cpp)
add_executable(lab1_tests tests.cpp task.cpp)
set_target_properties(lab1 PROPERTIES OUTPUT_NAME "main")
set_target_properties(lab1_tests PROPERTIES OUTPUT_NAME "tests")

target_link_libraries(lab1_tests ${GTEST_LIBRARIES})

enable_testing()
add_test(lab1_tests lab1_tests)