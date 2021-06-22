#pragma once

#include <unordered_map>

class State {
private:
    // REVIEW Does State need an ID?
    std::unordered_map<char, State *> transitions;
    bool final;

public:
	static const char EPSILON = '\0';
    State(bool final_ = false) : final(final_) {}

    State* epsilon_closure(); // TODO

	void goes_to(State * next, char c);
	
	bool is_final() { return final; }

	/** 
	 * While an NFA can have multiple states, a DFA is Deterministic, it will
	 * only have one state. We will return a single pointer since that is the
	 * DFA's API which we will be following.
	 */
	State* follow (char c = EPSILON) {
		if(transitions.find(c) != transitions.end()) // Character in Transitions
			return transitions[c];
		else return nullptr; // Failure to accept
	}
};
