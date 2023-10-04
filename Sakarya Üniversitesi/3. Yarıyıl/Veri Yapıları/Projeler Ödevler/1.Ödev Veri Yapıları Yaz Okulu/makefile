all: compile run

compile:
	g++ -I ./include/ -o ./lib/FileProcessor.o -c ./src/FileProcessor.cpp
	g++ -I ./include/ -o ./lib/LinkedList.o -c ./src/LinkedList.cpp
	g++ -I ./include/ -o ./lib/Node.o -c ./src/Node.cpp
	g++ -I ./include/ -o ./lib/Main.o -c ./src/Main.cpp
	g++ -o ./bin/Program ./lib/FileProcessor.o ./lib/LinkedList.o ./lib/Node.o ./lib/Main.o

run:
	./bin/Program
