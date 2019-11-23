#include "Node.hpp"
#include <utility>

using namespace std;

template<typename T>
class BTree{
    Node<T> *root;
    size_t t;
    void insertNonfull(Node<T> *, T &);
    void splitChild(Node<T> *x, size_t i, Node<T> *y);
    void remove(Node<T> *, T &);
    pair<Node<T> *, size_t> search(Node<T> *, const T &) const;
    public:
    BTree(size_t);
    void insert(T &);
    void remove(T &);
    pair<Node<T> *, size_t> search(const T &) const;
};

template<typename T>
pair<Node<T> *, size_t> BTree<T>::search(Node<T> *x, const T &k) const{
    size_t i = 0;
    while ((i < x->n) && (k > x->key[i]))
        ++i;
    if ((i < x->n) && (k == x->key[i]))
        return make_pair(x, i);
    if (x->isLeaf)
        return make_pair<Node<T> *>(NULL, 0);
    else
        return search(x->child[i], k);
}

template<typename T>
BTree<T>::BTree(size_t new_t){
    if (new_t < 2)
        new_t = 2;
    t = new_t;
    root = new Node<T>(t);//по умолчанию лист с 0 ключами
}

template<typename T>
void BTree<T>::splitChild(Node<T> *x, size_t i, Node<T> *y){// y == x->child[i]  (i -индекс согласованный с нумерацией в СИ)
    Node<T> *z = new Node<T>(t);
    z->isLeaf = y->isLeaf;
    z->n = t - 1;
    for(size_t j = 0; j < t - 1; ++j)   //{1..., t-1, t..., 2*t-1}
z->key[j] = y->key[t + j];
if (!(y->isLeaf))
    for(size_t j = 0; j < t; ++j)
        z->child[j] = y->child[t + j];
y->n = t - 1;

for(size_t j = x->n + 1; i < j;)//смещение потомков
    x->child[j] = x->child[--j];
x->child[i + 1] = z;//согласование с потомком z

for(size_t j = x->n; i < j;)//смещение ключей
    x->key[j] = x->key[--j];
x->key[i] = y->key[t - 1];//подъем ключа наверх
++x->n;
}

template<typename T>
void BTree<T>::insert(T &k){
    Node<T> *r = root;
    if (r->n == 2*t - 1){
        Node<T> *s = new Node<T>(t);
        root = s;
        s->isLeaf = false;
        s->child[0] = r;
        splitChild(s, 0, r);
        insertNonfull(s, k);
    }else
        insertNonfull(r, k);
}

template<typename T>
void BTree<T>::remove(T &k){
    remove(root, k);
}

template<typename T>
pair<Node<T> *, size_t>  BTree<T>::search(const T &k) const{
    return search(root, k);
}

template<typename T>
void BTree<T>::insertNonfull(Node<T> *x, T &k){
    long int i = x->n - 1;
    if (x->isLeaf){
        while (i >= 0 && k < x->key[i]){//поиск позиции для вставки
            x->key[i + 1] = x->key[i];
            --i;
        }
        x->key[i + 1] = k;
        ++x->n;
    }else{
        while (i >= 0 && k < x->key[i])//поиск позиции для вставки
            --i;
        i++;
        if (x->child[i]->n == 2*t - 1){
            splitChild(x, i, x->child[i]);
            if (k > x->key[i])
                ++i;
        }
        insertNonfull(x->child[i], k);
    }
}

