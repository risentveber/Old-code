#include <iostream>
#include <string>
#include <cstring>
#include <climits>

#define UC unsigned wchar_t
using namespace std;

const unsigned q = 524287;//достаточно большое простое число
const unsigned d = 1 << 16;

bool str_in(wstring &str, wstring &text, unsigned pos);


void Rabin_Carp_Matcher(wstring &text, wstring &str);
