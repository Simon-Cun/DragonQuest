#include "PlayerClasses.h"
#include "Items.h"
#include <string>
using namespace std;

Items::Items() : name(""), description("") {}

void Items::setName(string nameSet) {
    name = nameSet;
}

void Items::setDescription(string desc) {
    description = desc;
}

string Items::getName() {
    return name;
}

string Items::getDescription() { 
    return description;
}
