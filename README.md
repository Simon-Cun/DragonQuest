[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-22041afd0340ce965d47ae6ef1cefeee28c7c493a6346c4f15d667ab976d596c.svg)](https://classroom.github.com/a/EvxoT0RF)
[![Open in Codespaces](https://classroom.github.com/assets/launch-codespace-2972f46106e565e64193e422d61a12cf1da4916b45550586e14ef0a7c637dd04.svg)](https://classroom.github.com/open-in-codespaces?assignment_repo_id=21165628)

# Text-Based Game - Dragon Quest++
Authors: [Daniyal Ahmed](https://github.com/daniyal-ahmed10) • [Simon Cun](https://github.com/Simon-Cun/) • [Samuel You](https://github.com/EveningSt3r)• [Isaiah Dacio](https://github.com/IsaiahDacio5)

## Project Description

Oh no! The dragon and his minions have stolen all microprocessors from devices around the planet, and it's our job to save them! 

We wanted to make an interactive game and apply C++ skills into making a text based RPG game in a terminal CLI. This interests us because it lets us explore cool and fun features, be creative with dialogue, and, in general, make our own video game.

We will use C++ for our backend and the terminal as our interface. The user will use the command line to send character-based inputs, and the terminal will output dialogue and other user options. 

The game will have two main components: Movement and Combat. The player will move around using direction keys, and upon entering a combat encounter, the game will notify the user. Combat will be turn-based and divided into three phases, direction, attack, and defense. In the choice phase the player will choose an option such as attack, run, or item. During the attack phase, the user will carry out their specified action, and the game will notify the user of damage, debuffs, and anything else relevant. In the defense phase, the opponent will carry out their turn and the game will notify the user of relevant stat changes and such.

---

## Tech Stack
- **C++**
- **Command Line Interface (CLI)**
---

## Features (Planned / TBD)
- **Attack:** When players come across enemies, they will have the option to attack, run, or use items. We will keep enemy encounters varied, and in our level-based system, include powerful bosses at the end to mark checkpoints.
- **Run:** In some situations, the user can choose to to run from their enemies for the chance to escape. We will use the standard C++ random library to implement this feature.
- **Inventory:** The user can choose to access their invecntory to see what abilities/weapons to use, as well as toggle between menus for easier access in and out of combat.
- **Items:** Once the user is running low on health, they can re-heal and get back to full health. We will implement a wide variety of items to be used in combat such as weapon modifications, healing / strength items, and buffs and debuffs.
- **Narrative/Dialogue:** Alongside a combat system we will implement a narrative and dialogue to give the user context on their surroundings and also keep them invested in what happens next. The dialogue will also provide a meaningful way for us to make sure the user is never lost or confused and progresses smoothly.

---

## Input/Output

Input: The game will prompt the user with choices such as character selection (“Choose your class: “ and the options will be like mage, warrior, or archer. And based on your selection you will have stats that will determine your damage output and the amount of health you have. We will also have combat interactions which will let you choose to heal, attack, or run away. Also The user can go into their inventory and choose items that will change their stat points for their health or damage. For instance equipping a helmet will reduce damage by 4 or having a sword increases damage by 2.

Output: The output will be valid choices the user has. Such as “An enemy has appeared here are your options: attack, heal, run away”. It will output the description of what is happening like is there an enemy and it will display your health and stats at the end of each move you do.

---


 
## User Interface Specification

## Navigation Diagram
[Dragon Quest++ Navigation Diagram](https://lucid.app/lucidchart/da3d09de-dd7b-4bbb-86ac-0af5aac0a730/edit?invitationId=inv_694466f5-6ded-4d73-b1d3-15401896f92a&page=0_0#)
<img width="1794" height="1378" alt="image" src="https://github.com/user-attachments/assets/b54ca752-b6b5-41b4-bf19-1dd65a8bbdc1" />

This navigation diagram shows how each screen is linked together starting from the starting screen to the end of the game. It shows the possible screens you could be at next depeneding on the user choices.

---

## Screen Layouts
[Dragon Quest++ - Screen Layout](https://docs.google.com/document/d/1Ke-DGg1IT6af0jSFB3-Ns5cM8oQHCpyVCp6cDcoSUz4/edit?usp=sharing)

All screens will be in the "game box" window provided by the terminal's GUI.


===============================================

**Starting Screen:**
Dragon Quest++
...
Press Enter to Start


===============================================

**GAME START:**
A brief blurb about the game's context and story
Instructions
Press Enter to continue


===============================================

**CLASS SELECTION:**
Please choose your class:
- **MAGE**: A powerful caster-type who has the ability to deal overpowering amounts of damage. Lower base DEF.
- **WARRIOR**: A jack-of-all-trades with moderate DEF, ATK, and HP. 
- **ROGUE**: An assassin-type who has the ability to randomly dodge attacks. DEF is replaced by STEALTH
User chooses class by typing M, W, or R, and pressing enter

===============================================


**COMMAND MENU WHEN OUT OF COMBAT:**
- MOVE = M
- INVENTORY = I
- STATS = S
- QUIT = Q
User can access their inventory or progress through the world
User types in their option and the screen will clear

================================================


**ENEMY ENCOUNTER:**
You have encountered a SLIME!
- HP: 30
- ATK: 4
- DEF: 2

What will you do?
- FIGHT = F
- INVENTORY = I
- RUN = R

The screen lets the user choose between fighting, using items, or attempting to roll to run.

=================================================


**INVENTORY SCREEN:**
YOUR CURRENT CLASS: **WARRIOR**
*Items:*
- HEALTH POTION x1
- GREATER HEALTH POTION x1
- WEAPONS:
- OATHSWORD
- TIGER'S FANG

=================================================


**STATS SCREEN:**
YOUR CURRENT CLASS: **WARRIOR**
- HP: CURRENT / MAX
- ATK: CURRENT
- DEF: CURRENT

- EXP: CURRENT / EXP TO LVL UP

=================================================


**FIGHT SCREEN:**
(When user chooses to fight in an encounter)
- ATTACK WITH (NAME OF WEAPON) (Some weapons will have unique properties)
- BLOCK
- SPECIAL (Class-unique actions, like powerful spells for mages, or evasion boosts for rogues)
You have chosen to use ACTION
Screen clears when battle ends

---





## Class Diagram
[Dragon Quest++ - Class Diagram](https://lucid.app/lucidchart/419219fc-910f-41ff-aebf-cfc0c0618d76/edit?beaconFlowId=9073B42EF962BC59&page=0_0&invitationId=inv_f315a160-fa9c-49ed-86b4-58bcf5f5f1c6#)
<img width="1122" height="488" alt="Image" src="https://github.com/user-attachments/assets/ffde4b6b-38ab-4d37-a245-8534d07a92bf" />

For playable characters, a single "PlayerClasses" base class encompasses all types of players in the game (i.e. Warrior, Rogue, Mage). The type subclasses set the base stats for the instantiated PlayerClasses.

For enemy characters, an "Enemy" base class encompasses all types of enemies in the game (i.e Slime, Goblin, Dragon, etc.). The type subclasses also set the base stats for instantiated Enemy classes.

This keeps the game open to the addition of new characters and enemies further down the line. Different characters have their respective stats, including attack, defense, dodging, and health points. The "PlayerClasses" class goes a little further to include the user's name and type.

The "BattleTime" class covers the game's battle system, covering actions under the user's turn (attack, use an item from the inventory, or run), and the enemy's turn (user defends). Different actions depend on the stats found in PlayerClasses and Enemy.

The "GameDriver" class covers interactions with the game outside of battle (ie. dialogue, path scenarios, menu interactions, etc.). The GameDriver class also handles battles through functions implemented by the BattleTime class.

---

### Class Diagram and SOLID Principles

PlayerClasses, Mage, Warrior, Rogue: 
1. Open-Closed Principle (OCP) - The player types (Mage, Warrior, Rogue) only set base stats for PlayerClasses. With this, more player types can be added without modifying PlayerClasses. For example, we can implement a Cleric player type without having to change PlayerClasses to accomodate extra moves.
2. Liskov Substitution Principle (LSP) - Again, Mage, Warrior, and Rogue only set base stats. Thus, the player types cannot break the expected behavior in PlayerClasses. Also, the player tdo not add new constraints on the base class.
3. Interface Segregation Principle (ISP) - Mage, Warrior, and Rogue do not implement unused methods since they only set base stats.


Enemy and related enemy type subclasses:
1. Single Responsibility Principle (SRP) - Enemy controls enemy stats, while subclasses like Ogre, Robot, etc. control their specific stats, delegating each thing to one class. Each class only has one responsibility in the overall program.
2. Open-Closed Principle (OCP) - More enemies can be added without modifying the enemy class and all enemy class updates will carry over. Enemies is open for modification but the subclasses cannot damage it. 
3. Liskov Substitution Principle (LSP) - Enemy sublcasses cannot break enemy, as enemy only provides base stats and the getters and setters which the subclasses cannot modify. The subclasses only inherit what they need.
4. Interface Segregation Principe (ISP) - Enemy subclasses use all of enemy's methods at least once and do not implement unused methods, therefore not having the user carry the baggage of separate enemy classes that are not needed (ogre does not need robot)
5. Dependency Inversion Principle (DIP) - Enemies does not depend on enemy. The program depends on enemy, not on ogre, robot, etc. The game driver instantiates using Enemy, which then instantiates the subclasses.

BattleTime:
1. Single Responsibility Principle (SRP) - BattleTime manages the battle system which includes turn handling, actions, and combat flow. It only has one task and that is to manage the combat system between the player and enemy.
2. Open-Closed Principle (OCP) - BattleTime works entirely through abstract classes meaning you can add new player and enemy classes all without modifying BattleTime itself.
3. Liskov Substitution Principle (LSP) - Any subclass of PlayerClasses or Enemy can be used in BattleTime without breaking behavior, because the class only depends on the base-class methods. So it doesn’t matter if we use the children's classes.
4. Dependency Inversion Principle (DIP) - BattleTime depends on abstractions (PlayerClasses and Enemy), not concrete classes like Mage or Ogre. It depends on the abstraction of the Player and Enemies where it uses the methods found in player and enemy to simulate their combat.

GameDriver:
1. Single Responsibility Principle (SRP) - Applied SRP by making GameDriver responsible only for handling the overall game flow and user interaction. I specifically avoided putting any combat logic or stat calculations in GameDriver and instead split up that work to BattleTime, PlayerClasses, and Enemy. This change kept the driver clearer and easier to understand because it only coordinates screens and choicesand isn't in charge of everything. It also makes future changes safer, since I can modify battle logic or stats without having to worry about the driver.
2. Open-Closed Principle (OCP) - Applied OCP by having GameDriver work with the PlayerClasses type instead of hardcoding behavior for Mage, Warrior, and Rogue. The driver just chooses which subclass to create based on user input, but it doesn’t need to change if we want to add a new class. This means the code is open for extension but cannot be modified.
   
---
 
 ## Screenshots
 > Screenshots of the input/output after running your application
<img width="882" height="932" alt="image" src="https://github.com/user-attachments/assets/2c2009cf-854e-46e8-ab29-67cc4361045d" />
<img width="882" height="972" alt="image" src="https://github.com/user-attachments/assets/16fcc36b-c1da-4503-8100-4a27640657bf" />
<img width="882" height="892" alt="image" src="https://github.com/user-attachments/assets/930cf6f4-7c5e-4615-8b1d-ec013c9ffbe4" />
<img width="882" height="1020" alt="image" src="https://github.com/user-attachments/assets/553b6330-d0fe-423f-a7c7-674e2522c079" />
<img width="882" height="291" alt="image" src="https://github.com/user-attachments/assets/7c74559b-606a-440d-94a5-be8f58091b40" />
<img width="882" height="243" alt="image" src="https://github.com/user-attachments/assets/c4505598-5ca5-462d-a119-1088b3897ade" />
<img width="882" height="486" alt="image" src="https://github.com/user-attachments/assets/60173759-74a7-4b20-acba-56fa8bd4be10" />
<img width="882" height="302" alt="image" src="https://github.com/user-attachments/assets/1b65a65f-dcce-4afd-9358-5890e722549c" />
<img width="706" height="396" alt="image" src="https://github.com/user-attachments/assets/78e241a3-c8a1-42a3-ad59-3693213d79de" />
<img width="1571" height="641" alt="image" src="https://github.com/user-attachments/assets/3926abf5-cd90-4a37-be54-a93bb27e2bdb" />

 ## Installation/Usage
 > Instructions on installing and running your application
Clone the repository
```
git clone https://github.com/cs100/final-project-dahme007-scun002-syou029-idaci001.git
```

```
cd final-project-dahme007-scun002-syou029-idaci001
```

Create a build directory
```
mkdir build
cd build
```

Configure with CMake
```
cmake ..
```

Build the project
```
make
```

When compiled all the executables will appear in build/bin/ where you can run the game in the bin folder by doing:
```
./bin/game
```
 ## Testing
 We tested our project by implementing unit tests for each of the core functions used in the program. We wrote tests using GoogleTest which tested player functinality and behavior, battle logic, an d We also manually tested by playing our game through the terminal. We went through different scenarios that were possible which provided a variety of outputs, which helped test that out program functioned correctly, no matter what path the user chose. 
 
