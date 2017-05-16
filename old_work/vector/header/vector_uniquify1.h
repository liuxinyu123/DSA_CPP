#ifndef _VECTOR_UNIQUIFY1_H_
#define _VECTOR_UNIQUIFY1_H_

template<typename T>
int Vector<T>::Uniquify1()
{
	int oldSize = size_;
	int idx = 1;
	int i = 1;

	while(i < oldSize)
	{
		if(array_[i] == array_[idx - 1])
		{
			++i;
			--size_;
		}
		else
			array_[idx++] = array_[i++];
	}

	Shrunk();
	return (oldSize - size_);
}

#endif
