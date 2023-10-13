cmake_minimum_required(VERSION 3.10)
project(lab2)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

add_executable(lab2 main.cpp src/money.cpp include/money.h)
target_include_directories(lab2 PRIVATE include)
set_target_properties(lab2 PROPERTIES OUTPUT_NAME "main")

add_executable(lab2_tests tests/tests.cpp src/money.cpp include/money.h)
target_include_directories(lab2_tests PRIVATE include)
set_target_properties(lab2_tests PROPERTIES OUTPUT_NAME "tests")
target_link_libraries(lab2_tests ${GTEST_LIBRARIES})

enable_testing()
add_test(lab2_tests lab2_tests)