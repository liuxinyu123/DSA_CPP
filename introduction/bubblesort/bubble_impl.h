#ifndef _BUBBLE_IMPL_H_
#define _BUBBLE_IMPL_H_

#include <iostream>

template<typename T>
void Bubble<T>::Print()
{
	for(auto it = vec_.begin(); it != vec_.end(); ++it)
	{
		std::cout << *it << " "; 
	}

	std::cout << std::endl;
}

template<typename T>
Bubble<T>::Bubble(std::vector<T> &v):vec_(v)
{	
}

template<typename T>
void Bubble<T>::BubbleSort()
{
	int sz = vec_.size();
	int swp = 0;
	int cmp = 0;
	while(sz--)
	{
		for(int i = 0; i < sz; ++i)
		{
			if(vec_[i] > vec_[i + 1])
			{
				Swap(vec_[i],vec_[i + 1]);
				++swp;
			}

			++cmp;
		}
	}

	std::cout << "Compare: " << cmp << " Swap: " << swp << std::endl; 	
}

template<typename T>
void Bubble<T>::Swap(T &a,T &b)
{
	T temp = a;
	a = b;
	b = temp;
}

#endif
