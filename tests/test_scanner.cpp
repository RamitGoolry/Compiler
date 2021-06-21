#include <gtest/gtest.h>

#include <iostream>
#include <string>

#include "../src/NFA.h"

TEST (TestShuntingYard, NoChar) {
	EXPECT_TRUE(shunting_yard("") == "");
}

TEST (TestShuntingYard, SingleChar) {
	EXPECT_TRUE(shunting_yard("a") == "a");
}

TEST (TestShuntingYard, SingleOp) {
	EXPECT_TRUE(shunting_yard("a|b") == "ab|");
	EXPECT_TRUE(shunting_yard("a.b") == "ab.");
	EXPECT_TRUE(shunting_yard("a*") == "a*");
}

TEST (TestShuntingYard, Multiple_Op) {
	EXPECT_TRUE(shunting_yard("a.b|c") == "ab.c|");
}

TEST (TestShuntingYard, Parenthesis) {
	EXPECT_TRUE(shunting_yard("()") == "");
	EXPECT_TRUE(shunting_yard("()()") == "");
	EXPECT_TRUE(shunting_yard("(())") == "");


	EXPECT_TRUE(shunting_yard("(a|b)") == "ab|");
	EXPECT_TRUE(shunting_yard("(a.b)") == "ab.");
	EXPECT_TRUE(shunting_yard("(a*)") == "a*");

	EXPECT_TRUE(shunting_yard("(a)(b)") == "ab");
	EXPECT_TRUE(shunting_yard("(a|b)|c") == "ab|c|");
	EXPECT_TRUE(shunting_yard("(a?)(b|c)") == "a?bc|");
}

int main(int argc, char** argv) {
	testing::InitGoogleTest(&argc, argv);

	return RUN_ALL_TESTS();
}
