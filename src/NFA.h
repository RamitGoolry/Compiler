#pragma once

#include <string>
#include <unordered_set>

#include "State.h"

std::string shunting_yard(std::string infix);

class NFA {
private:
    State * start;
	State * end;
    
public:
    NFA(std::string regex) {
        // Regex -> NFA : Thompson's Construction
        std::string postfix = shunting_yard(regex);

        // TODO Compile postfix
    }
};
