
#ifdef QUEUE_TPL_H
#include "queue.h"

template<typename T>
queue<T>::queue(){
	index = 0;
	size = 1;
	massiv = new T[1];
}

template<typename T>
queue<T>::~queue(){
	std::cout << "destructor queue"<< std::endl;
	delete[] massiv;
}

template<typename T>
bool queue<T>::is_empty()const{
	if (index == (size - 1))
		return true;
	else 
		return false;
}

template<typename T>
void queue<T>::push(const T& temp){
	if (index == 0){
		index = size;
		T* new_massiv = new T[2*size];
		for (int i = 1; i < size; i++){
			new_massiv[size + i] = massiv[i];
		}
		delete[] massiv;
		massiv = new_massiv;
		size = size*2;
	}
	
	massiv[index] = temp;
	index--;
}

template<typename T>
T queue<T>::pop(){
	index++;
	return massiv[index];
}

#endif //QUEUE_TPL_H




