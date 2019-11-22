#include <iostream>
#include <vector>
#include <sstream>

#include <list>

using namespace std;

const unsigned pause = 2;
const unsigned transition = 3;
const unsigned escalator = 2;

class Edge
{
public:
	unsigned id;//from --> id only in Vertex
	unsigned line;
	unsigned weight;
	Edge() : line(UINT_MAX), weight(UINT_MAX) {};
};

class D //используется для матриц при нахождении расстояний в алгоритме флойда уоршелла
{
public:
	unsigned d;
	unsigned right;
	unsigned left;
	D() : d(UINT_MAX), right(UINT_MAX), left(UINT_MAX) {};
	friend bool operator < (const D &, const D &);
	friend D operator + (const D &, const D &);
};

bool operator < (const D & a, const D & b){
	return (a.d < b.d);
}

D operator + (const D & a, const D & b){
	D result;
	result.d = a.d + b.d;
	if ( a.right != b.left )
		result.d += transition + pause;
	result.left = a.left;
	result.right = b.right;
	return result;
}

class Vertex
{
public:
	unsigned line;
	unsigned d;
	unsigned p;
	list<Edge> edges;
};
