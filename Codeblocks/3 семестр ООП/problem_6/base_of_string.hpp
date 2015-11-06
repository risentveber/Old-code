#ifndef BASE_OF_STRING_HPP_INCLUDED
#define BASE_OF_STRING_HPP_INCLUDED

#include "help_functions.hpp"
#include "help_classes.hpp"
#include "axo.hpp"

class Base_of_string
{
public:
    void clear();
    void add(wstring &);
    void analyse();

    void add_files(const wstring &type, const vector<wstring> &);
private:
    Bohr_tree tree;
    vector<Word> words;
    wstring all_text;
};


#endif // BASE_OF_STRING_HPP_INCLUDED
