#ifndef _SINGLELIST_BACK_H_
#define _SINGLELIST_BACK_H_

template<typename T>
Position(T) SingleList<T>::End() const
{
	if(Empty())
		return nullptr;
	Position(T) p = Begin();
	while(p -> succ_)
		p = p -> succ_;

	return p;
}

#endif
