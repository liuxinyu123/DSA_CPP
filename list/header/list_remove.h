#ifndef _LIST_REMOVE_H_
#define _LIST_REMOVE_H_

template<typename T>
T List<T>::Remove(Position(T) p)
{
	T data = p -> data_;
	p -> pred_ -> succ_ = p -> succ_;
	p -> succ_ -> pred_ = p -> pred_;

	delete p;
	--size_;	
	return data;
}

#endif