template<typename T>
void BTree<T>::remove(Node<T> *x, T &k){
    bool inNode = false;
    size_t j;
    for(j = 0; j < x->n; ++j)//определение положения в листе или отсутствия ключа в данном листе
        if (x->key[j] >= k){
            if (x->key[j] == k)
                inNode = true;
            break;
        }

    if (inNode){ //если ключ находится в узле
        if (x->isLeaf){

            for(size_t i = j; i < x->n - 1; ++i)
                x->key[i] = x->key[i + 1];
            --x->n;
        }else{
            if (x->child[j]->n >= t){ //левый потомок содержит достаточно ключей
                //ищем предшественника
                Node<T> *p = x->child[j];
                while (!p->isLeaf)
                    p = p->child[p->n];
                T pred = p->key[p->n - 1];
                x->key[j] = pred;
                if (p->n >= t)
                    --p->n;
                else
                    remove(x->child[j], pred);

            }else if (x->child[j + 1]->n >= t){//правый потомок содержит достаточно ключей
                //ищем предшественника
                Node<T> *p = x->child[j + 1];
                while (!p->isLeaf)
                    p = p->child[0];
                T pred = p->key[0];
                x->key[j] = pred;
                if (p->n >= t){
                    for(size_t i = 0; i < p->n - 1; ++i)
                        p->key[i] = p->key[i + 1];
                    --p->n;
                }else
                    remove(x->child[j + 1], pred);

            }else{//оба содержат по t - 1 ключу: присоединяем правый к левому, затем удаляем правый выполняме сдвиг в родителе х
                Node<T> *left = x->child[j];
                Node<T> *right = x->child[j + 1];
                left->n = 2*t - 1;
                left->key[t-1] = k;
                for(size_t i = 0; i < t - 1;){//соединяем ключи
                    left->key[t + i] = right->key[i];
                    left->child[t + i] = right->child[i++];
                }
                left->child[2*t - 1] = right->child[t - 1];
                //delete right;
                for(size_t i = j + 1; i < x->n; ++i)//сдвиг потомков
                    x->child[i] = x->child[i + 1];
                --x->n;
                for(size_t i = j; i < x->n; ++i)//сдвиг ключей
                    x->key[i] = x->key[i + 1];
                if(x == root && x->n == 0){
                    delete x;
                    root = left;
                }
                remove(left, k);
            }
        }
    }else{//если ключа в узле нет
        if(x->isLeaf)
            return;//можно и выбросить исключение
        else{
            if(x->child[j]->n <= t - 1){
                if ( j >= 1 && x->child[j - 1]->n >= t){//левый сосед подходит
                    Node<T> *child =  x->child[j];
                    Node<T> *leftChild =  x->child[j - 1];
                    for(size_t i = child->n; i > 0; --i)
                        child->key[i] = child->key[i - 1];
                    ++child->n;
                    for(size_t i = child->n; i > 0; --i)
                        child->child[i] = child->child[i - 1];
                    child->key[0] = x->key[j];
                    child->child[0] = leftChild->child[leftChild->n];
                    --leftChild->n;
                    x->key[j] = leftChild->key[leftChild->n];
                    remove(x->child[j], k);
                }else if ( j + 1 <= x->n && x->child[j + 1]->n >= t){// правый сосед подходит
                    Node<T> *child =  x->child[j];
                    Node<T> *rightChild =  x->child[j + 1];
                    child->key[child->n] = x->key[j];
                    ++child->n;
                    child->child[child->n] = rightChild->child[0];
                    x->key[j] = rightChild->key[0];
                    --rightChild->n;
                    for(size_t i = 0; i < rightChild->n; ++i)
                        rightChild->key[i] = rightChild->key[i + 1];
                    for(size_t i = 0; i <= rightChild->n; ++i)
                        rightChild->child[i] = rightChild->child[i + 1];
                    remove(x->child[j], k);
                }else{//ни один сосед не подходит
                    if ( j >= 1 ){//левый существует объединяем с ним
                        Node<T> *child =  x->child[j];
                        Node<T> *leftChild =  x->child[j - 1];
                        leftChild->key[t - 1] = x->key[j - 1];
                        for(size_t i = 0; i < t - 1;){
                            leftChild->key[t + i] = child->key[i];
                            leftChild->child[t + i] = child->child[i++];
                        }
                        leftChild->child[2*t - 1] = child->child[t - 1];
                        leftChild->n = 2*t -1;
                        child->isLeaf = true;
                        delete child;
                        for(size_t i = j; i < x->n; ++i){
                            x->child[i] = x->child[i + 1];
                        }
                        --x->n;
                        for(size_t i = j - 1; i < x->n;++i){
                            x->key[i] = x->key[i + 1];
                        }
                        if (x == root && x->n == 0){
                            delete x;
                            root = leftChild;
                            remove(root, k);
                        }else
                            remove(leftChild, k);
                    }else{//правый существует объединяем с ним
                        Node<T> *child =  x->child[j];
                        Node<T> *rightChild =  x->child[j + 1];
                        child->key[t - 1] = x->key[j];
                        for(size_t i = 0; i < t - 1;){
                            child->key[t + i] = rightChild->key[i];
                            child->child[t + i] = rightChild->child[i++];
                        }
                        child->child[2*t - 1] = rightChild->child[t - 1];
                        child->n = 2*t -1;
                        rightChild->isLeaf = true;
                        delete rightChild;
                        for(size_t i = j + 1; i < x->n; ++i){
                            x->child[i] = x->child[i + 1];
                        }
                        --x->n;
                        for(size_t i = j; i < x->n; ++i){
                            x->key[i] = x->key[i + 1];
                        }
                        if (x == root && x->n == 0){
                            delete x;
                            root = child;
                            remove(root, k);
                        }else
                            remove(child, k);
                    }

                }

            }else
                remove(x->child[j], k);
        }
    }
}
