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
        void setDescription(string);


};