#ifndef EDGE_H_INCLUDED
#define EDGE_H_INCLUDED

#include "disjoint_sets.h"
#include <fstream>
#include <algorithm>

using namespace std;

class Edge
{
public:
    friend istream& operator >> (istream&, Edge&);
    friend ostream& operator << (ostream&, Edge&);
    friend bool operator <(const Edge&, const Edge&);
    int get_v1() {return v1;};
    int get_v2() {return v2;};
    int get_w() {return weight;};
    void add(){in_t = true;};
    bool in_tree(){return in_t;};
    Edge():in_t(false) {};
private:
    bool in_t;
    int v1;
    int v2;
    unsigned weight;
};

istream& operator >> (istream& input, Edge& x)
{
    input >> x.v1 >> x.v2 >> x.weight;
    return input;
}

ostream& operator << (ostream& output, Edge& x)
{
    output << x.v1 << ' ' << x.v2 << ' ' << x.weight;
    return output;
}

bool operator <(const Edge& l, const Edge& r)
{
    return l.weight < r.weight;
}

#endif // EDGE_H_INCLUDED
