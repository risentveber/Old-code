#include "rbk_algo.h"
#include <locale>

int main()
{
    locale utf("ru_RU.UTF-8");
    locale::global(utf);
    wcin.imbue(utf);
    wcout.imbue(utf);
    std::ios_base::sync_with_stdio(false);

    wstring text, str;
    wcin >> str;
    wcin >> text;
    Rabin_Carp_Matcher(text, str);
}
