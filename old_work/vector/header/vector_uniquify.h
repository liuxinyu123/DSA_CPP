#ifndef _VECTOR_UNIQUIFY_H_
#define _VECTOR_UNIQUIFY_H_

template<typename T>
int Vector<T>::Uniquify()
{
	int oldSize = size_;
	int i = 1;
	
	while(i < size_)
	{
		if(array_[i] == array_[i - 1])
			Delete(i);
		else
			++i;	
	}

	Shrunk();
	return size_ - oldSize;
}

#endif
