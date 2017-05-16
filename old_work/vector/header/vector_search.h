#ifndef _VECTOR_SEARCH_H_
#define _VECTOR_SEARCH_H_

template<typename T>
Rank Vector<T>::Search(const T &elem,Rank lo,Rank hi) const
{
	return BinSearch2(elem,lo,hi);	
}

#endif
