#ifndef _VECTOR_PUSHBACK_H_
#define _VECTOR_PUSHBACK_H_

template<typename T>
void Vector<T>::PushBack(const T &elem)
{
	Expand();
	Insert(size_,elem);	
}

#endif

