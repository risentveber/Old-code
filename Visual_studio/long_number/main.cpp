#include <iostream>
#include "long numbers.h"


int main(){
	/*freopen ("output.txt", "w", stdout);
	freopen ("input.txt", "r", stdin);*/
	BigInt a, b;
	std::cin >> a >> b;

	std::cout << a / b << std::endl;
	/*std::cout << a + b << std::endl;
	std::cout << a - b << std::endl;*/
	/*if (a <= b)
	std::cout << 1 << std::endl;
	else
		std::cout << 0 << std::endl;*/
	system("pause");
	return 0;
}

