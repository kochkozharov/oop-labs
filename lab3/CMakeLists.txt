cmake_minimum_required(VERSION 3.10)
project(lab3)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

add_executable(lab3 main.cpp src/figure.cpp include/figure.h
                             src/figure_array.cpp include/figure_array.h
                             src/point.cpp include/point.h
)
target_include_directories(lab3 PRIVATE include)
set_target_properties(lab3 PROPERTIES OUTPUT_NAME "main")

add_executable(lab3_tests tests/tests.cpp src/figure.cpp include/figure.h
                             src/figure_array.cpp include/figure_array.h
                             src/point.cpp include/point.h
)

target_include_directories(lab3_tests PRIVATE include)
set_target_properties(lab3_tests PROPERTIES OUTPUT_NAME "tests")
target_link_libraries(lab3_tests ${GTEST_LIBRARIES})

enable_testing()
add_test(lab3_tests lab3_tests)