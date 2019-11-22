#include "string.h"
#include <stdexcept>
my_string::my_string(){
	_array = new char[1];
	_array[0] = '\0';
	_length = 0;
}

int my_string::length(){
	return _length;
}

my_string::my_string(const my_string& temp){
	_length = temp._length;
	_array = new char[_length + 1];
	int i = 0;
	while(_array[i] = temp._array[i++]);
}

my_string::my_string(const char *temp){
	_length = 0;
	while (temp[_length])
		++_length;
	_array = new char[_length + 1];
	int i = 0;
	while(_array[i] = temp[i++]);
}

my_string::~my_string(){
	delete[] _array;
}

const my_string& my_string::operator=(const my_string& temp){
	if (this == &temp)
		return temp;
	_length = temp._length;
	delete[] _array;
	_array = new char[_length + 1];
	int i = 0;
	while(_array[i] = temp._array[i++]);
	return temp;
}

std::ostream& operator<<(std::ostream& output,const my_string& temp){
	for(int i = 0; i < temp._length; i++)
		output << temp._array[i];
	return output;
}

std::istream& operator>>(std::istream& input, my_string& temp){
	delete[] temp._array;
	temp._array = NULL;
	temp._length = 0;
	char buffer[3];
	char a;
	char* b;
	int i = 0;//указатель на первый пустой элемент буффера
	do{
		a = input.get();
		if ((a == '\n')||(a == ' '))
			a = '\0';
		if(i == 3){
			b = new char[temp._length + 3];
			for(i = 0; i < temp._length; i++)
				b[i] = temp._array[i];
			delete[] temp._array;
			for(i = 0; i < 3; i++)
				b[i + temp._length] = buffer[i];
			temp._array = b;
			
			temp._length = temp._length + 3;
			i = 1;
			buffer[0] = a;
		}else{
			buffer[i] = a;
			i++;
		};

	}while (a != '\0');

	b = new char[temp._length + i];
	for(int k = 0; k < temp._length; k++)
		b[k] = temp._array[k];
	delete[] temp._array;
	for(int k = 0; k < i; k++)
		b[k + temp._length] = buffer[k];
	temp._array = b;
			
	temp._length = temp._length + i - 1;

	//добуферизация
	return input;
}

my_string my_string::operator+(const my_string& temp)const{
	my_string result;
	delete[] result._array;
	result._array = new char[_length + temp._length + 1];
	result._length = _length + temp._length;
	int i;
	for(i = 0; i < _length; i++)
		result._array[i] = _array[i];
	for(i = 0; i < temp._length; i++)
		result._array[_length + i] = temp._array[i];
	result._array[result._length] = '\0';
	return result;
}

my_string my_string::substring(int left, int right) const{
	if ((0 <= left)&&(left <= right)&&( right < _length)){
		my_string result;
		delete[] result._array;
		result._array = new char[right - left + 2];
		result._length = right - left + 1;
		for(int i = 0; i < result._length; i++)
			result._array[i] = _array[left + i];
		result._array[result._length] = '\0';
		return result;
	}else
		throw std::out_of_range("out_of_range");
}

int my_string::find(const my_string& temp) const{
	for(int i = 0; i < _length - temp._length + 1; i++){
		for(int k = 0; (k < temp._length)&&(_array[i + k] == temp._array[k]); k++)
			if (k == temp._length - 1)
				return i;
	};
	return -1;
}

char& my_string::operator[](int index){
	if ((index >= 0)&&(index < _length))
		return _array[index];
	else
		throw std::out_of_range("out_of_range");
}

const char& my_string::operator[](int index) const{
	if ((index >= 0)&&(index < _length))
		return _array[index];
	else
		throw std::out_of_range("out_of_range");
}