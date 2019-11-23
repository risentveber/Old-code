#ifndef HELP_FUNCTIONS_HPP_INCLUDED
#define HELP_FUNCTIONS_HPP_INCLUDED

#include <boost/filesystem/fstream.hpp>
#include <string>
#include <cwchar>
#include <iostream>

using namespace std;


bool exists(const string &name);

void bad_talking(wstring &str);//writes error message and clear cin

void preprss(wstring & str, const locale &);

#endif // HELP_FUNCTIONS_HPP_INCLUDED
