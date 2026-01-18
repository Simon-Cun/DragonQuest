#include "gtest/gtest.h"
#include "GameDriver.h"

#include <sstream>
#include <iostream>
#include <queue>

class TestDriver : public GameDriver {
public:
    std::stringstream input;
    std::stringstream output;

    std::streambuf* cin_backup;
    std::streambuf* cout_backup;

    TestDriver() {
        cin_backup = std::cin.rdbuf(input.rdbuf());
        cout_backup = std::cout.rdbuf(output.rdbuf());
    }

    ~TestDriver() {
        std::cin.rdbuf(cin_backup);
        std::cout.rdbuf(cout_backup);
    }

    std::queue<std::string> fakeLines;

    int forcedRand = 0;
    int randPercent() { return forcedRand; }

    std::string getLine() {
        if (fakeLines.empty()) return "";
        std::string s = fakeLines.front();
        fakeLines.pop();
        return s;
    }

    void addLine(const std::string& line) { fakeLines.push(line); }

    PlayerClasses& playerRef() { return getPlayerForTesting(); }
    std::string& nameRef() { return getNameForTesting(); }
};


TEST(GameDriverTests, RandPercentWithinRange) {
    TestDriver g;

    for (int i = 0; i < 100; i++) {
        g.forcedRand = i;
        int result = g.randPercent();
        EXPECT_GE(result, 0);
        EXPECT_LE(result, 99);
    }
}

TEST(GameDriverTests, ChooseNameWorks) {
    TestDriver g;
    
    g.addLine("Simon");
    g.addLine("");

    g.choosePlayerName();

    EXPECT_EQ(g.nameRef(), "Hero");
}

TEST(GameDriverTests, ChooseMageClassWorks) {
    TestDriver g;

    g.input << "M\n";
    g.nameRef() = "Simon";

    g.addLine("");

    g.choosePlayerClass();

    EXPECT_EQ(g.playerRef().getPlayerType(), "Mage");
    EXPECT_EQ(g.playerRef().getPlayerName(), "Simon");
}

TEST(GameDriverTests, ChooseWarriorClassWorks) {
    TestDriver g;

    g.input << "W\n";
    g.nameRef() = "Simon";

    g.addLine("");

    g.choosePlayerClass();

    EXPECT_EQ(g.playerRef().getPlayerType(), "Warrior");
    EXPECT_EQ(g.playerRef().getPlayerName(), "Simon");
}

TEST(GameDriverTests, ChooseRogueClassWorks) {
    TestDriver g;

    g.input << "R\n";
    g.nameRef() = "Simon";

    g.addLine("");

    g.choosePlayerClass();

    EXPECT_EQ(g.playerRef().getPlayerType(), "Rogue");
    EXPECT_EQ(g.playerRef().getPlayerName(), "Simon");
}

TEST(GameDriverTests, TitleScreenPrintsCorrectly) {
    TestDriver g;
    g.addLine("");

    g.showTitleScreen();

    std::string out = g.output.str();
    EXPECT_NE(out.find("Dragon Quest++"), std::string::npos);
}

TEST(GameDriverTests, IntroDialoguePrintsCorrectly) {
    TestDriver g;
    g.addLine("");

    g.showIntroDialogue();

    std::string out = g.output.str();
    EXPECT_NE(out.find("Welcome, traveler"), std::string::npos);
}