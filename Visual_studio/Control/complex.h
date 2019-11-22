#include <iostream>

typedef enum{Re,Im} index;

class complex_number
{
private:
	float Re;
	float Im;
public:
	//��������
	complex_number();
	complex_number(float, float);
	//����������� � ������������
	complex_number(const complex_number&);
	const complex_number& operator=(const complex_number&);
	//��������
	complex_number operator+(const complex_number&) const;
	complex_number operator+(float) const;
	friend complex_number operator+(float, const complex_number&);
	//���������
	complex_number operator-(const complex_number&) const;
	complex_number operator-(float) const;
	//���������
	complex_number operator*(const complex_number&) const;
	complex_number operator*(float) const;
	//�������
	complex_number operator/(const complex_number&) const;
	complex_number operator/(float) const;
	//���������
	bool operator==(const complex_number&) const;
	bool operator==(float) const;
	//����-�����
	friend std::istream & operator>>(std::istream&, complex_number&);
	friend std::ostream & operator<<(std::ostream&, const complex_number&);
	//������
	complex_number con(const complex_number&) const;//������� ���������� ������������ �����
	float operator[](index) const;
	~complex_number(){};
};