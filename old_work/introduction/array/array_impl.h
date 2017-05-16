#ifndef _ARRAY_IMPL_H_
#define _ARRAY_IMPL_H_

#include <iostream>

template<typename T>
void Array<T>::Swap(T &a,T &b)
{
	T tmp = a;
	a = b;
	b = tmp;
}

template<typename T>
void Array<T>::Inverse()
{
	int lo = 0;
	int hi = vec_.size() - 1;

	while(lo < hi)
	{
		Swap(vec_[lo++],vec_[hi--]);
	}
}

template<typename T>
void Array<T>::Inverse(int lo,int hi)
{
	if(lo < hi)
	{
		Swap(vec_[lo],vec_[hi]);
		Inverse(lo + 1,hi - 1);
	}
}

template<typename T>
void Array<T>::Print()
{
	for(T &a : vec_)
		std::cout << a << " ";

	std::cout << std::endl;	
}

template<typename T>
int Array<T>::Sum(int n)
{
	return (n < 0) ? 0 : (Sum(n - 1) + vec_[n]);
}

template<typename T>
int Array<T>::Sum(int lo,int hi)
{
	if(lo == hi)
		return vec_[lo];

	int mid = (lo + hi) / 2;

	return Sum(lo,mid) + Sum(mid + 1,hi);
}

#endif
