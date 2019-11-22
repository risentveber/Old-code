#include <sstream>
#include <locale>
#include "help_functions.hpp"
#include "help_classes.hpp"
#include "base_of_string.hpp"

using namespace std;

int main()
{
    locale utf("ru_RU.UTF-8");
    locale::global(utf);
    wcin.imbue(utf);
    wcout.imbue(utf);
    std::ios_base::sync_with_stdio(false);

    vector<wstring> files;
    Base_of_string database;

    wstring input;
    wstring filename;
    wstring encode;
    unsigned n;

    wcin >> input;

    while (input != L"exit"){
        if (input == L"corp"){
            wcin >> encode;
            wcin >> n;
            files.resize(n);
            for (unsigned i = 0; i < n; ++i)
                wcin >> files[i];

            database.add_files(encode, files);

        } else if (input == L"analyse"){
            wcin >> n;
            database.clear();
            for (unsigned i = 0; i < n; ++i){
                wcin >> input;
                database.add(input);
            }
            database.analyse();
        } else {
            bad_talking(input);
        }
        wcin >> input;
    }


    return 0;
}
