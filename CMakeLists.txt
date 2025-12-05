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
#                        GAME LIBRARY
# ===================================================================
add_library(game_lib
    src/GameDriver.cpp
    src/BattleTime.cpp
    src/PlayerClasses.cpp
    src/Enemy.cpp

    # Players
    src/players/Mage.cpp
    src/players/Warrior.cpp
    src/players/Rogue.cpp

    # Enemies
    src/enemies/Slime.cpp
    src/enemies/Goblin.cpp
    src/enemies/Ogre.cpp
    src/enemies/Dragon.cpp
    src/enemies/Robot.cpp

    # Items (correct directory)
    src/Items.cpp

    # Armors
    src/Items/Armors/Armor.cpp
    src/Items/Armors/Dragonsbane.cpp
    src/Items/Armors/Obsidiansentinel.cpp

    # Potions
    src/Items/Potions/Potion.cpp
    src/Items/Potions/GreaterHealthPotion.cpp
    src/Items/Potions/LesserHealthPotion.cpp

    # Weapons
    src/Items/Weapons/Weapon.cpp
    src/Items/Weapons/Frostforged.cpp
    src/Items/Weapons/Thunderfury.cpp
)

target_include_directories(game_lib PUBLIC ${CMAKE_SOURCE_DIR}/include)

# ===================================================================
#                         PLAYER TESTS
# ===================================================================
add_executable(runPlayerTests
    tests/PlayerTests.cpp
)
target_compile_definitions(runPlayerTests PRIVATE GTEST)
target_link_libraries(runPlayerTests game_lib gmock gtest gtest_main)

# ===================================================================
#                         ENEMY TESTS
# ===================================================================
add_executable(runEnemyTests
    tests/EnemyTest.cpp
)
target_compile_definitions(runEnemyTests PRIVATE GTEST)
target_link_libraries(runEnemyTests game_lib gmock gtest gtest_main)

# ===================================================================
#                        BATTLE SYSTEM TESTS
# ===================================================================
add_executable(runBattleTests
    tests/BattleTimeTest.cpp
)
target_compile_definitions(runBattleTests PRIVATE GTEST)
target_link_libraries(runBattleTests game_lib gmock gtest gtest_main)

# ===================================================================
#                        ITEM TESTS
# ===================================================================
add_executable(runItemTests
    tests/ItemTests.cpp
)
target_compile_definitions(runItemTests PRIVATE GTEST)
target_link_libraries(runItemTests game_lib gmock gtest gtest_main)

# ===================================================================
#                        MAIN GAME EXECUTABLE
# ===================================================================
add_executable(game
    src/driverDragonQuest.cpp
)
target_link_libraries(game game_lib)
