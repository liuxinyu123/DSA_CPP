#ifndef _VECTOR_BUBBLESORT_H_
#define _VECTOR_BUBBLESORT_H_

template<typename T>
void Vector<T>::BubbleSort()
{
	for(int i = size_; i > 1; --i)
	{
		for(int j = 1; j < i; ++j)
		{
			if(array_[j - 1] > array_[j])
				Swap(array_[j - 1],array_[j]);
		}
	}
}

template<typename T>
void Vector<T>::BubbleSort(Rank lo,Rank hi)
{
	while(!Bubble(lo,hi--));
}

#endif
