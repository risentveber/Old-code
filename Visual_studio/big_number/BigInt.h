#define BASE 1000    // ��������� ������� ��������� - ������� 10
#define BASE_WIDTH 3 // ���������� �������
#include<vector>
#include <string>

class BigInt{
protected:
	std::vector<int> _coeff;
	bool _isNegativ;

public:
	//������������ � �����������
	BigInt();
	BigInt(int a);
	virtual ~BigInt();
	int operator  = (int n);

	//���� � �����
	friend std::istream& operator >> (std::istream& input, BigInt &tmp);
	friend std::ostream& operator << (std::ostream& output, const BigInt &tmp);
	friend std::string writerVector(const BigInt &tmp);
	//���������
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
	//����������� ����� ��� ��������� � �������
	friend bool isNegativ(const BigInt &a, const BigInt &b);
	friend bool isNegativ(const BigInt &a, int n);
	//�������� ��������� (� ��� ����� � �������)
	friend BigInt operator + (const BigInt &a);
	friend BigInt operator - (const BigInt &a);

	friend BigInt operator + (const BigInt &a, const BigInt &b);
	friend BigInt operator - (const BigInt &a, const BigInt &b);

	friend BigInt operator + (const BigInt &a, int n);
	friend BigInt operator - (const BigInt &a, int n);

	friend BigInt operator + (int n, const BigInt &b);
	friend BigInt operator - (int n, const BigInt &b);
	//���������
	friend BigInt operator *  (const BigInt &a, int n);
	friend BigInt operator *  (int n, const BigInt &b);
	friend BigInt operator << (BigInt a, unsigned int pos);//��������� �� ���������
	friend BigInt operator *  (const BigInt &a, const BigInt &b); 
	
	//�������
	friend BigInt operator / (const BigInt &a, int n);
	friend int operator % (const BigInt &a, int n);
	//friend BigInt operator >> (const BigInt &a, unsigned int pos);//������� �� ���������
	friend BigInt operator / (BigInt a, BigInt b);
	friend BigInt operator % (const BigInt &a, const BigInt &b);
};