#ifndef _VECTOR_BINSEARCH2_H_
#define _VECTOR_BINSEARCH2_H_

template<typename T>
Rank Vector<T>::BinSearch2(const T &elem,Rank lo,Rank hi) const
{
	while(lo < hi)
	{
		int mid = (lo + hi) / 2;
		if(elem < array_[mid])
			hi = mid;
		else 
			lo = mid + 1;
	}

	return (lo - 1);
}

#endif
