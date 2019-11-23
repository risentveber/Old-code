#ifdef RANDOM_QUEUE_TPL_H
#include "random_queue.h"
#include <cstdlib>
#include <iostream>

using namespace std;

template<typename T>
random_queue<T>::~random_queue(){
    std::cout << "destructor random_queue"<< std::endl;
}

template<typename T>
random_queue<T>::random_queue(){}

template<typename T>
T random_queue<T>::pop(){
    int a = rand() % (this->size - this->Index);
    if (a == 0)
        a = 1;
    T sw;
    sw = this->data[this->Index + a];
    this->data[this->Index + a] = this->data[this->Index + 1];
    this->data[this->Index + 1] = sw;
    std::cout << "pop"<< std::endl;
    return queue<T>::pop();
}

#endif //RANDOM_QUEUE_TPL_H
