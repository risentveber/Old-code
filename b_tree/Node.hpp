#include <stddef.h>

template<typename T>
class Node{
    public:
        size_t n;
        T *key;
        Node<T> **child;
        bool isLeaf;
        Node(size_t);
        ~Node();
};

template<typename T>
Node<T>::Node(size_t t){
    n = 0;
    isLeaf = true; //по умолчанию создается лист
    key = new T[2*t - 1];
    //key[2*t - 1] = '\0';
    child = new Node<T> *[2*t];
}

template<typename T>
Node<T>::~Node(){
    delete[] key;
    if (!isLeaf && n != 0)
        for(size_t i = 0; i <= n; i++)// возможно сделать удаление рекурсивным
            delete child[i];
    delete child;
}
