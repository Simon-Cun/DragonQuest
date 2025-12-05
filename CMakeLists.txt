cmake_minimum_required(VERSION 3.20)
project(final_project)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

add_subdirectory(googletest)

include_directories(
    ${CMAKE_SOURCE_DIR}/include
    ${CMAKE_SOURCE_DIR}/include/players
    ${CMAKE_SOURCE_DIR}/include/enemies
    ${CMAKE_SOURCE_DIR}/include/items
    ${CMAKE_SOURCE_DIR}/include/items/Armors
    ${CMAKE_SOURCE_DIR}/include/items/Potions
    ${CMAKE_SOURCE_DIR}/include/items/Weapons
)

# ===================================================================
#                         PLAYER TESTS
# ===================================================================
add_executable(runPlayerTests
    tests/PlayerTests.cpp
    src/PlayerClasses.cpp
    src/players/Mage.cpp
    src/players/Warrior.cpp
    src/players/Rogue.cpp
)

target_compile_definitions(runPlayerTests PRIVATE GTEST)
target_link_libraries(runPlayerTests gmock gtest gtest_main)

# ===================================================================
#                         ENEMY TESTS
# ===================================================================
add_executable(runEnemyTests
    tests/EnemyTest.cpp
    src/Enemy.cpp
    src/enemies/Slime.cpp
    src/enemies/Goblin.cpp
    src/enemies/Ogre.cpp
    src/enemies/Dragon.cpp
    src/enemies/Robot.cpp
)

target_compile_definitions(runEnemyTests PRIVATE GTEST)
target_link_libraries(runEnemyTests gmock gtest gtest_main)

# ===================================================================
#                        BATTLE SYSTEM TESTS
# ===================================================================
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

target_compile_definitions(runBattleTests PRIVATE GTEST)
target_link_libraries(runBattleTests gmock gtest gtest_main)

# ===================================================================
#                        MAIN GAME EXECUTABLE
# ===================================================================
add_executable(game
    src/driverDragonQuest.cpp
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

    src/Items/Items.cpp

    src/Items/Armors/Armor.cpp
    src/Items/Armors/Dragonsbane.cpp
    src/Items/Armors/Obsidiansentinel.cpp

    src/Items/Potions/Potion.cpp
    src/Items/Potions/GreaterHealthPotion.cpp
    src/Items/Potions/LesserHealthPotion.cpp

    src/Items/Weapons/Weapon.cpp
    src/Items/Weapons/Frostforged.cpp
    src/Items/Weapons/Thunderfury.cpp
)
