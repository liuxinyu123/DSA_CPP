#ifndef _SINGLELIST_PRINT_H_
#define _SINGLELIST_PRINT_H_

#include <iostream>

template<typename T>
void SingleList<T>::Print()
{
	if(!Empty())
	{
		Position(T) p = Begin();
		while(p)
		{
			std::cout << p -> data_ << " " ;
			p = p -> succ_;
		}
		
		std::cout << std::endl;
	}

}

#endif
