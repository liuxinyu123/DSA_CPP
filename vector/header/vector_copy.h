#ifndef _VECTOR_COPY_H_
#define _VECTOR_COPY_H_

template<typename T>
void Vector<T>::CopyFrom(const T *arr,Rank lo,Rank hi)
{
	capacity_ = 2 * (hi - lo);
	array_ = new T[capacity_];
	size_ = 0;
	while(lo < hi)
	{
		array_[size_++] = arr[lo++];
	}
}

#endif
