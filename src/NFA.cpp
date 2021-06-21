#include "NFA.h"

#include <unordered_map>
#include <stack>

std::string shunting_yard(std::string infix) { // TEST
    char top;

    // Priority of special characters
    std::unordered_map<char, int> specials {
		{'*', 10}, {'.', 9}, {'+', 8},
		{'?', 7}, {'|', 6}
	};

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
                    specials[c] <= (specials.find(top = op_stack.top()) != specials.end() ? specials[top] : 0)) {
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
