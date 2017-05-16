#ifndef _VECTOT_SORT1_H_
#define _VECTOT_SORT1_H_

template<typename T>
void Vector<T>::Sort1()
{
	MergeSort(0,size_);
}

template<typename T>
void Vector<T>::Sort1(Rank lo,Rank hi)
{
	MergeSort(lo,hi);
}

#endif
