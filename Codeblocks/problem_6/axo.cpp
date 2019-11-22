#include "axo.hpp"

void Bohr_tree::clear()
{
    pattern.clear(); cnt.clear(); bohr.assign(1, Bohr_vrtx());
}

Bohr_tree::Bohr_vrtx::Bohr_vrtx()
    : parent(0), suff_link(-1), gs_link(-1), flag(false)
{
}


Bohr_tree::Bohr_vrtx::Bohr_vrtx(int p, wchar_t c)
    : parent(p), symb(c), suff_link(-1), gs_link(-1), flag(false)
{
}


Bohr_tree::Bohr_tree()
    :bohr(1)
{
}


unsigned Bohr_tree::add_string(const wstring &str)
{
    if (str.length() == 0)
        return 0;
    int num = 0; //начинаем с корня
    wchar_t c;
    for (size_t i = 0; i < str.length(); ++i){
        c = str[i];
        if (bohr[num].next_vrtx[c] == 0){ //0 - признак отсутствия ребра
            bohr[num].next_vrtx[c] = bohr.size();
            bohr.push_back(Bohr_vrtx(num, c));
        }
        num = bohr[num].next_vrtx[c];
    }
    if (!bohr[num].flag){
        bohr[num].flag = true;
        bohr[num].pat_num = pattern.size();
        pattern.push_back(str);
        cnt.push_back(0);
    }
    return bohr[num].pat_num;

}

int Bohr_tree::get_auto_move(int v, wchar_t c)
{
    if (bohr[v].auto_move.find(c) == bohr[v].auto_move.end()){
        if (bohr[v].next_vrtx.find(c) != bohr[v].next_vrtx.end())
            bohr[v].auto_move[c] = bohr[v].next_vrtx[c];
        else if (v == 0)
            bohr[v].auto_move[c] = 0;
        else
            bohr[v].auto_move[c] = get_auto_move(get_suff_link(v), c);
    }
    return bohr[v].auto_move[c];
}

int Bohr_tree::get_suff_link(int v)
{
    if (bohr[v].suff_link == -1){ //если еще не считали
        if (v == 0 || bohr[v].parent == 0) //если v - корень или предок v - корень
            bohr[v].suff_link = 0;
        else
            bohr[v].suff_link = get_auto_move(get_suff_link(bohr[v].parent), bohr[v].symb);
    }
    return bohr[v].suff_link;
}

int Bohr_tree::get_suff_good_link(int v)
{
   if (bohr[v].gs_link == -1){
      int u = get_suff_link(v);
      if (u == 0) //либо v - корень, либо суф. ссылка v указывает на корень
         bohr[v].gs_link = 0;
      else
         bohr[v].gs_link = (bohr[u].flag) ? u : get_suff_good_link(u);
   }
   return bohr[v].gs_link;
}


void Bohr_tree::check(int v)
{
    for(int u = v; u != 0; u = get_suff_good_link(u)){
        if (bohr[u].flag)
            ++cnt[bohr[u].pat_num];
    }
}

void Bohr_tree::find_in(const wstring& in_str){

    int u = 0;
    for(size_t i = 0; i < in_str.length(); ++i){
        u = get_auto_move(u, in_str[i]);
        check(u);
    }
}
