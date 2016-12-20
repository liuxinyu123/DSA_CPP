#ifndef _VECTOR_POPBACK_H_
#define _VECTOR_POPBACK_H_

template<typename T>
T Vector<T>::PopBack()
{
	T temp = array_[size_ - 1];
	Delete(size_ - 1);

	return temp;
}

#endif
