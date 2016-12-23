#ifndef _LIST_CLEAR_H_
#define _LIST_CLEAR_H_

template<typename T>
int List<T>::Clear()
{
	int size = size_;
	while(!Empty())
	{
		Remove(First());
	}

	return size;
}

#endif
