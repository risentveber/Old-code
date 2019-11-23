#ifndef STRINGS_ALGO_H_INCLUDED
#define STRINGS_ALGO_H_INCLUDED

#include <iostream>
#include <string>
#include <cstring>
#include <climits>

#define UC unsigned wchar_t
using namespace std;

const unsigned q = 524287;//достаточно большое простое число
// const unsigned d = 1 << 16;

bool str_in(wstring &str, wstring &text, unsigned pos)
{
    unsigned k = 0;
    while (str[k] == text[pos + k] && str[k] != L'\0')
        ++k;
    if (str[k] == L'\0')
        return true;
    else
        return false;
}

void Rabin_Carp_Matcher(wstring &text, wstring &str)
{
    unsigned n = text.size();
    unsigned m = str.size();

    if (n < m)
        return;
    long int p = 0;
    long int t = 0;
    unsigned h = 1;

    for (unsigned i = 1; i < m; ++i)
        h = (h << 16) % q;

    for (unsigned i = 0; i < m; ++i){
        p = ((p << 16) + (UC)str[i]) % q;
        t = ((t << 16) + (UC)text[i]) % q;
    }

    for (unsigned s = 0; s <= n - m; ++s){
        if (p == t) {
            if (str_in(str, text, s)) {
                cout << "вхождение образца " << s << endl;
            } else {
                cout << "ложное срабатывание " << s << endl;
            }
        }
        if (s != n - m){
            t = ( ((t - (UC)text[s] * h) << 16) + (UC)text[s + m]) % q;
            if (t < 0)
                t += q;
        }
    }

}


#endif // STRINGS_ALGO_H_INCLUDED
