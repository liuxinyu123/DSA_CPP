#ifndef _VECTOR_DEDUPLICATE_H_
#define _VECTOR_DEDUPLICATE_H_

template<typename T>
int Vector<T>::Deduplicate()
{
	int oldSize = size_;
	int i = 1;
	while(i < size_)
	{
		if(Find(array_[i],0,i) < 0)//没找到
			++i;
		else
			Delete(i);
	}

	Shrunk();
	return (oldSize - size_);
}

#endif
