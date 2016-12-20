#ifndef _VECTOR_PRINT_H_
#define _VECTOR_PRINT_H_

#include <iostream>

template<typename T>
void Vector<T>::Print()
{
	for(int i = 0; i < size_; ++i)
		std::cout << array_[i] << " " ;

	std::cout << std::endl;
}

#endif
