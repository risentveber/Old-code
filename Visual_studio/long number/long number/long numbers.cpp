#include "long numbers.h"
#include <cstdio>
#include <string>
#include <sstream> 
#include <iostream>

////*****************************
////Help functions
//
//bool absCom(const BigInt &a, const BigInt &b){
//	if (a._coeff.size() > b._coeff.size())
//		return true;
//	else
//		if (a._coeff.size() == b._coeff.size())
//			for(int i = a._coeff.size() - 1; i >= 0; i--){
//				if (a._coeff[i] > b._coeff[i])
//					return true;
//				else 
//					if (a._coeff[i] < b._coeff[i])
//						return false;
//			}
//
//	return false;
//}
//
//unsigned int charToInt(const char a){
//	int b = (a - '0');
//		if ((b < 0) || (b > 9))
//			throw;
//	return b;
//}
//
//bool isNegativ(const BigInt &a, const BigInt &b){
//	return !( ( a._coeff.size() == 1 && a._coeff[0] == 0)
//			||( b._coeff.size() == 1 && b._coeff[0] == 0)
//			|| a._isNegativ && b._isNegativ 
//			|| !a._isNegativ && !b._isNegativ );
//}
//
////bool isNegativ(bool isNeg1, bool isNeg2){
////	return (isNeg1 && !isNeg2) || (!isNeg1 && isNeg2);
////}
//
//bool isNegativ(const BigInt &a, int n){
//	return !( ( a._coeff.size() == 1 && a._coeff[0] == 0)
//			||( n == 0)
//			|| a._isNegativ && n < 0 
//			|| !a._isNegativ && n > 0 );
//}
//
//std::string writer(const BigInt &a){
//	std::stringstream ss;
//	ss << a;
//	return ss.str();
//}
//
//std::string writerVector(const BigInt &tmp){
//	std::stringstream ss;
//	if (tmp._isNegativ)
//		ss << '-';
//	ss << ' ';
//	ss << tmp._coeff[ tmp._coeff.size() - 1];
//	ss << ' ';
//	int k;
//	for(int i = tmp._coeff.size() - 2; i >= 0; i--){
//		ss << tmp._coeff[i];
//		ss << ' ';		
//	};
//	
//	return ss.str();
//}
//

////*****************************
////Member of class BigInt functions

//BigInt::BigInt(){
//	_coeff.push_back(0);
//	_isNegativ = false;
//}
//
//BigInt::~BigInt(){
//}
//
//BigInt::BigInt(int a){
//	if (a < 0){
//		_isNegativ = true;
//		a = - a;
//	}else{
//		_isNegativ = false;
//		if (a == 0)
//			_coeff.push_back(0);
//	}
//
//
//	while (a > 0){
//		_coeff.push_back(a % BASE);
//		a = a / BASE;
//	}
//}

////*****************************
////Operators

//std::istream& operator >> (std::istream& input, BigInt& tmp){
//	std::string str;
//	input >> str;
//	int l = str.length();
//	int buf = 0;
//	tmp._coeff.clear();
//	int k = 1;
//	for (int i = l - 1; i > 0; i--){
//		
//		buf += charToInt(str[i]) * k;
//		k = k * 10;
//		if (buf >= BASE) {
//			tmp._coeff.push_back(buf % BASE);
//			buf = buf / BASE;
//			k = 10;
//		}
//	}
//	if (str[0] == '-'){
//		if (buf != 0)
//			tmp._coeff.push_back(buf % BASE);			
//		tmp._isNegativ = true;
//	}else{
//		buf += charToInt(str[0])*k;
//		if (buf >= BASE) {
//			tmp._coeff.push_back(buf % BASE);
//			buf = buf / BASE;
//		}
//		if (buf != 0)
//			tmp._coeff.push_back(buf % BASE);
//		buf = buf / BASE;
//		if (buf != 0)
//			tmp._coeff.push_back(buf);
//		tmp._isNegativ = false;
//	}
//	if (str[0] == '0')
//		tmp._coeff.push_back(0);
//	return input;
//}
//
//std::ostream& operator << (std::ostream& output, const BigInt &tmp){
//	if (tmp._isNegativ)
//		output << '-';
//	output << tmp._coeff[ tmp._coeff.size() - 1];
//	int k;
//	for(int i = tmp._coeff.size() - 2; i >= 0; i--){
//		k = BASE;
//		int b = tmp._coeff[i];
//		while(k != 1){
//			k = k/10;
//			if (b / k == 0)
//				output << 0;
//			else{
//				output << b;
//				k = 1;
//			}
//		}
//		//output << tmp._coeff[i] << std::endl;
//	};
//	return output;
//}

