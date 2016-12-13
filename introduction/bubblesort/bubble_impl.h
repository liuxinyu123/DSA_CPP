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

template<typename T>
void Bubble<T>::BubbleSort1A()
{
	int sorted = 0;
	int swp = 0;
	int cmp = 0;

	int n = vec_.size();

	while(!sorted)
	{
		sorted = 1;
		for(int i = 1; i < n; ++i)
		{
			if(vec_[i - 1] > vec_[i])
			{
				Swap(vec_[i - 1],vec_[i]);
				++swp;
				sorted = 0;
			}

			++cmp;
		}

		--n;
	}

	std::cout << "Compare: " << cmp << " Swap: " << swp << std::endl; 	
}

template<typename T>
void Bubble<T>::BubbleSort1B()
{
	int swp = 0;
	int cmp = 0;
	int n = vec_.size();

	for(int sorted = 0;sorted = !sorted; n--)
	{
		for(int i = 1; i < n; ++i)
		{
			if(vec_[i - 1] > vec_[i])
			{
				Swap(vec_[i - 1],vec_[i]);
				++swp;
				sorted = 0;
			}

			++cmp;
		}
	}

	std::cout << "Compare: " << cmp << " Swap: " << swp << std::endl; 	
}

template<typename T>
void Bubble<T>::BubbleSort2()
{
	int cmp = 0;
	int swp = 0;
	int n = vec_.size();

	for(int m = 0; 1 < n; n = m)
	{
		for(int i = m = 1; i < n; ++i)
		{
			if(vec_[i - 1] > vec_[i])
			{
				Swap(vec_[i - 1],vec_[i]);
				++swp;
				m = i;
			}

			++cmp;
		}
	}

	std::cout << "Compare: " << cmp << " Swap: " << swp << std::endl; 	
}
#endif
