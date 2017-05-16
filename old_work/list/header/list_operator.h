#ifndef _LIST_OPERATOR_H_
#define _LIST_OPERATOR_H_

template<typename T>
T List<T>::operator[](Rank r) const
{
	Position(T) p = First();

	while(0 < r--)
		p -> p -> succ_;

	return p -> data_;
}

#endif
