#ifndef _VECTOR_REPLACE_H_
#define _VECTOR_REPLACE_H_

template<typename T>
void Vector<T>::Replace(Rank r,const T &elem)
{
	array_[r] = elem;
}

#endif
