#pragma once
#include <string>
using namespace std;

class Items {
    protected:
        string name;
        string description;
    public:
        Items();
        void setName(string);
        string getName();
        void setDescription(string);
        string getDescription();
};