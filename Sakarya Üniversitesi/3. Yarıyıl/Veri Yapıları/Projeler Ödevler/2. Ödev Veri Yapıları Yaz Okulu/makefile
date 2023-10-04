all: compile run

compile:
	g++ -I ./include/ -o ./lib/Node.o -c ./src/Node.cpp
	g++ -I ./include/ -o ./lib/BST.o -c ./src/BST.cpp
	g++ -I ./include/ -o ./lib/Main.o -c ./src/Main.cpp
	g++ -o ./bin/Program ./lib/Node.o ./lib/BST.o ./lib/Main.o

run:
	./bin/Program
