#ifndef _VECTOR_MERGESORT_H_
#define _VECTOR_MERGESORT_H_

template<typename T>
void Vector<T>::MergeSort(Rank lo,Rank hi)
{
	if(hi - lo < 2)
		return;
	Rank mid = (hi + lo) / 2;

	MergeSort(lo,mid);
	MergeSort(mid,hi);
	Merge(lo,mid,hi);
}

template<typename T>
void Vector<T>::Merge(Rank lo,Rank mid,Rank hi)
{
	T *A = array_ + lo;
	int lB = mid - lo;
	T *B = new T[lB];
	for(int i = 0; i < lB; ++i)
		B[i] = A[i];
	int lC = hi - mid;
	T *C = array_ + mid;

	for(Rank i = 0,j = 0,k = 0; (j < lB)||(k < lC);)
	{
		if((j < lB) && ((lC <= k) || (B[j] <= C[k])))
			A[i++] = B[j++];
		if((k < lC) && ((lB <= j) || (C[k] < B[j])))
			A[i++] = C[k++];
	}
}
#endif

