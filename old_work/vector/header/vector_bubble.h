#ifndef _VECTOR_BUBBLE_H_
#define _VECTOR_BUBBLE_H_


template<typename T>
bool Vector<T>::Bubble(Rank lo,Rank hi)
{
	bool sorted = true;
	int i = lo + 1;
	while(i < hi)
	{
		if(array_[i - 1] > array_[i])
		{
			Swap(array_[i - 1],array_[i]);
			sorted = false;
		}
		++i;
	}

	return sorted;
}

#endif
