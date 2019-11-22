#define BASE 1000    // основание системы счисления - степень 10
#define BASE_WIDTH 3 // показатель степени
#include<vector>
#include <string>

class BigInt{
protected:
	std::vector<int> _coeff;
	bool _isNegativ;

public:
	//конструкторы и деструкторы
	BigInt();
	BigInt(int a);
	virtual ~BigInt();
	int operator  = (int n);

	//ввод и вывод
	friend std::istream& operator >> (std::istream& input, BigInt &tmp);
	friend std::ostream& operator << (std::ostream& output, const BigInt &tmp);
	friend std::string writerVector(const BigInt &tmp);
	//сравнение
	bool isNull() const;
	friend bool absCom(const BigInt &a, const BigInt &b);// |a| > |b|
	
	friend bool operator == (const BigInt &a, const BigInt &b);
	friend bool operator != (const BigInt &a, const BigInt &b);
	friend bool operator >  (const BigInt &a, const BigInt &b);
	friend bool operator <  (const BigInt &a, const BigInt &b);
	friend bool operator >= (const BigInt &a, const BigInt &b);
	friend bool operator <= (const BigInt &a, const BigInt &b);
	
	friend bool operator == (const BigInt &a, int n);
	friend bool operator != (const BigInt &a, int n);
	friend bool operator >  (const BigInt &a, int n);
	friend bool operator <  (const BigInt &a, int n);
	friend bool operator >= (const BigInt &a, int n);
	friend bool operator <= (const BigInt &a, int n);

	friend bool operator == (int n, const BigInt &b);
	friend bool operator != (int n, const BigInt &b);
	friend bool operator >  (int n, const BigInt &b);
	friend bool operator <  (int n, const BigInt &b);
	friend bool operator >= (int n, const BigInt &b);
	friend bool operator <= (int n, const BigInt &b);
	//определение знака при умножении и делении
	friend bool isNegativ(const BigInt &a, const BigInt &b);
	friend bool isNegativ(const BigInt &a, int n);
	//сложение вычитание (в том числе и унарное)
	friend BigInt operator + (const BigInt &a);
	friend BigInt operator - (const BigInt &a);

	friend BigInt operator + (const BigInt &a, const BigInt &b);
	friend BigInt operator - (const BigInt &a, const BigInt &b);

	friend BigInt operator + (const BigInt &a, int n);
	friend BigInt operator - (const BigInt &a, int n);

	friend BigInt operator + (int n, const BigInt &b);
	friend BigInt operator - (int n, const BigInt &b);
	//умножение
	friend BigInt operator *  (const BigInt &a, int n);
	friend BigInt operator *  (int n, const BigInt &b);
	friend BigInt operator << (BigInt a, unsigned int pos);//умножение на основание
	friend BigInt operator *  (const BigInt &a, const BigInt &b); 
	
	//деление
	friend BigInt operator / (const BigInt &a, int n);
	friend int operator % (const BigInt &a, int n);
	//friend BigInt operator >> (const BigInt &a, unsigned int pos);//деление на основание
	friend BigInt operator / (BigInt a, BigInt b);
	friend BigInt operator % (const BigInt &a, const BigInt &b);
};