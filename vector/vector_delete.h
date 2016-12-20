#ifndef _VECTOR_DELETE_H_
#define _VECTOR_DELETE_H_

template<typename T>
T Vector<T>::Delete(Rank r)
{
	T temp = array_[r];
	Remove(r,r + 1);
	return temp;
}

#endif
