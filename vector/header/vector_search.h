#ifndef _VECTOR_SEARCH_H_
#define _VECTOR_SEARCH_H_

template<typename T>
Rank Vector<T>::Search(const T &elem,Rank lo,Rank hi)
{
	return BinSearch(elem,lo,hi);	
}

#endif
