cmake_minimum_required(VERSION 3.20)
project(final_project)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

add_subdirectory(googletest)

include_directories(
    ${CMAKE_SOURCE_DIR}/include
    ${CMAKE_SOURCE_DIR}/include/players
    ${CMAKE_SOURCE_DIR}/include/enemies
)

add_executable(runPlayerTests
    tests/PlayerTests.cpp
    src/PlayerClasses.cpp
    src/players/Mage.cpp
    src/players/Warrior.cpp
    src/players/Rogue.cpp
)

target_link_libraries(runPlayerTests
    gmock
    gtest
    gtest_main
)

add_executable(runEnemyTests
    tests/EnemyTest.cpp
    src/Enemy.cpp
    src/enemies/Slime.cpp
    src/enemies/Goblin.cpp
    src/enemies/Ogre.cpp
    src/enemies/Dragon.cpp
    src/enemies/Robot.cpp
)

target_link_libraries(runEnemyTests
    gmock
    gtest
    gtest_main
)

add_executable(runBattleTests
    tests/BattleTimeTest.cpp
    src/BattleTime.cpp
    src/PlayerClasses.cpp
    src/Enemy.cpp
    src/players/Mage.cpp
    src/players/Warrior.cpp
    src/players/Rogue.cpp
    src/enemies/Slime.cpp
    src/enemies/Goblin.cpp
    src/enemies/Ogre.cpp
    src/enemies/Dragon.cpp
    src/enemies/Robot.cpp
)

target_link_libraries(runBattleTests
    gmock
    gtest
    gtest_main
)
