//Собственная реализация класса my_string:  констуктор, деструктор, копирование,
//присваивание, ввод/вывод, +, Substring, Find (поиск подстроки), получение отдельного символа через []
#include <iostream>

class my_string
{
private:
	int _length;//позиция символа конца строки
	char* _array;
public:
	my_string();
	my_string(const char *);
	~my_string();
	int length();
	my_string(const my_string&);
	const my_string& operator=(const my_string&);
	friend std::istream & operator>>(std::istream&, my_string&);
	friend std::ostream & operator<<(std::ostream&, const my_string&);
	my_string operator+(const my_string&) const;
	my_string substring(int, int) const;
	int find(const my_string&) const;
	char& operator[](int);
	const char& operator[](int) const;
};
