default: clean compile run

compile:
	mkdir build
	g++ --std=c++11 -g src/main.cpp -o build/main src/NFA.cpp

run:
	./build/main

clean:
	rm -rf build
