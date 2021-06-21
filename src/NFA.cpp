#include "NFA.h"

#include <unordered_map>
#include <stack>

std::string shunting_yard(std::string infix) { // TEST
    char top;

    // Priority of special characters
    std::unordered_map<char, int> specials {
		{'?', 70}, {'+', 60}, {'*', 50},
		{'.', 40}, {'|', 30}
	};

    std::string postfix;
    std::stack<char> stk;

    for(char c : infix) {
        switch(c) {
            case '(':
                stk.push(c);
            break;

            case ')':
                while((top = stk.top()) != '(') {
                    postfix.push_back(top);
                    stk.pop();
                }
                
                stk.pop();          // Remove '('
            break;

            case '?':
            case '+':
            case '*':
            case '.':
            case '|':            
                while (stk.size() > 0 && 
                    specials[c] <= (specials.find(top = stk.top()) != specials.end() ? specials[top] : 0)) {
                    postfix.push_back(top);
                    stk.pop();
                }
                stk.push(c);
            break;

            default:
                postfix.push_back(c);
        }
    }

	while(stk.size() > 0) {
		top = stk.top();
		postfix.push_back(top);
		stk.pop();
	}

    return postfix;
}
