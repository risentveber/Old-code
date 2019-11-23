#ifdef QUEUE_TPL_H
#include "queue.h"

template<typename T>
queue<T>::queue(){
    Index = 0;
    size = 1;
    data = new T[1];
}

template<typename T>
queue<T>::~queue(){
    std::cout << "destructor queue" << std::endl;
    delete[] data;
}

template<typename T>
bool queue<T>::is_empty()const{
    if (Index == (size - 1))
        return true;
    else
        return false;
}

template<typename T>
void queue<T>::push(const T& temp){
    if (Index == 0){
        Index = size;
        T* new_data = new T[2*size];
        for (int i = 1; i < size; i++){
            new_data[size + i] = data[i];
        }
        delete[] data;
        data = new_data;
        size = size*2;
    }

    data[Index] = temp;
    Index--;
}

template<typename T>
T queue<T>::pop(){
    Index++;
    return data[Index];
}

#endif //QUEUE_TPL_H
