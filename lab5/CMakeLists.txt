cmake_minimum_required(VERSION 3.10)
project(lab5)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

add_executable(lab5 main.cpp include/allocator.h include/vector.h
)

target_include_directories(lab5 PRIVATE include)
set_target_properties(lab5 PROPERTIES OUTPUT_NAME "main")

add_executable(lab5_tests tests/tests.cpp include/allocator.h include/vector.h
)

target_include_directories(lab5_tests PRIVATE include)
set_target_properties(lab5_tests PROPERTIES OUTPUT_NAME "tests")
target_link_libraries(lab5_tests ${GTEST_LIBRARIES})

enable_testing()
add_test(lab5_tests lab5_tests)