#ifndef _UNEXTREME_IMPL_H_
#define _UNEXTREME_IMPL_H_

#include <cstdlib>
#include <vector>

template <typename T>
T UnExtreme<T>::Max(T a,T b,T c)
{
	return Max2(Max2(a,b),Max2(b,c));
}

template <typename T>
T UnExtreme<T>::Min(T a,T b,T c)
{
	return Min2(Min2(a,b),Min2(b,c));
}

template <typename T>
pIndex UnExtreme<T>::RandProductThreeIndex()
{
	pIndex pIdx = new  Index;
	int vec_size = vec_.size();
	
	srand(std::time(0));
	pIdx -> idx1 = rand() % vec_size;
	pIdx -> idx2 = rand() % vec_size;
	pIdx -> idx3 = rand() % vec_size;

	return pIdx;
}

template <typename T>
T UnExtreme<T>::UnExtremeElement()
{
	pIndex p = RandProductThreeIndex();

	T min = Min(vec_[p -> idx1],vec_[p -> idx2],vec_[p -> idx3]);
	T max = Max(vec_[p -> idx1],vec_[p -> idx2],vec_[p -> idx3]);

	T result = min;
	if(vec_[p -> idx1] != min && vec_[p -> idx1] != max)
		result = vec_[p -> idx1];
	if(vec_[p -> idx2] != min && vec_[p -> idx2] != max)
		result = vec_[p -> idx2];
	if(vec_[p -> idx3] != min && vec_[p -> idx3] != max)
		result = vec_[p -> idx3];
	
	return result;
}

#endif
