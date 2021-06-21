#pragma once

#include <string>
#include <unordered_set>

#include "State.h"

std::string shunting_yard(std::string infix);

class NFA {
private:
    std::unordered_set<State *> states; 
    // REVIEW Do we even need this if we are starting always from start?

    State * start;
    
public:
    NFA(std::string regex) {
        // Regex -> NFA : Thompson's Construction
        std::string postfix = shunting_yard(regex);

        // TODO Compile postfix
    }
};
