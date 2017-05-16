#ifndef _VECTOR_BUBBLE1_H_
#define _VECTOR_BUBBLE1_H_


template<typename T>
Rank Vector<T>::Bubble1(Rank lo,Rank hi)
{
	Rank sorted = lo;
	int i = lo + 1;
	while(i < hi)
	{
		if(array_[i - 1] > array_[i])
		{
			Swap(array_[i - 1],array_[i]);
			sorted = i;
		}
		++i;
	}

	return sorted;
}

#endif
