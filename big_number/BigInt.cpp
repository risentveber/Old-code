#include "BigInt.hpp"
#include <iostream>
#include <iomanip>
#include <sstream>

//конструкторы и деструкторы
BigInt::BigInt(){
    _coeff.push_back(0);
    _isNegativ = false;
}
BigInt::BigInt(int a){
    if (a < 0){
        _isNegativ = true;
        a = - a;
    }else{
        _isNegativ = false;
        if (a == 0)
            _coeff.push_back(0);
    }

    while (a > 0){
        _coeff.push_back(a % BASE);
        a = a / BASE;
    }
}
BigInt::~BigInt(){
}
int BigInt::operator  = (int n){
    BigInt b(n);
    *this = b;
    return n;
}
//ввод и вывод
std::istream& operator >> (std::istream& input, BigInt& tmp){
    std::string str = "";
    char a = input.peek();
    while ((a == ' ') || (a == '\n')){// очистка лидирующих пробелов
        input.get();
        a = input.peek();
    };

    if (a == '-'){// определение знака
        input.get();
        tmp._isNegativ = true;
    }else if (a == '+')
        input.get();

    bool numberIsRead = false;
    while ( input.peek() == '0' ){//зачистка лидирующих нулей
        input.get();
        numberIsRead = true;
    };

    while((input.peek() >= '0') && (input.peek() <= '9')){
        str += input.get();
    };

    int l = str.length();
    if (l == 0){
        if (numberIsRead){//если это был ноль
            tmp._coeff.clear();
            tmp._coeff.push_back(0);
            tmp._isNegativ = false;
            return input;
        }else{//некорректный ввод
            throw;
        }
    }else{
        tmp._coeff.clear();
        int buf = 0;
        int k = 1;
        for(int i = l - 1; i >= 0; i--){
            if (k == BASE){//если разряды накидывать в вектор
                tmp._coeff.push_back(buf);
                buf = 0;
                k = 1;
            }
            buf += (str[i] - '0') * k;
            k = k * 10;
        }
        if (buf != 0)
            tmp._coeff.push_back(buf);
    }

    return input;
}
std::ostream& operator << (std::ostream& output, const BigInt &tmp){
    if (tmp._isNegativ)
        output << '-';
    output << tmp._coeff[ tmp._coeff.size() - 1];
    for(int i = tmp._coeff.size() - 2; i >= 0; i--)
        std::cout << std::setfill('0') << std::setw(BASE_WIDTH) << tmp._coeff[i];
    return output;
}
std::string writerVector(const BigInt &tmp){
    std::stringstream ss;
    if (tmp._isNegativ)
        ss << '-';
    ss << ' ';
    ss << tmp._coeff[ tmp._coeff.size() - 1];
    ss << ' ';
    for(int i = tmp._coeff.size() - 2; i >= 0; i--){
        ss << tmp._coeff[i];
        ss << ' ';
    };

    return ss.str();
}
//сравнение
bool BigInt::isNull() const{
    return (_coeff.size() == 1) && (_coeff[0] == 0);
}
bool absCom(const BigInt &a, const BigInt &b){
    int a_s = a._coeff.size();
    int b_s = b._coeff.size();
    if (a_s > b_s)
        return true;
    else
        if (a_s == b_s)
            for(int i = a_s - 1; i >= 0; i--){
                if (a._coeff[i] > b._coeff[i])
                    return true;
                else
                    if (a._coeff[i] < b._coeff[i])
                        return false;
            }
    return false;
}

bool operator == (const BigInt &a, const BigInt &b){
    if ((a._coeff.size() == b._coeff.size()) && (a._isNegativ == b._isNegativ)){
        for(int i = a._coeff.size() - 1; i >= 0; i--){
            if (a._coeff[i] != b._coeff[i])
                return false;
        }
        return true;
    }
    return false;
}
bool operator != (const BigInt &a, const BigInt &b){
    return !(a == b);
}
bool operator >  (const BigInt &a, const BigInt &b){
    if(a._isNegativ)
        if(b._isNegativ)
            return absCom(b, a);
        else
            return false;
    else
        if(b._isNegativ)
            return true;
        else
            return absCom(a, b);
}
bool operator <  (const BigInt &a, const BigInt &b){
    return b > a;
}
bool operator >= (const BigInt &a, const BigInt &b){
    return (a == b) || (a > b);
}
bool operator <= (const BigInt &a, const BigInt &b){
    return (a == b) || (b > a);
}

