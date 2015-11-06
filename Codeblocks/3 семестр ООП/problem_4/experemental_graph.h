#ifndef EXPEREMENTAL_GRAPH_H_INCLUDED
#define EXPEREMENTAL_GRAPH_H_INCLUDED

#include <vector>
#include <iostream>
#include <cstdlib>

#define SOURCE 0u
#define SINK 1u

using namespace std;

class Exp_grahp
{
public:
    class Exp_result;

    Exp_grahp(unsigned, unsigned, double);
    Exp_result research(unsigned);

private:
    class Vertex;
    class Edge;

    bool edge_exists();
    bool edge_direction();
    bool augmenting_path();
    unsigned path_capacity();
    unsigned rand_cap();
    void clear_vertices();
    void random_initialization();
    unsigned max_flow();

    unsigned n;
    unsigned w;
    double p;

    vector<Vertex> vertices;
    vector<vector<Edge>> edges;
};


class
Exp_grahp::Exp_result
{
public:
    Exp_result(unsigned, unsigned, double);
private:
    unsigned ignored;
    unsigned all;
    double average_flow;
    friend ostream& operator << (ostream &, const Exp_result&);
};

class Exp_grahp::Edge
{
public:
    Edge() : flow(0), c(0), in_graph(false) {};
    unsigned flow;
    unsigned c;
    bool in_graph;

};

class
Exp_grahp::Vertex
{
public:
    unsigned parent;
    bool used;
};

#endif // EXPEREMENTAL_GRAPH_H_INCLUDED
