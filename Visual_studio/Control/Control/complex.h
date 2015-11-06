#include <iostream>

typedef enum{Re,Im} index;

class complex_number
{
private:
	float Re;
	float Im;
public:
	//создание
	complex_number();
	complex_number(float, float);
	//копирование и присваивание
	complex_number(const complex_number&);
	const complex_number& operator=(const complex_number&);
	//сложение
	complex_number operator+(const complex_number&) const;
	complex_number operator+(float) const;
	friend complex_number operator+(float, const complex_number&);
	//вычитание
	complex_number operator-(const complex_number&) const;
	complex_number operator-(float) const;
	//умножение
	complex_number operator*(const complex_number&) const;
	complex_number operator*(float) const;
	//деление
	complex_number operator/(const complex_number&) const;
	complex_number operator/(float) const;
	//сравнение
	bool operator==(const complex_number&) const;
	bool operator==(float) const;
	//ввод-вывод
	friend std::istream & operator>>(std::istream&, complex_number&);
	friend std::ostream & operator<<(std::ostream&, const complex_number&);
	//прочее
	complex_number con(const complex_number&) const;//Функция вычисления сопряженного числа
	float operator[](index) const;
	~complex_number(){};
};