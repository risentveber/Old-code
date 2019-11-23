#include "help_functions.hpp"
#include <locale>

//bool exists(const wstring &name)
//{
//     return boost::filesystem::exists(name);
//}

void bad_talking(wstring &str)//writes error message and clear cin
{
    wcerr << L"Bad talking detected: " << str;
    getline(wcin, str);
    wcerr << str << endl;
}


void preprss(wstring & str, const locale & loc)
{
    for(unsigned i = 0; i < str.size(); ++i){
        if (!std::isalpha(str[i], loc))
            str[i] = L' ';
        else
            str[i] = std::tolower(str[i], loc);
    }
    str = L" " + str + L" ";
}
