#define BASE 1000//основание ситемы счисления
#define BASE_L 3
#include<vector>


class BigInt{
protected:
	std::vector<int> _coeff;
	bool _isNegativ;

public:
	BigInt();
	BigInt(int a);
	virtual ~BigInt();
	friend std::istream& operator >> (std::istream& input, BigInt &tmp);
	friend std::ostream& operator << (std::ostream& output, const BigInt &tmp);
	friend bool operator > (const BigInt &a, const BigInt &b);
	friend bool operator == (const BigInt &a, const BigInt &b);
	friend bool absCom(const BigInt &a, const BigInt &b);
	friend bool isNegativ(const BigInt &a, const BigInt &b);
	friend bool isNegativ(const BigInt &a, int n);
	friend bool operator <= (const BigInt &a, const BigInt &b);

	friend BigInt operator - (const BigInt &a);
	friend BigInt operator + (const BigInt &a, const BigInt &b);
	friend BigInt operator - (const BigInt &a, const BigInt &b);

	friend BigInt operator * (const BigInt &a, int n);
	friend BigInt operator / (const BigInt &a, int n);
	friend int operator % (const BigInt &a, int n);
	friend BigInt operator / (const BigInt &a, const BigInt &b);
	friend BigInt operator * (const BigInt &a, const BigInt &b);
	friend std::string writerVector(const BigInt &tmp);
	void LevelUp();
};