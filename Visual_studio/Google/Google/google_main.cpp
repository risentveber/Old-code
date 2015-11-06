#include "disjoint_set.h"
#include <iostream>

int main()
{
	disjoint_sets<int> a;
	for(int i = 0; i < 10; ++i)
		a.make_set(i);
	a.union_sets(1, 2);
	a.union_sets(1, 3);
	a.union_sets(8, 9);
	a.union_sets(7, 6);
	a.union_sets(8, 7);
	for(int i = 0; i < 10; ++i)
		cout << a.find_set(i) << endl;
	
	system("pause");
	return 0;
}