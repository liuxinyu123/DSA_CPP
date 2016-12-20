#ifndef _VECTOR_REMOVE_H_
#define _VECTOR_REMOVE_H_

template<typename T>
int Vector<T>::Remove(Rank lo,Rank hi)
{
	if(lo == hi)
		return 0;

	while(hi < size_)
		array_[lo++] = array_[hi++];

	size_ = lo;

	return hi - lo;
}

#endif
