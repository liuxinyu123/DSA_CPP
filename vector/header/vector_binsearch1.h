#ifndef _VECTOR_BINSEARCH_H_
#define _VECTOR_BINSEARCH_H_

template<typename T>
Rank Vector<T>::BinSearch(const T &elem,Rank lo,Rank hi) const
{
	while(lo < hi)
	{
		int mid = (lo + hi) / 2;
		if(elem < array_[mid])
			hi = mid;
		else if(array_[mid] < elem)
			lo = mid + 1;
		else
			return mid;
	}

	return -1;
}

#endif
