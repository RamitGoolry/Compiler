#include <gtest/gtest.h>

#include <iostream>
#include <string>

#include "../src/NFA.h"

TEST (ShuntingYard, NoChar) {
	EXPECT_TRUE(shunting_yard("") == "");
}

TEST (ShuntingYard, SingleChar) {
	EXPECT_TRUE(shunting_yard("a") == "a");
}

TEST (ShuntingYard, SingleOp) {
	EXPECT_TRUE(shunting_yard("a|b") == "ab|");
	EXPECT_TRUE(shunting_yard("a.b") == "ab.");
	EXPECT_TRUE(shunting_yard("a*") == "a*");
}

TEST (ShuntingYard, MultipleOp) {
	EXPECT_TRUE(shunting_yard("a|b|c") == "ab|c|");
	EXPECT_TRUE(shunting_yard("a.b|c") == "ab.c|");
	EXPECT_TRUE(shunting_yard("a.b|c") == "ab.c|");
}

TEST (ShuntingYard, Parenthesis) {
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

TEST (NFA, DefaultConstructor) {
	NFA nfa;

	// Testing if string was constructed correctly
	EXPECT_FALSE(nfa.get_start()->is_final());
	EXPECT_TRUE(nfa.get_end()->is_final());

	// Testing edges
	EXPECT_TRUE(nfa.get_start()->follow() == nullptr);
	EXPECT_TRUE(nfa.get_start()->follow(State::EPSILON) == nullptr);
	EXPECT_TRUE(nfa.get_start()->follow('a') == nullptr);
	EXPECT_TRUE(nfa.get_start()->follow('b') == nullptr);
	EXPECT_TRUE(nfa.get_start()->follow('c') == nullptr);
}

TEST (NFA, CharConstructor) {
	NFA nfa('R');

	// Testing if string was constructed correctly
	EXPECT_FALSE(nfa.get_start()->is_final());
	EXPECT_TRUE(nfa.get_end()->is_final());

	// Testing edges
	EXPECT_TRUE(nfa.get_start()->follow('R') == nfa.get_end()); // Should pass

	// All these should fail
	EXPECT_TRUE(nfa.get_start()->follow() == nullptr);
	EXPECT_TRUE(nfa.get_start()->follow(State::EPSILON) == nullptr);
	EXPECT_TRUE(nfa.get_start()->follow('a') == nullptr);
}

int main(int argc, char** argv) {
	testing::InitGoogleTest(&argc, argv);

	return RUN_ALL_TESTS();
}
