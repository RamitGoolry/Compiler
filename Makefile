test_scanner: test_scanner_compile test_scanner_run
default: compile run

compile:
	g++ --std=c++11 -g src/main.cpp -o build/main src/NFA.cpp src/State.cpp

run:
	build/main

test_scanner_compile:
	g++ --std=c++11 -g tests/test_scanner.cpp -o build/tests/scanner -lgtest -lgtest_main -pthread src/NFA.cpp src/State.cpp

test_scanner_run:
	build/tests/scanner