//bool operator > (const BigInt &a, const BigInt &b){
//	if(a._isNegativ)
//		if(b._isNegativ)
//			return absCom(b, a);
//		else
//			return false;
//	else
//		if(b._isNegativ)
//			return true;
//		else
//			return absCom(a, b);
//}
//
//bool operator == (const BigInt &a, const BigInt &b){
//	if ((a._coeff.size() == b._coeff.size()) && ((a._isNegativ && b._isNegativ) || !(a._isNegativ && b._isNegativ))){
//		for(int i = a._coeff.size() - 1; i >= 0; i--){
//			if (a._coeff[i] != b._coeff[i])
//				return false;
//		}
//		return true;
//	}
//	return false;
//}
//
//bool operator < (const BigInt &a, const BigInt &b){
//	return b > a;
//}
//
//bool operator <= (const BigInt &a, const BigInt &b){
//	return (a < b) || (a == b);
//}
//
//bool operator >= (const BigInt &a, const BigInt &b){
//	return (a > b) || (a == b);
//}
//
//BigInt operator + (const BigInt &a){
//	return a;
//}
//
//BigInt operator - (const BigInt &a){
//	BigInt c = a;
//	c._isNegativ = !c._isNegativ;
//	return c;
//}

///////
//BigInt operator + (const BigInt &a, const BigInt &b){
//	if (a._isNegativ)
//		if (b._isNegativ)
//			return -(-a + - b);
//		else
//			return b - (- a);
//	else
//		if (b._isNegativ)
//			return a - (- b);
//		else{
//			BigInt c;
//			c._coeff.clear();
//			int buf = 0;
//			int l = (a._coeff.size() > b._coeff.size()) ? a._coeff.size() : b._coeff.size();
//			for(int i = 0; i < l; i++){
//				if (i < a._coeff.size())
//					buf += a._coeff[i];
//				if (i < b._coeff.size())
//					buf += b._coeff[i];
//				c._coeff.push_back(buf % BASE);
//				buf = buf / BASE;
//			}
//			if (buf != 0)
//				c._coeff.push_back(buf);
// 			return c;
//		}
//}
//
//BigInt operator - (const BigInt &a, const BigInt &b){
//	if (a._isNegativ)
//		if (b._isNegativ)
//			return a + (-b);
//		else
//			return -(-a + b);
//	else
//		if (b._isNegativ)
//			return a + (- b);
//		else{
//			if (absCom(b, a))
//				return -(b - a);
//			BigInt c;
//			c._coeff.clear();
//			int buf = 0;
//			int l = (a._coeff.size() > b._coeff.size()) ? a._coeff.size() : b._coeff.size();
//			for(int i = 0; i < l; i++){
//				if (i < a._coeff.size())
//					buf += a._coeff[i];
//				if (i < b._coeff.size())
//					buf -= b._coeff[i];
//				if (buf < 0){
//				  c._coeff.push_back(buf + BASE);
//				  buf = -1;
//				}else{
//					c._coeff.push_back(buf);
//					buf = 0;
//				}
//			}
//			//c._coeff.push_back(buf);
//			return c;
//		}
//}
////////
//BigInt operator + (const BigInt &a, const int b){
//	BigInt bBig(b);
//	return a + bBig;
//}
//
//BigInt operator + (const int b, const BigInt &a){
//	BigInt bBig(b);
//	return a + bBig;
//}
//
//BigInt operator - (const BigInt &a, const int b){
//	BigInt bBig(b);
//	return a - bBig;
//}
//
//BigInt operator - (const int b, const BigInt &a){
//	BigInt bBig(b);
//	return a - bBig;
//}
//
//BigInt operator * (const BigInt &a, int n)
//{
//	/*if ((n > BASE) || (n < -BASE)){
//		BigInt d(n);
//		return a * d;
//	}*/
//
//	BigInt res;
//	res._coeff.clear();
//	//res.amount = a.amount;
//	res._isNegativ = isNegativ(a, n);
//	if (n < 0)
//		n = -n;
//	int r = 0;
//	for (int i=0; i < a._coeff.size(); i++){
//		res._coeff.push_back(a._coeff[i] * n + r);
//		r = res._coeff[i] / BASE;
//		res._coeff[i] -= r * BASE;
//	}
//	if (r != 0)
//		res._coeff.push_back(r);
//	int pos = a._coeff.size() - 1;
//	while (pos > 0 && !res._coeff[pos])
//    pos--;
//	res._coeff.resize(pos+1);
//
//	return res;
//}
//
//BigInt operator * ( int n, const BigInt &a){
//	return a * n;
//}

