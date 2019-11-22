#ifdef RANDOM_QUEUE_TPL_H
#include "random_queue.h"
#include <cstdlib>

template<typename T>
random_queue<T>::~random_queue(){
	std::cout << "destructor random_queue"<< std::endl;
}

template<typename T>
random_queue<T>::random_queue(){}

template<typename T>
T random_queue<T>::pop(){
	int a = rand()%(size - index);
	if (a == 0)
		a = 1;
	T sw;
	sw = massiv[index + a];
	massiv[index + a] = massiv[index+1];
	massiv[index+1] = sw;
	std::cout << "pop"<< std::endl;
	return queue<T>::pop();
}


#endif //RANDOM_QUEUE_TPL_H
