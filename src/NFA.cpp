#include "NFA.h"

int priority(char c) {
	switch(c) {
		case '*' : return 10;
		case '.' : return 9;
		case '+' : return 8;
		case '?' : return 7;
		case '|' : return 6;
		default: return 0;
	}
}

std::string shunting_yard(std::string infix) {
    char top;

    std::string postfix;
    std::stack<char> op_stack;

    for(char c : infix) {
        switch(c) {
            case '(':
                op_stack.push(c);
            break;

            case ')':
                while((top = op_stack.top()) != '(') {
                    postfix.push_back(top);
                    op_stack.pop();
                }
                
                op_stack.pop();          // Remove '('
            break;

            case '?':
            case '+':
            case '*':
            case '.':
            case '|':            
                while (op_stack.size() > 0 && 
                    priority(c) <= priority(top = op_stack.top())) {
                    postfix.push_back(top);
                    op_stack.pop();
                }
                op_stack.push(c);
            break;

            default:
                postfix.push_back(c);
        }
    }

	while(op_stack.size() > 0) {
		top = op_stack.top();
		postfix.push_back(top);
		op_stack.pop();
	}

    return postfix;
}

/**
 * Thompson's Construction of Concatenation
 */
NFA NFA::operator+(NFA &other) {  // TEST
    NFA nw(*this);
	
	nw.end->set_final(false);
	nw.end->goes_to(other.get_start());

	return nw;
}

/**
 * Thompson's Construction of Altercation
 */
NFA NFA::operator|(NFA &other) { // TEST
	NFA nw;

	this->end->set_final(false);
	other.end->set_final(false);

	nw.start->goes_to(this->start);
	nw.start->goes_to(other.start);

	this->end->goes_to(nw.end);
	other.end->goes_to(nw.end);

	return nw;
}

/**
 * Thompson's Construction of Kleene Closure
 */
NFA NFA::operator*() { // TEST
	NFA nw;

	this->get_end()->set_final(false);
	nw.get_start()->goes_to(nw.get_end());
	this->get_end()->goes_to(this->get_start());

	return nw;
}