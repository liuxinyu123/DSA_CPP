#ifndef _ARRAY_H_
#define _ARRAY_H_


template<typename T>
class Array
{
public:
		Array() {}
		Array(std::vector<T> &v):vec_(v) {}
		void Inverse();
		void Inverse(int lo,int hi);
		void Print();
		int Size() {return vec_.size();}
		int Sum(int n);
		int Sum(int lo,int hi);

private:
		static void Swap(T &a,T &b);
private:
		std::vector<T> vec_;
};

#include "array_impl.h"

#endif
