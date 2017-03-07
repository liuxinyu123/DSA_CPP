#ifndef _VECTOR_BUBBLESORT1_H_
#define _VECTOR_BUBBLESORT1_H_

template<typename T>
void Vector<T>::BubbleSort1(Rank lo,Rank hi)   
{
	while(lo < Bubble1(lo,hi--));
}


#endif
