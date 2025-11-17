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


 > ## Phase II
 
## User Interface Specification

### Navigation Diagram
[Dragon Quest++ Navigation Diagram](https://lucid.app/lucidchart/da3d09de-dd7b-4bbb-86ac-0af5aac0a730/edit?invitationId=inv_694466f5-6ded-4d73-b1d3-15401896f92a&page=0_0#)
<img width="1794" height="1378" alt="image" src="https://github.com/user-attachments/assets/b54ca752-b6b5-41b4-bf19-1dd65a8bbdc1" />

This navigation diagram shows how each screen is linked together starting from the starting screen to the end of the game. It shows the possible screens you could be at next depeneding on the user choices.

---

### Screen Layouts
[Dragon Quest++ - Screen Layout](https://docs.google.com/document/d/1Ke-DGg1IT6af0jSFB3-Ns5cM8oQHCpyVCp6cDcoSUz4/edit?usp=sharing)

All screens will be in the "game box" window provided by the terminal's GUI.

**STARTING SCREEN:** 
Dragon Quest++
...
Press Enter to Start

**GAME START:**
[A brief blurb about the game's context and story]
[Instructions]
Press Enter to continue

**CLASS SELECTION:**
Please choose your class:
*MAGE:* A powerful caster-type who has the ability to deal overpowering amounts of damage. Lower base DEF.
*WARRIOR:* A jack-of-all-trades with moderate DEF, ATK, and HP. 
*ROGUE:* An assassin-type who has the ability to randomly dodge attacks. DEF is replaced by STEALTH
[User chooses class by typing M, W, or R, and pressing enter]

**COMMAND MENU WHEN OUT OF COMBAT:**
MOVE[M]
INVENTORY[I]
STATS[S]
QUIT[Q]
[User can access their inventory or progress through the world]
[User types in their option and the screen will clear]

**ENEMY ENCOUNTER:**
You have encountered a [SLIME]!
HP: 30
ATK: 4
DEF: 2

What will you do?
FIGHT[F]
INVENTORY[I]
RUN[R]

[The screen lets the user choose between fighting, using items, or attempting to roll to run.]

**INVENTORY SCREEN:**
YOUR CURRENT CLASS: WARRIOR
Items:
HEALTH POTION x1
GREATER HEALTH POTION x1
WEAPONS:
OATHSWORD
TIGER'S FANG


**STATS SCREEN:**
YOUR CURRENT CLASS: WARRIOR
HP: [CURRENT HP]/[MAX HP]
ATK: [CURRENT ATK]
DEF: [CURRENT DEF]

EXP: [CURRENT EXP] / [EXP TO LEVEL UP]


**FIGHT SCREEN:**
(When user chooses to fight in an encounter)
1. ATTACK WITH [NAME OF WEAPON] (Some weapons will have unique properties)
2. BLOCK
3. SPECIAL (Class-unique actions, like powerful spells for mages, or evasion boosts for rogues)
[You have chosen to use [ACTION] ]
[Screen clears when battle ends]

---

## Class Diagram
[Dragon Quest++ - Class Diagram](https://lucid.app/lucidchart/419219fc-910f-41ff-aebf-cfc0c0618d76/edit?beaconFlowId=9073B42EF962BC59&page=0_0&invitationId=inv_f315a160-fa9c-49ed-86b4-58bcf5f5f1c6#)
<img width="1122" height="488" alt="Image" src="https://github.com/user-attachments/assets/ffde4b6b-38ab-4d37-a245-8534d07a92bf" />

For characters, a single "Character" class encompasses all types of characters in the game, including player types (i.e. Warrior, Rogue, Mage) and enemy types (i.e Slime, Goblin, Dragon, etc.). This keeps the game open to the addition of new characters further down the line. Different characters have their respective stats, including attack, defense, dodging, and health points. The "Player" class will include the user's name, but will inherit stats from the "Character" class.

The "BattleTime" class covers the game's battle system, including actions such as the action phase (attack, use an item from the inventory, or run), and the enemy attack (or defense) phase. Different actions are linked to separate classes. The "AttackAction" and "EnemyAttacks" classes are connected to the "Character" class since they both rely on the stats of different characters.

The "CheckInventory" class covers the game's item system, which can both be accessed in and out of battle. Thus, both the "Player" and "BattleTime" classes use the "CheckInventory" class.

---
 
 > ## Phase III
 > You will need to schedule a check-in for the second scrum meeting with the same reader you had your first scrum meeting with (using Calendly). Your entire team must be present. This meeting will occur on week 8 during lab time.
 
 > BEFORE the meeting you should do the following:
 > * Update your class diagram from Phase II to include any feedback you received from your TA/grader.
 > * Considering the SOLID design principles, reflect back on your class diagram and think about how you can use the SOLID principles to improve your design. You should then update the README.md file by adding the following:
 >   * A new class diagram incorporating your changes after considering the SOLID principles.
 >   * For each update in your class diagram, you must explain in 3-4 sentences:
 >     * What SOLID principle(s) did you apply?
 >     * How did you apply it? i.e. describe the change.
 >     * How did this change help you write better code?
 > * Perform a new sprint plan like you did in Phase II.
 > * Make sure that your README file (and Project board) are up-to-date reflecting the current status of your project and the most recent class diagram. Previous versions of the README file should still be visible through your commit history.
>  * Each team member should also submit the Peer Evaluation Form on Canvas for phase III. In this form, you need to fill in the names of all team members, the percentage of work contributed by each member for phase III, and a description of their contributions. Remember that each team member should submit the form individually.
 
> During the meeting with your reader you will discuss: 
 > * How effective your last sprint was (each member should talk about what they did)
 > * Any tasks that did not get completed last sprint, and how you took them into consideration for this sprint
 > * Any bugs you've identified and created issues for during the sprint. Do you plan on fixing them in the next sprint or are they lower priority?
 > * What tasks you are planning for this next sprint.

 
 > ## Final deliverable
 > All group members will give a demo to the reader during lab time. ou should schedule your demo on Calendly with the same reader who took your second scrum meeting. The reader will check the demo and the project GitHub repository and ask a few questions to all the team members. 
 > Before the demo, you should do the following:
 > * Complete the sections below (i.e. Screenshots, Installation/Usage, Testing)
 > * Plan one more sprint (that you will not necessarily complete before the end of the quarter). Your In-progress and In-testing columns should be empty (you are not doing more work currently) but your TODO column should have a full sprint plan in it as you have done before. This should include any known bugs (there should be some) or new features you would like to add. These should appear as issues/cards on your Project board.
 > * Make sure your README file and Project board are up-to-date reflecting the current status of your project (e.g. any changes that you have made during the project such as changes to your class diagram). Previous versions should still be visible through your commit history.
>  * Each team member should also submit the Peer Evaluation Form on Canvas for this final phase. In this form, you need to fill in the names of all team members, the percentage of work contributed by each member for the final phase, and a description of their contributions. Remember that each team member should submit the form individually.
 
 ## Screenshots
 > Screenshots of the input/output after running your application
 ## Installation/Usage
 > Instructions on installing and running your application
 ## Testing
 > How was your project tested/validated? If you used CI, you should have a "build passing" badge in this README.
 
