#include "vector_general.h"

//специализация bool
template<>
class myVector<bool>{
private:
	size_t _capacity;
	size_t _size;
	char *_array;
public:
	myVector();//done
	myVector(const myVector &);//done
	void pushBack(bool);//
	void popBack();//
	bool operator [] (size_t index)const;
	const myVector & operator = (const myVector &);//done
	friend bool operator == (const myVector &a, const myVector&b);//done
	void clear();//done
	~myVector();//done
	size_t size() const;//done
	void resize(size_t newSize);//done
};

bool operator == (const myVector<bool> &a, const myVector<bool> &b){
	if (a._size == b._size){
		size_t size = a._size;
		for(size_t i = 0; i < size / 8; ++i)
			if (a._array[i] != b._array[i])
				return false;
		if (a._array[size/8*8] & (255 << (7 - size % 8)) != b._array[size/8*8] & (255 << (7 - size % 8)))
			return false;
		return true;
	}
	return false;
};

myVector<bool>::myVector(){
	_capacity = 2;
	_size = 0;
	_array = new char[2];
}

myVector<bool>::myVector(const myVector& a){
	_capacity = a._capacity;
	_size = a._size;
	_array = new char[_capacity];
	for(size_t i = 0; i < _capacity; ++i)
		_array[i] = a._array[i];
}

myVector<bool>::~myVector(){
	delete[] _array;
}

const myVector<bool> & myVector<bool>::operator = (const myVector& a){
	if (this == &a)
		return a;
	_capacity = a._capacity;
	_size = a._size;
	_array = new char[_capacity];
	for(int i = 0; i < _capacity; ++i)
		_array[i] = a._array[i];
	return a;
}

size_t myVector<bool>::size() const{
	return _size;
}

void myVector<bool>::clear(){
	delete[] _array;
	_capacity = 2;
	_size = 0;
	_array = new char[2];
}

void myVector<bool>::resize(size_t newSize){
	size_t newCapacity;
	if (newSize < 16)
		newCapacity = 2;
	else{
		newCapacity = newSize/8;
		if (newSize % 8)
			++newCapacity;
	}
	char * newArray = new char[newCapacity];
	for(size_t i = 0; i < newCapacity && i <_capacity; ++i)
		newArray[i] = _array[i];
	delete[] _array;
	_array = newArray;
	_capacity = newCapacity;
	_size = newSize;

};

void myVector<bool>::pushBack(bool x){
	if( _size == _capacity * 8){
		char* tmp = new char[_capacity * 2];
		for(size_t i = 0; i < _capacity; ++i)
			tmp[i] = _array[i];
		delete[] _array;
		_array = tmp;
		_capacity *= 2;
	}
	char a;
	a = 1 << (7 - _size % 8);
	if (x){
		_array[_size / 8] = _array[_size / 8] | a;
	}else{
		a = ~a;
		_array[_size / 8] = _array[_size / 8] & a;
	}
	++_size;
};

void myVector<bool>::popBack(){
	if(_size > 0)
		--_size;
	if(_capacity/2 >= 2 && _size <= _capacity / 2 * 8){
		char* tmp = new char[_capacity / 2];
		for(size_t i = 0; i < _capacity / 2; ++i)
			tmp[i] = _array[i];
		delete[] _array;
		_array = tmp;
		_capacity /= 2;
	}
};

bool  myVector<bool>::operator [] (size_t index)const{
	if (index < _size){
		return _array[index / 8] & (1 << (7 - index % 8));
	}else
		throw std::out_of_range("myVector");

};















