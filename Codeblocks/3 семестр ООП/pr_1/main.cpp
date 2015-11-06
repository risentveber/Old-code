#include <iostream>
#include <fstream>
#include <iomanip>
#include "Graph.h"

using namespace std;

bool parser(istream & input, Graph& graph)
{
	char a;
	input >> a;
	unsigned x, y;
	switch (a){
	case '+' :
		input >> x;
		input >> y;
		graph.add_edge(x, y);
		return true;
	case '-':
		input >> x;
		input >> y;
		graph.del_edge(x, y);
		return true;
	case 's':
    {
		input >> x;
		input >> y;
		input >> ws;
        auto ptr=make_shared<TWord>();
		input.getline(ptr->word, TWord::buf_size);
		graph.rename(x, y, ptr);
		return true;
    }
	case 'c':
		input >> x;
		input >> y;
		graph.del_name(x, y);
		return true;
	case 'f':
		graph.search_components();
		return true;
	case 'p':
		cout << "print graph" << endl;
		cout << graph;
		return true;
	case 'e':
		return false;
	default:
		cerr << "unexpected input" << endl;
		return false;
	};

}

void read_file(Graph & graph)
{
	ifstream infile;
	infile.open("input.txt", ios::in);
	unsigned n;
	infile >> n;
	if (!infile.good()){
		//cerr << "file not exist" << endl;
		return;
	}
	for(unsigned i = 0; i < n; ++i){
		parser(infile, graph);
	}
}

void proc_input(Graph & graph)
{
	while (parser(cin, graph));
}

int main()
{
	Graph graph;

	read_file(graph);
	proc_input(graph);

	exit(0);
}
