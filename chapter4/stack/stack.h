#ifndef _STACK_H_
#define _STACK_H_

#include <stdexcept>

const int DefaultSize = 10;

template<typename T>
class Stack
{

public:
		Stack (int cap = DefaultSize)
			:_capacity (cap), _size (0), _data (new T[_capacity])	{}
		Stack (const Stack &s);
		Stack& operator= (const Stack &s);
		~Stack ()
		{
			delete [] _data;
		}
		int size () const
		{
			return _size;
		}
		bool isEmpty () const
		{
			return _size == 0;
		}
		void push (const T &e)
		{
			if (isFull ())
				expand ();
			_data[_size++] = e;
		}
		T pop ()
		{
			shrink ();
			return _data[--_size];
		}
		T top () const
		{
			if (isEmpty ())
				throw std::runtime_error ("underflow");
			return _data [_size - 1];
		}

		bool operator== (const Stack<T> &s);
		bool operator!= (const Stack<T> &s);
private:
		void expand ();
		bool isFull () const
		{
			return _size == _capacity;
		}
		void shrink ();
		void copyFrom (const Stack<T> &s);
private:
		int _capacity;
		int _size;
		T *_data;
};

#include "stack_impl.h"
#endif
