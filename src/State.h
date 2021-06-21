#pragma once

#include <unordered_map>

class State {
private:
    // Does State need an ID?
    std::unordered_map<char, State *> transitions;
    bool final;

public:
    State(bool final_ = false) : final(final_) {}

    State* epsilon_closure(); // TODO
};