//BigInt operator / (const BigInt &a, int n){
//	
//	/*if ((n > BASE) || (n < -BASE)){
//		BigInt d(n);
//		return a / d;
//	}*/
//	BigInt res;
//	res._isNegativ = isNegativ(a, n);
//	if (n < 0)
//		n = -n;
//	
//	res._coeff.resize(a._coeff.size());
//	int ost = 0;
//	int cur;
//	for (int i = a._coeff.size() - 1; i >= 0; i--){
//		cur = ost * BASE + a._coeff[i];
//		res._coeff[i] = cur / n;
//		ost = cur % n;
//	}
//	if (!res._coeff[res._coeff.size() - 1] && res._coeff.size() != 1)
//		res._coeff.resize(res._coeff.size() - 1);
//	return res;
//}

//int operator % (const BigInt &a, int n){
//	BigInt res;
//	res._isNegativ = isNegativ(a, n);
//	if (n < 0)
//		n = -n;
//	
//	res._coeff.resize(a._coeff.size());
//	int ost = 0;
//	int cur;
//	for (int i = res._coeff.size() - 1; i >= 0; i--){
//		cur =  ost * BASE + a._coeff[i];
//		res._coeff[i] = cur / n;
//		ost = cur % n;
//	}
//	if (res._isNegativ)
//		ost = -ost;
//	return ost;
//}

//BigInt operator * (const BigInt &a, const BigInt &b)
//{
//	BigInt res;
//	res._isNegativ = isNegativ(a, b);
//	res._coeff.resize(a._coeff.size() + b._coeff.size());
//
//	for (int i = 0; i < a._coeff.size(); i++){
//		int r = 0;
//		int j;
//		for (j = 0; j < b._coeff.size(); j++){
//			res._coeff[i+j] += a._coeff[i] * b._coeff[j] + r; 
//			r = res._coeff[i+j] / BASE;
//			res._coeff[i+j] -= r * BASE;
//		}
//		while(r != 0){
//			res._coeff[i+j] +=  r; 
//			r = res._coeff[i+j] / BASE;
//			res._coeff[i+j] -= r * BASE;
//			j++;
//		}
//  }
//  //int pos = a.amount + b.amount;
//  while ((res._coeff.size() > 1 && !res._coeff[res._coeff.size() - 1]))
//    res._coeff.pop_back();
//  //res.amount = pos + 1;
//  return res;
//}


//void BigInt::LevelUp()
//{
//	_coeff.push_back(0);
//  for (int i = _coeff.size() - 1; i >= 1; i--)
//    _coeff[i] = _coeff[i-1];
//  if (!_coeff[_coeff.size() - 1])
//    _coeff.pop_back();
//}

BigInt operator / (const BigInt &a, const BigInt &b)
{
  BigInt res;
  BigInt curValue;
  res._coeff.resize(a._coeff.size());
  for (int i = a._coeff.size()-1; i >= 0; i--)
  {
    curValue.LevelUp(); // * osn
    curValue._coeff[0] = a._coeff[i];
    // подбираем максимальное число x, такое что b * x <= curValue
    int x = 0;
    int l = 0;
	int r;
	r = BASE;
    while (l <= r)
    {
      int m = (l + r) >> 1;
      BigInt cur = b * m;
      if (cur <= curValue)
      {
        x = m;
        l = m + 1;
      }
      else
        r = m - 1;
    }
	res._coeff[i] = x;
    curValue = curValue - b * x;
  }
  // избавляемся от лидирующих нулей
  int pos = a._coeff.size() - 1;
  while (pos > 0 && !res._coeff[pos])
    pos--;
  res._coeff.resize(pos+1);
 
  return res;
}



