bool operator == (const BigInt &a, int n){
    BigInt b(n);
    return a == b;
}
bool operator != (const BigInt &a, int n){
    BigInt b(n);
    return !(a == b);
}
bool operator >  (const BigInt &a, int n){
    BigInt b(n);
    return a > b;
}
bool operator <  (const BigInt &a, int n){
    BigInt b(n);
    return b > a;
}
bool operator >= (const BigInt &a, int n){
    BigInt b(n);
    return (a > b) || (a == b);
}
bool operator <= (const BigInt &a, int n){
    BigInt b(n);
    return (b > a) || (b == a);
}

bool operator == (int n, const BigInt &b){
    BigInt a(n);
    return a == b;
}
bool operator != (int n, const BigInt &b){
    BigInt a(n);
    return !(a == b);
}
bool operator >  (int n, const BigInt &b){
    BigInt a(n);
    return a > b;
}
bool operator <  (int n, const BigInt &b){
    BigInt a(n);
    return b > a;
}
bool operator >= (int n, const BigInt &b){
    BigInt a(n);
    return (a > b) || (a == b);
}
bool operator <= (int n, const BigInt &b){
    BigInt a(n);
    return (b > a) || (b == a);
}
//определение знака при умножении
bool isNegativ(const BigInt &a, const BigInt &b){
    return !a.isNull() && !b.isNull() && (a._isNegativ ^ b._isNegativ);
}
bool isNegativ(const BigInt &a, int n){
    return !a.isNull() && n != 0 && (a._isNegativ ^ (n < 0));
}
//сложение вычитание (в том числе и унарное)
BigInt operator + (const BigInt &a){
    return a;
}
BigInt operator - (const BigInt &a){
    if (a.isNull())
        return a;
    else{
        BigInt b = a;
        b._isNegativ = !a._isNegativ;
        return b;
    }
}

BigInt operator + (const BigInt &a, const BigInt &b){
    if (a._isNegativ)
        if (b._isNegativ)
            return -(-a + - b);
        else
            return b - (- a);
    else
        if (b._isNegativ)
            return a - (- b);
        else{
            BigInt c;
            c._coeff.clear();
            int buf = 0;
            unsigned int l = (a._coeff.size() > b._coeff.size()) ? a._coeff.size() : b._coeff.size();
            for(unsigned int i = 0; i < l; i++){
                if (i < a._coeff.size())
                    buf += a._coeff[i];
                if (i < b._coeff.size())
                    buf += b._coeff[i];
                c._coeff.push_back(buf % BASE);
                buf = buf / BASE;
            }
            if (buf != 0)
                c._coeff.push_back(buf);
            return c;
        }
}
BigInt operator - (const BigInt &a, const BigInt &b){
    if (a._isNegativ)
        if (b._isNegativ)
            return a + (-b);
        else
            return -(-a + b);
    else
        if (b._isNegativ)
            return a + (- b);
        else{
            if (absCom(b, a))
                return -(b - a);
            BigInt res;
            res._coeff.clear();
            int buf = 0;
            unsigned int l = (a._coeff.size() > b._coeff.size()) ? a._coeff.size() : b._coeff.size();
            for(unsigned int i = 0; i < l; i++){
                if (i < a._coeff.size())
                    buf += a._coeff[i];
                if (i < b._coeff.size())
                    buf -= b._coeff[i];
                if (buf < 0){
                    res._coeff.push_back(buf + BASE);
                    buf = -1;
                }else{
                    res._coeff.push_back(buf);
                    buf = 0;
                }
            }
            while (res._coeff.size() > 1 && res._coeff[res._coeff.size() - 1] == 0)
                res._coeff.pop_back();
            return res;
        }
}

BigInt operator + (const BigInt &a, int n){
    BigInt b(n);
    return a + b;
}
BigInt operator - (const BigInt &a, int n){
    BigInt b(n);
    return a - b;
}

