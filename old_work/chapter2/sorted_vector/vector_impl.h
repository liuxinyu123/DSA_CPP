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
Rank Vector<T>::insert (Rank r, const T &e)
{
	check (r, "rank passed!");
	if (isFull ())
		expand ();
	for (Rank i = _size; i > r; --i)
		_elem[i] = _elem[i - 1];
	_elem[r] = e;
	++_size;

	return r;
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

template<typename T>
Rank Vector<T>::find (const T &e, Rank lo, Rank hi) const
{
	for (Rank i = hi; i > 0; --i)
	{
		if (e == _elem[i - 1])
			return i - 1;
	}
	return -1;
}

template<typename T>
void Vector<T>::pushBack (const T &e)
{
	if (isFull ())
		expand ();
	_elem[_size++] = e;
}

template<typename T>
T Vector<T>::popBack ()
{
	if (isEmpty ())
		throw std::out_of_range ("underflow");
	return _elem[_size--];
}

template<typename T>
void Vector<T>::remove (Rank lo, Rank hi)
{
	check (hi - 1, "passed the max index");
	
	if (lo == hi)
		return;

	for (Rank i = hi; i < _size; ++i)
		_elem[lo++] = _elem[hi++];
	_size = _size - (hi - lo);
	shrink ();
}

template<typename T>
void Vector<T>::remove (Rank r) 
{
	check (r, "passed the max index");
	remove (r, r+1);
}

template<typename T>
int Vector<T>::deduplicate ()
{
	Rank old_size = _size;

	Rank i = 1;
	while (i < _size)
	{
		if (find (_elem[i], 0, i) < 0)
			++i;
		else
			remove (i);
	}
	return old_size - _size;
}

template<typename T>
void Vector<T>::pushFront (const T &e)
{
	if (isFull ())
		expand ();
	for (Rank i = _size; i > 0; --i)
		_elem[i] = _elem[i - 1];
  	
   	_elem[0] = e;
	++_size;	   
}

template<typename T>
T Vector<T>::popFront ()
{
	if (isEmpty ())
		throw std::out_of_range ("underflow");
	T ret = _elem[0];
	remove (0, 1);
	return ret;
}

template<typename T> template<typename VST>
void Vector<T>::traverse (VST &visit)
{
	for (Rank i = 0; i < _size; ++i)
		visit (_elem[i]);
}

template<typename T>
int Vector<T>::disordered () const
{
	int ret = 0;
	for (Rank i = 1; i < _size; ++i)
	{
		if (_elem[i - 1] > _elem[i])
			++ret;
	}

	return ret;
}

template<typename T>
void Vector<T>::sort ()
{
	bool sorted = false;
	Rank sz = _size;
	using std::swap;
	while (!sorted)
	{
		sorted = true;
		for (Rank i = 0; i < sz - 1; ++i)
		{
			if (_elem[i] > _elem[i + 1] )
			{
				swap (_elem[i], _elem[i + 1]);
				sorted = false;			
			}
		}
		--sz;
	
	}
}

template<typename T>
int Vector<T>::uniquify ()
{
	int old_size = _size;
	Rank i = 1;
	while (i < _size)
	{
		if (_elem[i] == _elem[i - 1])
			remove (i);
		else
			++i;
	}

	return old_size - _size;
}

template<typename T>
int Vector<T>::uniquify_v2 ()
{
	int old_size = _size;

	Rank i = 0, j = 1;
	while (j < _size)
	{
		if (_elem[j] == _elem[i])
			++j;
		else
		{
			_elem[++i] = _elem[j];
			
		}
	}

	_size = ++i;

	return old_size - _size;
}
#endif
