cmake_minimum_required(VERSION 3.20)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
add_subdirectory(googletest)

add_executable(runPlayerTests
  tests/PlayerTests.cpp
  PlayerClasses/PlayerClasses.cpp
  PlayerClasses/Mage.cpp
  PlayerClasses/Warrior.cpp
  PlayerClasses/Rogue.cpp
)

target_link_libraries(runPlayerTests gmock gtest gtest_main)
