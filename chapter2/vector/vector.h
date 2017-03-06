#ifndef _VECTOR_H_
#define _VECTOR_H_

#include <string>
#include <stdexcept>

using Rank = int;
const int Default_Capacity = 10;

template<typename T>
class Vector
{
public:
		Vector (int cap = Default_Capacity, Rank sz = 0, T e = 0)
			:_capacity (cap), _size (sz), _elem (new T[cap]) 
		{
			for (Rank i = 0; i < _size; ++i)
				_elem [i] = e;
		}
		Vector (const Vector<T> &v);
		Vector& operator= (const Vector<T> &v);
		T& operator[] (const Rank r)
		{
			check (r, "overflow");
			return _elem[r];
		}
		~Vector ()
		{
			delete [] _elem;
		}
		Rank size () const
		{
			return _size;
		}
		void copyFrom (const T* arr, Rank lo, Rank hi);
		void insert (Rank r, T &e);
			
		
private:
		void check (Rank r, const std::string &s) const;
private:
		int _capacity;
		Rank _size;
		T *_elem;
};

#include "vector_impl.h"

#endif
