#ifndef _BUBBLE_H_
#define _BUBBLE_H_

#include <vector>

template<typename T>
class Bubble
{

public:
		Bubble(std::vector<T> &v);
		void BubbleSort();
		void Print();
private:
		void Swap(T &a,T &b);
private:
		std::vector<T> vec_;

};

#include "bubble_impl.h"

#endif
