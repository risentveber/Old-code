#include "Vert.h"

class Graph
{
public:
	Graph() : vertices(1) {};
	unsigned get_id(unsigned v);//done
	void add_edge(unsigned v1, unsigned v2);//done
	void del_edge(unsigned v1, unsigned v2);//done
	void rename(unsigned v1, unsigned v2, char* word);//done
	void del_name(unsigned v1, unsigned v2);//done
	void search_components();
	friend ostream & operator << (ostream & out, Graph graph);
private:
	unordered_map<unsigned, unsigned> conform; //v1 --> id
	vector<Vert> vertices;
};
