#include <memory>
#include <vector>
#include <string>
#include <unordered_map>
#include <iostream>
#include <stack>


#define EMPTY "empty_name"
using namespace std;

typedef unordered_map<unsigned, shared_ptr<string>>::iterator maptype;



class Vert  //основной принцип - поступают корректные данные
{
public:
	Vert(){};
	Vert(unsigned v, unsigned id, vector<Vert> * g_v): ident(id), vert(v), v_graph(g_v) {};
	void set(unsigned v, unsigned id);
	void add_edge(unsigned id, shared_ptr<string> & ptr);
	void del_edge(unsigned id);
	void del_name(unsigned id);
	void rename(unsigned id, string & word);
	shared_ptr<string> name_of(unsigned id);
	unsigned my_name(){ return vert; };
	friend ostream & operator << (ostream & out, Vert vert);
	unordered_map<unsigned, shared_ptr<string>> & get_list() { return v_list; };
	maptype begin();
	maptype end();
private:
	unsigned ident;
	unsigned vert;
	vector<Vert> * v_graph;
	unordered_map<unsigned, shared_ptr<string>> v_list;
};
