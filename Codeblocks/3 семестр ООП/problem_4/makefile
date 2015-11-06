COMP = g++-4.7

main: main.o experemental_graph.o experemental_result.o
	g++ -o experement.out main.o experemental_graph.o experemental_result.o -lboost_program_options

main.o: main.cpp experemental_graph.h
	${COMP} -std=c++11 -c main.cpp

experemental_graph.o: experemental_graph.cpp experemental_graph.h
	${COMP} -std=c++11 -c experemental_graph.cpp

experemental_result.o: experemental_result.cpp experemental_graph.h
	${COMP} -std=c++11 -c experemental_result.cpp

clean:
	rm *.o
	rm *.out
