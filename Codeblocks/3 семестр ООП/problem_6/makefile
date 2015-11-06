
all: analizator.out

analizator.out: main.o axo.o help_functions.o base_of_string.o
	g++ -o analizator.out  main.o axo.o help_functions.o base_of_string.o -lboost_filesystem

main.o: main.cpp help_functions.hpp base_of_string.hpp help_classes.hpp
	g++-4.7 -c -std=c++11 main.cpp -o main.o
axo.o: axo.cpp axo.hpp
	g++-4.7 -c -std=c++11 axo.cpp -o axo.o
help_functions.o: help_functions.cpp help_functions.hpp
	g++-4.7 -c -std=c++11 help_functions.cpp -o help_functions.o
base_of_string.o: base_of_string.cpp base_of_string.hpp help_classes.hpp
	g++-4.7 -c -std=c++11 base_of_string.cpp -o base_of_string.o

