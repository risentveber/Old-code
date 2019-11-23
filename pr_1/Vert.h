#include <memory>
#include <vector>
#include <string>
#include <cstring>
#include <unordered_map>
#include <iostream>
#include <stack>


#define EMPTY "empty_name"
using namespace std;

class TWord{
public:
    static const int buf_size = 140;
    char word[buf_size];
    TWord()
    {
        strcpy(word, EMPTY);
    };
};

typedef unordered_map<unsigned, shared_ptr<TWord>>::iterator maptype;



class Vert  //îñíîâíîé ïðèíöèï - ïîñòóïàþò êîððåêòíûå äàííûå
{
public:
	Vert(){};
	Vert(unsigned v, unsigned id, vector<Vert> * g_v): ident(id), vert(v), v_graph(g_v) {};
	void set(unsigned v, unsigned id);
	void add_edge(unsigned id, shared_ptr<TWord> & ptr);
	void del_edge(unsigned id);
	void del_name(unsigned id);
	void rename(unsigned id, TWord & word);
	shared_ptr<TWord> name_of(unsigned id);
	unsigned my_name(){ return vert; };
	friend ostream & operator << (ostream & out, Vert & vert);
	unordered_map<unsigned, shared_ptr<TWord>> & get_list() { return v_list; };
	maptype begin();
	maptype end();
private:
	unsigned ident;
	unsigned vert;
	vector<Vert> * v_graph;
	unordered_map<unsigned, shared_ptr<TWord>> v_list;
};

