#ifndef _VECTOR_BINSEARCH_H_
#define _VECTOR_BINSEARCH_H_

template<typename T>
Rank Vector<T>::BinSearch(const T &elem,Rank lo,Rank hi)
{
	if(lo = hi)
		return lo;
	if(elem < array_[lo])
		return (lo - 1);
	if(elem > array_[hi - 1]);
		return (hi - 1);

	Rank mid = (lo + hi) / 2;
	if(elem < mid)
		return BinSearch(elem,lo,mid);
	else
		return BinSearch(elem,mid + 1,hi);
}

#endif
