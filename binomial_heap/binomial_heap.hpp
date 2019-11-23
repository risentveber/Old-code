#ifndef BINOMIAL_HEAP_HPP_INCLUDED
#define BINOMIAL_HEAP_HPP_INCLUDED
#include <cstdio>
#include <functional>
#include <vector>
#include <limits>
#include <stack>

using namespace std;

template <class T, class Comp = less<T>>
class Binomial_heap
{
public:
    class Node;
    Binomial_heap():head(NULL){};
    Node* insert_item(const T&);
    const T& minimum();
    void extract_min();
    Binomial_heap(Binomial_heap &, Binomial_heap &);
    void decrease_key(Node*, const T&);
    void delete_node(Node*);
    ~Binomial_heap();
private:
    const Binomial_heap& operator =(const Binomial_heap&);//не определено по умолчанию
    Binomial_heap(const Binomial_heap &);//не определено по умолчанию

    Node * min_node();
    void insert_node(Node*);
    Node* union_heaps(Binomial_heap&, Binomial_heap&);
    Node* merge_heaps(Binomial_heap&, Binomial_heap&);
    void link(Node*, Node*);
    void delete_tree(Node*);

    static Comp comp;
    Node* head;
};

template <class T, class Comp>
Comp Binomial_heap<T, Comp>::comp;



template <class T, class Comp>
class Binomial_heap<T, Comp>::Node
{
public:
    //Binomial_heap * heap;
    Node(): p(NULL), degree(0), child(NULL), sibling(NULL) {};
    T key;
    Node* p;
    unsigned degree;
    Node* child;
    Node* sibling;
};

template <class T, class Comp>
typename Binomial_heap<T, Comp>::Node* Binomial_heap<T, Comp>::min_node()
{
    Node* y = NULL;
    Node* x = head;
    T min_item;
    if (head){//если пирамида не пуста
        min_item = head->key;
        y = head;
    } else
        return NULL;

    while(x){
        if (comp(x->key, min_item)){
            min_item = x->key;
            y = x;
        }
        x = x->sibling;
    }

    return y;
}

template <class T, class Comp>
const T& Binomial_heap<T, Comp>::minimum()
{
    Node *x = min_node();
    if (x)
        return x->key;
    else
        throw;//if heap is empty
}

template <class T, class Comp>
void Binomial_heap<T, Comp>::link(Node* y, Node* z)
{
    y->p = z;
    y->sibling = z->child;
    z->child = y;
    ++(z->degree);
}

template <class T, class Comp>
typename Binomial_heap<T, Comp>::Node*
    Binomial_heap<T, Comp>::union_heaps(Binomial_heap& h1, Binomial_heap& h2)
{
    Node* heap = merge_heaps(h1, h2);

    if(heap == NULL)
        return heap;
    Node* prev_x = NULL;
    Node* x = heap;
    Node* next_x = heap->sibling;
    while (next_x){
        if (x->degree != next_x->degree ||
        (next_x->sibling && next_x->sibling->degree == x->degree)) {
            prev_x = x;
            x = next_x;
        } else if (comp(x->key, next_x->key)){
            x->sibling = next_x->sibling;
            link(next_x, x);
        } else {
            if (prev_x == NULL)
                heap = next_x;
            else
                prev_x->sibling = next_x;
            link(x, next_x);
            x = next_x;
        }
        next_x = x->sibling;
    }
    return heap;
}

template <class T, class Comp>
typename Binomial_heap<T, Comp>::Node*
    Binomial_heap<T, Comp>::merge_heaps(Binomial_heap& h1, Binomial_heap& h2)
{
    Node* l1 = h1.head;
    Node* l2 = h2.head;
    h1.head = NULL;
    h2.head = NULL;
    Node* result = NULL;
    Node* k = NULL;
    Node* temp;
    while (l1 && l2){
        if (l1->degree < l2->degree){
            temp = l1;
            l1 = l1->sibling;
        }else{
            temp = l2;
            l2 = l2->sibling;
        }
        if(result)
            k->sibling = temp;
        else
            result = temp;
        k = temp;
    }
    if(l1)
        temp = l1;
    else
        temp = l2;
    if(result)
        k->sibling = temp;
    else
        result = temp;

    return result;
}

template <class T, class Comp>
typename Binomial_heap<T, Comp>::Node* Binomial_heap<T, Comp>::insert_item(const T& t)
{
    Node* node = new Node();
    node->key = t;
    insert_node(node);
    return node;
}

template <class T, class Comp>
void Binomial_heap<T, Comp>::insert_node(Node* node)
{
    Binomial_heap heap;
    heap.head = node;
    head = union_heaps(heap, *this);//можно и красивее сделать
}

template <class T, class Comp>
void Binomial_heap<T, Comp>::extract_min()
{
    Node* y = NULL;
    Node* prev_y;
    Node* prev_x = NULL;
    Node* x = head;
    T min_item;
    if (head){//если пирамида не пуста
        prev_y = NULL;
        min_item = head->key;
        y = head;
    } else
        throw;

    while(x){
        if (comp(x->key, min_item)){
            min_item = x->key;
            prev_y = prev_x;
            y = x;
        }
        prev_x = x;
        x = x->sibling;
    }

    //удаление дерева y с минимальным корнем
    if (prev_y)
        prev_y->sibling = y->sibling;
    else
        head = y->sibling;
    y->sibling = NULL;

    Binomial_heap tmp_heap;
    Node* tmp = y->child;
    delete y;

    vector<Node*> head_list;

    while (tmp){//раскидываем детей y по head_list
        head_list.push_back(tmp);
        tmp->p = NULL;
        tmp = tmp->sibling;
        (head_list.back())->sibling = NULL;
    }

    Node* prev = NULL;
    Node* new_head = NULL;
    for(auto it = head_list.rbegin(); it != head_list.rend(); it++){
        if (prev)
            prev->sibling = *it;
        else
            new_head = *it;
        prev = *it;
    }
    tmp_heap.head = new_head;

    head = union_heaps(tmp_heap, *this);
}

template <class T, class Comp>
void Binomial_heap<T, Comp>::decrease_key(Node* x, const T& k)
{
    if (comp(x->key, k))
        return;
    x->key = k;
    Node* y = x;
    Node* z = y->p;
    while (z && comp(y->key, z->key)){
        swap(y->key, z->key);
        y = z;
        z = y->p;
    }

}

template <class T, class Comp>
Binomial_heap<T, Comp>::Binomial_heap(Binomial_heap& h1, Binomial_heap& h2)
{
    head = union_heaps(h1, h2);
}

template <class T, class Comp>
void Binomial_heap<T, Comp>::delete_node(Node* x)
{
    decrease_key(x,numeric_limits<T>::min());
    extract_min();
}
//написать деструктор

template <class T, class Comp>
Binomial_heap<T, Comp>::~Binomial_heap()
{
    Node* tmp;
    while (head){
        tmp = head;
        head = head->sibling;
        tmp->sibling = NULL;
        delete_tree(tmp);
    }

}

template <class T, class Comp>
void Binomial_heap<T, Comp>::delete_tree(Node* x)
{
    stack<Node*> nodes;
    if (x)
        nodes.push(x);
    else
        return;
    Node* tmp;

    while (!nodes.empty()){
        tmp = nodes.top();
        if (tmp->child){
            nodes.push(tmp->child);
            tmp->child = NULL;
        }else {
            nodes.pop();
            if (tmp->sibling)
                nodes.push(tmp->sibling);
            delete tmp;
        }

    }

}

#endif // BINOMIAL_HEAP_HPP_INCLUDED
