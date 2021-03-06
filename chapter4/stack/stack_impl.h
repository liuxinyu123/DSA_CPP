#ifndef _STACK_IMPL_H_
#define _STACK_IMPL_H_

template<typename T>
void Stack<T>::expand ()
{
	_capacity *= 2;
	auto old_data = _data;
	_data = new T[_capacity];

	for (int i = 0; i < _size; ++i)
		_data[i] = old_data[i];
	delete [] old_data;
}

template<typename T>
Stack<T>::Stack (const Stack<T> &s)
	:_capacity (s._capacity), _size (s._size), _data (new T[_capacity]) 
{
	copyFrom (s);
}

template<typename T>
Stack<T>& Stack<T>::operator= (const Stack<T> &s)
{
	if (*this != s)
	{
		delete [] _data;
		_capacity = s._capacity;
		_size = s._size;
		_data = new T[_capacity];

		copyFrom (s);
	}

	return *this;
}

template<typename T>
bool Stack<T>::operator== (const Stack<T> &s)
{
	return (_capacity == s._capacity) && (_size == s._size) && (_data == s._data);
}

template<typename T>
bool Stack<T>::operator!= (const Stack<T> &s)
{
	return !(*this == s);
}

template<typename T>
void Stack<T>::shrink ()
{
	if (5 * _size < _capacity)
	{
		_capacity /= 2;
		_capacity = (_capacity < DefaultCapacity) ? DefaultCapacity : _capacity;
		auto old_data = _data;
		_data = new T[_capacity];
		
		for (int i = 0; i < _size; ++i)
			_data[i] = old_data [i];
	}
}

template<typename T>
void Stack<T>::copyFrom (const Stack<T> &s)
{
	for (int i = 0; i < s.size (); ++i)
		_data[i] = s._data[i];
}
#endif
