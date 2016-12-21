#ifndef _VECTOR_BINSEARCH1_H_
#define _VECTOR_BINSEARCH1_H_

template<typename T>
Rank Vector<T>::BinSearch1(const T &elem,Rank lo,Rank hi) const
{
	while(hi - lo > 1)
	{
		Rank mid = (lo + hi) / 2;
		if(elem < array_[mid])
			hi = mid;
		else
			lo = mid;
	}

	if(array_[lo] == elem)
		return lo;
	else
		return -1;
}	

#endif
