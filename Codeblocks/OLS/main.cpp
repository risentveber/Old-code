#include <stdio.h>
#include <iostream>
#include <string>
#include <ostream>
#include <fstream>
#include <math.h>
#include <stdio.h>

using namespace std;

int main()
{
    locale utf("ru_RU.UTF-8");
    locale::global(utf);
	wofstream output;//("output.txt");
	wifstream input;//("input.txt");
	output.imbue(utf);
    input.imbue(utf);
    output.open("output.txt");
    input.open("input.txt");

	wstring name;
	getline(input, name);
	output << name << endl;

	int n;
	input >> n;

//	wchar_t str[200];
//	wchar_t c = L'a';
//	int l = 0;
//	while ('\n' != (c = input.get())){
//        str[l++] = c;
//        wcout << c;
//        wcout << L'H';
//    }
//    str[l] = L'\0';
//	wstring parameter(str);
    wstring parameter;
	getline(input, parameter);
	if (parameter == L"")
        getline(input, parameter);
    wcout << parameter << endl;
	output << parameter << endl;

    long double tmp_x;
	long double tmp_y;
	long double xy = 0;
	long double x = 0;
	long double y = 0;
	long double x_square = 0;
	long double y_square = 0;

	for(int i = 0; i < n; i++){
		input >> tmp_x;
		x += tmp_x;
		x_square += tmp_x*tmp_x;
		input >> tmp_y;
		y += tmp_y;
		y_square += tmp_y*tmp_y;
		xy += tmp_x*tmp_y;
	}


	x /= n;
	y /= n;
	x_square /= n;
	y_square /= n;
	xy /= n;
	long double k;
	long double s_k;
	wstring sign = L"+-";
	if (parameter == L"график проходит через 0"){
		output << L"y = kx" << endl;
		k = xy/x_square;
		s_k = sqrt(y_square/x_square - k*k)/sqrt(n);
		output << L"k = " << k << L' ' << sign << L' ' << s_k << endl;
	}else{
		output << L"y = kx + b" << endl;
		long double b;
		long double s_b;
		k = (xy - x*y)/(x_square - x*x);
		b = y - k*x;
		s_k = sqrt((y_square - y*y)/(x_square - x*x) - k*k)/sqrt(n);
		s_b = s_k*sqrt(x_square - x*x);
		output << L"k = " << k << L' ' << sign << L' ' << s_k << endl;
		output << L"b = " << b << L' ' << sign << L' ' << s_b << endl;
	}


	return 0;
}
