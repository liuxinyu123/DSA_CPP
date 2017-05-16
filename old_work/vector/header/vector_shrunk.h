#ifndef _VECTOR_SHRUNK_H_
#define _VECTOR_SHRUNK_H_

template<typename T>
void Vector<T>::Shrunk()
{
	if(capacity_ / size_ < 5)//低于20%，则缩容
		return;
	T *oldArray = array_;
	array_ = new T[capacity_ / 2];

	for(int i = 0; i < size_; ++i)
		array_[i] = oldArray[i];
	
	capacity_ /= 2;

}

#endif
