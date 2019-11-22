#include <vector>
#include <list>
using namespace std;

template<typename K, typename V>
class Hash{
    public:
        void insert(K &k, V &v);
        V* search(K &k);
        void remove(K &k);
        Hash();
    private:
        unsigned long int size;
        unsigned int arraySize;
        vector<list<pair<K, V>>> array_e;
        unsigned int h(K &k);
        void redistribution();
};

template<typename K, typename V>
Hash<K, V>::Hash(){
    size = 0;
    arraySize = 10;
    array_e.resize(10);
}

template<typename K, typename V>
unsigned int Hash<K, V>::h(K &k){
    unsigned int size = sizeof(k);
    char* m = (char*)&k;
    unsigned int result = 0;
    unsigned int c = 1;
    for(unsigned int i = 0; i < size; ++i){
        c *= 279;
        result += c*m[i];
    }
    return result%arraySize;
}

template<typename K, typename V>
void Hash<K, V>::insert(K &k, V &v){
    list<pair<K, V>> &l = array_e[h(k)];
    for(auto i = l.begin(); i != l.end(); ++i)
        if (i->first == k){
            i->second = v;
            return;
        }
    l.push_front(make_pair(k, v));
    ++size;
    if (size >= arraySize*4)
        redistribution();
}

template<typename K, typename V>
void Hash<K, V>::remove(K &k){
    list<pair<K, V>> &l = array_e[h(k)];
    for(auto i = l.begin(); i != l.end(); ++i)
        if (i->first == k){
            l.erase(i);
            --size;
            break;
        }
}

template<typename K, typename V>
V* Hash<K, V>::search(K &k){
    list<pair<K, V>> &l = array_e[h(k)];
    for(auto i = l.begin(); i != l.end(); ++i)
        if (i->first == k){
            return &(i->second);
        }
    return NULL;
}

template<typename K, typename V>
void Hash<K, V>::redistribution(){
    unsigned int lastSize = arraySize;
    arraySize *= 2;
    vector<list<pair<K, V>>> newArray(arraySize);
    for(unsigned int i = 0; i < lastSize; ++i){
        list<pair<K, V>> &l = array_e[i];
        for(auto k = l.begin(); k != l.end(); ++k){
            newArray[h(k->first)].push_front(*k);
        }
    }
    array_e.assign(newArray.begin(), newArray.end());
}
