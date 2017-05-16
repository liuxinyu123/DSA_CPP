#ifndef _LIST_PRINT_H_
#define _LIST_PRINT_H_

#include <iostream>

template<typename T>
void List<T>::Print() const
{
	if(!Empty())
	{
		Position(T) p = First();
		while(p != trailer_)
		{
			std::cout << p -> data_ << " ";
		}
	}

	std::cout << std::endl;
}

#endif
