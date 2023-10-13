cmake_minimum_required(VERSION 3.10)
project(lab1)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

add_executable(lab1 main.cpp src/task.cpp include/task.h)
target_include_directories(lab1 PRIVATE include)
set_target_properties(lab1 PROPERTIES OUTPUT_NAME "main")

add_executable(lab1_tests tests/tests.cpp src/task.cpp include/task.h)
target_include_directories(lab1_tests PRIVATE include)
set_target_properties(lab1_tests PROPERTIES OUTPUT_NAME "tests")
target_link_libraries(lab1_tests ${GTEST_LIBRARIES})

enable_testing()
add_test(lab1_tests lab1_tests)