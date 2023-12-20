cmake_minimum_required(VERSION 3.10)
project(lab7)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

add_executable(lab7 main.cpp include/npc.h src/npc.cpp include/rogue.h src/rogue.cpp 
              include/bear.h src/bear.cpp include/elf_.h src/elf_.cpp)

target_include_directories(lab7 PRIVATE include)
set_target_properties(lab7 PROPERTIES OUTPUT_NAME "main")

add_executable(lab7_tests tests/tests.cpp include/npc.h src/npc.cpp include/rogue.h src/rogue.cpp 
              include/bear.h src/bear.cpp include/elf_.h src/elf_.cpp)

target_include_directories(lab7_tests PRIVATE include)
set_target_properties(lab7_tests PROPERTIES OUTPUT_NAME "tests")
target_link_libraries(lab7_tests ${GTEST_LIBRARIES})

enable_testing()
add_test(lab7_tests lab7_tests)