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
		Vector (const T *arr, int lo, int hi);

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
		void insert (Rank r, const T &e);
		bool isEmpty () const
		{
			return _size == 0;
		}
		T get (Rank r) const
		{
			check (r, "passed the max rank");
			return _elem[r];
		}	
		void put (Rank r, const T &e)
		{
			check (r, "passed the max rank");
			_elem[r] = e;
		}	
		void unsort (Rank lo, Rank hi);
private:
		void check (Rank r, const std::string &s) const;
		void expand ();
		bool isFull () const
		{
			return _size == _capacity;
		}
		void shrink ();
private:
		int _capacity;
		Rank _size;
		T *_elem;
};

#include "vector_impl.h"

#endif
