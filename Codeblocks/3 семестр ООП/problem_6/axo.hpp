#ifndef AXO_HPP_INCLUDED
#define AXO_HPP_INCLUDED

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;


class Bohr_tree
{
public:
    void clear();
    Bohr_tree();
    long unsigned count_of_word(unsigned x) {return cnt[x];};
    wstring & word(unsigned x) {return pattern[x]; };
    unsigned add_string(const wstring &);
    void find_in(const wstring& in_str);

private:
    struct Bohr_vrtx;

    int get_auto_move(int v, wchar_t c);
    int get_suff_link(int v);
    int get_suff_good_link(int v);
    void check(int v);

    vector<wstring> pattern;
    vector<long unsigned> cnt;
    vector<Bohr_vrtx> bohr;
};


struct Bohr_tree::Bohr_vrtx
{
    Bohr_vrtx();
    Bohr_vrtx(int, wchar_t);

    unordered_map<wchar_t, int> next_vrtx;
    unordered_map<wchar_t, int> auto_move;

    int parent;
    wchar_t symb;
    int suff_link;
    int gs_link;
    bool flag;
    int pat_num;

};




#endif // AXO_HPP_INCLUDED
