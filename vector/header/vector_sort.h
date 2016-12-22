#ifndef _VECTOT_SORT_H_
#define _VECTOT_SORT_H_

template<typename T>
void Vector<T>::Sort()
{
	BubbleSort();
}

template<typename T>
void Vector<T>::Sort(Rank lo,Rank hi)
{
	BubbleSort1(lo,hi);
}
#endif
