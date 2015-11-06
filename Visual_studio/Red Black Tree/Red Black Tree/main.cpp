#include "RBTree.h"
#include <iostream>
#include <time.h>

using namespace std;

int main(){
	unsigned __int64 temp;//����� ������
	temp = __rdtsc();
	RBTree<int> tree;
	for(int i = 0; i < 10000; i++)
		tree.insert(i);
	for(int i = 0; i < 10000; i++)
		tree.remove(i);
	temp = __rdtsc() - temp;
	cout << temp << endl;
	/*tree.insert(100);
	tree.insert(2000);
	cout << tree.search(150) << endl;
	cout << tree.search(100) << endl;
	cout << tree.search(200000) << endl;*/
	system("pause");
	return 0;
}