BigInt operator + (int n, const BigInt &b){
    BigInt a(n);
    return a + b;
}
BigInt operator - (int n, const BigInt &b){
    BigInt a(n);
    return a - b;
}
//умножение
BigInt operator *  (const BigInt &a, int n){
    BigInt res;
    if (a.isNull() || n == 0)
        return 0;
    res._coeff.clear();
    res._isNegativ = isNegativ(a, n);
    if (n < 0)
        n = -n;

    int r = 0;
    for (unsigned int i = 0; i < a._coeff.size(); i++){
        res._coeff.push_back(a._coeff[i] * n + r);
        r = res._coeff[i] / BASE;
        res._coeff[i] -= r * BASE;
    }
    while (r != 0){
        res._coeff.push_back(r % BASE);
        r = r / BASE;
    }
    return res;
}
BigInt operator *  (int n, const BigInt &b){
    return b * n;
}
BigInt operator << (BigInt a, unsigned int pos){
    if (a.isNull() || pos == 0)
        return a;
    int s = a._coeff.size();
    for(int i = 0; i < pos; i++)
        a._coeff.push_back(0);
    for (int i = s-1; i >= 0; i--)
        a._coeff[i + pos] = a._coeff[i];
    for(int i = 0; i < pos; i++)
        a._coeff[i] = 0;
    return a;
}
BigInt operator *  (const BigInt &a, const BigInt &b){
    if (a.isNull() || b.isNull())
        return 0;
    BigInt res;
    res._isNegativ = isNegativ(a, b);
    res._coeff.resize(a._coeff.size() + b._coeff.size());

    for (int i = 0; i < a._coeff.size(); i++){
        int r = 0;
        int j;
        for (j = 0; j < b._coeff.size(); j++){
            res._coeff[i+j] += a._coeff[i] * b._coeff[j] + r;
            r = res._coeff[i+j] / BASE;
            res._coeff[i+j] -= r * BASE;
        }
        while(r != 0){
            res._coeff[i+j] +=  r;
            r = res._coeff[i+j] / BASE;
            res._coeff[i+j] -= r * BASE;
            j++;
        }
    }
    while ((res._coeff.size() > 1) && (res._coeff[res._coeff.size() - 1] == 0))
        res._coeff.pop_back();
    return res;
}
//деление
BigInt operator / (const BigInt &a, int n){
    if (n == 0)
        throw;
    BigInt res;
    if (a.isNull())
        return 0;


    res._isNegativ = isNegativ(a, n);
    if (n < 0)
        n = -n;

    res._coeff.resize(a._coeff.size());
    int ost = 0;
    int cur;
    for (int i = a._coeff.size() - 1; i >= 0; i--){
        cur = ost * BASE + a._coeff[i];
        res._coeff[i] = cur / n;
        ost = cur % n;
    }
    while((res._coeff.size() != 1) && (res._coeff[res._coeff.size() - 1] == 0))
        res._coeff.resize(res._coeff.size() - 1);
    return res;
}
int operator % (const BigInt &a, int n){
    if (n == 0)
        throw;
    BigInt res;
    if (a.isNull())
        return 0;
    if (n < 0)
        n = -n;

    res._coeff.resize(a._coeff.size());
    int ost = 0;
    int cur;
    for (int i = res._coeff.size() - 1; i >= 0; i--){
        cur =  ost * BASE + a._coeff[i];
        res._coeff[i] = cur / n;
        ost = cur % n;
    }
    if (isNegativ(a, n))
        ost = -ost;
    return ost;
}
BigInt operator /  (BigInt a, BigInt b){
    if(b.isNull())
        throw;
    if(a.isNull())
        return 0;

    BigInt res;
    //определяемся со знаком
    res._isNegativ = isNegativ(a, b);
    if(a._isNegativ)
        a = - a;
    if(b._isNegativ)
        b = - b;

    res._coeff.resize(a._coeff.size());
    for(unsigned int i = 0; i < a._coeff.size(); i++)
        res._coeff[i] = 0;
    BigInt curValue;
    BigInt cur;
    for (int i = a._coeff.size() - 1; i >= 0; i--){
        curValue = curValue << 1; // * osn
        curValue._coeff[0] = a._coeff[i];
        //std::cout << curValue << std::endl;

        // подбираем максимальное число x, такое что b * x <= curValue
        int x = 0;
        int l = 0, r = BASE;
        while (l <= r){
            int m = (l + r) >> 1;
            cur = b * m;
            if (cur <= curValue){
                x = m;
                l = m+1;
            }else
                r = m-1;
        }
        res._coeff[i] = x;
        curValue = curValue - b * x;
    }
    // избавляемся от лидирующих нулей
    while (res._coeff.size() > 1 && res._coeff[res._coeff.size() - 1] == 0)
        res._coeff.pop_back();
    if(res.isNull())
        res._isNegativ = false;

    return res;
}

BigInt operator % (const BigInt &a, const BigInt &b){
    return a - a / b * b;
}



