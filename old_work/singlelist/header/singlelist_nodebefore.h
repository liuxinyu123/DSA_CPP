#ifndef _SINGLELIST_NODEBEFORE_H_
#define _SINGLELIST_NODEBEFORE_H_

template<typename T>
Position(T) SingleList<T>::NodeBefore(Position(T) p) const
{
	Position(T) q = Begin();

	while(q && (q -> succ_ != p))
		q = q -> succ_;

	return q;
}

#endif
