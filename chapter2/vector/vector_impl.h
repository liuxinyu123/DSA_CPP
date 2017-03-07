#ifndef _VECTOR_IMPL_H_
#define _VECTOR_IMPL_H_

#include <algorithm>
#include <cstdlib>

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

template<typename T>
Vector<T>::Vector (const T *arr, int lo, int hi)
	:_capacity (2 * (hi - lo)), _size (hi - lo), _elem (new T[_capacity])
{
	copyFrom (arr, lo, hi);	
}

template<typename T>
Vector<T>& Vector<T>::operator= (const Vector<T> &v)
{
	if (_elem != v._elem)
	{
		delete _elem;
		_capacity = v._capacity;
		_size = v._size;
		_elem = new T[_capacity];
		copyFrom (v._elem, 0, v._size);
	}

	return *this;
}

template<typename T>
void Vector<T>::expand ()
{
	_capacity *= 2;
	if (_capacity < Default_Capacity)
		_capacity = Default_Capacity;
	auto old_elem = _elem;
	_elem = new T[_capacity];
	copyFrom (old_elem, 0, _size);
	delete [] old_elem;
}

template<typename T>
void Vector<T>::insert (Rank r, const T &e)
{
	check (r, "rank passed!");
	if (isFull ())
		expand ();

}

template<typename T>
void Vector<T>::shrink ()
{
	if (_capacity < 2*Default_Capacity)
		return;
	if (_size * 4 > _capacity)
		return;
	auto old_elem = _elem;
	_capacity /= 2;
	_elem = new T[_capacity];
	copyFrom (old_elem, 0, _size);
	delete [] old_elem;
}

template<typename T>
void Vector<T>::unsort (Rank lo, Rank hi)
{
	T *v = _elem + lo;
	for (int i = hi - lo; i > 0; --i)
	{
		using std::swap;
		swap (v[i - 1], v[rand () % i]);
	}
}

#endif
