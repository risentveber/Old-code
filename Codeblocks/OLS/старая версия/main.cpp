#include <stdio.h>
#include <iostream>
#include <string>
#include <math.h>
#include <stdio.h>

using namespace std;

int main()
{
    	freopen ("output.txt", "w", stdout);
	freopen ("input.txt", "r", stdin);

	
	string name;
	getline(cin, name);
	cout << name << endl;
	
	int n;
	cin >> n;

	string parameter;
	getline(cin, parameter);
	getline(cin, parameter);
	int l = parameter.length() - 1;

	while ( parameter[l--] == ' ');
	parameter.resize(l + 2);
	cout << parameter << endl;

    	long double tmp_x;
	long double tmp_y;
	long double xy = 0;
	long double x = 0;
	long double y = 0;
	long double x_square = 0;
	long double y_square = 0;
	for(int i = 0; i < n; i++){
		cin >> tmp_x;
		x += tmp_x;
		x_square += tmp_x*tmp_x;
		cin >> tmp_y;
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
	string sign = "+-";
	if (parameter == "график проходит через 0"){
		cout << "y = kx" << endl;
		k = xy/x_square;
		s_k = sqrt(y_square/x_square - k*k)/sqrt(n);
		cout << "k = "<< k << ' '<< sign << ' ' << s_k << endl;
	}else{
		cout << "y = kx + b" << endl;
		long double b;
		long double s_b;
		k = (xy - x*y)/(x_square - x*x);
		b = y - k*x;
		s_k = sqrt((y_square - y*y)/(x_square - x*x) - k*k)/sqrt(n);
		s_b = s_k*sqrt(x_square - x*x);
		cout << "k = "<< k << ' '<< sign << ' ' << s_k << endl;
		cout << "b = "<< b << ' '<< sign << ' ' << s_b << endl;
	}


	return 0;
}
