

all: main point

main: Main.cpp point
	g++ -std=c++17 -Wall Main.cpp -o main

point: Point.cpp Point.h
	g++ -std=c++17 -Wall -c Point.cpp

clean: 
	rm main Point.o


