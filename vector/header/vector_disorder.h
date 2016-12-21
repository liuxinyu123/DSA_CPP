#ifndef _VECTOR_DISORDER_H_
#define _VECTOR_DISORDER_H_

template<typename T>
int Vector<T>::Disorder() const
{
	int cnt = 0;
	for(int i = 0; i < size_ - 1; ++i)
	{
		if(array_[i] > array_[i + 1])
			++cnt;
	}

	return cnt;
}

#endif
