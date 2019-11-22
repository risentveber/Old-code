#ifndef SEGMENT_TREE_HPP_INCLUDED
#define SEGMENT_TREE_HPP_INCLUDED

#include <climits>
#include <vector>
#include <stdexcept>
#include <iostream>

using namespace std;

template<typename T, typename Operation>
class SegmentTree
{
public:

    ~SegmentTree() {};
    SegmentTree();
    template<typename InputIterator>
        SegmentTree( InputIterator, InputIterator, const T = T());
    template<typename InputIterator>
        SegmentTree(InputIterator, InputIterator, Operation &, const T = T());
    void print() const;
    void change(size_t i, const T &);
    T operator()(size_t, size_t) const;

private:
    Operation opn;
    T DefaultValue;

    std::vector<T> values;
    size_t item_count;
    size_t tree_depth;
    size_t first_index;//первый значащий индекс

    T calculate(size_t, size_t, size_t, size_t, size_t) const;
    template<typename InputIterator>
    void initialization(InputIterator &, InputIterator &);

    size_t parent(size_t index) const {return (index - 1) >> 1; };
    size_t l_child(size_t index) const {return (index << 1) + 1; };
    size_t r_child(size_t index) const {return (index << 1) + 2; };
    size_t tree_size() const {return (1 << tree_depth) - 1; };
};



template<typename T, typename Operation>
SegmentTree<T, Operation>::SegmentTree():
    item_count(0),
    tree_depth(0)
{
};

template<typename T, typename Operation>
template<typename InputIterator>
SegmentTree<T, Operation>::SegmentTree(InputIterator from, InputIterator to, const T def):
    DefaultValue(def),
    item_count((size_t)(to - from)),
    tree_depth(0)
{
    if (item_count == 0)
        return;
    initialization(from, to);
}

template<typename T, typename Operation>
template<typename InputIterator>
SegmentTree<T, Operation>::SegmentTree(InputIterator from, InputIterator to, Operation &op, const T def):
    opn(op),
    DefaultValue(def),
    item_count((size_t)(to - from)),
    tree_depth(0),
    first_index(UINT_MAX)//максимальное значение для типа
{
    if (item_count == 0)
        return;
    initialization(from, to);
};

template<typename T, typename Operation>
template<typename InputIterator>
void SegmentTree<T, Operation>::initialization(InputIterator &from, InputIterator &to)
{
    //находим глубину дерева и выделяем память
    ++tree_depth;
    for (size_t i = 1; i < item_count; ){
        i = i << 1;
        ++tree_depth;
    }
    values.resize(tree_size());
    first_index = (1 << (tree_depth - 1)) - 1;

    //заполнение изначального уровня
    size_t tmp = first_index;
    for(auto it = from; it != to; ++it)
        values[tmp++] = *it;
    while (tmp < tree_size())
        values[tmp++] = DefaultValue;
    //заполнение остальных уровней
    if (first_index){
        tmp = first_index;
        do {
            --tmp;
            values[tmp] = opn(values[l_child(tmp)], values[r_child(tmp)]);
        } while (tmp);
    }
}


template<typename T, typename Operation>
void SegmentTree<T, Operation>::print() const
{
    size_t tmp = 0;
    size_t level_num;
    for (size_t i = 0; i < tree_depth; ++i){
        level_num = 1 << i;
        for (size_t k = 0; k < level_num; ++k)
            cout << values[tmp++] << ' ';
        cout << endl;
    }

}

template<typename T, typename Operation>
void SegmentTree<T, Operation>::change(size_t i, const T &new_value)
{
    if (i >= item_count)
    {
        throw std::out_of_range("index out of bounds");
    }

    i += first_index;
    values[i] = new_value;
    size_t p;
    while ( i > 0 )
    {
        p = parent(i);
        values[p] = opn(values[l_child(p)], values[r_child(p)]); // обновление значений предков
        i = p;
    }
}


template<typename T, typename Operation>
T SegmentTree<T, Operation>::operator()(size_t left, size_t right) const
{
    if (left > right)
    {
            return operator()(right, left);
    }
    if (right >= item_count)
    {
            throw std::out_of_range("index out of bounds");
    }

    return calculate(left, right, 0, 0, (1 << (tree_depth -1))-1);
}

template<typename T, typename Operation>
T SegmentTree<T, Operation>::calculate(size_t from, size_t to, size_t current, size_t left_bound, size_t right_bound) const
{ // сумма элементов между left_bound и right_bound хранится в элемнете current
        if (from > to)
        {
                return DefaultValue;
        }
        if (from == left_bound && to == right_bound)
        {
                return values[current];
        }

        size_t middle_bound = (left_bound + right_bound) / 2;

        T l_v = calculate(from, min(to, middle_bound), l_child(current), left_bound, middle_bound);
        T r_v = calculate(max(middle_bound + 1, from), to, r_child(current), middle_bound + 1, right_bound);

        return opn(l_v, r_v);
}
















#endif // SEGMENT_TREE_HPP_INCLUDED
