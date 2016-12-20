#ifndef _VECTOR_EXPAND_H_
#define _VECTOR_EXPAND_H_

#define Max(a,b)  ((a) > (b)? (a):(b))

template<typename T>
void Vector<T>::Expand()
{
	if(size_ < capacity_)
		return;
	capacity_ = Max(DEFAULT_CAPACITY,2 * capacity_);

	T *oldArray = array_;
	array_ = new T[capacity_];
	for(int i = 0; i < size_; ++i)
		array_[i] = oldArray[i];

	delete [] oldArray;
}

#endif
