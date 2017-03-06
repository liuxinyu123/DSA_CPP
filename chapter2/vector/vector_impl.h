#ifndef _VECTOR_IMPL_H_
#define _VECTOR_IMPL_H_

template<typename T>
Vector<T>::Vector (const Vector<T> &v)
	:_capacity (v._capacity), _size (v._size), _elem (new T[_capacity])
{
	copyFrom (v._elem, 0, _size);	
}

template<typename T>
void Vector<T>::copyFrom (const T *arr, Rank lo, Rank hi)
{
	for (Rank i = 0; lo < hi; ++lo, ++i)
		_elem[i] = arr[lo];
}

template<typename T>
void Vector<T>::check (Rank r, const std::string &s) const
{
	if (_size <= r)
		throw std::out_of_range (s);
}

#endif
