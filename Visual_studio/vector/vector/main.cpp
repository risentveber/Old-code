#include "vector.h"
#include <iostream>
#include <vector>
#include <list>
using namespace std;

int main(){
	myVector<bool> a;
	for(size_t i = 0; i < 100; ++i)
		a.pushBack( i % 3);
	for(int i = 99; i > 0; --i){
		cout << a[i];
		a.popBack();
	}
	cout << endl;
	system("pause");
	return 0;
}