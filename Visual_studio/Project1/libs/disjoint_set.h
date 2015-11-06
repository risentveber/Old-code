#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;


template<typename T>
class disjoint_sets
{
	class tree_node
	{
	public:
		T name;
		unsigned index;
		tree_node *parent;
		unsigned rank;
		tree_node() : parent(NULL), rank(0) {};
	};

public:
	~disjoint_sets();

	void make_set(const T&);
	void union_sets(const T&, const T&);
	const T& find_set(const T&);

	void pin();
private:
	tree_node* find(const T&);
	void link(tree_node*, tree_node*);
	void del_set_id(tree_node*);//удаление вершины как идентификатора множества, если нужно

	unordered_map<T, tree_node*> identif;
	vector<tree_node*> sets;
};
