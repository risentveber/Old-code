#ifndef HELP_CLASSES_HPP_INCLUDED
#define HELP_CLASSES_HPP_INCLUDED

#include <cwchar>

class file_obj
{
public:
    wstring name;
    wstring type;
};

class Word
{
public:
    wstring name;
    vector<unsigned> num;
};


#endif // HELP_CLASSES_HPP_INCLUDED
