#include "BTree.hpp"
#include <iostream>

int main(){
	BTree<size_t> tree(10);
	size_t x = 15;
	for(size_t i = 0; i <= 1000; ++i)
		tree.insert(i);
	if( (tree.search(x)).first)
		cout << true << endl;
	tree.remove(x);
	tree.remove(x);
	if( (tree.search(x)).first)
		cout << true << endl;
	for(size_t i = 1000; i > 1; --i)
		tree.remove(i);
	//getchar();
	return 0;
}
