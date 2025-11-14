cmake_minimum_required(VERSION 3.20)

add_subdirectory(googletest)

add_executable(runPlayerTests
  tests/EnemyTest.cpp
  src/Enemies/*.h
  src/Enemies/*.cpp

)

target_link_libraries(runPlayerTests gmock gtest gtest_main)