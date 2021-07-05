#include "State.h"

void State::goes_to(State *next, char c) {
	this->transitions[c] = next;
}