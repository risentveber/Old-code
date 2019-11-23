CC = g++-4.7 -std=c++11

MST.out: main.cpp ./libs/disjoint_sets.a
	$(CC)  -o MST.out -I./libs/ main.cpp ./libs/disjoint_sets.a

./libs/disjoint_sets.a: ./libs/disjoint_sets.h ./libs/disjoint_sets.cpp
	$(CC) -c -I./libs/ ./libs/disjoint_sets.cpp -o ./libs/disjoint_sets.a 


