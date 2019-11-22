#include "graph.hpp"


int main(int argc, char** argv)
{
	Graph G;
	ofstream outfile("output.txt");
	ifstream infile("input.txt");
	infile >> G;
	G.projects(infile);
}

