#ifndef SUFFIX_TREE_H_INCLUDED
#define SUFFIX_TREE_H_INCLUDED

#include <string>
#include <map>
#include <vector>

using namespace std;

class SuffixTree
{
    public:
        SuffixTree() {} ;
        SuffixTree(const wstring &);

        void build_from(const wstring &);
        unsigned find(const wstring &);//

    private:
        void build();
        void push();

        class Suff_vrtx;

        wstring text;
        vector<Suff_vrtx> vertexes;
};

class SuffixTree::Suff_vrtx
{
    public:
        Suff_vrtx(int n) : num(n) {};
        Suff_vrtx(int n, int l) : leaf_num(l), num(n) {};

        int leaf_num;
        int num;
        int parent;
        int from;///по умолчанию - все нули
        int to;
        int suff_link;
        map<wchar_t, int> next;

        void link(wchar_t c, int i) {next[c] = i;};
        bool is_leaf() {return 0 == next.size();};
        bool is_root() {return num; };
        void set_from(int f) {from = f;};
        void set_to(int t) {to = t;};
        void set_leaf_num(int n) {leaf_num = n;};
};


#endif // SUFFIX_TREE_H_INCLUDED
