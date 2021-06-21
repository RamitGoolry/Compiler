#include <gtest/gtest.h>

#include <iostream>
#include <string>

#include "../src/NFA.h"

TEST (TestShuntingYard, SingleChar) {
	std::string regex = "a";
	ASSERT_TRUE(shunting_yard(regex) == "a");
}

TEST (TestShuntingYard, SingleAltercation) {
	std::string regex = "a|b";
	ASSERT_TRUE(shunting_yard(regex) == "ab|");
}

TEST (TestShuntingYard, SingleConcatenation) {
	std::string regex = "a.b";
	ASSERT_TRUE(shunting_yard(regex) == "ab.");
}

TEST (TestShuntingYard, NoChar) {
	std::string regex = "";
	ASSERT_TRUE(shunting_yard(regex) == "");
}

TEST (TestShuntingYard, LongString) {
	std::string regex = "abcdef";
	ASSERT_TRUE(shunting_yard(regex) == "abcdef");
}

int main(int argc, char** argv) {
	testing::InitGoogleTest(&argc, argv);

	return RUN_ALL_TESTS();
}
