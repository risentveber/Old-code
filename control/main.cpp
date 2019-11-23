#include <iostream>
#include <cstdlib>

#include "random_queue.h"

using namespace std;

int main(){
    random_queue<int>* vvv = new random_queue<int>;
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
    vvv->~random_queue();
}

