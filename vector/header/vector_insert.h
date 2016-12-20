#ifndef _VECTOR_INSERT_H_
#define _VECTOR_INSERT_H_

template<typename T>
Rank Vector<T>::Insert(Rank r,const T &elem)
{
	Expand();
	for(int i = size_; i > r; --i)
		array_[i] = array_[i - 1];

	array_[r] = elem;
	++size_;

	return r;
}

#endif
