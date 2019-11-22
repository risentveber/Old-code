#include <iostream>

#include "BigInt.h"


using namespace std;

int main(){
	BigInt a, b;
	cin >> a;

	cin >> b;
	cout << a / b << endl;
	cout << a % b << endl;
	/*cout << (a << 1) << endl;*/
	system("pause");
	return 0;
}