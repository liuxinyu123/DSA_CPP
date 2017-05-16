#ifndef _LIST_DESTRUCTOR_H_
#define _LIST_DESTRUCTOR_H_

template<typename T>
List<T>::~List()
{
	Clear();
	delete header_;
	delete trailer_;
}

#endif
