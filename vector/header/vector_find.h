#ifndef _VECTOR_FIND_H_
#define _VECTOR_FIND_H_

template<typename T>
Rank Vector<T>::Find(const T &elem,Rank lo,Rank hi) const
{
	int i = hi - 1;
	for(; i >= lo; --i)
	{
		if(elem == array_[i])
			break;
	}

	return i;
}

#endif
