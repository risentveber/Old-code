all: Graph

Graph: main.o vert.o graph.o
	g++ main.o vert.o graph.o -o Graph.out

main.o:
	g++ -g -std=c++11 -c main.cpp
graph.o:
	g++ -g -std=c++11 -c Graph.cpp -o graph.o
vert.o:
	g++ -g -std=c++11 -c Vert.cpp -o vert.o

