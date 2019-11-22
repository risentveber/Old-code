#include "complex.h"
#include <iostream>

complex_number::complex_number(){
	Re = 0;
	Im = 0;
};

complex_number::complex_number(float x, float y){
	Re = x;
	Im = y;
};


complex_number::complex_number(const complex_number& temp){
	Re = temp.Re;
	Im = temp.Im;
};

const complex_number& complex_number::operator=(const complex_number& temp){
	Re = temp.Re;
	Im = temp.Im;
	return temp;
};


complex_number complex_number::operator+(const complex_number& temp) const{
	complex_number result;
	result.Re = Re + temp.Re;
    result.Im = Im + temp.Im;
	return result;
};

complex_number complex_number::operator+(float x) const{
	complex_number result;
	result.Re = x + Re;
	result.Im = Im;
	return result;
};

complex_number operator+(float x, const complex_number& temp){
	complex_number result;
	result = temp + x;
	return result;
}


complex_number complex_number::operator*(const complex_number& temp) const{
	complex_number result;
	result.Re = Re*temp.Re - Im*temp.Im;
	result.Im = Re*temp.Im + Im*temp.Re;
	return result;
}

complex_number complex_number::operator*(float x) const{
	complex_number result;
	result.Re = Re*x;
	result.Im = Im*x;
	return result;
};

complex_number operator*(float x, const complex_number& temp){
	complex_number result;
	result = temp*x;
	return result;
};

complex_number complex_number::con(const complex_number& temp) const{
	complex_number result;
	result.Re = Re;
	result.Im = -Im;
	return result;
};

complex_number complex_number::operator/(float x) const{
	complex_number result;
	result.Re = Re/x;
	result.Im = Im/x;
	return result;
};

complex_number complex_number::operator/(const complex_number& temp) const{
	complex_number result;
	result = (*this)*con(temp)/(temp.Re*temp.Re + temp.Im*temp.Im);
	return result;
};

complex_number operator/(float x, const complex_number& temp){
	complex_number complex(x, 0);
	return complex/temp;
};

complex_number operator-(const complex_number& temp){
	return (-1)*temp;
};

complex_number complex_number::operator-(const complex_number& temp) const{
	return *this+(-1)*temp;
};

complex_number complex_number::operator-(float x) const{
	complex_number result;
	result.Re = Re - x;
	result.Im = Im;
	return result;
};

complex_number operator-(float x, const complex_number& temp){
	return -(temp - x);
}

float complex_number::operator[](index i) const{
	return (i == Re);
}

bool complex_number::operator==(const complex_number& temp) const{
	return ((Re == temp.Re)&&(Im == temp.Im));
}

bool complex_number::operator==(float x) const{
	return((Re == x)&&(Im == 0));
}

std::istream & operator >>(std::istream & is, complex_number& temp){
	is >> temp.Re >> temp.Im;
	return is;
}

std::ostream & operator <<(std::ostream & os, const complex_number& temp){
	if ((Re != 0) && (Im != 0)){
		os << Re << " + " << Im << "i" << std::endl;
	}else if (Re == 0) {
		os << Im << "i" << std::endl;
	}else if (Im == 0) {
		os << Re << std::endl;
	}else{
		os << '0' << std::endl;
	};
	return os;
}
