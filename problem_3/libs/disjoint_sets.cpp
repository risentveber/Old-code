#include "disjoint_sets.h"
#include <ostream>
#include <list>


template<typename T>
void disjoint_sets<T>::make_set(const T& a)
{
	if (identif.end() != identif.find(a)){
		//cerr << "this element exists" << endl;
	}else{
		tree_node * temp = new tree_node;
		temp->name = a;
		temp->index = sets.size();
		sets.push_back(temp);
		identif[a] = temp;
	}
}

template<typename T>
void disjoint_sets<T>::union_sets(const T& x, const T& y)
{
	link(find(x), find(y));
}

template<typename T>
typename disjoint_sets<T>::tree_node* disjoint_sets<T>::find(const T& a)
{
	auto it = identif.find(a);
	if (it == identif.end())
		return NULL;
	else{
		tree_node * temp = it->second; 
		list<tree_node*> stack;
		while (temp->parent != NULL){
			stack.push_back(temp);
			temp = temp->parent;
		}
		while (!stack.empty()){
			stack.back()->parent = temp;
			stack.pop_back();
		}
		return temp;
	}
}

template<typename T>
const T& disjoint_sets<T>::find_set(const T& a)
{
	return (find(a))->name;
}

template<typename T>
void disjoint_sets<T>::link(tree_node* x, tree_node* y)
{
	if (x == y){
		//cerr << "these elements are in one and the same set" << endl;
	}else{
		if (x->rank > y->rank){
			del_set_id(y);
			y->parent = x;
		}else{
			del_set_id(x);
			x->parent = y;			
			if (x->rank == y->rank)
				y->rank++;
		}
	}
}

template<typename T>
void disjoint_sets<T>::del_set_id(tree_node* a)
{
	if (a->parent == NULL)
		return;
	else{
		unsigned i = sets.size() - 1;
		unsigned curr = a->index;
		sets[i]->index = curr;
		sets[curr] = sets[i];
		sets.pop_back();
	}
}

template<typename T>
disjoint_sets<T>::~disjoint_sets()
{
	typename unordered_map<T, tree_node*>::iterator it;
	for(it = identif.begin(); it != identif.end(); ++it)
		delete it->second;
	
}

void example()
{
	disjoint_sets<int> a;
	a.make_set(1);
	a.make_set(2);
	a.find_set(1);
	a.union_sets(1, 2);
}

