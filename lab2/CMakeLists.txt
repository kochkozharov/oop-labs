cmake_minimum_required(VERSION 3.10)
project(lab2)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

add_executable(lab2 src/main.cpp)
set_target_properties(lab2 PROPERTIES OUTPUT_NAME "main")

#[[
add_executable(gtests tests.cpp task.cpp)

target_link_libraries(gtests ${GTEST_LIBRARIES})
enable_testing()
add_test(gtests gtests)
]]