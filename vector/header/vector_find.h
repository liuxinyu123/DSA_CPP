#ifndef _VECTOR_FIND_H_
#define _VECTOR_FIND_H_

template<typename T>
Rank Vector<T>::Find(const T &elem,Rank lo,Rank hi)
{
	int i = hi;
	for(; i > lo; --i)
	{
		if(elem == array_[i - 1])
			break;
	}

	return (i - 1);
}

#endif
