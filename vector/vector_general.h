#include <cstring>
#include <stdexcept>

template<typename T>
class myVector{
private:
	size_t _capacity;
	size_t _size;
	T* _array;
public:
	myVector();
	myVector(const myVector &);
	void pushBack(const T &);
	void popBack();
	T & operator [] (size_t index);
	const T & operator[](size_t) const;
	const myVector & operator = (const myVector &);
	friend bool operator == (const myVector &a, const myVector&b);
	void clear();
	~myVector();
	size_t size() const;
	size_t capacity() const;
	void resize(size_t newSize);
};

//реализация
template<typename T>
myVector<T>::myVector(){
	_capacity = 4;
	_size = 0;
	_array = new T[4];
}

template<typename T>
myVector<T>::myVector(const myVector& a){
	_capacity = a._capacity;
	_size = a._size;
	_array = new T[_capacity];
	for(int i = 0; i < _size; i++)
		_array[i] = a._array[i];
}

template<typename T>
const myVector<T> & myVector<T>::operator = (const myVector& a){
	if (this == &a)
		return a;
	_capacity = a._capacity;
	_size = a._size;
	_array = new T[_capacity];
	for(int i = 0; i < _size; i++)
		_array[i] = a._array[i];
	return *this;
}

template<typename T>
myVector<T>::~myVector(){
	delete[] _array;
}

template<typename T>
void myVector<T>::clear(){
	delete _array;
	_capacity = 4;
	_size = 0;
	_array = new T[4];
}

template<typename T>
void myVector<T>::pushBack(const T &x){
	if ( _size == _capacity){
		T *temp = _array;
		_array = new T[_capacity * 2];
		for(int i = 0; i < _size; i++)
			_array[i] = temp[i];
		delete[] temp;
		_capacity *= 2;
	}
	_array[_size] = x;
	_size++;
}

template<typename T>
void myVector<T>::popBack(){
	if (_size > 0){
		_size--;
		size_t newCapacity = _capacity;
		while((newCapacity >> 1 > 4) && (newCapacity >> 1 > _size))
			newCapacity = newCapacity >> 1;

		if ((_capacity != newCapacity)){
			T *temp = _array;
			_array = new T[newCapacity];
			for(int i = 0; i < _size; i++)
				_array[i] = temp[i];
			delete[] temp;
			_capacity = newCapacity;
		}
	}else
		throw std::out_of_range("myVector:out_of_range");

}

template<typename T>
T & myVector<T>::operator[](size_t i){
	if (i < _size)
		return _array[i];
	else
		throw std::out_of_range("myVector:out_of_range");
}

template<typename T>
const T & myVector<T>::operator[](size_t i) const{
	if (i < _size)
		return _array[i];
	else
		throw std::out_of_range("myVector:out_of_range");
}

template<typename T>
bool operator == (const myVector<T> &a, const myVector<T> &b){
	if (a._size != b._size)
		return false;
	else{
		for(size_t i = 0; i < a._size; i++)
			if (a._array[i] != b._array[i])
				return false;
		return true;
	}
}

template<typename T>
size_t myVector<T>::size() const{
	return _size;
}

template<typename T>
size_t myVector<T>::capacity() const{
	return _capacity;
}

template<typename T>
void myVector<T>::resize(size_t newSize){
	if (newSize <= _capacity)
		_size = newSize;
	else{
		_capacity = 4;
		while (_capacity < newSize)
			_capacity = _capacity << 1;
		T *temp = new T[_capacity];
		if (newSize < _size)
			_size = newSize;
		for(int i = 0; i < _size; ++i)
			temp[i] = _array[i];
		delete[] _array;
		_array = temp;
		_size = newSize;
	}
}



