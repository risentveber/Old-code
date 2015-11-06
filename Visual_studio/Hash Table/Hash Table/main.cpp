#include <iostream>
#include "Hash.h"

int main(){
	Hash<unsigned long int, unsigned long int> farm;
	for(unsigned long int i = 0; i < 100; ++i)
		farm.insert(i,i);
	for(unsigned long int i = 0; i < 100; ++i)
		if (i != 76)
		farm.remove(i);
	unsigned long int i = 76;
	cout << farm.search(i) << endl;
	i = 50;
	cout << farm.search(i) << endl;
	return 0;
}