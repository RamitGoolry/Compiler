#include <iostream>
#include <gtest/gtest.h>

#include "NFA.h"

int main() {
	std::string regex = "a|b";

	std::cout << shunting_yard(regex) << std::endl;

	return 0;
}
