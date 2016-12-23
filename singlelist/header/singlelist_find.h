#ifndef _SINGLELIST_FIND_H_
#define _SINGLELIST_FIND_H_

template<typename T>
Position(T) SingleList<T>::Find(const T &elem) const
{
	if(Empty())
		return nullptr;
	Position(T) p = Begin();
	while(p && (p -> data_ != elem))
		p = p -> succ_;
	return p;
}

#endif
