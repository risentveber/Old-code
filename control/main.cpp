#include "random_queue.h"

#include <iostream>
#include <cstdlib>

using namespace std;

class A
{
protected:
	virtual~A(){cout << "destructor A" << endl;}
};

class B : public A
{
public:
 ~B(){cout << "destructor B" << endl;}
};

class C : public B
{
public:
 ~C(){cout << "destructor C" << endl;}
};


void main(){

	/*random_queue<int>* vvv = new random_queue<int>;
	vvv->push(32);
	vvv->push(39);
	vvv->push(45);
	vvv->push(51);
	vvv->push(60);
	vvv->push(70);
	vvv->push(90);
	std::cout << vvv->queue::pop() << std::endl;
	std::cout << vvv->pop() << std::endl;
	std::cout << vvv->pop() << std::endl;
	std::cout << vvv->pop() << std::endl;
	std::cout << vvv->pop() << std::endl;
	vvv->~random_queue();*/



	system("pause");
}



