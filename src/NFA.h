#pragma once

#include <string>
#include <unordered_set>

#include "State.h"

std::string shunting_yard(std::string infix);

class NFA {
private:
    State* start = nullptr;
	State* end = nullptr;
 
public:

	/**
	 * Default Constructor, Returns an NFA that just has no transitions.
	 */
	NFA() {
		start = new State();
		end = new State(true);
	}

	/**
	 * Char Constructor, Returns an NFA that has one character transition to end.
	 * As a result it only accepts that one character.
	 */
	NFA(char c) {
		start = new State();
		end = new State(true);

		start->goes_to(end, c);
	}

	NFA(NFA& nfa) {
		// TODO Copy constructor
	}

	/**
	 * RegEx Constructor, Returns an NFA that accepts a regular expression.
	 */
	NFA(std::string regex) {
		// Regex -> NFA : Thompson's Construction
		std::string postfix = shunting_yard(regex);

		// TODO Compile postfix
	}

	NFA operator| (NFA& other);

	NFA operator+ (NFA& other);

	NFA operator* ();

	~NFA() {
		// TODO Deconstruct Object by traversing each each node from start -> end
		// or store all nodes in a DS and destroy them that way.
	}

	State* get_start() {
		return start;
	}

	State* get_end() {
		return end;
	}

};
